#!/usr/bin/env python3
"""
fetch_leetcode_ac.py — 從手動下載的 leetcode_all.json 讀出目前帳號的 AC 總數，
寫入 leetcode_ac_cache.json，供 generate_site.py 在複習清單頁面（docs/review.md）最上方顯示。

leetcode_all.json 的取得方式跟 find_gap.py 用的完全一樣：
  1. 瀏覽器登入 leetcode.com
  2. 登入狀態下直接打開 https://leetcode.com/api/problems/all/
  3. 把整頁內容存成 leetcode_all.json（放在 repo 根目錄）

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


def load_leetcode_all(path):
    if not os.path.exists(path):
        print(f"❌ 找不到 {path}")
        print("   請先登入 leetcode.com，再開啟 https://leetcode.com/api/problems/all/")
        print(f"   把內容存成 {path}（放在 repo 根目錄），跟 find_gap.py 用的是同一份檔案")
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

    if num_solved is None:
        # 保底：如果 num_solved 欄位不存在，改用 stat_status_pairs 自己數
        num_solved = sum(
            1 for pair in data.get('stat_status_pairs', [])
            if pair.get('status') == 'ac'
        )

    if not user_name:
        print("⚠️ 這份 JSON 裡沒有 user_name，可能是登入狀態沒生效（抓到的是匿名版本），"
              "請確認下載當下瀏覽器有登入 leetcode.com")

    return num_solved, num_total, user_name


def main():
    json_path = sys.argv[1] if len(sys.argv) > 1 else JSON_FILE_DEFAULT
    cache_path = sys.argv[2] if len(sys.argv) > 2 else CACHE_FILE_DEFAULT

    data = load_leetcode_all(json_path)
    num_solved, num_total, user_name = extract_ac_count(data)

    cache = {
        'num_solved': num_solved,
        'num_total': num_total,
        'user_name': user_name,
        'fetched_at': datetime.now().strftime('%Y-%m-%d %H:%M'),
    }
    with open(cache_path, 'w', encoding='utf-8') as f:
        json.dump(cache, f, ensure_ascii=False, indent=2)

    print(f"✓ 帳號 {user_name or '(未知)'}：AC {num_solved}{f' / {num_total}' if num_total else ''} 題")
    print(f"  已寫入 {cache_path}")


if __name__ == '__main__':
    main()
