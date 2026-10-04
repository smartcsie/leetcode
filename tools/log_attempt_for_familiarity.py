#!/usr/bin/env python3
"""
log_attempt_for_familiarity.py — 幫某個熟悉度分類（預設「易忘」）底下的所有解法，
補寫一筆練習歷程紀錄（attempts），方便之後「即使練習時答對了」，
也能在這份解法的練習歷程裡找到「曾經被標記過易忘／再練習」這個事實。

不會更動 familiarity 欄位本身，只是在 attempts 清單裡多加一筆紀錄。

用法（在 repo 根目錄、跟 metadata/ 同一層執行）：
    python3 log_attempt_for_familiarity.py
        → 預設對 familiarity == '易忘' 的解法，補一筆 result='錯' 的紀錄

    python3 log_attempt_for_familiarity.py metadata 再練習
        → 改成對 familiarity == '再練習' 的解法補紀錄

    python3 log_attempt_for_familiarity.py metadata 易忘 "自訂的原因文字"
        → 自訂這筆紀錄的 reason

    python3 log_attempt_for_familiarity.py metadata 易忘 "" --dry-run
        → 先看看會改到哪些檔案，不實際寫入（確認無誤後再拿掉 --dry-run 重新執行）
"""
import sys
import os
import glob
from datetime import date

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

DEFAULT_REASON_TEMPLATE = "批次補紀錄：目前標記為「{familiarity}」，先留一筆紀錄方便之後追蹤複習"


def main():
    args = sys.argv[1:]
    dry_run = '--dry-run' in args
    args = [a for a in args if a != '--dry-run']

    meta_dir = args[0] if len(args) > 0 else 'metadata'
    familiarity = args[1] if len(args) > 1 else '易忘'
    reason = args[2] if len(args) > 2 and args[2] else DEFAULT_REASON_TEMPLATE.format(familiarity=familiarity)

    today = date.today().isoformat()

    changed_files = 0
    changed_solutions = []

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        file_changed = False
        for sol in data.get('solutions', []):
            if sol.get('familiarity') != familiarity:
                continue

            attempts = sol.get('attempts') or []
            attempts.append({'date': today, 'result': '錯', 'reason': reason})
            sol['attempts'] = attempts
            file_changed = True
            changed_solutions.append((data.get('number'), sol.get('file')))

        if file_changed:
            changed_files += 1
            if not dry_run:
                with open(fpath, 'w', encoding='utf-8') as f:
                    yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    label = '（dry-run，尚未寫入，請確認清單無誤後拿掉 --dry-run 重新執行）' if dry_run else ''
    print(f"✓ 熟悉度「{familiarity}」共 {len(changed_solutions)} 個解法、{changed_files} 個檔案 {label}")
    for number, file in changed_solutions:
        print(f"  {number}: {file}")

    if not dry_run and changed_files:
        print("\n完成後請重新執行 generate_site.py 重新產生網站頁面，才會在 review.md / 題目頁看到這筆新紀錄。")
    elif not changed_solutions:
        print(f"沒有找到任何 familiarity == 「{familiarity}」的解法，請確認分類名稱或 metadata 資料夾路徑是否正確。")


if __name__ == '__main__':
    main()
