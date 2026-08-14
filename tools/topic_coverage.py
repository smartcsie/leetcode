#!/usr/bin/env python3
"""
topic_coverage.py

1) 列出目前 metadata/*.yml 裡，各分類（topic）已收錄的題目。
2) 針對有對應到 LeetCode 官方 tag 的分類，抓該 tag 下「還沒收錄」的題目，
   優先列出 Easy、再列 Medium（盡量不建議 Hard），當作練習建議。

用法：
    python3 topic_coverage.py [metadata_dir] [--suggest N]

    metadata_dir   預設 'metadata'
    --suggest N    每個分類最多建議幾題（預設 5，設 0 = 只列已收錄、不查 LeetCode）

注意：
    - 「已收錄」的部分完全用本機 metadata 就能算出來，一定準確。
    - 「建議」的部分需要打 LeetCode 的公開 GraphQL API，且只有在
      TOPIC_TAG_MAP 裡有對應到「LeetCode 官方 tag slug」的分類才查得到。
      你的 topics 大多是自訂的細分類（例如 math-digit-decomposition），
      跟 LeetCode 官方 tag（例如 math）不是一對一，所以下面 TOPIC_TAG_MAP
      只先幫幾個名稱剛好對得上的分類填好，其他的請照註解自己補上對應的
      官方 tag slug（去 https://leetcode.com/problemset/ 篩選 tag，
      網址列的 tag=xxx 就是 slug）。沒填的分類會照樣列出已收錄清單，
      只是不會有建議。
"""
import sys
import os
import glob
import json
import urllib.request
import urllib.error

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

# 自訂 topic slug -> LeetCode 官方 tag slug（可以是多個，會合併查詢）
# 沒填的分類就只會列出已收錄清單，不會有建議。自己覺得哪個分類想要建議，
# 就在這裡加一行，例如 'math-digit-decomposition': ['math']。
TOPIC_TAG_MAP = {
    'array': ['array'],
    'string': ['string'],
    'hash-table': ['hash-table'],
    'two-pointers': ['two-pointers'],
    'sliding-window': ['sliding-window'],
    'stack': ['stack'],
    'binary-search': ['binary-search'],
    'linked-list': ['linked-list'],
    'tree': ['tree', 'binary-tree'],
    'dynamic-programming': ['dynamic-programming'],
    'greedy': ['greedy'],
    'backtracking': ['backtracking'],
    'sorting': ['sorting'],
    'bit-manipulation': ['bit-manipulation'],
    'math': ['math'],
    'design': ['design'],
    'trie': ['trie'],
    'union-find': ['union-find'],
    'topological-sort': ['topological-sort'],
    'priority-queue': ['heap-priority-queue'],
    'sql': ['database'],
}

GRAPHQL_URL = 'https://leetcode.com/graphql/'
QUERY = '''
query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
  problemsetQuestionList: questionList(
    categorySlug: $categorySlug
    limit: $limit
    skip: $skip
    filters: $filters
  ) {
    total: totalNum
    questions: data {
      difficulty
      title
      titleSlug
      questionFrontendId
      paidOnly: isPaidOnly
    }
  }
}
'''


def to_list(value):
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)


def load_collected(meta_dir):
    """回傳 {topic_slug: [{'number','title','difficulty','familiarity'}, ...]}"""
    by_topic = {}
    numbers_seen = set()
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        number = data.get('number')
        title = data.get('title', '')
        numbers_seen.add(number)
        seen_topics_this_problem = set()
        for sol in data.get('solutions', []):
            for topic in to_list(sol.get('topics')):
                if topic in seen_topics_this_problem:
                    continue
                seen_topics_this_problem.add(topic)
                by_topic.setdefault(topic, []).append({
                    'number': number,
                    'title': title,
                    'difficulty': sol.get('difficulty', ''),
                    'familiarity': sol.get('familiarity') or '未標記',
                })
    return by_topic, numbers_seen


def fetch_tag_questions(tag_slugs, limit=200):
    """查一個或多個 LeetCode 官方 tag，回傳題目清單（合併去重）。查詢失敗回傳 None。"""
    seen = {}
    for tag in tag_slugs:
        variables = {
            'categorySlug': '',
            'skip': 0,
            'limit': limit,
            'filters': {'tags': [tag]},
        }
        payload = json.dumps({
            'query': QUERY,
            'variables': variables,
            'operationName': 'problemsetQuestionList',
        }).encode('utf-8')

        req = urllib.request.Request(
            GRAPHQL_URL,
            data=payload,
            headers={
                'Content-Type': 'application/json',
                'Referer': 'https://leetcode.com/problemset/',
                'User-Agent': 'Mozilla/5.0',
            },
        )
        try:
            with urllib.request.urlopen(req, timeout=15) as resp:
                result = json.loads(resp.read().decode('utf-8'))
        except (urllib.error.URLError, urllib.error.HTTPError, TimeoutError) as e:
            print(f"    ⚠️ 查詢 LeetCode tag '{tag}' 失敗：{e}")
            return None

        questions = (
            result.get('data', {})
            .get('problemsetQuestionList', {})
            .get('questions', [])
        )
        for q in questions:
            fid = q.get('questionFrontendId')
            if fid is None:
                continue
            seen[int(fid)] = q
    return seen


DIFF_ORDER = {'Easy': 0, 'Medium': 1, 'Hard': 2}


def suggest_for_topic(topic, collected_numbers, limit):
    tags = TOPIC_TAG_MAP.get(topic)
    if not tags:
        return None  # 沒有對應到官方 tag，不查
    questions = fetch_tag_questions(tags)
    if questions is None:
        return []

    candidates = [
        q for num, q in questions.items()
        if num not in collected_numbers and not q.get('paidOnly')
    ]
    candidates.sort(key=lambda q: (DIFF_ORDER.get(q['difficulty'], 9), int(q['questionFrontendId'])))
    return candidates[:limit]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    meta_dir = args[0] if args else 'metadata'

    suggest_n = 5
    if '--suggest' in sys.argv:
        idx = sys.argv.index('--suggest')
        if idx + 1 < len(sys.argv):
            suggest_n = int(sys.argv[idx + 1])

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    by_topic, collected_numbers = load_collected(meta_dir)

    print(f"共 {len(collected_numbers)} 題、{len(by_topic)} 個分類\n")
    print('=' * 60)

    for topic in sorted(by_topic):
        rows = sorted(by_topic[topic], key=lambda r: r['number'])
        print(f"\n📂 {topic}（已收錄 {len(rows)} 題）")
        for r in rows:
            print(f"   {r['number']:>5}  {r['title']:<45} {r['difficulty']:<8} {r['familiarity']}")

        if suggest_n <= 0:
            continue

        if topic not in TOPIC_TAG_MAP:
            print(f"   （沒有對應到 LeetCode 官方 tag，略過建議 — 想要的話在 TOPIC_TAG_MAP 補上對應 slug）")
            continue

        print(f"   👉 建議練習（優先 Easy/Medium）：")
        suggestions = suggest_for_topic(topic, collected_numbers, suggest_n)
        if not suggestions:
            print(f"      （查不到建議，或這個 tag 底下都已經收錄了）")
            continue
        for q in suggestions:
            url = f"https://leetcode.com/problems/{q['titleSlug']}/"
            print(f"      {q['questionFrontendId']:>5}  {q['title']:<45} {q['difficulty']:<8} {url}")

    print('\n' + '=' * 60)


if __name__ == '__main__':
    main()
