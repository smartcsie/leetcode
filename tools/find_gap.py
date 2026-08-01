#!/usr/bin/env python3
import sys
import os
import glob
import json

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

def main():
    json_path = sys.argv[1] if len(sys.argv) > 1 else 'leetcode_all.json'
    meta_dir = sys.argv[2] if len(sys.argv) > 2 else 'metadata'

    with open(json_path, 'r', encoding='utf-8') as f:
        data = json.load(f)

    ac_problems = {}
    for pair in data.get('stat_status_pairs', []):
        if pair.get('status') == 'ac':
            stat = pair.get('stat', {})
            num = stat.get('frontend_question_id')
            title = stat.get('question__title', '')
            slug = stat.get('question__title_slug', '')
            if num is not None:
                ac_problems[num] = {'title': title, 'slug': slug}

    print(f"LeetCode 帳號顯示已 AC：{len(ac_problems)} 題")

    existing_numbers = set()
    for fpath in glob.glob(os.path.join(meta_dir, '*.yml')):
        base = os.path.basename(fpath).replace('.yml', '')
        try:
            existing_numbers.add(int(base))
        except ValueError:
            continue

    print(f"repo 裡 metadata 已收錄：{len(existing_numbers)} 題")

    gap = sorted(set(ac_problems.keys()) - existing_numbers)
    print(f"\n落差（已 AC 但 repo 裡沒有）：共 {len(gap)} 題\n")

    for num in gap:
        info = ac_problems[num]
        url = f"https://leetcode.com/problems/{info['slug']}/"
        print(f"{num:>5} | {info['title']:<50} | {url}")

if __name__ == '__main__':
    main()
