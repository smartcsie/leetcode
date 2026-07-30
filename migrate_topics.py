#!/usr/bin/env python3
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml")
    sys.exit(1)

MERGE_MAP = {
    'sorting-2': 'sorting',
    'dynamic-programming-2': 'dynamic-programming',
    'dynamic-programming-3': 'dynamic-programming',
    'dynamic-programming-4': 'dynamic-programming',
    'knapsack-problem-2': 'knapsack-problem',
    'string-substring-2': 'string-substring',
    'array-continuous-counting-2': 'array-continuous-counting',
}

def to_list(value):
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    changed_files = 0
    changed_solutions = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        file_changed = False
        for sol in data.get('solutions', []):
            old_topics = to_list(sol.get('topics'))
            new_topics = []
            for t in old_topics:
                mapped = MERGE_MAP.get(t, t)
                if mapped not in new_topics:
                    new_topics.append(mapped)

            if new_topics != old_topics:
                sol['topics'] = new_topics
                file_changed = True
                changed_solutions += 1
                print(f"  {os.path.basename(fpath)}: {old_topics} -> {new_topics}")

        if file_changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)
            changed_files += 1

    print(f"\n完成：修改了 {changed_files} 個檔案，共 {changed_solutions} 筆 solution 的 topics")

if __name__ == '__main__':
    main()
