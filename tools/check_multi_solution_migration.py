#!/usr/bin/env python3
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

EXPECTED = {
    78: ['Solution_0078.cpp', 'Solution_0078_1.cpp'],
    90: ['Solution_0090.cpp', 'Solution_90.cpp'],
    94: ['Solution_0094.cpp', 'Solution_0094_1.cpp'],
    137: ['Solution_0137.cpp', 'Solution_0137_1.cpp'],
    144: ['Solution_0144.cpp', 'Solution_0144_1.cpp'],
    145: ['Solution_0145.cpp', 'Solution_0145_1.cpp'],
    217: ['Solution_0217.cpp', 'Solution_0217_1.cpp', 'Solution_0217_2.cpp', 'Solution_0217_3.cpp'],
    268: ['Solution_0268.cpp', 'Solution_0268_2.cpp'],
    300: ['Solution_0300.cpp', 'Solution_0300_1.cpp'],
    392: ['Solution_0392.cpp', 'Solution_0392_1.cpp'],
    648: ['Solution_0648_1.cpp', 'Solution_0648_2.cpp'],
    674: ['Solution_0674.cpp', 'Solution_0674_1.cpp'],
    1588: ['Solution_1588.cpp', 'Solution_1588_1.cpp'],
    2441: ['Solution_2441.cpp', 'Solution_2441_1.cpp'],
    2605: ['Solution_2605.cpp', 'Solution_2605_1.cpp', 'Solution_2605_2.cpp', 'Solution_2605_3.cpp'],
    3483: ['Solution_3483.cpp', 'Solution_3483_1.cpp'],
}

def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    solution_dir = sys.argv[2] if len(sys.argv) > 2 else 'solution'

    fully_ok = []
    missing_files = []
    missing_metadata = []

    for num, expected_files in EXPECTED.items():
        meta_path = os.path.join(meta_dir, f"{num:04d}.yml")

        if not os.path.exists(meta_path):
            missing_metadata.append((num, expected_files))
            continue

        with open(meta_path, 'r', encoding='utf-8') as f:
            data = yaml.safe_load(f)
        current_solution_files = set(s.get('file', '') for s in data.get('solutions', []))

        missing = [f for f in expected_files if f not in current_solution_files]

        if missing:
            missing_files.append((num, missing, sorted(current_solution_files)))
        else:
            fully_ok.append(num)

    print(f"✅ 已完整搬移（{len(fully_ok)} 題）：{fully_ok}\n")

    if missing_files:
        print(f"⚠️ metadata 存在，但缺少部分解法變體（{len(missing_files)} 題）：")
        for num, missing, current in missing_files:
            print(f"  {num}: 缺少 {missing}，目前已有 {current}")
        print()

    if missing_metadata:
        print(f"❌ 完全找不到 metadata（{len(missing_metadata)} 題）：")
        for num, expected in missing_metadata:
            print(f"  {num}: 預期應有 {expected}")

if __name__ == '__main__':
    main()
