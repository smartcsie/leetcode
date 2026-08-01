#!/usr/bin/env python3
"""
逐行小片段比對，而不是整段大區塊比對，降低終端機貼上造成的隱藏字元差異風險。
每一行都會分別回報成功或失敗，方便精準定位問題。
"""
import sys

PATCHES = [
    # (old, new, label)
    (
        "                    'title': problem['title'],\n                    'difficulty': sol.get('difficulty', ''),\n                    'tags': to_list(sol.get('tags')),",
        "                    'title': problem['title'],\n                    'url': problem.get('url', ''),\n                    'file': sol.get('file', ''),\n                    'difficulty': sol.get('difficulty', ''),\n                    'tags': to_list(sol.get('tags')),",
        'build_topic_indexes: dict 加入 url/file',
    ),
    (
        '"| # | 題目 | 難度 | 標籤 | 時間 | 空間 |",\n                 "| --- | --- | --- | --- | --- |"]',
        '"| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |",\n                 "| --- | --- | --- | --- | --- | --- |"]',
        'build_topic_indexes: 表頭改欄位',
    ),
    (
        "            tags_str = ', '.join(r['tags'])\n            link = f\"../problems/{r['number']:04d}.md\"\n            lines.append(f\"| {r['number']} | [{r['title']}]({link}) | \"\n                         f\"{r['difficulty']} | {tags_str} | {r['time']} | {r['space']} |\")",
        "            tags_str = ', '.join(r['tags'])\n            page_link = f\"../problems/{r['number']:04d}.md\"\n            title_cell = f\"[{r['title']}]({r['url']})\" if r['url'] else r['title']\n            file_cell = f\"[C++]({page_link})\" if r['file'] else ''\n            lines.append(f\"| {r['number']} | {title_cell} | \"\n                         f\"{r['difficulty']} | {tags_str} | {file_cell} | {r['time']} | {r['space']} |\")",
        'build_topic_indexes: row 內容改連結',
    ),
    (
        "                    'title': problem['title'],\n                    'file': sol.get('file', ''),\n                    'difficulty': sol.get('difficulty', ''),\n                    'topics': ', '.join(to_list(sol.get('topics'))),",
        "                    'title': problem['title'],\n                    'url': problem.get('url', ''),\n                    'file': sol.get('file', ''),\n                    'difficulty': sol.get('difficulty', ''),\n                    'topics': ', '.join(to_list(sol.get('topics'))),",
        'build_review_page: dict 加入 url',
    ),
    (
        "    for r in rows:\n        link = f\"problems/{r['number']:04d}.md\"\n        lines.append(f\"| {r['number']} | [{r['title']}]({link}) | {r['difficulty']} | {r['file']} | {r['topics']} |\")",
        "    for r in rows:\n        page_link = f\"problems/{r['number']:04d}.md\"\n        title_cell = f\"[{r['title']}]({r['url']})\" if r['url'] else r['title']\n        file_cell = f\"[C++]({page_link})\" if r['file'] else ''\n        lines.append(f\"| {r['number']} | {title_cell} | {r['difficulty']} | {file_cell} | {r['topics']} |\")",
        'build_review_page: row 內容改連結',
    ),
]

def main():
    path = sys.argv[1] if len(sys.argv) > 1 else 'tools/generate_site.py'
    with open(path, 'r', encoding='utf-8') as f:
        content = f.read()

    ok_all = True
    for old, new, label in PATCHES:
        if old in content:
            content = content.replace(old, new, 1)
            print(f"✓ {label}")
        else:
            print(f"❌ {label} —— 找不到這段，需要進一步比對")
            ok_all = False

    with open(path, 'w', encoding='utf-8') as f:
        f.write(content)

    print("\n✅ 全部套用完成" if ok_all else "\n⚠️ 有部分沒套用成功，見上方 ❌")

if __name__ == '__main__':
    main()
