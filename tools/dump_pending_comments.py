#!/usr/bin/env python3
"""
dump_pending_comments.py
把含「待補充」的 .cpp 檔案內容輸出，方便貼給 Claude 補註解。
用法：python3 tools/dump_pending_comments.py > pending_dump.txt
"""

import os

BASE = "/home/laurence/leetcode-docs/repo/solution"

def check_file(filepath):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()
    return "待補充" in content, content

if __name__ == "__main__":
    for filename in sorted(os.listdir(BASE)):
        if not filename.endswith(".cpp"):
            continue
        filepath = os.path.join(BASE, filename)
        has_pending, content = check_file(filepath)
        if not has_pending:
            continue
        print(f"// ===== {filename} =====")
        # 只輸出前 60 行，避免太長
        lines = content.splitlines()
        for line in lines[:60]:
            print(line)
        if len(lines) > 60:
            print(f"// ... (共 {len(lines)} 行，已截斷)")
        print()
