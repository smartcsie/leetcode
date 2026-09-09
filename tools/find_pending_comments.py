#!/usr/bin/env python3
"""
find_pending_comments.py
找出 .cpp 檔案中仍有「待補充」註解的題目。
用法：python3 tools/find_pending_comments.py
"""

import os

BASE = "/home/laurence/leetcode-docs/repo/solution"

def check_file(filepath):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()
    return "待補充" in content

if __name__ == "__main__":
    found = []
    for filename in sorted(os.listdir(BASE)):
        if not filename.endswith(".cpp"):
            continue
        filepath = os.path.join(BASE, filename)
        if check_file(filepath):
            num = filename.replace("Solution_", "").replace(".cpp", "")
            found.append((num, filename))

    print(f"\n找到 {len(found)} 個含「待補充」的檔案：\n")
    for num, filename in found:
        print(f"  [{num}] {filename}")
