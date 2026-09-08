#!/usr/bin/env python3
"""
dump_flagged_solutions.py
把 check_topic_classification.py 標記的檔案內容輸出，方便複製給 Claude 確認分類。
用法：python3 tools/dump_flagged_solutions.py > flagged_dump.txt
"""

import os

BASE = "/home/laurence/leetcode-docs/repo/solution"

# (題號, 題目名稱, 檔案名稱, 目前 topics)
FLAGGED = [
    ("0015", "3Sum", "Solution_0015.cpp", "two-pointers-opposite"),
    ("0016", "3Sum Closest", "Solution_0016.cpp", "two-pointers-opposite"),
    ("0018", "4Sum", "Solution_0018.cpp", "two-pointers-opposite"),
    ("0019", "Remove Nth Node From End of List", "Solution_0019.cpp", "fast-slow-pointers"),
    ("0023", "Merge k Sorted Lists", "Solution_0023.cpp", "priority-queue"),
    ("0039", "Combination Sum", "Solution_0039.cpp", "backtracking-combination"),
    ("0040", "Combination Sum II", "Solution_0040.cpp", "backtracking-combination"),
    ("0047", "Permutations II", "Solution_0047.cpp", "backtracking-permutation"),
    ("0049", "Group Anagrams", "Solution_0049_1.cpp", "hash-table-mapping"),
    ("0056", "Merge Intervals", "Solution_0056.cpp", "array-interval"),
    ("0085", "Maximal Rectangle", "Solution_0085.cpp", "dp-grid-path"),
    ("0086", "Partition List", "Solution_0086.cpp", "two-pointers-same"),
    ("0090", "Subsets II", "Solution_0090.cpp", "bit-bitmask-subset-enumeration"),
    ("0095", "Unique Binary Search Trees II", "Solution_0095.cpp", "dp-interval"),
    ("0109", "Convert Sorted List to Binary Search Tree", "Solution_0109.cpp", "binary-search-tree"),
    ("0129", "Sum Root to Leaf Numbers", "Solution_0129.cpp", "tree-dfs-path"),
    ("0141", "Linked List Cycle", "Solution_0141.cpp", "fast-slow-pointers"),
    ("0142", "Linked List Cycle II", "Solution_0142.cpp", "fast-slow-pointers"),
    ("0147", "Insertion Sort List", "Solution_0147.cpp", "sorting"),
    ("0148", "Sort List", "Solution_0148.cpp", "sorting-implementation"),
    ("0160", "Intersection of Two Linked Lists", "Solution_0160.cpp", "two-pointers-other"),
    ("0217", "Contains Duplicate", "Solution_0217_2.cpp", "hash-table-uniqueness"),
    ("0217", "Contains Duplicate", "Solution_0217_3.cpp", "hash-table-uniqueness"),
    ("0220", "Contains Duplicate III", "Solution_0220.cpp", "fixed-size-sliding-window"),
    ("0239", "Sliding Window Maximum", "Solution_0239.cpp", "monotonic-queue"),
    ("0257", "Binary Tree Paths", "Solution_0257.cpp", "tree-dfs-path"),
    ("0328", "Odd Even Linked List", "Solution_0328.cpp", "two-pointers-same"),
    ("0337", "House Robber III", "Solution_337.cpp", "dp-tree"),
    ("0354", "Russian Doll Envelopes", "Solution_0354.cpp", "dp-lis"),
    ("0406", "Queue Reconstruction by Height", "Solution_0406.cpp", "greedy-sorting-decision"),
    ("0435", "Non-overlapping Intervals", "Solution_0435.cpp", "array-interval"),
    ("0437", "Path Sum III", "Solution_0437.cpp", "tree-dfs-path"),
    ("0445", "Add Two Numbers II", "Solution_0445.cpp", "stack"),
    ("0452", "Minimum Number of Arrows to Burst Balloons", "Solution_0452.cpp", "greedy-interval-scheduling"),
    ("0455", "Assign Cookies", "Solution_0455.cpp", "greedy-fractional-knapsack"),
    ("0462", "Minimum Moves to Equal Array Elements II", "Solution_0462.cpp", "greedy-parity-contribution"),
    ("0502", "IPO", "Solution_0502.cpp", "greedy-job-sequencing"),
    ("0611", "Valid Triangle Number", "Solution_0611.cpp", "two-pointers-opposite"),
    ("0611", "Valid Triangle Number", "Solution_0611_1.cpp", "binary-search-find-right-bound"),
    ("0630", "Course Schedule III", "Solution_0630.cpp", "greedy-job-sequencing"),
    ("0638", "Shopping Offers", "Solution_0638.cpp", "backtracking-combination"),
    ("0646", "Maximum Length of Pair Chain", "Solution_0646.cpp", "dp-lis"),
    ("0743", "Network Delay Time", "Solution_0743.cpp", "graph-shortest-path"),
    ("0767", "Reorganize String", "Solution_0767.cpp", "greedy-frequency-merging"),
    ("0778", "Swim in Rising Water", "Solution_0778.cpp", "greedy-graph"),
    ("0847", "Shortest Path Visiting All Nodes", "Solution_0847.cpp", "dp-bitmask"),
    ("0871", "Minimum Number of Refueling Stops", "Solution_0871.cpp", "greedy-fractional-knapsack"),
    ("0876", "Middle of the Linked List", "Solution_0876.cpp", "fast-slow-pointers"),
    ("0881", "Boats to Save People", "Solution_0881.cpp", "greedy-sorting-decision"),
    ("0899", "Orderly Queue", "Solution_0899.cpp", "greedy-string-construction"),
    ("0943", "Find the Shortest Superstring", "Solution_0943.cpp", "dp-bitmask"),
    ("0945", "Minimum Increment to Make Array Unique", "Solution_0945.cpp", "greedy-sorting-decision"),
    ("0949", "Largest Time for Given Digits", "Solution_0949.cpp", "math-permutation"),
    ("0968", "Binary Tree Cameras", "Solution_0968.cpp", "dp-tree"),
    ("0983", "Minimum Cost For Tickets", "Solution_0983.cpp", "dp-knapsack"),
    ("0988", "Smallest String Starting From Leaf", "Solution_0988.cpp", "tree-dfs-backtracking"),
    ("1005", "Maximize Sum Of Array After K Negations", "Solution_1005.cpp", "greedy-sorting-decision"),
    ("1019", "Next Greater Node In Linked List", "Solution_1019.cpp", "monotonic-stack"),
    ("1029", "Two City Scheduling", "Solution_1029.cpp", "greedy-priority-queue"),
    ("1092", "Shortest Common Supersequence", "Solution_1092.cpp", "dp-lcs"),
    ("1130", "Minimum Cost Tree From Leaf Values", "Solution_1130.cpp", "dp-interval"),
    ("1170", "Compare Strings by Frequency", "Solution_1170.cpp", "binary-search-build-in"),
    ("1288", "Remove Covered Intervals", "Solution_1288.cpp", "array-interval"),
    ("1373", "Maximum Sum BST in Binary Tree", "Solution_1373.cpp", "dp-tree"),
    ("1405", "Longest Happy String", "Solution_1405.cpp", "greedy-priority-queue"),
    ("1405", "Longest Happy String", "Solution_1405_1.cpp", "greedy-string-construction"),
    ("1467", "Probability of Two Boxes", "Solution_1467.cpp", "dp-probability"),
    ("1531", "String Compression II", "Solution_1531.cpp", "greedy-optimal-partitioning"),
    ("1584", "Minimum Cost to Connect All Points", "Solution_1584.cpp", "greedy-graph"),
    ("1608", "Special Array", "Solution_1608_1.cpp", "binary-search-on-answer"),
    ("1631", "Path With Minimum Effort", "Solution_1631.cpp", "greedy-graph"),
    ("1696", "Jump Game VI", "Solution_1696.cpp", "greedy-selection-constraints"),
    ("1710", "Maximum Units on a Truck", "Solution_1710.cpp", "greedy-sorting-decision"),
    ("1753", "Maximum Score From Removing Stones", "Solution_1753.cpp", "greedy-parity-contribution"),
    ("1770", "Maximum Score From Multiplication", "Solution_1770.cpp", "greedy-selection-constraints"),
    ("1851", "Minimum Interval to Include Each Query", "Solution_1851.cpp", "greedy-priority-queue"),
    ("1877", "Minimize Maximum Pair Sum", "Solution_1877.cpp", "two-pointers-opposite"),
    ("1930", "Unique Length-3 Palindromic Subsequences", "Solution_1930.cpp", "greedy"),
    ("1964", "Find the Longest Valid Obstacle Course", "Solution_1964.cpp", "dp-lis"),
    ("1984", "Minimum Difference Between Highest and Lowest", "Solution_1984.cpp", "fixed-size-sliding-window"),
    ("2035", "Partition Array Into Two Arrays", "Solution_2035.cpp", "dp-knapsack"),
    ("2044", "Count Number of Maximum Bitwise-OR Subsets", "Solution_2044_1.cpp", "bit-bitmask-subset-enumeration"),
    ("2094", "Finding 3-Digit Even Numbers", "Solution_2094.cpp", "hash-table-uniqueness"),
    ("2095", "Delete the Middle Node of a Linked List", "Solution_2095.cpp", "fast-slow-pointers"),
    ("2111", "Minimum Operations to Make the Array K-Increasing", "Solution_2111.cpp", "greedy-optimal-partitioning"),
    ("2130", "Maximum Twin Sum of a Linked List", "Solution_2130.cpp", "fast-slow-pointers"),
    ("2160", "Minimum Sum of Four Digit Number", "Solution_2160.cpp", "math-digit-decomposition"),
    ("2195", "Append K Integers With Minimal Sum", "Solution_2195.cpp", "binary-search-on-answer"),
    ("2208", "Minimum Operations to Halve Array Sum", "Solution_2208.cpp", "greedy-priority-queue"),
    ("2246", "Difference Between Maximum and Minimum Price Sum", "Solution_2246.cpp", "dp-tree"),
    ("2279", "Maximum Bags With Full Capacity of Rocks", "Solution_2279.cpp", "greedy-sorting-decision"),
    ("2441", "Largest Positive Integer That Exists With Its Negative", "Solution_2441_1.cpp", "two-pointers-swap"),
    ("2471", "Minimum Number of Operations to Sort a Binary Tree by Level", "Solution_2471.cpp", "sorting-cycle-decomposition"),
    ("2476", "Closest Nodes Queries in a Binary Search Tree", "Solution_2476.cpp", "binary-search-build-in"),
    ("2578", "Split With Minimum Sum", "Solution_2578.cpp", "greedy-digit-construction"),
    ("2807", "Insert Greatest Common Divisors in Linked List", "Solution_2807.cpp", "math-gcd"),
    ("2966", "Divide Array Into Arrays With Max Difference", "Solution_2966.cpp", "greedy-sorting-decision"),
    ("2974", "Minimum Number Game", "Solution_2974.cpp", "array-linear-scan"),
    ("3014", "Minimum Number of Pushes to Type Word I", "Solution_3014.cpp", "greedy-frequency-merging"),
    ("3364", "Minimum Positive Sum Subarray", "Solution_3364.cpp", "array-prefix-sum"),
    ("3867", "Sum of GCD of Formed Pairs", "Solution_3867.cpp", "math-gcd"),
]

if __name__ == "__main__":
    for number, title, filename, topics in FLAGGED:
        filepath = os.path.join(BASE, filename)
        print(f"// ===== {number} {title} | topics: {topics} | {filename} =====")
        if not os.path.exists(filepath):
            print(f"// [NOT FOUND]\n")
            continue
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            # 只輸出前 60 行，避免太長
            lines = f.readlines()
            for line in lines[:60]:
                print(line, end="")
        if len(lines) > 60:
            print(f"\n// ... (共 {len(lines)} 行，已截斷)")
        print()
