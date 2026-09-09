#!/usr/bin/env python3
"""
find_empty_yml_complexity.py
找出 metadata yml 檔案中 time/space 欄位為空的題目。
用法：python3 tools/find_empty_yml_complexity.py
"""

import os
import yaml

BASE = "/home/laurence/leetcode-docs/repo/metadata"

def check_file(filepath):
    with open(filepath, "r", encoding="utf-8") as f:
        data = yaml.safe_load(f)

    issues = []
    solutions = data.get("solutions", [])
    for sol in solutions:
        filename = sol.get("file", "")
        time_val = sol.get("time", None)
        space_val = sol.get("space", None)
        if time_val == "" or time_val is None:
            issues.append((filename, "time"))
        if space_val == "" or space_val is None:
            issues.append((filename, "space"))
    return issues


if __name__ == "__main__":
    found = []
    for filename in sorted(os.listdir(BASE)):
        if not filename.endswith(".yml"):
            continue
        filepath = os.path.join(BASE, filename)
        try:
            issues = check_file(filepath)
            if issues:
                found.extend([(filename, sol_file, field) for sol_file, field in issues])
        except Exception as e:
            print(f"[ERROR] {filename}: {e}")

    print(f"\n找到 {len(found)} 個空白複雜度：\n")
    for yml_file, sol_file, field in found:
        print(f"  [{yml_file}]  {sol_file}  →  {field}: ''")
