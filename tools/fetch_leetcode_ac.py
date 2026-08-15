#!/usr/bin/env python3
"""
fetch_leetcode_ac.py — 取得目前帳號的 AC 總數，寫入 leetcode_ac_cache.json，
供 generate_site.py 在複習清單頁面（docs/review.md）最上方顯示。

有兩種取得資料的方式：

【自動模式（推薦）】
  1. 瀏覽器登入 leetcode.com
  2. 打開開發者工具（F12）→ Application/應用程式 → Cookies → https://leetcode.com
  3. 找到 LEETCODE_SESSION 這個 cookie，複製它的值
  4. 在 repo 根目錄建立 leetcode_session.txt，把值貼進去存檔（這個檔案已加進
     .gitignore，不會被 push 上去）
  5. 之後每次執行 python3 tools/fetch_leetcode_ac.py，會自動連線抓最新資料，
     不用再手動開網頁複製貼上。

  ⚠️ LEETCODE_SESSION 過期後（通常數週到數月，視 LeetCode 設定），自動抓取
     會失敗並提示你，屆時回到步驟 2 重新複製一次新的值即可。

【手動模式（沒有設定 leetcode_session.txt 時的備用方式）】
  1. 瀏覽器登入 leetcode.com
  2. 登入狀態下直接打開 https://leetcode.com/api/problems/all/
  3. 把整頁內容存成 leetcode_all.json（放在 repo 根目錄）
  4. 執行 python3 tools/fetch_leetcode_ac.py

用法（在 repo 根目錄執行）：
    python3 tools/fetch_leetcode_ac.py
    python3 tools/fetch_leetcode_ac.py 自訂json檔 自訂cache檔
"""
import sys
import os
import json
from datetime import datetime

JSON_FILE_DEFAULT = 'leetcode_all.json'
CACHE_FILE_DEFAULT = 'leetcode_ac_cache.json'
SESSION_FILE_DEFAULT = 'leetcode_session.txt'
LEETCODE_ALL_URL = 'https://leetcode.com/api/problems/all/'


def load_session_cookie(path):
    if not os.path.exists(path):
        return None
    with open(path, 'r', encoding='utf-8') as f:
        value = f.read().strip()
    return value or None


def try_auto_fetch(session_path, json_path):
    """
    如果有設定 leetcode_session.txt，就自動連線抓最新的 leetcode_all.json，
    覆蓋掉本機那份舊快照。回傳 True 代表成功抓到新資料並已寫檔，
    False 代表沒有設定 session（不算錯誤，會 fallback 用手動模式）。
    連線失敗（例如 session 過期）會直接印出錯誤並結束程式，不會悄悄 fallback，
    避免你誤以為抓到新資料、其實還是在看舊的快照。
    """
    session_value = load_session_cookie(session_path)
    if not session_value:
        return False

    try:
        import requests
    except ImportError:
        print("❌ 自動模式需要 requests 套件，請先執行: pip install requests --break-system-packages")
        sys.exit(1)

    print("🔄 偵測到 leetcode_session.txt，正在自動連線抓取最新資料...")
    try:
        resp = requests.get(
            LEETCODE_ALL_URL,
            cookies={'LEETCODE_SESSION': session_value},
            headers={
                'User-Agent': 'Mozilla/5.0',
                'Referer': 'https://leetcode.com/problemset/all/',
            },
            timeout=15,
        )
    except requests.RequestException as e:
        print(f"❌ 連線失敗: {e}")
        print("   請檢查網路連線，或改用手動模式（見檔案開頭說明）")
        sys.exit(1)

    if resp.status_code != 200:
        print(f"❌ LeetCode 回應狀態碼 {resp.status_code}，session 可能已過期")
        print("   請重新登入 leetcode.com，重新複製一次 LEETCODE_SESSION cookie 值，")
        print(f"   覆蓋掉 {session_path} 的內容後再試一次")
        sys.exit(1)

    try:
        data = resp.json()
    except ValueError:
        print("❌ 回應內容不是合法的 JSON，session 可能已過期或被導向登入頁")
        sys.exit(1)

    if not data.get('user_name'):
        print("❌ 回應裡沒有 user_name，代表這個 session 沒有登入生效（抓到匿名版本）")
        print("   請重新登入 leetcode.com，重新複製一次 LEETCODE_SESSION cookie 值")
        sys.exit(1)

    with open(json_path, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False)
    print(f"✓ 已自動抓取最新資料並覆蓋 {json_path}")
    return True


