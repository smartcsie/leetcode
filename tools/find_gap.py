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
    existing_info = {}
    for fpath in glob.glob(os.path.join(meta_dir, '*.yml')):
        base = os.path.basename(fpath).replace('.yml', '')
        try:
            num = int(base)
        except ValueError:
            continue
        existing_numbers.add(num)
        try:
            with open(fpath, 'r', encoding='utf-8') as f:
                meta = yaml.safe_load(f)
            existing_info[num] = {
                'title': (meta or {}).get('title', ''),
                'url': (meta or {}).get('url', ''),
            }
        except Exception:
            existing_info[num] = {'title': '', 'url': ''}

    print(f"repo 裡 metadata 已收錄：{len(existing_numbers)} 題")

    gap = sorted(set(ac_problems.keys()) - existing_numbers)
    print(f"\n落差（已 AC 但 repo 裡沒有）：共 {len(gap)} 題\n")

    for num in gap:
        info = ac_problems[num]
        url = f"https://leetcode.com/problems/{info['slug']}/"
        print(f"{num:>5} | {info['title']:<50} | {url}")

    reverse_gap = sorted(existing_numbers - set(ac_problems.keys()))
    print(f"\n\n反向落差（repo 裡有筆記，但 LeetCode 帳號還沒 AC）：共 {len(reverse_gap)} 題\n")
    print("（可能原因：只寫了筆記還沒真的送出/AC、AC 記錄用別的帳號、或是題號打錯）\n")

    for num in reverse_gap:
        info = existing_info.get(num, {'title': '', 'url': ''})
        url = info['url'] or f"https://leetcode.com/problems/{num}/"
        print(f"{num:>5} | {info['title']:<50} | {url}")

if __name__ == '__main__':
    main()

