#!/usr/bin/env python3
"""
find_empty_complexity.py
找出 .cpp 檔案中時間/空間複雜度欄位為空白的題目。
用法：python3 tools/find_empty_complexity.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/solution"

def check_file(filepath):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    issues = []

    # 檢查時間複雜度是否為空（只有欄位名稱但沒有值）
    time_match = re.search(r'\*\s*時間複雜度[：:]\s*(\S*)', content)
    if time_match:
        val = time_match.group(1).strip()
        if not val:
            issues.append("❌ 時間複雜度為空")
    else:
        # 沒有時間複雜度欄位
        if "時間複雜度" not in content and "/**" in content:
            issues.append("❌ 缺少時間複雜度欄位")

    # 檢查空間複雜度是否為空
    space_match = re.search(r'\*\s*空間複雜度[：:]\s*(\S*)', content)
    if space_match:
        val = space_match.group(1).strip()
        if not val:
            issues.append("❌ 空間複雜度為空")
    else:
        if "空間複雜度" not in content and "/**" in content:
            issues.append("❌ 缺少空間複雜度欄位")

    return issues


if __name__ == "__main__":
    found = []
    for filename in sorted(os.listdir(BASE)):
        if not filename.endswith(".cpp"):
            continue
        filepath = os.path.join(BASE, filename)
        issues = check_file(filepath)
        if issues:
            num = filename.replace("Solution_", "").replace(".cpp", "")
            found.append((num, filename, issues))

    print(f"\n找到 {len(found)} 個有問題的檔案：\n")
    for num, filename, issues in found:
        print(f"  [{num}] {filename}")
        for issue in issues:
            print(f"      {issue}")
