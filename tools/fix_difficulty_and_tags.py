#!/usr/bin/env python3
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

DIFFICULTY_MAP = {
    '簡單 (Easy)': '🟢 Easy',
    '中等 (Medium)': '🟡 Medium',
    '困難 (Hard)': '🔴 Hard',
}

def to_list(value):
    if value is None:
        return []
    if isinstance(value, str):
        return [value]
    return list(value)

def full_labelize(slug):
    return ' '.join(w.capitalize() for w in slug.split('-'))

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    fixed_difficulty = []
    fixed_tags = []
    skipped_difficulty = []

    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        changed = False
        number = data.get('number')

        for sol in data.get('solutions', []):
            old_diff = sol.get('difficulty', '')
            if old_diff in DIFFICULTY_MAP:
                sol['difficulty'] = DIFFICULTY_MAP[old_diff]
                changed = True
                fixed_difficulty.append((number, old_diff, sol['difficulty']))
            elif old_diff == '待補充' or not old_diff:
                skipped_difficulty.append((number, old_diff))

            tags = to_list(sol.get('tags'))
            if not tags:
                topics = to_list(sol.get('topics'))
                if topics:
                    derived = full_labelize(topics[0])
                    sol['tags'] = [derived]
                    changed = True
                    fixed_tags.append((number, derived))

        if changed:
            with open(fpath, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"✓ 修正難度格式 {len(fixed_difficulty)} 筆：")
    for num, old, new in fixed_difficulty:
        print(f"  {num}: '{old}' -> '{new}'")

    print(f"\n✓ 補上預設標籤 {len(fixed_tags)} 筆：")
    for num, tag in fixed_tags:
        print(f"  {num}: 標籤補為 '{tag}'（建議之後用工具精修）")

    if skipped_difficulty:
        print(f"\n⚠️ 有 {len(skipped_difficulty)} 筆難度真的是空的/待補充，需要你手動確認：")
        for num, diff in skipped_difficulty:
            print(f"  {num}: 目前難度為 {diff!r}")

if __name__ == '__main__':
    main()
