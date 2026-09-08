#!/usr/bin/env python3
"""
fix_missing_complexity.py
針對有開頭 /** 註解但缺少時間/空間複雜度的檔案，插入正確的複雜度。
用法：python3 fix_missing_complexity.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/solution"

# 每題的正確複雜度 (時間, 空間)
COMPLEXITY = {
    "Solution_0066.cpp":  ("O(N)",          "O(1)"),
    "Solution_0098.cpp":  ("O(N)",          "O(H)"),
    "Solution_0100.cpp":  ("O(N)",          "O(H)"),
    "Solution_0102.cpp":  ("O(N)",          "O(W)"),
    "Solution_0110.cpp":  ("O(N)",          "O(H)"),
    "Solution_0111.cpp":  ("O(N)",          "O(H)"),
    "Solution_0112.cpp":  ("O(N)",          "O(H)"),
    "Solution_0199.cpp":  ("O(N)",          "O(W)"),
    "Solution_0231.cpp":  ("O(1)",          "O(1)"),
    "Solution_0268.cpp":  ("O(N)",          "O(1)"),
    "Solution_0326.cpp":  ("O(1)",          "O(1)"),
    "Solution_0342.cpp":  ("O(1)",          "O(1)"),
    "Solution_0344.cpp":  ("O(N)",          "O(1)"),
    "Solution_0349.cpp":  ("O(N+M)",        "O(N)"),
    "Solution_0706.cpp":  ("O(N/K)",        "O(M+K)"),
    "Solution_1609.cpp":  ("O(N)",          "O(W)"),
    "Solution_1886.cpp":  ("O(N^2)",        "O(1)"),
    "Solution_2248.cpp":  ("O(N*M)",        "O(N)"),
    "Solution_2761.cpp":  ("O(NloglogN)",   "O(N)"),
}

INSERT_TEMPLATE = " * 時間複雜度：{time}\n * 空間複雜度：{space}\n"

def fix_file(filepath, time_val, space_val):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    # 已有複雜度就跳過
    if "時間複雜度" in content:
        return "skip"

    # 沒有開頭 /** 就跳過
    if not content.strip().startswith("/**"):
        return "no_comment"

    insert_line = INSERT_TEMPLATE.format(time=time_val, space=space_val)

    # 在 */ 前插入複雜度
    new_content = re.sub(r"(\s*\*/)", f"\n{insert_line}\\1", content, count=1)

    if new_content == content:
        return "no_end"

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(new_content)

    return "ok"


if __name__ == "__main__":
    ok = skip = no_comment = no_end = not_found = 0

    for filename, (time_val, space_val) in COMPLEXITY.items():
        filepath = os.path.join(BASE, filename)

        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}")
            not_found += 1
            continue

        result = fix_file(filepath, time_val, space_val)

        if result == "ok":
            print(f"[OK]    {filename}  →  {time_val} / {space_val}")
            ok += 1
        elif result == "skip":
            print(f"[SKIP]  {filename}  (已有複雜度)")
            skip += 1
        elif result == "no_comment":
            print(f"[WARN]  {filename}  (缺少 /** 開頭)")
            no_comment += 1
        elif result == "no_end":
            print(f"[WARN]  {filename}  (找不到 */)")
            no_end += 1

    print(f"\n完成！OK:{ok}  SKIP:{skip}  NOT_FOUND:{not_found}  WARN:{no_comment + no_end}")
