#!/usr/bin/env python3
import sys
import os
import re
import json
import glob
from collections import OrderedDict

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml")
    sys.exit(1)

LANG_MAP = {'.cpp': 'cpp', '.sql': 'sql', '.py': 'python', '.java': 'java', '.js': 'javascript'}

def to_list(value):
    """把 None 或單一字串安全轉成清單，避免字串被逐字元拆解。"""
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)



GROUPS = [
    (r'^design$', '🎨 Design'),
    (r'^math', '🔢 Math'),
    (r'^bit-bitmask-subset-enumeration$', '📊 Bit Manipulation'),
    (r'^bit-manipulation', '📊 Bit Manipulation'),
    (r'^hamming-distance', '📊 Bit Manipulation'),
    (r'^string', '🔗 String'),
    (r'^array', '🍱 Array'),
    (r'^2d-array', '🍱 Array'),
    (r'^binary-search-tree$', '🌳 Tree'),
    (r'^binary-search', '🔍 Binary Search'),
    (r'^linked-list', '⛓️ Linked List'),
    (r'^fast-slow-pointers$', '👥 Pointers'),
    (r'^two-pointers', '👥 Pointers'),
    (r'^hash-table', '🔑 Hash Table'),
    (r'^stack$', '📚 Stack'),
    (r'^monotonic-stack$', '📚 Stack'),
    (r'^monotonic-queue$', '📚 Stack'),
    (r'^priority-queue$', '📚 Priority Queue'),
    (r'^quick-select$', '📚 Quick Select'),
    (r'^tree', '🌳 Tree'),
    (r'^trie$', '🌳 Tree'),
    (r'^graph-bfs$', '🕸️ Graph'),
    (r'^graph-dfs$', '🕸️ Graph'),
    (r'^union-find$', '🕸️ Graph'),
    (r'^topological-sort$', '🕸️ Graph'),
    (r'^graph-shortest-path$', '🕸️ Graph'),
    (r'^sorting', '📊 Sorting'),
    (r'^dynamic-programming', '🧩 Dynamic Programming'),
    (r'^knapsack-problem', '🧩 Dynamic Programming'),
    (r'^greedy$', '🧩 Greedy'),
    (r'^backtracking', '🔢 Backtracking'),
    (r'sliding-window$', '🔢 Sliding Window'),
    (r'^sql$', '🔢 SQL'),
]

def group_for(slug):
    for pattern, title in GROUPS:
        if re.search(pattern, slug):
            return title
    return '📄 Other'

def lang_for_file(filename):
    ext = os.path.splitext(filename)[1]
    return LANG_MAP.get(ext, 'text')

def load_metadata(meta_dir):
    problems = []
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        problems.append(data)
    return problems

def load_code(solution_dir, filename):
    if not filename:
        return None
    path = os.path.join(solution_dir, filename)
    if not os.path.exists(path):
        return None
    with open(path, encoding='utf-8', errors='replace') as f:
        return f.read()


def complexity_rank(time_str):
    """回傳一個數字，越小代表複雜度越低（越快）。無法辨識的排最後。"""
    if not time_str:
        return 999
    m = re.match(r'\s*O\(([^)]*)\)', time_str.strip())
    if not m:
        return 998
    t = m.group(1).replace(' ', '').upper()

    if t in ('1',):
        return 0

    if re.search(r'\d\^N|2\^N|K\^N|N!', t):
        return 100

    power_match = re.search(r'N[\^²³](\d*)', t)
    if power_match:
        exp_str = power_match.group(1)
        if exp_str:
            exp_val = int(exp_str)
        elif '²' in t:
            exp_val = 2
        elif '³' in t:
            exp_val = 3
        else:
            exp_val = 2
        return 20 * exp_val

    log_pos = t.find('LOG')
    if log_pos != -1:
        prefix = t[:log_pos]
        if re.search(r'[A-Z]', prefix):
            return 15
        return 1

    if 'SQRT' in t:
        return 5

    if re.search(r'[A-Z]', t):
        return 10

    return 3

