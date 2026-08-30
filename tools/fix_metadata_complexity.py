#!/usr/bin/env python3
"""
fix_metadata_complexity.py

把 metadata/*.yml 裡每個解法的 time / space 欄位，只保留開頭的
O(...) 表達式，後面附加的說明文字都刪掉：
    O(N) - 說明文字         ->  O(N)
    O(2^(N-1))（最壞情況）  ->  O(2^(N-1))
用「括號深度追蹤」而不是簡單 regex，正確處理巢狀括號
（例如 O(∏(needs[i]+1) × 優惠數量)、O(N*2^(N/2)) 這種）。

這支是 fix_complexity.py 的 metadata 版本：fix_complexity.py 清的是
solution/*.cpp 檔案裡的註解文字，這支清的是 metadata/*.yml 裡的
time/space 欄位——兩邊資料是分開存放的，网站頁面（docs/topics/*.md、
docs/review.md）顯示的複雜度是從 metadata 讀出來的，不是從 .cpp
註解重新解析，所以要清網站上看到的殘留，必須跑這支，不是跑
fix_complexity.py。

用法：
    python3 fix_metadata_complexity.py [metadata_dir]        # dry-run，只列出
    python3 fix_metadata_complexity.py [metadata_dir] --yes   # 真的套用

    metadata_dir  預設 'metadata'
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)


def extract_complexity(text):
    """
    從一段文字裡取出開頭的 O(...) 表達式，正確處理巢狀括號。
    找不到 'O(' 這個型態就原封不動回傳，不硬砍。
    """
    if not text:
        return text
    idx = text.find('O(')
    if idx == -1:
        return text.strip()

    i = idx + 2
    depth = 1
    while i < len(text) and depth > 0:
        if text[i] == '(':
            depth += 1
        elif text[i] == ')':
            depth -= 1
        i += 1

    return text[idx:i]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    meta_dir = args[0] if args else 'metadata'
    do_apply = '--yes' in sys.argv

    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    total_changes = 0
    files_changed = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue

        number = data.get('number')
        title = data.get('title', '')
        file_changed = False

        for sol in data.get('solutions', []):
            for field in ('time', 'space'):
                original = sol.get(field)
                if not original:
                    continue
                cleaned = extract_complexity(original)
                if cleaned != original:
                    label = '時間' if field == 'time' else '空間'
                    print(f"  {number:>5} {title:<45} [{sol.get('file','?')}] "
                          f"{label}：{original!r} → {cleaned!r}")
                    sol[field] = cleaned
                    total_changes += 1
                    file_changed = True

        if file_changed:
            files_changed += 1
            if do_apply:
                with open(fpath, 'w', encoding='utf-8') as f:
                    yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"\n{'=' * 60}")
    if do_apply:
        print(f"完成：{files_changed} 個檔案、{total_changes} 處複雜度欄位已清理。")
    else:
        print(f"這是 dry-run（{files_changed} 個檔案、{total_changes} 處會被異動），"
              f"還沒有真的寫入。確認沒問題後加 --yes 再跑一次：")
        print(f"  python3 {os.path.basename(__file__)} {meta_dir} --yes")


if __name__ == '__main__':
    main()
