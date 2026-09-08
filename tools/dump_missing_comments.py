#!/usr/bin/env python3
"""
dump_missing_comments.py
把缺少開頭 /** 註解的 .cpp 檔案內容輸出，方便複製給 Claude 補註解。
用法：python3 dump_missing_comments.py
"""

import os

BASE = "/home/laurence/leetcode-docs/repo/solution"

MISSING = [
    "Solution_0026_1.cpp",
    "Solution_0049_1.cpp",
    "Solution_0053_1.cpp",
    "Solution_0144_2.cpp",
    "Solution_0151_1.cpp",
    "Solution_0189.cpp",
    "Solution_0191_1.cpp",
    "Solution_0198_1.cpp",
    "Solution_0213_1.cpp",
    "Solution_0217_1.cpp",
    "Solution_0217_2.cpp",
    "Solution_0217_3.cpp",
    "Solution_0235_1.cpp",
    "Solution_0283_1.cpp",
    "Solution_0287_1.cpp",
    "Solution_0342_1.cpp",
    "Solution_0342_2.cpp",
    "Solution_0404_1.cpp",
    "Solution_0461_1.cpp",
    "Solution_0509_1.cpp",
    "Solution_0557_1.cpp",
    "Solution_0693_1.cpp",
    "Solution_0930_1.cpp",
    "Solution_0930_2.cpp",
    "Solution_0938_1.cpp",
    "Solution_0961_1.cpp",
    "Solution_1137_1.cpp",
    "Solution_1512_1.cpp",
    "Solution_1608_1.cpp",
    "Solution_1721_1.cpp",
    "Solution_1790_1.cpp",
    "Solution_2006.cpp",
    "Solution_2485_1.cpp",
    "Solution_2605_1.cpp",
    "Solution_2605_2.cpp",
    "Solution_2605_3.cpp",
    "Solution_2785_1.cpp",
    "Solution_2864_1.cpp",
    "Solution_3513_1.cpp",
    "Solution_3513_2.cpp",
]

if __name__ == "__main__":
    for filename in MISSING:
        filepath = os.path.join(BASE, filename)
        if not os.path.exists(filepath):
            print(f"// [NOT FOUND] {filename}\n")
            continue
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        print(f"// ===== {filename} =====")
        print(content)
        print()
