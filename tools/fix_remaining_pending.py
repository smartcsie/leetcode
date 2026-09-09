#!/usr/bin/env python3
"""
fix_remaining_pending.py
修正剩餘 43 個含「待補充」的 .cpp 檔案。
用法：python3 tools/fix_remaining_pending.py
"""

import os
import re

BASE = "/home/laurence/leetcode-docs/repo/solution"

# (filename, 題目, 難度, 描述)
# None 表示該欄不需修改
STANDARD_FIXES = [
    ("Solution_0141.cpp", "141. Linked List Cycle",                    None,             "判斷鏈表中是否有環。"),
    ("Solution_0144_1.cpp","144. Binary Tree Preorder Traversal",      None,             "以前序（根→左→右）遍歷二元樹，回傳節點值序列。"),
    ("Solution_0167.cpp", "167. Two Sum II - Input Array Is Sorted",   None,             "在已排序的陣列中找出兩個數使其和等於 target，回傳兩者的索引（1-indexed）。"),
    ("Solution_0190.cpp", "190. Reverse Bits",                         None,             "反轉一個 32 位元無號整數的所有位元。"),
    ("Solution_0206.cpp", "206. Reverse Linked List",                  None,             "反轉一個鏈表，回傳新的頭節點。"),
    ("Solution_0217.cpp", "217. Contains Duplicate",                   "簡單 (Easy)",    "判斷陣列中是否有重複元素。"),
    ("Solution_0219.cpp", "219. Contains Duplicate II",                None,             "判斷陣列中是否存在兩個相同元素，其索引差不超過 k。"),
    ("Solution_0242.cpp", "242. Valid Anagram",                        None,             "判斷兩個字串是否為字母異位詞（組成字母完全相同）。"),
    ("Solution_0387.cpp", "387. First Unique Character in a String",   None,             "找出字串中第一個不重複的字元，回傳其索引；若不存在則回傳 -1。"),
    ("Solution_0448.cpp", "448. Find All Numbers Disappeared in an Array", "簡單 (Easy)", "找出 1 到 n 中所有在陣列裡消失的數字。"),
    ("Solution_0459.cpp", "459. Repeated Substring Pattern",           None,             "判斷字串是否可以由其子字串重複多次構成。"),
    ("Solution_0509.cpp", "509. Fibonacci Number",                     "簡單 (Easy)",    "計算第 n 個費氏數列的值。"),
    ("Solution_0563.cpp", "563. Binary Tree Tilt",                     None,             "計算二元樹所有節點的傾斜度總和，傾斜度定義為左右子樹節點值之和的絕對差。"),
    ("Solution_0572.cpp", "572. Subtree of Another Tree",              None,             "判斷一棵二元樹 subRoot 是否為另一棵二元樹 root 的子樹。"),
    ("Solution_0583.cpp", "583. Delete Operation for Two Strings",     None,             "找出使兩個字串相同所需的最少刪除次數。"),
    ("Solution_0977.cpp", "977. Squares of a Sorted Array",            "簡單 (Easy)",    "給定一個已排序的整數陣列，回傳每個元素的平方組成的新陣列，且新陣列也應為排序狀態。"),
    ("Solution_0141.cpp", "141. Linked List Cycle",                    None,             "判斷鏈表中是否有環。"),
]

# 只修正描述
DESCRIPTION_ONLY = {
    "Solution_0230.cpp": "在 BST 中找出第 k 小的元素。",
    "Solution_0637.cpp": "計算二元樹每層節點值的平均值，回傳所有層的平均值陣列。",
    "Solution_1002.cpp": "找出所有字串中共同出現的字元，包含重複字元。",
    "Solution_1008.cpp": "根據前序遍歷序列重建二元搜尋樹。",
    "Solution_1161.cpp": "找出二元樹中節點值總和最大的那一層，回傳層號（從 1 開始）。",
    "Solution_2574.cpp": "計算陣列中每個位置的左右前綴和差的絕對值。",
}

# 只修正難度
DIFFICULTY_ONLY = {
    "Solution_0318.cpp": "中等 (Medium)",
    "Solution_0986.cpp": "中等 (Medium)",
    "Solution_1342.cpp": "簡單 (Easy)",
    "Solution_1387.cpp": "中等 (Medium)",
    "Solution_1461.cpp": "中等 (Medium)",
    "Solution_1608.cpp": "中等 (Medium)",
    "Solution_2554.cpp": "中等 (Medium)",
}

