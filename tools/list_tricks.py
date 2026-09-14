#!/usr/bin/env python3
"""
list_tricks.py
列出所有 metadata yml 檔案中已填寫的 tricks。
用法：python3 tools/list_tricks.py
"""

import os
import yaml
from collections import defaultdict

BASE = "/home/laurence/leetcode-docs/repo/metadata"

def main():
    trick_map = defaultdict(list)  # trick -> [(number, title, file)]
    empty_count = 0
    filled_count = 0

    for filename in sorted(os.listdir(BASE)):
        if not filename.endswith(".yml"):
            continue
        filepath = os.path.join(BASE, filename)
        with open(filepath, "r", encoding="utf-8") as f:
            data = yaml.safe_load(f)

        number = data.get("number", "")
        title = data.get("title", "")
        solutions = data.get("solutions", [])

        for sol in solutions:
            tricks = sol.get("tricks")
            sol_file = sol.get("file", "")
            if not tricks:
                empty_count += 1
                continue
            filled_count += 1
            for trick in tricks:
                trick_map[trick].append((number, title, sol_file))

    # 按 trick 名稱排序輸出
    print(f"\n{'='*60}")
    print(f"已填寫 tricks：{filled_count} 個解法")
    print(f"尚未填寫：{empty_count} 個解法")
    print(f"{'='*60}\n")

    print(f"共 {len(trick_map)} 種 trick：\n")
    for trick in sorted(trick_map.keys()):
        problems = trick_map[trick]
        print(f"  [{trick}]  ({len(problems)} 題)")
        for number, title, sol_file in problems:
            print(f"    {number}. {title}  ({sol_file})")
        print()

if __name__ == "__main__":
    main()
