#!/usr/bin/env python3
"""
find_multi_topic_tags.py — 掃描全部 metadata/*.yml，找出「一個解法同時掛了
超過一個 topic」的情況（例如 topics: [array, hash-table-set]）。

這種解法會同時出現在兩個（或更多）不同的 topics/*.md 分類頁上。
如果你希望「每個題目只出現在單一分類頁」，這支腳本會列出所有需要你
去挑一個最終分類、拿掉其餘 topic 的候選清單。

⚠️ 例外說明：array-min-max、array-negative-marking 這類 array 開頭的子分類，
即使 topics 只寫一個（例如只寫 array-min-max，沒有額外寫 array），也依然會
「自動」同時出現在子分類頁 + array.md 兩個頁面上——這是 generate_site.py 裡
AGGREGATE_PARENT_TOPICS 這個功能刻意設計的行為（之前你要求 array 大分類頁
要能看到子分類的題目），不算是這支腳本要抓的「重複掛標籤」問題，這支腳本
只會抓「topics 欄位本身就寫了兩個以上不同 topic」的情況。

用法（在 repo 根目錄執行）：
    python3 tools/find_multi_topic_tags.py
"""
import glob
import os
import sys

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

META_DIR = "metadata"


def to_list(v):
    if v is None:
        return []
    if isinstance(v, str):
        return [v]
    return list(v)


def main():
    found = []
    for fpath in sorted(glob.glob(os.path.join(META_DIR, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        number = data.get('number')
        title = data.get('title', '')
        for sol in data.get('solutions', []) or []:
            topics = to_list(sol.get('topics'))
            if len(topics) > 1:
                found.append((number, title, sol.get('file', ''), topics))

    print(f"=== 同一解法掛了超過一個 topic 的情況（{len(found)} 筆）===\n")
    for number, title, file, topics in found:
        print(f"  {number:04d}  {title}  ({file})")
        print(f"        目前 topics: {', '.join(topics)}")

    print()
    print(f"共 {len(found)} 筆解法需要決定只保留哪一個 topic。")
    print("到 solution-generator.html 打開對應題目，topics 只勾選一個最貼切的分類即可。")


if __name__ == '__main__':
    main()