def build_problem_page(problem, solution_dir):
    number = problem['number']
    title = problem['title']
    url = problem.get('url', '')
    solutions = sorted(problem['solutions'], key=lambda s: complexity_rank(s.get('time', '')))

    lines = [f"# {number}. {title}", '']
    if url:
        lines.append(f"[在 LeetCode 上查看]({url})")
        lines.append('')

    multi = len(solutions) > 1
    missing_files = []

    for sol in solutions:
        label_key = ' / '.join(to_list(sol.get('topics')))
        if multi:
            lines.append(f"## 解法：{label_key}")
            lines.append('')

        tags_str = ', '.join(to_list(sol.get('tags')))
        familiarity = sol.get('familiarity')
        familiarity_badge = ''
        if familiarity == '熟練':
            familiarity_badge = '　**熟悉度:** 🟢 熟練'
        elif familiarity == '注意':
            familiarity_badge = '　**熟悉度:** 🟡 注意'
        elif familiarity == '生疏':
            familiarity_badge = '　**熟悉度:** 🔴 生疏'

        best_badge = '　🏆 **最佳解**' if sol.get('is_best') else ''

        info = (f"**難度:** {sol.get('difficulty','')}　"
                f"**標籤:** {tags_str}　"
                f"**時間:** {sol.get('time','')}　"
                f"**空間:** {sol.get('space','')}{familiarity_badge}{best_badge}")
        lines.append(info)
        lines.append('')

        code = load_code(solution_dir, sol.get('file'))
        if code is not None:
            lang = lang_for_file(sol['file'])
            lines.append(f"```{lang}")
            lines.append(code.rstrip('\n'))
            lines.append("```")
            lines.append('')
        else:
            missing_files.append(sol.get('file'))

        note_body = sol.get('note')
        if note_body:
            lines.append(note_body)
            lines.append('')

        related = to_list(sol.get('related'))
        if related:
            related_links = ', '.join(
                f"[{r}](../problems/{int(r):04d}.md)" for r in related
            )
            lines.append(f"**相關題目:** {related_links}")
            lines.append('')

        if multi:
            lines.append('---')
            lines.append('')

    return '\n'.join(lines), missing_files

def build_topic_indexes(problems, topics_out_dir):
    topic_rows = OrderedDict()

    # 註：曾經有過「array-min-max 等子分類自動匯總進 array.md」的機制，
    # 後來因為會導致同一題同時出現在兩個分類頁（例如 1094 同時出現在
    # array 和 array-difference-array），跟「每題只在單一分類頁」的需求
    # 互相衝突，已經拿掉。現在每個解法只會出現在它 topics 欄位裡寫的
    # 那個（單一）分類頁，不會有自動匯總的行為。

    for problem in problems:
        for sol in problem['solutions']:
            for topic in to_list(sol.get('topics')):
                topic_rows.setdefault(topic, []).append({
                    'number': problem['number'],
                    'title': problem['title'],
                    'url': problem.get('url', ''),
                    'file': sol.get('file', ''),
                    'difficulty': sol.get('difficulty', ''),
                    'tags': to_list(sol.get('tags')),
                    'time': sol.get('time', ''),
                    'space': sol.get('space', ''),
                    'familiarity': sol.get('familiarity'),
                })

    os.makedirs(topics_out_dir, exist_ok=True)
    for fname in os.listdir(topics_out_dir):
        os.remove(os.path.join(topics_out_dir, fname))

    def render_table(sub_rows):
        lines = ["| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |",
                 "| --- | --- | --- | --- | --- | --- | --- |"]
        for r in sub_rows:
            tags_str = ', '.join(r['tags'])
            page_link = f"../problems/{r['number']:04d}.md"
            title_cell = f"[{r['title']}]({r['url']})" if r['url'] else r['title']
            file_cell = f"[C++]({page_link})" if r['file'] else ''
            lines.append(f"| {r['number']} | {title_cell} | "
                         f"{r['difficulty']} | {tags_str} | {file_cell} | {r['time']} | {r['space']} |")
        return lines

    for topic, rows in topic_rows.items():
        rows.sort(key=lambda r: r['number'])

        unfamiliar_rows = [r for r in rows if r['familiarity'] == '生疏']
        caution_rows = [r for r in rows if r['familiarity'] == '注意']
        familiar_rows = [r for r in rows if r['familiarity'] not in ('生疏', '注意')]

        lines = [f"# {topic}", '']

        lines.append(f"## 🔴 生疏（{len(unfamiliar_rows)}）")
        lines.append('')
        if unfamiliar_rows:
            lines.extend(render_table(unfamiliar_rows))
        else:
            lines.append('目前沒有標記為生疏的解法。')
        lines.append('')

        lines.append(f"## 🟡 注意（{len(caution_rows)}）")
        lines.append('')
        if caution_rows:
            lines.extend(render_table(caution_rows))
        else:
            lines.append('目前沒有標記為注意的解法。')
        lines.append('')

        lines.append(f"## 🟢 熟悉（{len(familiar_rows)}）")
        lines.append('')
        if familiar_rows:
            lines.extend(render_table(familiar_rows))
        else:
            lines.append('目前沒有標記為熟悉的解法。')

        with open(os.path.join(topics_out_dir, f"{topic}.md"), 'w', encoding='utf-8') as f:
            f.write('\n'.join(lines) + '\n')

    return topic_rows


