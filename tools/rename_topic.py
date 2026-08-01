#!/usr/bin/env python3
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

def to_list(value):
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)

def main():
    if len(sys.argv) != 4:
        print("Usage: python3 rename_topic.py <metadata_dir> <old_slug> <new_slug>")
        sys.exit(1)
    meta_dir, old_slug, new_slug = sys.argv[1], sys.argv[2], sys.argv[3]

    changed = []
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        file_changed = False
        for sol in data.get('solutions', []):
            topics = to_list(sol.get('topics'))
            if old_slug in topics:
                sol['topics'] = [new_slug if t == old_slug else t for t in topics]
                file_changed = True

        if file_changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)
            changed.append(os.path.basename(fpath))

    print(f"✓ 已將 '{old_slug}' 改名為 '{new_slug}'，共 {len(changed)} 個檔案：")
    for f in changed:
        print(f"  {f}")

if __name__ == '__main__':
    main()
