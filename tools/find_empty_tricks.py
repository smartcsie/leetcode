#!/usr/bin/env python3
"""
find_empty_tricks.py
找出指定熟悉度的題目中，tricks 欄位為空的解法。
用法：python3 tools/find_empty_tricks.py
"""

import os
import yaml

BASE = "/home/laurence/leetcode-docs/repo/metadata"

# 要檢查的熟悉度，可自行調整
TARGET_FAMILIARITY = {"熟練", "練習過", "易忘"}

def main():
    found = {f: [] for f in TARGET_FAMILIARITY}

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
            familiarity = sol.get("familiarity", "")
            tricks = sol.get("tricks")
            sol_file = sol.get("file", "")

            if familiarity in TARGET_FAMILIARITY and not tricks:
                found[familiarity].append((number, title, sol_file))

    total = sum(len(v) for v in found.values())
    print(f"\n tricks 為空：{total} 個\n")
    for fam in ["熟練", "練習過", "易忘"]:
        problems = found[fam]
        if not problems:
            continue
        print(f"【{fam}】{len(problems)} 個")
        for number, title, sol_file in problems:
            print(f"  [{number}] {title}  ({sol_file})")
        print()

if __name__ == "__main__":
    main()