def load_ac_cache(cache_path):
    """讀取 fetch_leetcode_ac.py 產生的 leetcode_ac_cache.json，抓不到就回傳 None（不影響其他功能）。"""
    if not os.path.exists(cache_path):
        return None
    try:
        with open(cache_path, 'r', encoding='utf-8') as f:
            return json.load(f)
    except Exception:
        return None


def build_review_page(problems, docs_dir, ac_cache_path='leetcode_ac_cache.json'):
    """列出所有標記為「生疏」的解法，並在最上方加上統計總覽，寫成 docs/review.md 複習清單"""
    rows = []
    for problem in problems:
        for sol in problem['solutions']:
            if sol.get('familiarity') == '生疏':
                rows.append({
                    'number': problem['number'],
                    'title': problem['title'],
                    'url': problem.get('url', ''),
                    'file': sol.get('file', ''),
                    'difficulty': sol.get('difficulty', ''),
                    'topics': ', '.join(to_list(sol.get('topics'))),
                })
    rows.sort(key=lambda r: r['number'])

    # 每一題的整體熟悉度：生疏 > 注意 > 熟練 > 未標記（優先度由左到右，只要任一解法符合就算該題）
    problem_status = {}
    topic_stats = OrderedDict()

    for problem in problems:
        sols = problem['solutions']
        statuses = {sol.get('familiarity') for sol in sols}
        if '生疏' in statuses:
            status = '生疏'
        elif '注意' in statuses:
            status = '注意'
        elif '熟練' in statuses:
            status = '熟練'
        else:
            status = '未標記'
        problem_status[problem['number']] = status

        problem_topics = set()
        for sol in sols:
            for topic in to_list(sol.get('topics')):
                problem_topics.add(topic)
        for topic in problem_topics:
            stat = topic_stats.setdefault(topic, {'生疏': 0, '注意': 0, '熟練': 0, '未標記': 0})
            stat[status] += 1

    total_problems = len(problems)
    total_shengshu = sum(1 for s in problem_status.values() if s == '生疏')
    total_zhuyi = sum(1 for s in problem_status.values() if s == '注意')
    total_shulian = sum(1 for s in problem_status.values() if s == '熟練')
    total_unmarked = total_problems - total_shengshu - total_zhuyi - total_shulian

    ac_info = load_ac_cache(ac_cache_path)

    lines = ['# 📝 複習清單（生疏）', '', '## 📊 總覽', '']

    if ac_info and ac_info.get('num_solved') is not None:
        fetched_at = ac_info.get('fetched_at', '')
        num_total = ac_info.get('num_total')
        total_str = f" / {num_total}" if num_total else ''
        lines.append(f"- **LeetCode 網站 AC 總數：** {ac_info['num_solved']}{total_str} 題"
                     f"（最後更新：{fetched_at}）")
    else:
        lines.append("- **LeetCode 網站 AC 總數：** 尚未取得，請先執行 `python3 tools/fetch_leetcode_ac.py`")

    lines.append(f"- **目前收錄總題目數：** {total_problems} 題　"
                 f"🔴 生疏：{total_shengshu} 題　🟡 注意：{total_zhuyi} 題　🟢 熟練：{total_shulian} 題　⚪ 未標記：{total_unmarked} 題")
    lines.append('')

    lines.append('### 各分類生疏 / 注意 / 熟練統計')
    lines.append('')
    lines.append('| 分類 | 🔴 生疏 | 🟡 注意 | 🟢 熟練 | ⚪ 未標記 | 總數 |')
    lines.append('| --- | --- | --- | --- | --- | --- |')
    for topic, stat in sorted(topic_stats.items()):
        topic_total = stat['生疏'] + stat['注意'] + stat['熟練'] + stat['未標記']
        lines.append(f"| [{topic}](topics/{topic}.md) | {stat['生疏']} | {stat['注意']} | {stat['熟練']} | {stat['未標記']} | {topic_total} |")
    lines.append('')
    lines.append('---')
    lines.append('')

    lines.append(f'目前共有 {len(rows)} 個解法標記為生疏，建議找時間重新練習。')
    lines.append('')
    lines.append('| # | 題目 | 難度 | 解法檔案 | 分類 |')
    lines.append('| --- | --- | --- | --- | --- |')
    for r in rows:
        page_link = f"problems/{r['number']:04d}.md"
        title_cell = f"[{r['title']}]({r['url']})" if r['url'] else r['title']
        file_cell = f"[C++]({page_link})" if r['file'] else ''
        lines.append(f"| {r['number']} | {title_cell} | {r['difficulty']} | {file_cell} | {r['topics']} |")

    with open(os.path.join(docs_dir, 'review.md'), 'w', encoding='utf-8') as f:
        f.write('\n'.join(lines) + '\n')

    return len(rows)


