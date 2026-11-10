#!/usr/bin/env python3
"""
update_official_solution.py — 掃描 metadata/*.yml，到 LeetCode 查每一題有沒有官方解答（editorial），
官方沒有解答的題目，把解法的 official_solution 寫成 no-solution。

判斷方式：LeetCode GraphQL 的 question.solution 欄位。
  - 有官方解答 -> 回傳物件（Premium 解答也算有，不論你有沒有訂閱）
  - 沒有官方解答 -> 回傳 null（例如 1185 Day of the Week 的 editorial 頁面是空的）

預設只處理 official_solution 是「空 / pending」的解法，不會動你已經手動標成
synced（已同步）、better（優於官方）的解法。

用法（在 repo 根目錄、啟動 venv 之後）：
    python3 tools/update_official_solution.py                 # 掃描全部，直接寫入
    python3 tools/update_official_solution.py --dry-run       # 只顯示會改哪些，不寫檔
    python3 tools/update_official_solution.py --only 1185 748 # 只處理指定題號
    python3 tools/update_official_solution.py --recheck       # 連已標 no-solution 的也重查
                                                              # （官方之後補上解答會改回 pending）

登入資訊（選用，被 LeetCode 擋 403 時才需要）：
    export LEETCODE_SESSION='你的 LEETCODE_SESSION cookie'
    export LEETCODE_CSRF='你的 csrftoken cookie'      # 可省略
cookie 取得方式：瀏覽器登入 LeetCode -> F12 -> Application -> Cookies -> leetcode.com。
cookie 等同你的登入憑證，不要貼給別人、不要 commit 進 git。

查詢結果會快取在 .editorial_cache.json（中斷後重跑不會重複查詢；記得加進 .gitignore）。
"""
import argparse
import glob
import json
import os
import re
import sys
import time
import urllib.error
import urllib.request

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml")
    sys.exit(1)

GRAPHQL_URL = "https://leetcode.com/graphql"
CACHE_FILE = ".editorial_cache.json"

PENDING = "pending"
NO_SOLUTION = "no-solution"

QUERY = """
query solutionInfo($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionFrontendId
    solution { id }
  }
}
"""


class AbortError(Exception):
    """遇到不該繼續打 API 的狀況（被擋、GraphQL 欄位錯誤），整個程式中止。"""


def slug_from_url(url):
    m = re.search(r"/problems/([^/]+)/?", url or "")
    return m.group(1) if m else None


def fetch_editorial_info(slug, session=None, csrf=None, retries=4):
    """回傳 {'frontend_id': int|None, 'has_editorial': bool}。"""
    headers = {
        "Content-Type": "application/json",
        "Referer": f"https://leetcode.com/problems/{slug}/",
        "Origin": "https://leetcode.com",
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 "
                      "(KHTML, like Gecko) Chrome/124.0 Safari/537.36",
    }
    if session:
        cookie = f"LEETCODE_SESSION={session}"
        if csrf:
            cookie += f"; csrftoken={csrf}"
            headers["x-csrftoken"] = csrf
        headers["Cookie"] = cookie

    body = json.dumps({"query": QUERY, "variables": {"titleSlug": slug}}).encode("utf-8")

    for attempt in range(1, retries + 1):
        req = urllib.request.Request(GRAPHQL_URL, data=body, headers=headers, method="POST")
        try:
            with urllib.request.urlopen(req, timeout=30) as resp:
                payload = json.loads(resp.read().decode("utf-8"))
        except urllib.error.HTTPError as e:
            if e.code in (429, 500, 502, 503, 504) and attempt < retries:
                wait = 2 ** attempt
                print(f"    HTTP {e.code}，{wait} 秒後重試（{attempt}/{retries}）")
                time.sleep(wait)
                continue
            if e.code in (401, 403):
                raise AbortError(
                    f"HTTP {e.code}：被 LeetCode 擋下。請設定環境變數 LEETCODE_SESSION"
                    "（登入後的 cookie）再試一次。")
            raise AbortError(f"HTTP {e.code}：{e.reason}")
        except urllib.error.URLError as e:
            if attempt < retries:
                time.sleep(2 ** attempt)
                continue
            raise AbortError(f"連線失敗：{e.reason}")

        if payload.get("errors"):
            raise AbortError(f"GraphQL 回傳錯誤（API 欄位可能已變更）：{payload['errors']}")

        question = (payload.get("data") or {}).get("question")
        if question is None:
            # slug 不存在
            return {"frontend_id": None, "has_editorial": None}

        fid = question.get("questionFrontendId")
        try:
            fid = int(fid)
        except (TypeError, ValueError):
            fid = None
        return {"frontend_id": fid, "has_editorial": question.get("solution") is not None}

    raise AbortError("重試次數用完")


def load_cache():
    if os.path.exists(CACHE_FILE):
        try:
            with open(CACHE_FILE, "r", encoding="utf-8") as f:
                return json.load(f)
        except (json.JSONDecodeError, OSError):
            pass
    return {}