# 「註解：待補充」舊格式，整段替換
LEGACY_FIXES = {
    "Solution_0199.cpp": (
        " * 註解：待補充",
        " * 題目：199. Binary Tree Right Side View\n * 難度：中等 (Medium)\n * 描述：從二元樹右側看，回傳從上到下每層最右邊可見的節點值。"
    ),
    "Solution_0231.cpp": (
        " * 註解：待補充",
        " * 題目：231. Power of Two\n * 難度：簡單 (Easy)\n * 描述：判斷一個整數是否為 2 的冪次方。"
    ),
    "Solution_0268.cpp": (
        " * 註解：待補充",
        " * 題目：268. Missing Number\n * 難度：簡單 (Easy)\n * 描述：給定一個包含 0 到 n 的陣列，找出缺少的那個數字。"
    ),
    "Solution_0326.cpp": (
        " * 註解：待補充",
        " * 題目：326. Power of Three\n * 難度：簡單 (Easy)\n * 描述：判斷一個整數是否為 3 的冪次方。"
    ),
    "Solution_0342.cpp": (
        " * 註解：待補充",
        " * 題目：342. Power of Four\n * 難度：簡單 (Easy)\n * 描述：判斷一個整數是否為 4 的冪次方。"
    ),
    "Solution_0344.cpp": (
        " * 註解：待補充",
        " * 題目：344. Reverse String\n * 難度：簡單 (Easy)\n * 描述：原地反轉字元陣列。"
    ),
    "Solution_0349.cpp": (
        " * 註解：待補充",
        " * 題目：349. Intersection of Two Arrays\n * 難度：簡單 (Easy)\n * 描述：找出兩個陣列的交集，結果中的每個元素只能出現一次。"
    ),
    "Solution_0706.cpp": (
        " * 註解：待補充",
        " * 題目：706. Design HashMap\n * 難度：簡單 (Easy)\n * 描述：不使用內建 hash map，自行設計實作一個 HashMap。"
    ),
    "Solution_1170.cpp": (
        " * 註解：待補充",
        " * 題目：1170. Compare Strings by Frequency of the Smallest Character\n * 難度：中等 (Medium)\n * 描述：定義 f(s) 為字串中最小字元的出現頻率，比較 queries 和 words 的 f 值大小，回傳每個 query 的 f 值嚴格小於幾個 words 的 f 值。"
    ),
    "Solution_1609.cpp": (
        " * 註解：待補充",
        " * 題目：1609. Even Odd Tree\n * 難度：中等 (Medium)\n * 描述：判斷二元樹是否為 Even-Odd 樹（奇數層嚴格遞增且為奇數，偶數層嚴格遞減且為偶數）。"
    ),
    "Solution_1886.cpp": (
        " * 註解：待補充",
        " * 題目：1886. Determine Whether Matrix Can Be Obtained By Rotation\n * 難度：簡單 (Easy)\n * 描述：判斷矩陣 mat 是否可以透過旋轉 0、90、180 或 270 度得到矩陣 target。"
    ),
    "Solution_2108.cpp": (
        " * 註解：待補充",
        " * 題目：2108. Find First Palindromic String in the Array\n * 難度：簡單 (Easy)\n * 描述：找出陣列中第一個回文字串，若不存在則回傳空字串。"
    ),
    "Solution_2248.cpp": (
        " * 註解：待補充",
        " * 題目：2248. Intersection of Multiple Arrays\n * 難度：簡單 (Easy)\n * 描述：找出所有陣列中共同出現的元素，回傳排序後的結果。"
    ),
    "Solution_2761.cpp": (
        " * 註解：待補充",
        " * 題目：2761. Prime Pairs With Target Sum\n * 難度：中等 (Medium)\n * 描述：找出所有和為 n 的質數配對 (x, y)，其中 x <= y。"
    ),
}


def fix_file(filepath, title=None, difficulty=None, description=None):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()
    original = content
    if title:
        content = content.replace(" * 題目：待補充", f" * 題目：{title}", 1)
    if difficulty:
        content = content.replace(" * 難度：待補充", f" * 難度：{difficulty}", 1)
    if description:
        content = content.replace(" * 描述：待補充", f" * 描述：{description}", 1)
    if content == original:
        return "skip"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    return "ok"


def fix_legacy(filepath, old, new):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()
    original = content
    content = content.replace(old, new, 1)
    if content == original:
        return "skip"
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    return "ok"


