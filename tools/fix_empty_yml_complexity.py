#!/usr/bin/env python3
"""
fix_empty_yml_complexity.py
修正 metadata yml 檔案中 time/space 欄位為空的題目。
用法：python3 tools/fix_empty_yml_complexity.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/metadata"

# yml檔案 -> [(solution_file, time, space)]
FIXES = {
    "0144.yml": [
        ("Solution_0144_2.cpp", "O(N)", "O(H)"),
    ],
    "0283.yml": [
        ("Solution_0283_1.cpp", "O(N)", "O(1)"),
    ],
    "0397.yml": [
        ("Solution_0397.cpp", None, "O(1)"),  # time 已有值，只補 space
    ],
    "0557.yml": [
        ("Solution_0557_1.cpp", "O(N)", "O(1)"),
    ],
    "0746.yml": [
        ("Solution_0746_1.cpp", "O(N)", "O(1)"),
    ],
    "0938.yml": [
        ("Solution_0938_1.cpp", "O(N)", "O(H)"),
    ],
    "1351.yml": [
        ("Solution_1351_1.cpp", "O(R*logC)", "O(1)"),
    ],
    "1461.yml": [
        ("Solution_1461.cpp", None, "O(2^K)"),  # time 已有值，只補 space
    ],
    "1790.yml": [
        ("Solution_1790_1.cpp", "O(N)", "O(1)"),
    ],
    "2023.yml": [
        ("Solution_2023.cpp", None, "O(N)"),  # time 已有值，只補 space
    ],
}


def fix_yml(filepath, sol_file, time_val, space_val):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    original = content

    # 找到對應 solution block 後替換 time/space
    # 用 solution file 名稱定位區塊，再替換 time: '' 和 space: ''
    # 只在該 solution 的區塊內替換

    lines = content.split("\n")
    result = []
    in_target = False
    i = 0
    while i < len(lines):
        line = lines[i]
        if f"file: {sol_file}" in line:
            in_target = True
        if in_target:
            if time_val and re.match(r"\s*time:\s*''", line):
                line = line.replace("time: ''", f"time: {time_val}")
                in_target = True
            if space_val and re.match(r"\s*space:\s*''", line):
                line = line.replace("space: ''", f"space: {space_val}")
        # 遇到下一個 - file: 代表進入下一個 solution，離開當前 block
        if in_target and line.strip().startswith("- file:") and f"file: {sol_file}" not in line:
            in_target = False
        result.append(line)
        i += 1

    new_content = "\n".join(result)

    if new_content == original:
        return "skip"

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(new_content)
    return "ok"


if __name__ == "__main__":
    ok = skip = not_found = 0

    for yml_file, solutions in FIXES.items():
        filepath = os.path.join(BASE, yml_file)
        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {yml_file}")
            not_found += 1
            continue

        for sol_file, time_val, space_val in solutions:
            result = fix_yml(filepath, sol_file, time_val, space_val)
            if result == "ok":
                print(f"[OK]   {yml_file} / {sol_file}  →  time:{time_val}  space:{space_val}")
                ok += 1
            else:
                print(f"[SKIP] {yml_file} / {sol_file}")
                skip += 1

    print(f"\n完成！OK:{ok}  SKIP:{skip}  NOT_FOUND:{not_found}")
