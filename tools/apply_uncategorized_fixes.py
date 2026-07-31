#!/usr/bin/env python3
import sys
import os

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

FIXES = {
    532: 'hash-table-counting',
    1022: 'tree-dfs-path',
    1422: 'array-linear-scan',
    1567: 'dynamic-programming',
    1593: 'backtracking-combination',
    1738: 'prefix-sum',
    2044: 'bit-bitmask-subset-enumeration',
    2176: 'array-linear-scan',
    2210: 'array-continuous-counting',
    2570: 'two-pointers-same',
    2656: 'greedy',
    2974: 'array-linear-scan',
    3514: 'bit-manipulation-xor',
    3754: 'math-digit-decomposition',
}

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    applied = []
    missing = []

    for num, new_topic in FIXES.items():
        path = os.path.join(meta_dir, f"{num:04d}.yml")
        if not os.path.exists(path):
            missing.append(num)
            continue

        with open(path, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)

        changed = False
        for sol in data.get('solutions', []):
            topics = sol.get('topics') or []
            if isinstance(topics, str):
                topics = [topics]
            if 'uncategorized' in topics:
                new_topics = [new_topic if t == 'uncategorized' else t for t in topics]
                sol['topics'] = new_topics
                changed = True

        if changed:
            with open(path, 'w', encoding='utf-8') as f:
                yaml.dump(data, f, allow_unicode=True, sort_keys=False)
            applied.append((num, new_topic))

    print(f"✓ 已套用 {len(applied)} 筆：")
    for num, topic in applied:
        print(f"  {num:04d} -> {topic}")

    if missing:
        print(f"\n⚠️ 找不到檔案（{len(missing)} 筆）：")
        for num in missing:
            print(f"  {num:04d}")

if __name__ == '__main__':
    main()