if __name__ == "__main__":
    ok = skip = not_found = 0
    seen = set()

    # 標準修正（題目/難度/描述）
    fixes = [
        ("Solution_0141.cpp",  "141. Linked List Cycle",                        None,          "判斷鏈表中是否有環。"),
        ("Solution_0144_1.cpp","144. Binary Tree Preorder Traversal",            None,          "以前序（根→左→右）遍歷二元樹，回傳節點值序列。"),
        ("Solution_0167.cpp",  "167. Two Sum II - Input Array Is Sorted",        None,          "在已排序的陣列中找出兩個數使其和等於 target，回傳兩者的索引（1-indexed）。"),
        ("Solution_0190.cpp",  "190. Reverse Bits",                              None,          "反轉一個 32 位元無號整數的所有位元。"),
        ("Solution_0206.cpp",  "206. Reverse Linked List",                       None,          "反轉一個鏈表，回傳新的頭節點。"),
        ("Solution_0217.cpp",  "217. Contains Duplicate",                        "簡單 (Easy)", "判斷陣列中是否有重複元素。"),
        ("Solution_0219.cpp",  "219. Contains Duplicate II",                     None,          "判斷陣列中是否存在兩個相同元素，其索引差不超過 k。"),
        ("Solution_0242.cpp",  "242. Valid Anagram",                             None,          "判斷兩個字串是否為字母異位詞（組成字母完全相同）。"),
        ("Solution_0387.cpp",  "387. First Unique Character in a String",        None,          "找出字串中第一個不重複的字元，回傳其索引；若不存在則回傳 -1。"),
        ("Solution_0448.cpp",  "448. Find All Numbers Disappeared in an Array",  "簡單 (Easy)", "找出 1 到 n 中所有在陣列裡消失的數字。"),
        ("Solution_0459.cpp",  "459. Repeated Substring Pattern",                None,          "判斷字串是否可以由其子字串重複多次構成。"),
        ("Solution_0509.cpp",  "509. Fibonacci Number",                          "簡單 (Easy)", "計算第 n 個費氏數列的值。"),
        ("Solution_0563.cpp",  "563. Binary Tree Tilt",                          None,          "計算二元樹所有節點的傾斜度總和，傾斜度定義為左右子樹節點值之和的絕對差。"),
        ("Solution_0572.cpp",  "572. Subtree of Another Tree",                   None,          "判斷一棵二元樹 subRoot 是否為另一棵二元樹 root 的子樹。"),
        ("Solution_0583.cpp",  "583. Delete Operation for Two Strings",          None,          "找出使兩個字串相同所需的最少刪除次數。"),
        ("Solution_0977.cpp",  "977. Squares of a Sorted Array",                 "簡單 (Easy)", "給定已排序的整數陣列，回傳每個元素平方後仍為排序狀態的新陣列。"),
    ]

    for filename, title, difficulty, description in fixes:
        filepath = os.path.join(BASE, filename)
        seen.add(filename)
        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}"); not_found += 1; continue
        result = fix_file(filepath, title, difficulty, description)
        print(f"[{'OK' if result=='ok' else 'SKIP'}]   {filename}")
        if result == "ok": ok += 1
        else: skip += 1

    # 只修描述
    for filename, description in DESCRIPTION_ONLY.items():
        filepath = os.path.join(BASE, filename)
        seen.add(filename)
        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}"); not_found += 1; continue
        result = fix_file(filepath, description=description)
        print(f"[{'OK' if result=='ok' else 'SKIP'}]   {filename}")
        if result == "ok": ok += 1
        else: skip += 1

    # 只修難度
    for filename, difficulty in DIFFICULTY_ONLY.items():
        filepath = os.path.join(BASE, filename)
        seen.add(filename)
        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}"); not_found += 1; continue
        result = fix_file(filepath, difficulty=difficulty)
        print(f"[{'OK' if result=='ok' else 'SKIP'}]   {filename}")
        if result == "ok": ok += 1
        else: skip += 1

    # 舊格式整段替換
    for filename, (old, new) in LEGACY_FIXES.items():
        filepath = os.path.join(BASE, filename)
        seen.add(filename)
        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}"); not_found += 1; continue
        result = fix_legacy(filepath, old, new)
        print(f"[{'OK' if result=='ok' else 'SKIP'}]   {filename}")
        if result == "ok": ok += 1
        else: skip += 1

    print(f"\n完成！OK:{ok}  SKIP:{skip}  NOT_FOUND:{not_found}")
