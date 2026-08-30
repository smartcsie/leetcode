#!/usr/bin/env python3
"""
fix_complexity.py
把時間/空間複雜度後面的描述文字刪掉，只留 O(...) 本身
O(N) - 說明文字         →  O(N)
O(2^(N-1))（最壞情況）  →  O(2^(N-1))
用法：python3 fix_complexity.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/solution"

LABEL_RE = re.compile(r'(\s*\*\s*(?:時間複雜度|空間複雜度)[：:]\s*)(.*)')


def extract_complexity(text):
    """
    從一段文字裡取出開頭的 O(...) 表達式，正確處理巢狀括號
    （例如 O(2^(N-1))、O(N*2^(N/2))），回傳 (複雜度本身, 後面被砍掉的說明文字)。
    如果找不到 'O(' 這個型態，原封不動回傳整段文字、說明文字給空字串。
    """
    idx = text.find('O(')
    if idx == -1:
        return text, ''

    i = idx + 2
    depth = 1
    while i < len(text) and depth > 0:
        if text[i] == '(':
            depth += 1
        elif text[i] == ')':
            depth -= 1
        i += 1

    complexity = text[idx:i]
    rest = text[i:]
    # 前面如果還有其他文字（正常情況下不會有，但保留以防萬一）
    prefix = text[:idx]
    return prefix + complexity, rest


def fix_file(filepath):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        lines = f.readlines()

    changed = False
    new_lines = []
    for line in lines:
        m = LABEL_RE.match(line.rstrip('\n'))
        if m:
            label, rest_of_line = m.group(1), m.group(2)
            trailing_newline = '\n' if line.endswith('\n') else ''
            kept, _dropped = extract_complexity(rest_of_line)
            new_line = label + kept + trailing_newline
            if new_line != line:
                changed = True
            new_lines.append(new_line)
        else:
            new_lines.append(line)

    if changed:
        with open(filepath, "w", encoding="utf-8") as f:
            f.writelines(new_lines)
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
