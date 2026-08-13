#!/usr/bin/env python3
"""
rename_zhuyi_to_zailianxi.py

把所有 metadata/*.yml 裡 familiarity: 注意 改成 familiarity: 再練習。
是「熟悉度四階段」改版的第一步（生疏 -> 再練習 -> 練習過 -> 熟練），
執行完這支之後再套用 generate_site.py / solution-generator.html 的修改。

用法：
    python3 rename_zhuyi_to_zailianxi.py [metadata_dir]

預設 metadata_dir 是 'metadata'。
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

OLD_VALUE = '注意'
NEW_VALUE = '再練習'


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
            if sol.get('familiarity') == OLD_VALUE:
                sol['familiarity'] = NEW_VALUE
                file_changed = True
                changed_solutions += 1

        if file_changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)
            changed_files += 1
            print(f"✓ {os.path.basename(fpath)}")

    print(f"\n完成：共更新 {changed_files} 個檔案、{changed_solutions} 個解法"
          f"（{OLD_VALUE} -> {NEW_VALUE}）")


if __name__ == '__main__':
    main()
