#!/usr/bin/env python3
"""
dump_empty_yml_complexity.py
把 yml 複雜度為空的 cpp 檔案的複雜度行輸出，方便確認正確值。
用法：python3 tools/dump_empty_yml_complexity.py
"""

import os

BASE_SOL = "/home/laurence/leetcode-docs/repo/solution"

FILES = [
    "Solution_0144_2.cpp",
    "Solution_0283_1.cpp",
    "Solution_0397.cpp",
    "Solution_0557_1.cpp",
    "Solution_0746_1.cpp",
    "Solution_0938_1.cpp",
    "Solution_1351_1.cpp",
    "Solution_1461.cpp",
    "Solution_1790_1.cpp",
    "Solution_2023.cpp",
]

if __name__ == "__main__":
    for filename in FILES:
        filepath = os.path.join(BASE_SOL, filename)
        print(f"// ===== {filename} =====")
        if not os.path.exists(filepath):
            print("// [NOT FOUND]\n")
            continue
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            lines = f.readlines()
        for line in lines[:20]:
            print(line, end="")
        print()
