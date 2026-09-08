#!/usr/bin/env python3
"""
fetch_leetcode_ac.py — 取得目前帳號的 AC 總數，寫入 leetcode_ac_cache.json，
供 generate_site.py 在複習清單頁面（docs/review.md）最上方顯示。

改用 GraphQL API 抓取，解決舊版 /api/problems/all/ 只回傳部分題目（約 2000 題）
的問題，現在會分頁抓取所有題目的完整 AC 狀態。

有兩種取得資料的方式：

【自動模式（推薦）】
  1. 瀏覽器登入 leetcode.com
  2. 打開開發者工具（F12）→ Application/應用程式 → Cookies → https://leetcode.com
  3. 找到 LEETCODE_SESSION 這個 cookie，複製它的值
  4. 在 repo 根目錄建立 leetcode_session.txt，把值貼進去存檔（這個檔案已加進
     .gitignore，不會被 push 上去）
  5. 之後每次執行 python3 tools/fetch_leetcode_ac.py，會自動用 GraphQL API
     分頁抓取完整 AC 清單，不用再手動開網頁複製貼上。

  ⚠️ LEETCODE_SESSION 過期後（通常數週到數月，視 LeetCode 設定），自動抓取
     會失敗並提示你，屆時回到步驟 2 重新複製一次新的值即可。

【手動模式（沒有設定 leetcode_session.txt 時的備用方式）】
  1. 瀏覽器登入 leetcode.com
  2. 登入狀態下直接打開 https://leetcode.com/api/problems/all/
  3. 把整頁內容存成 leetcode_all.json（放在 repo 根目錄）
  4. 執行 python3 tools/fetch_leetcode_ac.py

  ⚠️ 手動模式使用舊版 API，可能只回傳部分題目，建議改用自動模式。

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
LEETCODE_GRAPHQL_URL = 'https://leetcode.com/graphql'

# 每次 GraphQL 分頁抓取的題數（LeetCode 單次上限約 2000，分批確保完整）
PAGE_SIZE = 2000


def load_session_cookie(path):
    if not os.path.exists(path):
        return None
    with open(path, 'r', encoding='utf-8') as f:
        value = f.read().strip()
    return value or None


def try_auto_fetch(session_path, json_path):
    """
    如果有設定 leetcode_session.txt，就用 GraphQL API 自動抓取完整 AC 清單，
    轉換成與原本 leetcode_all.json 相容的格式後寫檔。
    回傳 True 代表成功，False 代表沒有設定 session（fallback 手動模式）。
    連線失敗或 session 過期會直接印錯誤並結束程式。
    """
    session_value = load_session_cookie(session_path)
    if not session_value:
        return False

    try:
        import requests
    except ImportError:
        print("❌ 自動模式需要 requests 套件，請先執行: pip install requests --break-system-packages")
        sys.exit(1)

    print("🔄 偵測到 leetcode_session.txt，正在用 GraphQL API 抓取完整 AC 清單...")

    headers = {
        'Content-Type': 'application/json',
        'User-Agent': 'Mozilla/5.0',
        'Referer': 'https://leetcode.com/problemset/all/',
        'x-csrftoken': 'fetch',
    }
    cookies = {
        'LEETCODE_SESSION': session_value,
        'csrftoken': 'fetch',
    }

    # Step 1: 取得帳號名稱
    profile_query = {
        'query': '''
            query globalData {
                userStatus {
                    username
                    isSignedIn
                }
            }
        '''
    }
    try:
        resp = requests.post(LEETCODE_GRAPHQL_URL, json=profile_query,
                             headers=headers, cookies=cookies, timeout=15)
    except requests.RequestException as e:
        print(f"❌ 連線失敗: {e}")
        sys.exit(1)

    if resp.status_code != 200:
        print(f"❌ LeetCode 回應狀態碼 {resp.status_code}，session 可能已過期")
        print(f"   請重新複製 LEETCODE_SESSION 並覆蓋 {session_path}")
        sys.exit(1)

    profile_data = resp.json()
    user_status = profile_data.get('data', {}).get('userStatus', {})
    user_name = user_status.get('username', '')
    is_signed_in = user_status.get('isSignedIn', False)

    if not is_signed_in or not user_name:
        print("❌ session 未登入生效，請重新複製 LEETCODE_SESSION cookie 值")
        sys.exit(1)

    print(f"   帳號：{user_name}")

    # Step 2: 分頁抓取所有題目的 AC 狀態
    ac_query = {
        'query': '''
            query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
                problemsetQuestionList: questionList(
                    categorySlug: $categorySlug
                    limit: $limit
                    skip: $skip
                    filters: $filters
                ) {
                    total: totalNum
                    questions: data {
                        frontendQuestionId: questionFrontendId
                        title
                        status
                    }
                }
            }
        ''',
        'variables': {
            'categorySlug': '',
            'skip': 0,
            'limit': PAGE_SIZE,
            'filters': {},
        }
    }

    all_questions = []
    skip = 0
    total = None

    while True:
        ac_query['variables']['skip'] = skip
        try:
            resp = requests.post(LEETCODE_GRAPHQL_URL, json=ac_query,
                                 headers=headers, cookies=cookies, timeout=30)
        except requests.RequestException as e:
            print(f"❌ 連線失敗（skip={skip}）: {e}")
            sys.exit(1)

        if resp.status_code != 200:
            print(f"❌ 狀態碼 {resp.status_code}（skip={skip}），session 可能已過期")
            sys.exit(1)

        page_data = resp.json().get('data', {}).get('problemsetQuestionList', {})
        if total is None:
            total = page_data.get('total', 0)
            print(f"   題庫總題數：{total}")

        questions = page_data.get('questions', [])
        if not questions:
            break

        all_questions.extend(questions)
        skip += len(questions)
        print(f"   已抓取 {len(all_questions)} / {total} 題...", end='\r')

        if len(all_questions) >= total:
            break

    print()

    # Step 3: 轉換成與 leetcode_all.json 相容的格式
    stat_status_pairs = []
    for q in all_questions:
        try:
            fid = int(q.get('frontendQuestionId', 0))
        except (ValueError, TypeError):
            continue
        stat_status_pairs.append({
            'stat': {'frontend_question_id': fid, 'question__title': q.get('title', '')},
            'status': 'ac' if q.get('status') == 'AC' else (q.get('status') or ''),
        })

    num_solved = sum(1 for p in stat_status_pairs if p['status'] == 'ac')
    data = {
        'user_name': user_name,
        'num_solved': num_solved,
        'num_total': total,
        'stat_status_pairs': stat_status_pairs,
    }

    with open(json_path, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False)

    print(f"✓ 已抓取完整資料並覆蓋 {json_path}（共 {len(all_questions)} 題，AC {num_solved} 題）")
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
