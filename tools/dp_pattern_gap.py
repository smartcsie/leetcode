#!/usr/bin/env python3
"""
dp_pattern_gap.py

把 Dynamic Programming 拆成 13 個經典 pattern，比對 metadata/*.yml
裡已經收錄的題號，列出每個 pattern 底下「還沒收錄」的題目。

用法：
    python3 dp_pattern_gap.py [metadata_dir]

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

# (LeetCode 題號, 標題)
PATTERNS = {
    "Pattern 1: Linear DP (1D)": [
        (70, "Climbing Stairs"),
        (198, "House Robber"),
        (746, "Min Cost Climbing Stairs"),
        (139, "Word Break"),
        (91, "Decode Ways"),
        (213, "House Robber II"),
    ],
    "Pattern 2: Longest Increasing Subsequence (LIS)": [
        (300, "Longest Increasing Subsequence"),
        (673, "Number of Longest Increasing Subsequence"),
        (354, "Russian Doll Envelopes"),
        (646, "Maximum Length of Pair Chain"),
        (1964, "Find the Longest Valid Obstacle Course at Each Position"),
    ],
    "Pattern 3: Knapsack - 0/1": [
        (416, "Partition Equal Subset Sum"),
        (494, "Target Sum"),
        (1049, "Last Stone Weight II"),
        (474, "Ones and Zeroes"),
        (2035, "Partition Array Into Two Arrays to Minimize Sum Difference"),
    ],
    "Pattern 3: Knapsack - Unbounded": [
        (322, "Coin Change"),
        (518, "Coin Change 2"),
        (377, "Combination Sum IV"),
        (279, "Perfect Squares"),
        (983, "Minimum Cost For Tickets"),
    ],
    "Pattern 4: Grid DP": [
        (62, "Unique Paths"),
        (63, "Unique Paths II"),
        (64, "Minimum Path Sum"),
        (221, "Maximal Square"),
        (85, "Maximal Rectangle"),
        (931, "Minimum Falling Path Sum"),
        (1277, "Count Square Submatrices with All Ones"),
        (120, "Triangle"),
    ],
    "Pattern 5: String DP": [
        (1143, "Longest Common Subsequence"),
        (72, "Edit Distance"),
        (583, "Delete Operation for Two Strings"),
        (712, "Minimum ASCII Delete Sum for Two Strings"),
        (1092, "Shortest Common Supersequence"),
        (516, "Longest Palindromic Subsequence"),
        (5, "Longest Palindromic Substring"),
        (647, "Palindromic Substrings"),
        (10, "Regular Expression Matching"),
        (44, "Wildcard Matching"),
    ],
    "Pattern 6: Interval DP": [
        (312, "Burst Balloons"),
        (1039, "Minimum Score Triangulation of Polygon"),
        (1130, "Minimum Cost Tree From Leaf Values"),
        (96, "Unique Binary Search Trees"),
        (95, "Unique Binary Search Trees II"),
        (1000, "Minimum Cost to Merge Stones"),
        (375, "Guess Number Higher or Lower II"),
    ],
    "Pattern 7: State Machine DP": [
        (121, "Best Time to Buy and Sell Stock"),
        (122, "Best Time to Buy and Sell Stock II"),
        (123, "Best Time to Buy and Sell Stock III"),
        (188, "Best Time to Buy and Sell Stock IV"),
        (309, "Best Time to Buy and Sell Stock with Cooldown"),
        (714, "Best Time to Buy and Sell Stock with Transaction Fee"),
    ],
    "Pattern 8: Tree DP": [
        (337, "House Robber III"),
        (124, "Binary Tree Maximum Path Sum"),
        (543, "Diameter of Binary Tree"),
        (968, "Binary Tree Cameras"),
        (1373, "Maximum Sum BST in Binary Tree"),
        (2246, "Difference Between Maximum and Minimum Price Sum"),
    ],
    "Pattern 9: Digit DP": [
        (233, "Number of Digit One"),
        (357, "Count Numbers with Unique Digits"),
        (902, "Numbers At Most N Given Digit Set"),
        (1012, "Numbers With Repeated Digits"),
        (2376, "Count Special Integers"),
    ],
    "Pattern 10: Game Theory DP (Minimax)": [
        (486, "Predict the Winner"),
        (877, "Stone Game"),
        (1140, "Stone Game II"),
        (1406, "Stone Game III"),
        (464, "Can I Win"),
        (1510, "Stone Game IV"),
    ],
    "Pattern 11: Bitmask DP": [
        (698, "Partition to K Equal Sum Subsets"),
        (847, "Shortest Path Visiting All Nodes"),
        (943, "Find the Shortest Superstring"),
        (1125, "Smallest Sufficient Team"),
        (1434, "Number of Ways to Wear Different Hats to Each Other"),
        (1986, "Minimum Number of Work Sessions to Finish the Tasks"),
    ],
    "Pattern 12: DP on Subsequences": [
        (115, "Distinct Subsequences"),
        (940, "Distinct Subsequences II"),
        (446, "Arithmetic Slices II - Subsequence"),
        (1987, "Number of Unique Good Subsequences"),
        (1425, "Constrained Subsequence Sum"),
    ],
    "Pattern 13: Probability DP": [
        (688, "Knight Probability in Chessboard"),
        (808, "Soup Servings"),
        (837, "New 21 Game"),
        (1230, "Toss Strange Coins"),
        (1467, "Probability of a Two Boxes Having The Same Number of Distinct Balls"),
    ],
}


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
        missing = [(n, t) for n, t in problems if n not in collected]
        total_all += len(problems)
        total_missing += len(missing)

        done = len(problems) - len(missing)
        print(f"\n{pattern}  ({done}/{len(problems)} 已收錄)")
        if not missing:
            print("   ✅ 全部收錄")
            continue
        for n, t in missing:
            print(f"   ❌ {n:>5}  {t}  https://leetcode.com/problems/{t.lower().replace(' ', '-').replace(':', '')}/")

    print(f"\n{'=' * 60}")
    print(f"總計：{total_all - total_missing}/{total_all} 已收錄，還缺 {total_missing} 題")


if __name__ == '__main__':
    main()
