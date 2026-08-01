#!/usr/bin/env python3
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    changed_files = 0
    changed_solutions = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        file_changed = False
        for sol in data.get('solutions', []):
            if sol.get('familiarity') != '生疏':
                sol['familiarity'] = '生疏'
                file_changed = True
                changed_solutions += 1

        if file_changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)
            changed_files += 1

    print(f"✓ 已將 {changed_files} 個檔案、共 {changed_solutions} 個解法的熟悉度設為「生疏」")

if __name__ == '__main__':
    main()
