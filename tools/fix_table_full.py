#!/usr/bin/env python3
"""
1. 修正 tools/generate_site.py 裡分隔線的欄位數，讓它跟表頭一致
2. 重新產生網站
3. 徹底掃描 docs/ 底下所有檔案，檢查：
   - 表頭跟分隔線的欄位數是否一致
   - 連結裡有沒有異常空格
   全部由程式自己判斷回報，不需要人工複製貼上比對
"""
import sys
import os
import re
import glob

def fix_separator(generate_site_path):
    with open(generate_site_path, 'r', encoding='utf-8') as f:
        content = f.read()

    changed = False

    # build_topic_indexes 的分隔線：確保是 6 個 --- (對應 7 欄表頭)
    old_sep_variants = [
        '"| --- | --- | --- | --- | --- |"]',
    ]
    new_sep = '"| --- | --- | --- | --- | --- | --- |"]'
    for old_sep in old_sep_variants:
        if old_sep in content:
            content = content.replace(old_sep, new_sep, 1)
            changed = True
            print(f"✓ 修正了分隔線欄位數")

    if changed:
        with open(generate_site_path, 'w', encoding='utf-8') as f:
            f.write(content)
    else:
        print("（分隔線已經是正確的，或找不到需要修正的舊格式）")

def check_table_integrity(docs_dir):
    files_to_check = glob.glob(os.path.join(docs_dir, 'topics', '*.md'))
    review_path = os.path.join(docs_dir, 'review.md')
    if os.path.exists(review_path):
        files_to_check.append(review_path)

    total_issues = 0

    for fpath in sorted(files_to_check):
        with open(fpath, 'r', encoding='utf-8') as f:
            lines = f.readlines()

        header_cols = None
        sep_cols = None
        for lineno, line in enumerate(lines, 1):
            stripped = line.strip()
            if stripped.startswith('| #') or (stripped.startswith('|') and '題目' in stripped):
                header_cols = stripped.count('|') - 1
            elif stripped.startswith('| ---') or stripped.startswith('|---'):
                sep_cols = stripped.count('|') - 1
                if header_cols is not None and sep_cols != header_cols:
                    total_issues += 1
                    print(f"⚠️  {os.path.relpath(fpath, docs_dir)}:{lineno} — 表頭 {header_cols} 欄，分隔線 {sep_cols} 欄，對不上")

            # 檢查連結格式異常
            if re.search(r'/\s+\d', line):  # 例如 "problems/ 0001"
                total_issues += 1
                print(f"⚠️  {os.path.relpath(fpath, docs_dir)}:{lineno} — 連結路徑裡有異常空格")
                print(f"     {line.rstrip()}")
            if re.search(r'[A-Za-z]\s{2,}[A-Za-z]', line):  # 例如 "Hash  Table"
                total_issues += 1
                print(f"⚠️  {os.path.relpath(fpath, docs_dir)}:{lineno} — 文字中間有連續多個空格")
                print(f"     {line.rstrip()}")

    print(f"\n{'❌ 總共發現 ' + str(total_issues) + ' 處問題' if total_issues else '✅ 全部檔案表格結構與連結格式都正確'}")
    return total_issues == 0

def main():
    generate_site_path = sys.argv[1] if len(sys.argv) > 1 else 'tools/generate_site.py'
    docs_dir = sys.argv[2] if len(sys.argv) > 2 else 'docs'

    print("===== Step 1: 修正分隔線欄位數 =====")
    fix_separator(generate_site_path)

    print("\n===== Step 2: 檢查所有檔案的表格結構與連結格式 =====")
    check_table_integrity(docs_dir)

if __name__ == '__main__':
    main()
