#!/usr/bin/env python3
"""
list_topic_review_order.py

給定一個 topic slug，列出這個分類底下所有題目，依照複習優先順序排好：
    生疏 > 易忘 > 再練習 > 練習過 > 熟練 > (未標記)
同一個熟悉度等級內，按題號排序。

用法：
    python3 list_topic_review_order.py <topic_slug> [metadata_dir]

範例：
    python3 list_topic_review_order.py dp-knapsack
    python3 list_topic_review_order.py binary-search-find-left-bound metadata
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

# 數字越小，複習優先權越高
PRIORITY = {
    '生疏': 0,
    '易忘': 1,
    '再練習': 2,
    '練習過': 3,
    '熟練': 4,
}


def to_list(value):
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)


def main():
    if len(sys.argv) < 2:
        print("用法: python3 list_topic_review_order.py <topic_slug> [metadata_dir]")
        sys.exit(1)

    topic_slug = sys.argv[1]
    meta_dir = sys.argv[2] if len(sys.argv) > 2 else 'metadata'

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    rows = []
    seen_numbers = set()

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        try:
            number = int(data.get('number'))
        except (TypeError, ValueError):
            continue

        title = data.get('title', '')
        for sol in data.get('solutions', []) or []:
            topics = to_list(sol.get('topics'))
            if topic_slug not in topics:
                continue
            if number in seen_numbers:
                continue  # 同一題有多個解法變體，只列一次
            seen_numbers.add(number)
            familiarity = sol.get('familiarity') or '未標記'
            priority = PRIORITY.get(familiarity, 5)
            rows.append((priority, number, title, familiarity))
            break  # 找到這個 topic 的其中一個解法就夠了，不用再檢查其他變體

    if not rows:
        print(f"沒有找到任何屬於「{topic_slug}」的題目。")
        return

    rows.sort(key=lambda r: (r[0], r[1]))

    print(f"=== {topic_slug}（{len(rows)} 題，依複習優先順序排列）===\n")
    current_priority = None
    for priority, number, title, familiarity in rows:
        if priority != current_priority:
            current_priority = priority
            print(f"--- {familiarity} ---")
        print(f"   {number:>5}  {title}")


if __name__ == '__main__':
    main()