def load_leetcode_all(path):
    if not os.path.exists(path):
        print(f"❌ 找不到 {path}")
        print("   請先登入 leetcode.com，再開啟 https://leetcode.com/api/problems/all/")
        print(f"   把內容存成 {path}（放在 repo 根目錄），跟 find_gap.py 用的是同一份檔案")
        print("   （或設定 leetcode_session.txt 改用自動模式，見檔案開頭說明）")
        sys.exit(1)
    with open(path, 'r', encoding='utf-8') as f:
        try:
            return json.load(f)
        except json.JSONDecodeError as e:
            print(f"❌ {path} 不是合法的 JSON: {e}")
            sys.exit(1)


def extract_ac_count(data):
    num_solved = data.get('num_solved')
    num_total = data.get('num_total')
    user_name = data.get('user_name', '')

    # 逐題 AC 清單：從 stat_status_pairs 裡把每一筆 status == 'ac' 的
    # frontend_question_id 收集起來，供 find_ac_gap.py 逐題比對用。
    # （frontend_question_id 就是 LeetCode 網站上顯示、也是 metadata/*.yml
    #   裡 number 欄位對應的題號，跟內部的 question_id 不是同一組編號）
    solved_ids = sorted({
        pair['stat']['frontend_question_id']
        for pair in data.get('stat_status_pairs', [])
        if pair.get('status') == 'ac' and pair.get('stat', {}).get('frontend_question_id') is not None
    })

    if num_solved is None:
        # 保底：如果 num_solved 欄位不存在，改用 stat_status_pairs 自己數
        num_solved = sum(
            1 for pair in data.get('stat_status_pairs', [])
            if pair.get('status') == 'ac'
        )

    if not user_name:
        print("⚠️ 這份 JSON 裡沒有 user_name，可能是登入狀態沒生效（抓到的是匿名版本），"
              "請確認下載當下瀏覽器有登入 leetcode.com")

    if not solved_ids:
        print("⚠️ 沒有從 stat_status_pairs 抓到任何逐題 AC 紀錄，"
              "leetcode_ac_cache.json 裡的 solved_ids 會是空的，"
              "find_ac_gap.py 仍只能看到總數，無法逐題比對")

    return num_solved, num_total, user_name, solved_ids


def main():
    json_path = sys.argv[1] if len(sys.argv) > 1 else JSON_FILE_DEFAULT
    cache_path = sys.argv[2] if len(sys.argv) > 2 else CACHE_FILE_DEFAULT
    session_path = os.path.join(os.path.dirname(os.path.abspath(json_path)) or '.', SESSION_FILE_DEFAULT) \
        if os.path.dirname(json_path) else SESSION_FILE_DEFAULT

    try_auto_fetch(session_path, json_path)

    data = load_leetcode_all(json_path)
    num_solved, num_total, user_name, solved_ids = extract_ac_count(data)

    cache = {
        'num_solved': num_solved,
        'num_total': num_total,
        'user_name': user_name,
        'fetched_at': datetime.now().strftime('%Y-%m-%d %H:%M'),
        'solved_ids': solved_ids,
    }
    with open(cache_path, 'w', encoding='utf-8') as f:
        json.dump(cache, f, ensure_ascii=False, indent=2)

    print(f"✓ 帳號 {user_name or '(未知)'}：AC {num_solved}{f' / {num_total}' if num_total else ''} 題")
    print(f"  已寫入 {cache_path}（含 {len(solved_ids)} 筆逐題 AC 題號）")


if __name__ == '__main__':
    main()
