#!/usr/bin/env python3
"""
1. 修正 build_topic_indexes 的表頭（單獨處理，不跟分隔線綁在一起）
2. 掃描所有 docs/topics/*.md 和 docs/review.md，檢查連結格式是否有異常空格
   （例如 ". ./" 或 "C++ ]" 這種），直接由程式回報，不用你手動複製貼上比對
"""
import sys
import os
import re
import glob

def fix_header(generate_site_path):
    with open(generate_site_path, 'r', encoding='utf-8') as f:
        content = f.read()

    old = '"| # | 題目 | 難度 | 標籤 | 時間 | 空間 |",'
    new = '"| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |",'

    if old not in content:
        print(f"❌ 找不到表頭錨點，需要手動處理")
        return False
    content = content.replace(old, new, 1)
    with open(generate_site_path, 'w', encoding='utf-8') as f:
        f.write(content)
    print(f"✓ 表頭已修正")
    return True

def check_link_integrity(docs_dir):
    bad_patterns = [
        (re.compile(r'\]\(\.\s+\.'), '連結路徑裡 ".." 中間夾了空格'),
        (re.compile(r'\[C\+\+\s+\]'), '"C++" 連結文字裡有多餘空格'),
        (re.compile(r'\]\(\s'), '連結網址開頭有多餘空格'),
        (re.compile(r'\s\)'), '連結網址結尾有多餘空格'),
    ]

    files_to_check = glob.glob(os.path.join(docs_dir, 'topics', '*.md'))
    review_path = os.path.join(docs_dir, 'review.md')
    if os.path.exists(review_path):
        files_to_check.append(review_path)

    total_issues = 0
    for fpath in sorted(files_to_check):
        with open(fpath, 'r', encoding='utf-8') as f:
            lines = f.readlines()
        for lineno, line in enumerate(lines, 1):
            for pattern, label in bad_patterns:
                if pattern.search(line):
                    total_issues += 1
                    print(f"⚠️  {os.path.relpath(fpath, docs_dir)}:{lineno} — {label}")
                    print(f"     {line.rstrip()}")

    print(f"\n{'❌ 總共發現 ' + str(total_issues) + ' 處連結格式異常' if total_issues else '✅ 沒有發現任何連結格式異常，檔案本身是乾淨的'}")
    return total_issues == 0

def main():
    generate_site_path = sys.argv[1] if len(sys.argv) > 1 else 'tools/generate_site.py'
    docs_dir = sys.argv[2] if len(sys.argv) > 2 else 'docs'

    print("===== Step 1: 修正表頭 =====")
    fix_header(generate_site_path)

    print("\n===== Step 2: 檢查現有 docs/ 底下的連結完整性（修正表頭前產生的舊檔案）=====")
    check_link_integrity(docs_dir)

if __name__ == '__main__':
    main()