def main():
    if len(sys.argv) != 4:
        print("Usage: python3 generate_site.py <metadata_dir> <solution_dir> <docs_dir>")
        sys.exit(1)

    meta_dir, solution_dir, docs_dir = sys.argv[1:4]
    problems_out_dir = os.path.join(docs_dir, 'problems')
    topics_out_dir = os.path.join(docs_dir, 'topics')
    os.makedirs(problems_out_dir, exist_ok=True)

    problems = load_metadata(meta_dir)
    print(f"讀取到 {len(problems)} 題 metadata")

    all_missing = []
    for problem in problems:
        content, missing = build_problem_page(problem, solution_dir)
        number = problem['number']
        out_path = os.path.join(problems_out_dir, f"{number:04d}.md")
        with open(out_path, 'w', encoding='utf-8') as f:
            f.write(content)
        if missing:
            all_missing.append((number, missing))

    print(f"寫入 {len(problems)} 個 docs/problems/*.md")
    if all_missing:
        print(f"\n⚠️ 有 {len(all_missing)} 題找不到對應的 .cpp 檔案：")
        for number, files in all_missing[:20]:
            print(f"  {number:04d}: 缺少 {files}")

    topic_rows = build_topic_indexes(problems, topics_out_dir)
    print(f"\n寫入 {len(topic_rows)} 個 docs/topics/*.md")

    review_count = build_review_page(problems, docs_dir)
    print(f"複習清單（生疏）: {review_count} 筆 -> docs/review.md")

    # 固定分類顯示順序（不再依賴 metadata 掃描順序，避免每次改資料 nav 順序就跟著亂跳）。
    # 沒列在這裡的分類（例如未來新增的 GROUPS 規則、或掉進 📄 Other 的）會被排在最後面。
    CATEGORY_ORDER = [
        '🔢 Math',
        '🔗 String',
        '📊 Bit Manipulation',
        '🍱 Array',
        '🔍 Binary Search',
        '🔢 Sliding Window',
        '🔑 Hash Table',
        '👥 Pointers',
        '⛓️ Linked List',
        '📚 Stack',
        '🔢 Backtracking',
        '🧩 Dynamic Programming',
        '🧩 Greedy',
        '🌳 Tree',
        '🕸️ Graph',
        '🎨 Design',
        '📊 Sorting',
        '📚 Priority Queue',
        '🔢 SQL',
        '📚 Quick Select',
    ]

    nav_entries = OrderedDict()
    for topic in topic_rows:
        group_title = group_for(topic)
        nav_entries.setdefault(group_title, []).append(topic)

    def category_sort_key(group_title):
        if group_title in CATEGORY_ORDER:
            return (0, CATEGORY_ORDER.index(group_title))
        return (1, group_title)  # 沒列出的分類排最後，彼此間照字母排序

    sorted_groups = sorted(nav_entries.keys(), key=category_sort_key)

    print("\n\n----- 貼到 mkdocs.yml 的 nav: 區塊 -----\n")
    print("nav:")
    print("  - 首頁: index.md")
    print("  - 📝 複習清單: review.md")
    for group_title in sorted_groups:
        print(f"  - {group_title}:")
        for topic in nav_entries[group_title]:
            print(f"      - {topic}: topics/{topic}.md")

if __name__ == '__main__':
    main()
