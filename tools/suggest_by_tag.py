#!/usr/bin/env python3
"""
suggest_by_tag.py

不管你自己怎麼分類，直接照 LeetCode 官方 tag 建議「還沒收錄過」的題目，
優先 Easy，再來 Medium（盡量不建議 Hard）。分類是你自己的事，這支只負責：
    1. 讀 metadata/*.yml，抓出已經收錄的題號
    2. 對每個 LeetCode 官方 tag，查該 tag 底下的題目
    3. 扣掉已收錄的、扣掉付費題，剩下的照 Easy -> Medium -> Hard 排序取前 N 題

用法：
    python3 suggest_by_tag.py [metadata_dir] [--suggest N] [--tags tag1,tag2,...]

    metadata_dir   預設 'metadata'
    --suggest N    每個 tag 最多建議幾題（預設 5）
    --tags         只查指定的 tag（用逗號分隔的官方 slug）。
                   不指定的話，預設查下面 DEFAULT_TAGS 這份常見演算法 tag 清單。
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

# LeetCode 官方常見演算法 tag slug（不含 company/list 這種標籤）。
# 想只看特定 tag 就用 --tags 指定，不用改這裡。
DEFAULT_TAGS = [
    'array', 'string', 'hash-table', 'two-pointers', 'sliding-window',
    'stack', 'queue', 'monotonic-stack', 'binary-search', 'linked-list',
    'tree', 'binary-tree', 'binary-search-tree', 'depth-first-search',
    'breadth-first-search', 'graph', 'union-find', 'topological-sort',
    'dynamic-programming', 'greedy', 'backtracking', 'recursion',
    'divide-and-conquer', 'sorting', 'bit-manipulation', 'math',
    'design', 'trie', 'heap-priority-queue', 'matrix', 'simulation',
    'prefix-sum', 'counting', 'database',
]

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

DIFF_ORDER = {'Easy': 0, 'Medium': 1, 'Hard': 2}


def to_list(value):
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)


def load_collected_numbers(meta_dir):
    numbers = set()
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if data and data.get('number') is not None:
            numbers.add(int(data['number']))
    return numbers


def fetch_tag_questions(tag, limit=200):
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
    with urllib.request.urlopen(req, timeout=15) as resp:
        result = json.loads(resp.read().decode('utf-8'))

    return (
        result.get('data', {})
        .get('problemsetQuestionList', {})
        .get('questions', [])
    )


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    meta_dir = args[0] if args else 'metadata'

    suggest_n = 5
    if '--suggest' in sys.argv:
        idx = sys.argv.index('--suggest')
        if idx + 1 < len(sys.argv):
            suggest_n = int(sys.argv[idx + 1])

    tags = DEFAULT_TAGS
    if '--tags' in sys.argv:
        idx = sys.argv.index('--tags')
        if idx + 1 < len(sys.argv):
            tags = [t.strip() for t in sys.argv[idx + 1].split(',') if t.strip()]

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    collected = load_collected_numbers(meta_dir)
    print(f"目前已收錄 {len(collected)} 題\n")
    print('=' * 60)

    for tag in tags:
        print(f"\n🏷️  {tag}")
        try:
            questions = fetch_tag_questions(tag)
        except (urllib.error.URLError, urllib.error.HTTPError, TimeoutError) as e:
            print(f"   ⚠️ 查詢失敗：{e}")
            continue

        candidates = [
            q for q in questions
            if q.get('questionFrontendId') is not None
            and int(q['questionFrontendId']) not in collected
            and not q.get('paidOnly')
        ]
        candidates.sort(key=lambda q: (DIFF_ORDER.get(q['difficulty'], 9), int(q['questionFrontendId'])))

        if not candidates:
            print(f"   （這個 tag 底下沒有還沒收錄的免費題目了）")
            continue

        for q in candidates[:suggest_n]:
            url = f"https://leetcode.com/problems/{q['titleSlug']}/"
            print(f"   {q['questionFrontendId']:>5}  {q['title']:<45} {q['difficulty']:<8} {url}")

    print('\n' + '=' * 60)


if __name__ == '__main__':
    main()
