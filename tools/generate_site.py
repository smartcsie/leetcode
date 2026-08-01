#!/usr/bin/env python3
import sys
import os
import re
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
    (r'^interval$', '🍱 Array'),
    (r'^prefix-sum$', '🍱 Array'),
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
    (r'^dfs-bfs$', '🌳 Tree'),
    (r'^sorting', '📊 Sorting'),
    (r'^dynamic-programming', '🧩 Dynamic Programming'),
    (r'^knapsack-problem', '🧩 Dynamic Programming'),
    (r'^greedy$', '🧩 Greedy'),
    (r'^backtracking', '🔢 Backtracking'),
    (r'^negative-marking$', '🔢 Backtracking'),
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
                })

    os.makedirs(topics_out_dir, exist_ok=True)
    for fname in os.listdir(topics_out_dir):
        os.remove(os.path.join(topics_out_dir, fname))

    for topic, rows in topic_rows.items():
        rows.sort(key=lambda r: r['number'])
        lines = [f"# {topic}", '',
                 "| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |",
                 "| --- | --- | --- | --- | --- | --- | --- |"]
        for r in rows:
            tags_str = ', '.join(r['tags'])
            page_link = f"../problems/{r['number']:04d}.md"
            title_cell = f"[{r['title']}]({r['url']})" if r['url'] else r['title']
            file_cell = f"[C++]({page_link})" if r['file'] else ''
            lines.append(f"| {r['number']} | {title_cell} | "
                         f"{r['difficulty']} | {tags_str} | {file_cell} | {r['time']} | {r['space']} |")
        with open(os.path.join(topics_out_dir, f"{topic}.md"), 'w', encoding='utf-8') as f:
            f.write('\n'.join(lines) + '\n')

    return topic_rows


def build_review_page(problems, docs_dir):
    """列出所有標記為「生疏」的解法，寫成 docs/review.md 複習清單"""
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

    lines = ['# 📝 複習清單（生疏）', '',
             f'目前共有 {len(rows)} 個解法標記為生疏，建議找時間重新練習。', '',
             '| # | 題目 | 難度 | 解法檔案 | 分類 |',
             '| --- | --- | --- | --- | --- |']
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

    nav_entries = OrderedDict()
    for topic in topic_rows:
        group_title = group_for(topic)
        nav_entries.setdefault(group_title, []).append(topic)

    print("\n\n----- 貼到 mkdocs.yml 的 nav: 區塊 -----\n")
    print("nav:")
    print("  - 首頁: index.md")
    print("  - 📝 複習清單: review.md")
    for group_title, topics in nav_entries.items():
        print(f"  - {group_title}:")
        for topic in topics:
            print(f"      - {topic}: topics/{topic}.md")

if __name__ == '__main__':
    main()
