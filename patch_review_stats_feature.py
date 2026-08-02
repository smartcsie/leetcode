#!/usr/bin/env python3
"""
patch_review_stats_feature.py — 套用到 generate_site.py，
在複習清單頁面（docs/review.md）最上方加入：
  1. LeetCode 網站 AC 總數（讀 leetcode_ac_cache.json，由 fetch_leetcode_ac.py 產生）
  2. 目前收錄總題目數，以及生疏 / 熟練 / 未標記各幾題
  3. 各分類生疏 / 熟練統計表格

用法：
    python3 patch_review_stats_feature.py generate_site.py
"""
import sys

OLD_IMPORT_BLOCK = '''import sys
import os
import re
import glob
from collections import OrderedDict'''

NEW_IMPORT_BLOCK = '''import sys
import os
import re
import json
import glob
from collections import OrderedDict'''


OLD_BUILD_REVIEW_PAGE_FUNC = '''def build_review_page(problems, docs_dir):
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
        f.write('\\n'.join(lines) + '\\n')

    return len(rows)'''


NEW_BUILD_REVIEW_PAGE_FUNC = '''def load_ac_cache(cache_path):
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

    # 每一題的整體熟悉度：只要有任一解法是生疏就算生疏，否則只要有任一解法是熟練就算熟練，都沒標記則算未標記
    problem_status = {}
    topic_stats = OrderedDict()

    for problem in problems:
        sols = problem['solutions']
        statuses = {sol.get('familiarity') for sol in sols}
        if '生疏' in statuses:
            status = '生疏'
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
            stat = topic_stats.setdefault(topic, {'生疏': 0, '熟練': 0, '未標記': 0})
            stat[status] += 1

    total_problems = len(problems)
    total_shengshu = sum(1 for s in problem_status.values() if s == '生疏')
    total_shulian = sum(1 for s in problem_status.values() if s == '熟練')
    total_unmarked = total_problems - total_shengshu - total_shulian

    ac_info = load_ac_cache(ac_cache_path)

    lines = ['# 📝 複習清單（生疏）', '', '## 📊 總覽', '']

    if ac_info and ac_info.get('num_solved') is not None:
        fetched_at = ac_info.get('fetched_at', '')
        num_total = ac_info.get('num_total')
        total_str = f" / {num_total}" if num_total else ''
        lines.append(f"- **LeetCode 網站 AC 總數：** {ac_info['num_solved']}{total_str} 題"
                     f"（最後更新：{fetched_at}，執行 `python3 tools/fetch_leetcode_ac.py` 可更新）")
    else:
        lines.append("- **LeetCode 網站 AC 總數：** 尚未取得，請先執行 `python3 tools/fetch_leetcode_ac.py`")

    lines.append(f"- **目前收錄總題目數：** {total_problems} 題　"
                 f"🔴 生疏：{total_shengshu} 題　🟢 熟練：{total_shulian} 題　⚪ 未標記：{total_unmarked} 題")
    lines.append('')

    lines.append('### 各分類生疏 / 熟練統計')
    lines.append('')
    lines.append('| 分類 | 🔴 生疏 | 🟢 熟練 | ⚪ 未標記 | 總數 |')
    lines.append('| --- | --- | --- | --- | --- |')
    for topic, stat in sorted(topic_stats.items()):
        topic_total = stat['生疏'] + stat['熟練'] + stat['未標記']
        lines.append(f"| [{topic}](topics/{topic}.md) | {stat['生疏']} | {stat['熟練']} | {stat['未標記']} | {topic_total} |")
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
        f.write('\\n'.join(lines) + '\\n')

    return len(rows)'''


def apply_patch(content, old, new, label):
    if old not in content:
        print(f"❌ 找不到錨點，無法套用「{label}」，請手動處理")
        return content, False
    if new in content:
        print(f"（「{label}」看起來已經套用過，跳過）")
        return content, True
    return content.replace(old, new, 1), True


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else 'generate_site.py'
    with open(path, 'r', encoding='utf-8') as f:
        content = f.read()

    ok_all = True

    content, ok1 = apply_patch(content, OLD_IMPORT_BLOCK, NEW_IMPORT_BLOCK, '加入 import json')
    content, ok2 = apply_patch(content, OLD_BUILD_REVIEW_PAGE_FUNC, NEW_BUILD_REVIEW_PAGE_FUNC, '複習清單總覽統計')

    ok_all = ok1 and ok2

    with open(path, 'w', encoding='utf-8') as f:
        f.write(content)

    if ok_all:
        print("\n✅ 全部套用完成，可以執行 python3 generate_site.py metadata solution docs 測試")
    else:
        print("\n⚠️ 有部分無法自動套用，請照上方訊息手動處理")


if __name__ == '__main__':
    main()
