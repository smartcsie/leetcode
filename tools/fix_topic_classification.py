#!/usr/bin/env python3
"""
fix_topic_classification.py
修正核心邏輯放錯分類的 metadata yml 檔案。
用法：python3 tools/fix_topic_classification.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/metadata"

# (yml 檔案, 舊 topic, 新 topic, 舊 tag, 新 tag)
FIXES = [
    ("0085.yml",  "dp-grid-path",           "monotonic-stack",          "Dp Grid Path",             "Monotonic Stack"),
    ("0220.yml",  "fixed-size-sliding-window", "binary-search-build-in", "Fixed Size Sliding Window", "Binary Search Build In"),
    ("0257.yml",  "tree-dfs-path",           "tree-dfs-backtracking",    "Tree Dfs Path",            "Tree Dfs Backtracking"),
    ("0437.yml",  "tree-dfs-path",           "tree-dfs-global",          "Tree Dfs Path",            "Tree Dfs Global"),
    ("1029.yml",  "greedy-priority-queue",   "greedy-sorting-decision",  "Greedy Priority Queue",    "Greedy Sorting Decision"),
    ("1930.yml",  "greedy",                  "binary-search-build-in",   "Greedy",                   "Binary Search Build In"),
    ("1984.yml",  "fixed-size-sliding-window", "sorting",                "Fixed Size Sliding Window", "Sorting"),
    ("2094.yml",  "hash-table-uniqueness",   "backtracking-combination", "Hash Table Uniqueness",    "Backtracking Combination"),
    ("2974.yml",  "array-linear-scan",       "sorting",                  "Array Linear Scan",        "Sorting"),
]

def fix_file(filepath, old_topic, new_topic, old_tag, new_tag):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    original = content

    # 替換 topics
    content = content.replace(f"  - {old_topic}", f"  - {new_topic}")

    # 替換 tags
    content = content.replace(f"  - {old_tag}", f"  - {new_tag}")

    if content == original:
        return "skip"

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    return "ok"


if __name__ == "__main__":
    ok = skip = not_found = 0

    for filename, old_topic, new_topic, old_tag, new_tag in FIXES:
        filepath = os.path.join(BASE, filename)

        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}")
            not_found += 1
            continue

        result = fix_file(filepath, old_topic, new_topic, old_tag, new_tag)

        if result == "ok":
            print(f"[OK]   {filename}  {old_topic} → {new_topic}")
            ok += 1
        else:
            print(f"[SKIP] {filename}  (找不到 {old_topic})")
            skip += 1

    print(f"\n完成！OK:{ok}  SKIP:{skip}  NOT_FOUND:{not_found}")
