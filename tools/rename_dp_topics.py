#!/usr/bin/env python3
"""
rename_dp_topics.py

把 metadata/*.yml 裡舊的 dynamic-programming-xxx 分類 slug 改成新的 dp-xxx。
注意：'dynamic-programming'（不帶後綴的大分類本身）保持不變，不會被改到。

用法：
    python3 rename_dp_topics.py [metadata_dir]

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

RENAME_MAP = {
    'dynamic-programming-knapsack': 'dp-knapsack',
    'dynamic-programming-kadane': 'dp-kadane',
    'dynamic-programming-fibonacci': 'dp-fibonacci',
    'dynamic-programming-lcs': 'dp-lcs',
    'dynamic-programming-grid-path': 'dp-grid-path',
    'dynamic-programming-lis': 'dp-lis',
    'dynamic-programming-state-machine': 'dp-machine',
}


def rename_topics(value):
    """value 可能是 None / str / list，統一處理成改名後的結果，回傳 (新值, 是否有改)"""
    if value is None:
        return value, False
    if isinstance(value, str):
        new = RENAME_MAP.get(value, value)
        return new, new != value
    # list
    changed = False
    new_list = []
    for t in value:
        nt = RENAME_MAP.get(t, t)
        if nt != t:
            changed = True
        new_list.append(nt)
    return new_list, changed


def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    changed_files = 0
    changed_solutions = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        if not data or 'solutions' not in data:
            continue

        file_changed = False
        for sol in data['solutions']:
            new_topics, changed = rename_topics(sol.get('topics'))
            if changed:
                sol['topics'] = new_topics
                file_changed = True
                changed_solutions += 1

        if file_changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)
            changed_files += 1
            print(f"✓ {os.path.basename(fpath)}")

    print(f"\n完成：共更新 {changed_files} 個檔案、{changed_solutions} 個解法的 topics")


if __name__ == '__main__':
    main()
