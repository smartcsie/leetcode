#!/usr/bin/env python3
"""
fix_pending_comments.py
修正 .cpp 檔案中「待補充」的題目、難度、描述欄位。
用法：python3 tools/fix_pending_comments.py
"""

import os

BASE = "/home/laurence/leetcode-docs/repo/solution"

# filename -> {title, difficulty, description}
# 若某欄不需改，設為 None
FIXES = {
    "Solution_0027.cpp":  ("27. Remove Element (移除元素)",               "簡單 (Easy)",   "給定一個陣列 nums 和一個值 val，原地移除所有等於 val 的元素，回傳新長度。"),
    "Solution_0053.cpp":  ("53. Maximum Subarray (最大子陣列和)",           "中等 (Medium)", "找出具有最大和的連續子陣列，回傳其最大和。"),
    "Solution_0065.cpp":  (None,                                           "困難 (Hard)",   None),
    "Solution_0090_1.cpp":(None,                                           "中等 (Medium)", None),
    "Solution_0119.cpp":  ("119. Pascal's Triangle II",                    "簡單 (Easy)",   "給定一個非負索引 rowIndex，回傳楊輝三角形的第 rowIndex 行（索引從 0 開始）。"),
    "Solution_3637.cpp":  (None,                                           "簡單 (Easy)",   None),
    "Solution_3702.cpp":  (None,                                           "簡單 (Easy)",   None),
    "Solution_3783.cpp":  (None,                                           "簡單 (Easy)",   None),
    "Solution_3823.cpp":  (None,                                           "簡單 (Easy)",   None),
    "Solution_3838.cpp":  (None,                                           "簡單 (Easy)",   None),
    "Solution_3936.cpp":  (None,                                           "簡單 (Easy)",   None),
    "Solution_3986.cpp":  (None,                                           "簡單 (Easy)",   None),
    "Solution_3992.cpp":  (None,                                           "簡單 (Easy)",   None),
}

# 「註解：待補充」舊格式，整段替換成標準格式
LEGACY_FIXES = {
    "Solution_0066.cpp": (
        " * 註解：待補充\n * 時間複雜度：O(N)\n * 空間複雜度：O(1)\n\n */",
        " * 題目：66. Plus One (加一)\n * 難度：簡單 (Easy)\n * 描述：給定一個以整數陣列表示的非負整數，對其加一並回傳結果陣列。\n *\n * 時間複雜度：O(N)\n * 空間複雜度：O(1)\n *\n * 解法思路：\n * （模擬進位）：\n * 從最低位開始加 1，若有進位則繼續往前傳遞，若最高位仍有進位則在最前面插入 1。\n */"
    ),
    "Solution_0098.cpp": (
        " * 註解：待補充\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n\n */",
        " * 題目：98. Validate Binary Search Tree\n * 難度：中等 (Medium)\n * 描述：判斷一棵二元樹是否為合法的二元搜尋樹（BST）。\n *\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n *\n * 解法思路：\n * （遞迴傳遞上下界）：\n * 每個節點必須在 (min, max) 範圍內，左子樹上界為當前節點值，右子樹下界為當前節點值。\n */"
    ),
    "Solution_0100.cpp": (
        " * 註解：待補充\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n\n */",
        " * 題目：100. Same Tree\n * 難度：簡單 (Easy)\n * 描述：判斷兩棵二元樹是否完全相同（結構相同且對應節點值相同）。\n *\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n *\n * 解法思路：\n * （DFS 遞迴比較）：\n * 同時遍歷兩棵樹，若當前節點值相同則繼續比較左右子樹，任一不同則回傳 false。\n */"
    ),
    "Solution_0102.cpp": (
        " * 註解：待補充\n * 時間複雜度：O(N)\n * 空間複雜度：O(W)\n\n */",
        " * 題目：102. Binary Tree Level Order Traversal\n * 難度：中等 (Medium)\n * 描述：以層序（BFS）遍歷二元樹，回傳每層節點值組成的二維陣列。\n *\n * 時間複雜度：O(N)\n * 空間複雜度：O(W)\n *\n * 解法思路：\n * （BFS + Queue）：\n * 用 queue 做層序遍歷，每次處理完整的一層，把該層所有節點值收集後加入結果。\n */"
    ),
    "Solution_0110.cpp": (
        " * 註解：待補充\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n\n */",
        " * 題目：110. Balanced Binary Tree\n * 難度：簡單 (Easy)\n * 描述：判斷一棵二元樹是否為高度平衡的二元樹（每個節點左右子樹高度差不超過 1）。\n *\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n *\n * 解法思路：\n * （遞迴計算高度 + 判斷平衡）：\n * 對每個節點計算左右子樹高度，若差值超過 1 或子樹不平衡則回傳 false。\n */"
    ),
    "Solution_0111.cpp": (
        " * 註解：待補充\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n\n */",
        " * 題目：111. Minimum Depth of Binary Tree\n * 難度：簡單 (Easy)\n * 描述：找出二元樹從根節點到最近葉節點的最小深度。\n *\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n *\n * 解法思路：\n * （DFS 遞迴）：\n * 若只有一側子節點，強制往有子節點的那側走，避免把 null 誤認為葉節點。\n */"
    ),
    "Solution_0112.cpp": (
        " * 註解：待補充\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n\n */",
        " * 題目：112. Path Sum\n * 難度：簡單 (Easy)\n * 描述：判斷二元樹中是否存在一條從根節點到葉節點的路徑，使得路徑上所有節點值之和等於 targetSum。\n *\n * 時間複雜度：O(N)\n * 空間複雜度：O(H)\n *\n * 解法思路：\n * （DFS 遞迴，逐步減去當前節點值）：\n * 每次遞迴將 targetSum 減去當前節點值，到達葉節點時判斷剩餘值是否為 0。\n */"
    ),
}


def process_file(filepath, title, difficulty, description):
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


def process_legacy(filepath, old, new):
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

    for filename, (title, difficulty, description) in FIXES.items():
        filepath = os.path.join(BASE, filename)
        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}")
            not_found += 1
            continue
        result = process_file(filepath, title, difficulty, description)
        print(f"[{'OK' if result == 'ok' else 'SKIP'}]   {filename}")
        if result == "ok": ok += 1
        else: skip += 1

    for filename, (old, new) in LEGACY_FIXES.items():
        filepath = os.path.join(BASE, filename)
        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}")
            not_found += 1
            continue
        result = process_legacy(filepath, old, new)
        print(f"[{'OK' if result == 'ok' else 'SKIP'}]   {filename}")
        if result == "ok": ok += 1
        else: skip += 1

    print(f"\n完成！OK:{ok}  SKIP:{skip}  NOT_FOUND:{not_found}")
