#!/usr/bin/env python3
"""
check_comments.py
檢查 .cpp 檔案的開頭註解格式：
1. 是否有 /** ... */ 開頭註解
2. 時間/空間複雜度是否只有 O(...) 不含其他描述文字
用法：python3 check_comments.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/solution"

def check_file(filepath):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    issues = []

    # 1. 檢查是否有開頭註解
    if not content.strip().startswith("/**"):
        issues.append("❌ 缺少開頭 /** 註解")
        return issues  # 沒有註解就不用繼續檢查

    # 2. 找時間複雜度行
    time_match = re.search(r'\*\s*時間複雜度[：:]\s*(.+)', content)
    if not time_match:
        issues.append("❌ 缺少時間複雜度")
    else:
        time_val = time_match.group(1).strip()
        # 只允許 O(...) 格式，不能有 " - " 後面的描述
        if not re.fullmatch(r'O\([^)]+\)', time_val):
            issues.append(f"⚠️  時間複雜度格式不對：{time_val}")

    # 3. 找空間複雜度行
    space_match = re.search(r'\*\s*空間複雜度[：:]\s*(.+)', content)
    if not space_match:
        issues.append("❌ 缺少空間複雜度")
    else:
        space_val = space_match.group(1).strip()
        if not re.fullmatch(r'O\([^)]+\)', space_val):
            issues.append(f"⚠️  空間複雜度格式不對：{space_val}")

    return issues


if __name__ == "__main__":
    ok = 0
    problems = []

    for filename in sorted(os.listdir(BASE)):
        if not filename.endswith(".cpp"):
            continue
        filepath = os.path.join(BASE, filename)
        issues = check_file(filepath)
        if issues:
            problems.append((filename, issues))
        else:
            ok += 1

    print(f"\n✅ 格式正確：{ok} 個")
    print(f"⚠️  需要修正：{len(problems)} 個\n")
    for filename, issues in problems:
        num = filename.replace("Solution_", "").replace(".cpp", "")
        print(f"  [{num}] {filename}")
        for issue in issues:
            print(f"      {issue}")