def save_cache(cache):
    with open(CACHE_FILE, "w", encoding="utf-8") as f:
        json.dump(cache, f, ensure_ascii=False, indent=1)


def to_int(v):
    try:
        return int(v)
    except (TypeError, ValueError):
        return None


def process(meta_dir, args, fetch=fetch_editorial_info):
    session = os.environ.get("LEETCODE_SESSION")
    csrf = os.environ.get("LEETCODE_CSRF")
    cache = {} if args.no_cache else load_cache()

    check_states = {"", PENDING}
    if args.recheck:
        check_states.add(NO_SOLUTION)

    only = set(args.only or [])
    paths = sorted(glob.glob(os.path.join(meta_dir, "*.yml")))
    if not paths:
        print(f"找不到任何 {meta_dir}/*.yml，請確認在 repo 根目錄執行。")
        return 1

    changed_files = 0
    set_no_solution = []
    set_pending = []
    skipped_missing_url = []
    mismatch = []
    unknown_slug = []
    checked = 0

    for path in paths:
        with open(path, "r", encoding="utf-8") as f:
            data = yaml.safe_load(f)
        if not isinstance(data, dict):
            continue
        number = to_int(data.get("number"))
        if only and number not in only:
            continue

        sols = data.get("solutions") or []
        targets = [s for s in sols if (s.get("official_solution") or "") in check_states]
        if not targets:
            continue

        slug = slug_from_url(data.get("url"))
        if not slug:
            skipped_missing_url.append(number)
            continue

        info = cache.get(slug)
        if info is None or args.recheck:
            try:
                info = fetch(slug, session, csrf)
            except AbortError as e:
                print(f"\n中止：{e}")
                print("已處理完的結果有保留（快取與已寫入的檔案不會丟失），修正後直接重跑即可。")
                if not args.dry_run:
                    save_cache(cache)
                return 2
            cache[slug] = info
            if not args.dry_run:
                save_cache(cache)
            time.sleep(args.delay)
        checked += 1

        if info["has_editorial"] is None:
            unknown_slug.append((number, slug))
            continue

        if info["frontend_id"] is not None and number is not None and info["frontend_id"] != number:
            mismatch.append((number, slug, info["frontend_id"]))
            continue  # 網址與題號對不上，不敢亂改

        file_changed = False
        for s in targets:
            current = s.get("official_solution") or ""
            if not info["has_editorial"] and current in ("", PENDING):
                s["official_solution"] = NO_SOLUTION
                file_changed = True
            elif info["has_editorial"] and current == NO_SOLUTION:
                s["official_solution"] = PENDING   # 官方之後補上解答了
                file_changed = True

        if file_changed:
            changed_files += 1
            label = f"{number:>4} {slug}"
            if not info["has_editorial"]:
                set_no_solution.append(label)
            else:
                set_pending.append(label)
            if not args.dry_run:
                with open(path, "w", encoding="utf-8") as f:
                    yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    mode = "（dry-run，未寫檔）" if args.dry_run else ""
    print(f"\n查詢了 {checked} 題{mode}")
    print(f"標成 no-solution（官方沒有解答）：{len(set_no_solution)} 題")
    for label in set_no_solution:
        print(f"   {label}")
    if set_pending:
        print(f"改回 pending（官方現在有解答了）：{len(set_pending)} 題")
        for label in set_pending:
            print(f"   {label}")
    if mismatch:
        print(f"題號與網址不一致，已跳過：{len(mismatch)} 題")
        for number, slug, fid in mismatch:
            print(f"   metadata 是 {number}，但 {slug} 實際是 {fid}")
    if unknown_slug:
        print(f"LeetCode 查不到這個網址，已跳過：{len(unknown_slug)} 題")
        for number, slug in unknown_slug:
            print(f"   {number} {slug}")
    if skipped_missing_url:
        print(f"metadata 沒有 url，已跳過：{skipped_missing_url}")
    print(f"實際修改的檔案數：{changed_files}")
    return 0


def main():
    ap = argparse.ArgumentParser(description="把官方沒有解答的題目標成 official_solution: no-solution")
    ap.add_argument("meta_dir", nargs="?", default="metadata", help="metadata 資料夾（預設 metadata）")
    ap.add_argument("--dry-run", action="store_true", help="只顯示結果，不寫檔")
    ap.add_argument("--only", nargs="+", type=int, metavar="N", help="只處理這些題號")
    ap.add_argument("--recheck", action="store_true", help="連已標 no-solution 的也重查，並忽略快取")
    ap.add_argument("--no-cache", action="store_true", help="不使用快取")
    ap.add_argument("--delay", type=float, default=0.7, help="每次查詢間隔秒數（預設 0.7）")
    args = ap.parse_args()
    sys.exit(process(args.meta_dir, args))


if __name__ == "__main__":
    main()
