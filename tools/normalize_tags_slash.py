#!/usr/bin/env python3
"""
把 metadata/*.yml 裡「單一標籤內含斜線」的情況拆成多個獨立標籤。
例如 tags: ["Hash Table / String Parsing"] -> tags: ["Hash Table", "String Parsing"]

Usage:
    python3 normalize_tags_slash.py metadata
"""
import sys
import os
import re
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml")
    sys.exit(1)

def split_tag_if_needed(tag):
    if '/' in tag:
        return [t.strip() for t in re.split(r'\s*/\s*', tag) if t.strip()]
    return [tag]

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    changed = 0

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        file_changed = False
        for sol in data.get('solutions', []):
            old_tags = sol.get('tags') or []
            if isinstance(old_tags, str):
                old_tags = [old_tags]
            new_tags = []
            for t in old_tags:
                new_tags.extend(split_tag_if_needed(t))
            if new_tags != old_tags:
                sol['tags'] = new_tags
                file_changed = True
                print(f"  {os.path.basename(fpath)}: {old_tags} -> {new_tags}")

        if file_changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)
            changed += 1

    print(f"\n完成：修改了 {changed} 個檔案")

if __name__ == '__main__':
    main()
