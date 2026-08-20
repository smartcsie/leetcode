#!/usr/bin/env python3
"""
backtracking_gap.py

把 Backtracking 拆成 Level 1 / Level 2 兩個難度層級，比對 metadata/*.yml
裡已經收錄的題號，列出還沒收錄的題目。

用法：
    python3 backtracking_gap.py [metadata_dir]

    metadata_dir  預設 'metadata'
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

LEVELS = {
    "Level 1": [
        (46, "Permutations"),
        (47, "Permutations II"),
        (77, "Combinations"),
        (39, "Combination Sum"),
        (40, "Combination Sum II"),
        (216, "Combination Sum III"),
        (78, "Subsets"),
        (90, "Subsets II"),
        (131, "Palindrome Partitioning"),
        (22, "Generate Parentheses"),
        (79, "Word Search"),
        (638, "Shopping Offers"),
        (2266, "Count Number of Texts"),
        (17, "Letter Combinations of a Phone Number"),
    ],
    "Level 2": [
        (51, "N-Queens"),
        (37, "Sudoku Solver"),
        (784, "Letter Case Permutation"),
        (1219, "Path with Maximum Gold"),
        (526, "Beautiful Arrangement"),
        (2305, "Fair Distribution of Cookies"),
        (1980, "Find Unique Binary String"),
        (980, "Unique Paths III"),
        (1947, "Maximum Compatibility Score Sum"),
        (1255, "Maximum Score Words Formed by Letters"),
        (1238, "Circular Permutation in Binary Representation"),
        (1415, "The k-th Lexicographical String of All Happy Strings of Length n"),
    ],
}


def slugify_title(title):
    return title.lower().replace(' ', '-')


def load_collected_numbers(meta_dir):
    numbers = set()
    for fpath in sorted(glob.glob(os.path.join(meta_dir, '*.yml'))):
        with open(fpath, encoding='utf-8') as f:
            data = yaml.safe_load(f)
        if data and data.get('number') is not None:
            numbers.add(int(data['number']))
    return numbers


def main():
    meta_dir = sys.argv[1] if len(sys.argv) > 1 else 'metadata'
    if not os.path.isdir(meta_dir):
        print(f"❌ 找不到資料夾: {meta_dir}")
        sys.exit(1)

    collected = load_collected_numbers(meta_dir)

    total_missing = 0
    total_all = 0
    for level, problems in LEVELS.items():
        missing = [(n, t) for n, t in problems if n not in collected]
        total_all += len(problems)
        total_missing += len(missing)

        done = len(problems) - len(missing)
        print(f"\n{level}  ({done}/{len(problems)} 已收錄)")
        if not missing:
            print("   ✅ 全部收錄")
            continue
        for n, t in missing:
            print(f"   ❌ {n:>5}  {t}  https://leetcode.com/problems/{slugify_title(t)}/")

    print(f"\n{'=' * 60}")
    print(f"總計：{total_all - total_missing}/{total_all} 已收錄，還缺 {total_missing} 題")


if __name__ == '__main__':
    main()
