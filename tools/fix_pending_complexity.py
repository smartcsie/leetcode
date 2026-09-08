#!/usr/bin/env python3
"""
fix_pending_complexity.py
修正「待補充」的時間/空間複雜度
用法：python3 fix_pending_complexity.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/solution"

# 每題的正確複雜度 (時間, 空間)
COMPLEXITY = {
    "Solution_0148.cpp":  ("O(NlogN)",  "O(logN)"),
    "Solution_1342.cpp":  ("O(logN)",   "O(1)"),
    "Solution_1387.cpp":  ("O(N*S)",    "O(N+S)"),
    "Solution_1461.cpp":  ("O(N*K)",    "O(2^K)"),
    "Solution_2063.cpp":  ("O(N)",      "O(1)"),
    "Solution_2554.cpp":  ("O(N+M)",    "O(M)"),
    "Solution_3090.cpp":  ("O(N)",      "O(1)"),
    "Solution_3132.cpp":  ("O(NlogN)",  "O(1)"),
    "Solution_3861.cpp":  ("O(N)",      "O(1)"),
}

def fix_file(filepath, time_val, space_val):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    original = content

    # 替換「待補充」的時間複雜度
    content = re.sub(
        r'(\*\s*時間複雜度[：:]\s*)待補充',
        rf'\g<1>{time_val}',
        content
    )

    # 替換「待補充」的空間複雜度
    content = re.sub(
        r'(\*\s*空間複雜度[：:]\s*)待補充',
        rf'\g<1>{space_val}',
        content
    )

    if content != original:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)
        return True
    return False


if __name__ == "__main__":
    fixed = 0
    skipped = 0
    not_found = 0

    for filename, (time_val, space_val) in COMPLEXITY.items():
        filepath = os.path.join(BASE, filename)
        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}")
            not_found += 1
            continue

        if fix_file(filepath, time_val, space_val):
            print(f"[OK] {filename}  →  時間:{time_val}  空間:{space_val}")
            fixed += 1
        else:
            print(f"[SKIP] {filename}  (無待補充或已正確)")
            skipped += 1

    print(f"\n完成！修正:{fixed}  跳過:{skipped}  找不到:{not_found}")
