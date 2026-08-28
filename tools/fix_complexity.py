#!/usr/bin/env python3
"""
fix_complexity.py
把時間/空間複雜度後面的描述文字刪掉
O(N) - 說明文字  →  O(N)
用法：python3 fix_complexity.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/solution"

def fix_file(filepath):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    original = content

    # 找時間/空間複雜度行，把 O(...) 後面的描述刪掉
    content = re.sub(
        r'(\*\s*時間複雜度[：:]\s*)(O\([^)]+\))(.*)',
        r'\1\2',
        content
    )
    content = re.sub(
        r'(\*\s*空間複雜度[：:]\s*)(O\([^)]+\))(.*)',
        r'\1\2',
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

    for filename in sorted(os.listdir(BASE)):
        if not filename.endswith(".cpp"):
            continue
        filepath = os.path.join(BASE, filename)
        if fix_file(filepath):
            print(f"[OK] {filename}")
            fixed += 1
        else:
            skipped += 1

    print(f"\n完成！修正：{fixed} 個  未變動：{skipped} 個")
