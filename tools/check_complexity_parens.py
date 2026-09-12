#!/usr/bin/env python3
"""
check_complexity_parens.py

掃描 metadata/*.yml 裡每個解法的 time / space 欄位，檢查括號數量是否
平衡（左括號 '(' 的數量應該要等於右括號 ')' 的數量）。用來抓出像
"O(M!"（缺右括號）這種因為過去解析 bug 而被截斷、壞掉的資料——這種
資料沒辦法自動修好（正確值已經遺失），只能列出來讓你手動重新填寫。

用法：
    python3 check_complexity_parens.py [metadata_dir]

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


def is_balanced(text):
    """
    檢查括號是否配對。分開檢查半形 ()  跟全形 （） 兩種括號，
    因為註解裡常常中英文括號混用（英文複雜度用半形，中文說明用全形），
    只檢查其中一種會漏掉另一種被截斷的情況。
    """
    if not text:
        return True
    for open_ch, close_ch in [('(', ')'), ('（', '）')]:
        depth = 0
        for ch in text:
            if ch == open_ch:
                depth += 1
            elif ch == close_ch:
                depth -= 1
                if depth < 0:
                    return False  # 右括號比左括號先出現，也是不合法
        if depth != 0:
            return False
    return True


def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    total_broken = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if not data:
            continue
        try:
            number = int(data.get('number'))
        except (TypeError, ValueError):
            number = data.get('number', '?')
        title = data.get('title', '')

        for sol in data.get('solutions', []) or []:
            for field in ('time', 'space'):
                value = sol.get(field)
                if value and not is_balanced(value):
                    print(f"  {number:>5} {title:<45} [{sol.get('file','?')}] "
                          f"{field}: {value!r}  <-- 括號不平衡")
                    total_broken += 1

    print(f"\n{'=' * 60}")
    if total_broken == 0:
        print("沒有發現括號不平衡的複雜度欄位。")
    else:
        print(f"共發現 {total_broken} 處括號不平衡，這些資料已經被截斷、"
              f"正確值遺失了，沒辦法自動修復，需要手動重新填寫。")


if __name__ == '__main__':
    main()
