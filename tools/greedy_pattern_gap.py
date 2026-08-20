#!/usr/bin/env python3
"""
greedy_pattern_gap.py

把 Greedy 拆成 15 個常見 pattern（只取每個 pattern 的 Practice Problems，
Bonus Problems 沒收進來），比對 metadata/*.yml 裡已經收錄的題號，列出
每個 pattern 底下「還沒收錄」的題目。

用法：
    python3 greedy_pattern_gap.py [metadata_dir]

    metadata_dir  預設 'metadata'

注意：清單裡有 3 題我沒辦法很有信心地對到正確的 LeetCode 題號
（原始清單的標題可能跟 LeetCode 官方標題有出入，或是同一題在多個
pattern 裡出現用了不同名字），這幾題會印出 ⚠️ 提醒你自己確認，不會
被當成「還沒收錄」直接列出來：
    - Pattern 8: Least Interval（很可能跟 Task Scheduler 621 是同一題，
      但標題對不上任何 LeetCode 官方題目）
    - Pattern 11: Smallest Number at Given Digit Swaps（找不到對應的
      LeetCode 官方標題）
    - Pattern 14: Minimize Sum of Distances in Array（找不到對應的
      LeetCode 官方標題）

另外 Meeting Rooms（Pattern 1 Bonus 有出現過，但沒收進來這份清單）跟
Meeting Rooms II 是付費題（LeetCode Premium），如果沒有訂閱可能沒辦法
在網站上直接解，不確定的話自己斟酌要不要花時間補。
"""
import sys
import os
import glob

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

# (LeetCode 題號, 標題)，None 代表題號不確定，程式會跳過不列入統計
PATTERNS = {
    "Pattern 1: Interval Scheduling": [
        (435, "Non-overlapping Intervals"),
        (56, "Merge Intervals"),
        (253, "Meeting Rooms II"),  # LeetCode Premium
        (452, "Minimum Number of Arrows to Burst Balloons"),
        (57, "Insert Interval"),
    ],
    "Pattern 2: Fractional Knapsack": [
        (455, "Assign Cookies"),
        (135, "Candy"),
        (134, "Gas Station"),
        (871, "Minimum Number of Refueling Stops"),
        (2064, "Minimized Maximum of Products Distributed to Any Store"),
    ],
    "Pattern 3: Job Sequencing / Deadline Scheduling": [
        (630, "Course Schedule III"),
        (621, "Task Scheduler"),
        (502, "IPO"),
        (1029, "Two City Scheduling"),
        (871, "Minimum Number of Refueling Stops"),
    ],
    "Pattern 4: Frequency Merging / Huffman-Type Greedy": [
        (1167, "Minimum Cost to Connect Sticks"),
        (767, "Reorganize String"),
        (451, "Sort Characters By Frequency"),
        (1338, "Reduce Array Size to the Half"),
        (1296, "Divide Array in Sets of K Consecutive Numbers"),
    ],
    "Pattern 5: Coin Change (Greedy Variant)": [
        (860, "Lemonade Change"),
        (1210, "Minimum Moves to Reach Target With Rotations"),
        (2169, "Count Operations to Obtain Zero"),
        (1551, "Minimum Operations to Make Array Equal"),
        (1647, "Minimum Deletions to Make Character Frequencies Unique"),
    ],
    "Pattern 6: Sorting + Greedy Decision": [
        (406, "Queue Reconstruction by Height"),
        (881, "Boats to Save People"),
        (1029, "Two City Scheduling"),
        (1094, "Car Pooling"),
        (1710, "Maximum Units on a Truck"),
    ],
    "Pattern 7: Prefix/Suffix Greedy": [
        (55, "Jump Game"),
        (45, "Jump Game II"),
        (53, "Maximum Subarray"),
        (1653, "Minimum Deletions to Make String Balanced"),
        (763, "Partition Labels"),
    ],
    "Pattern 8: Priority Queue Greedy": [
        (621, "Task Scheduler"),
        (767, "Reorganize String"),
        (502, "IPO"),
        (846, "Hand of Straights"),
        (None, "Least Interval"),  # 找不到對應題號，可能跟 621 重複
    ],
    "Pattern 9: Greedy in Graph Algorithms": [
        (743, "Network Delay Time"),
        (1631, "Path With Minimum Effort"),
        (778, "Swim in Rising Water"),
        (1584, "Minimum Cost to Connect All Points"),
        (787, "Cheapest Flights Within K Stops"),
    ],
    "Pattern 10: Exchange Argument / Proof-Based Greedy": [
        (55, "Jump Game"),
        (134, "Gas Station"),
        (135, "Candy"),
        (53, "Maximum Subarray"),
        (1405, "Longest Happy String"),
    ],
    "Pattern 11: Greedy Digit / Number Construction": [
        (402, "Remove K Digits"),
        (738, "Monotone Increasing Digits"),
        (None, "Smallest Number at Given Digit Swaps"),  # 找不到對應題號
        (670, "Maximum Swap"),
        (556, "Next Greater Element III"),
    ],
    "Pattern 12: Greedy String Construction": [
        (316, "Remove Duplicate Letters"),
        (1081, "Smallest Subsequence of Distinct Characters"),
        (899, "Orderly Queue"),
        (1061, "Lexicographically Smallest Equivalent String"),
        (1405, "Longest Happy String"),
    ],
    "Pattern 13: Optimal Partitioning": [
        (763, "Partition Labels"),
        (1531, "String Compression II"),
        (1750, "Minimum Length of String After Deleting Similar Ends"),
        (2111, "Minimum Operations to Make the Array K-Increasing"),
        (410, "Split Array Largest Sum"),
    ],
    "Pattern 14: Greedy Based on Parity / Contribution": [
        (1005, "Maximize Sum of Array After K Negations"),
        (1877, "Minimize Maximum Pair Sum in Array"),
        (1753, "Maximum Score From Removing Stones"),
        (2208, "Minimum Operations to Halve Array Sum"),
        (None, "Minimize Sum of Distances in Array"),  # 找不到對應題號
    ],
    "Pattern 15: Greedy Selection With Constraints": [
        (1770, "Maximum Score From Performing Multiplication Operations"),
        (1696, "Jump Game VI"),
        (2279, "Maximum Bags With Full Capacity of Rocks"),
        (1593, "Split a String Into the Max Number of Unique Substrings"),
        (1392, "Longest Happy Prefix"),
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
    for pattern, problems in PATTERNS.items():
        known = [(n, t) for n, t in problems if n is not None]
        unknown = [t for n, t in problems if n is None]

        missing = [(n, t) for n, t in known if n not in collected]
        total_all += len(known)
        total_missing += len(missing)

        done = len(known) - len(missing)
        print(f"\n{pattern}  ({done}/{len(known)} 已收錄"
              f"{f'，另有 {len(unknown)} 題題號不確定未列入統計' if unknown else ''})")
        if not missing:
            print("   ✅ 全部收錄")
        for n, t in missing:
            print(f"   ❌ {n:>5}  {t}  https://leetcode.com/problems/{slugify_title(t)}/")
        for t in unknown:
            print(f"   ⚠️  題號不確定：{t}（自己確認一下是不是想指其他題）")

    print(f"\n{'=' * 60}")
    print(f"總計：{total_all - total_missing}/{total_all} 已收錄，還缺 {total_missing} 題"
          f"（不含題號不確定的題目）")


if __name__ == '__main__':
    main()
