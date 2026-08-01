#!/usr/bin/env python3
import sys
import os

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

MOVES = {
    'design': [146, 155, 705, 2667],
    'math-game-theory': [292, 810, 1025, 1927, 3227, 3232],
    'math-geometry': [836, 1232],
}

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    applied = []
    missing = []

    for new_topic, numbers in MOVES.items():
        for num in numbers:
            path = os.path.join(meta_dir, f"{num:04d}.yml")
            if not os.path.exists(path):
                missing.append(num)
                continue

            with open(path, 'r', encoding='utf-8') as f:
                data = yaml.safe_load(f)

            changed = False
            for sol in data.get('solutions', []):
                sol['topics'] = [new_topic]
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
