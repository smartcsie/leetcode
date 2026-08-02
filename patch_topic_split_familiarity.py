#!/usr/bin/env python3
"""
把 docs/topics/*.md（分類頁）從單一表格，
改成上下兩段：上面「🔴 生疏」、下面「🟢 熟悉」。

用法：
    python3 patch_topic_split_familiarity.py generate_site.py
（不指定路徑則預設抓同目錄下的 generate_site.py）

跑完後照舊：
    python3 tools/generate_site.py metadata solution docs
就會產生分成兩段的分類頁。
"""
import sys

OLD_FUNC = '''def build_topic_indexes(problems, topics_out_dir):
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
            f.write('\\n'.join(lines) + '\\n')

    return topic_rows'''

NEW_FUNC = '''def build_topic_indexes(problems, topics_out_dir):
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
                    'familiarity': sol.get('familiarity', ''),
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
        familiar_rows = [r for r in rows if r['familiarity'] != '生疏']

        lines = [f"# {topic}", '']

        lines.append(f"## 🔴 生疏（{len(unfamiliar_rows)}）")
        lines.append('')
        if unfamiliar_rows:
            lines.extend(render_table(unfamiliar_rows))
        else:
            lines.append('目前沒有標記為生疏的解法。')
        lines.append('')

        lines.append(f"## 🟢 熟悉（{len(familiar_rows)}）")
        lines.append('')
        if familiar_rows:
            lines.extend(render_table(familiar_rows))
        else:
            lines.append('目前沒有標記為熟悉的解法。')

        with open(os.path.join(topics_out_dir, f"{topic}.md"), 'w', encoding='utf-8') as f:
            f.write('\\n'.join(lines) + '\\n')

    return topic_rows'''


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else 'generate_site.py'
    with open(path, 'r', encoding='utf-8') as f:
        content = f.read()

    if NEW_FUNC in content:
        print("（build_topic_indexes 看起來已經套用過此 patch，跳過）")
        return

    if OLD_FUNC not in content:
        print("❌ 找不到 build_topic_indexes 的原始內容，可能已被手動修改過。")
        print("   請手動比對 generate_site.py 裡的 build_topic_indexes() 函式，")
        print("   或把檔案貼給我，我幫你重新產生 patch。")
        sys.exit(1)

    content = content.replace(OLD_FUNC, NEW_FUNC, 1)

    with open(path, 'w', encoding='utf-8') as f:
        f.write(content)

    print("✅ 已套用完成：分類頁現在會分成「🔴 生疏」與「🟢 熟悉」兩段。")
    print("   接著執行：python3 tools/generate_site.py metadata solution docs")


if __name__ == '__main__':
    main()
