#!/usr/bin/env python3
"""
insert_missing_comments.py
為缺少開頭 /** 註解的 .cpp 檔案插入完整註解。
用法：python3 insert_missing_comments.py
"""

import os

BASE = "/home/laurence/leetcode-docs/repo/solution"

COMMENTS = {
    "Solution_0026_1.cpp": """/**
 * 題目：26. Remove Duplicates from Sorted Array
 * 難度：簡單 (Easy)
 * 描述：移除排序陣列中的重複元素，回傳不重複元素的個數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （快慢指針）：
 * fast 往前跳過重複元素，找到不同值後與 slow+1 交換，slow 記錄有效元素的末端。
 */
""",
    "Solution_0049_1.cpp": """/**
 * 題目：49. Group Anagrams
 * 難度：中等 (Medium)
 * 描述：將字串陣列中互為字母異位詞的字串分組。
 *
 * 時間複雜度：O(N*KlogK)
 * 空間複雜度：O(N*K)
 *
 * 解法思路：
 * （排序作為 key）：
 * 將每個字串排序後作為 hash map 的 key，相同 key 的字串歸為同一組。
 */
""",
    "Solution_0053_1.cpp": """/**
 * 題目：53. Maximum Subarray
 * 難度：中等 (Medium)
 * 描述：找出具有最大和的連續子陣列，回傳其最大和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DP，dp[i] 代表以 i 結尾的最大子陣列和）：
 * dp[i] = max(nums[i], dp[i-1] + nums[i])，與 Kadane's Algorithm 等價但使用陣列。
 */
""",
    "Solution_0144_2.cpp": """/**
 * 題目：144. Binary Tree Preorder Traversal
 * 難度：簡單 (Easy)
 * 描述：以前序（根→左→右）遍歷二元樹，回傳節點值序列。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （迭代，Morris-like Stack）：
 * 用 stack 模擬遞迴，cur 指向當前節點，向左走時推入 stack，無左子節點時從 stack pop 轉向右子節點。
 */
""",
    "Solution_0151_1.cpp": """/**
 * 題目：151. Reverse Words in a String
 * 難度：中等 (Medium)
 * 描述：反轉字串中的單字順序，移除多餘空白。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （原地三步驟）：
 * 1. 快慢指針移除多餘空白。
 * 2. 反轉整個字串。
 * 3. 逐一反轉每個單字。
 */
""",
    "Solution_0189.cpp": """/**
 * 題目：189. Rotate Array
 * 難度：中等 (Medium)
 * 描述：將陣列向右旋轉 k 步。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （三次 Reverse）：
 * 1. 反轉整個陣列。
 * 2. 反轉前 k 個元素。
 * 3. 反轉剩餘元素。
 */
""",
    "Solution_0191_1.cpp": """/**
 * 題目：191. Number of 1 Bits
 * 難度：簡單 (Easy)
 * 描述：計算無號整數的二進位表示中 1 的個數（Hamming Weight）。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （C++20 std::popcount）：
 * 直接使用標準庫函式，對應 CPU 的 POPCNT 指令，最快速的寫法。
 */
""",
    "Solution_0198_1.cpp": """/**
 * 題目：198. House Robber
 * 難度：中等 (Medium)
 * 描述：不能搶相鄰房子的情況下，求能搶到的最大金額。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DP，dp[i] 代表搶到第 i 間房子時的最大金額）：
 * dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])，使用 dp 陣列版本。
 */
""",
    "Solution_0213_1.cpp": """/**
 * 題目：213. House Robber II
 * 難度：中等 (Medium)
 * 描述：房子排成環狀，不能搶相鄰房子，求能搶到的最大金額。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （拆成兩個線性 House Robber）：
 * 環狀問題拆成「搶第 0 到 n-2 間」和「搶第 1 到 n-1 間」兩個子問題取最大值。
 */
""",
    "Solution_0217_1.cpp": """/**
 * 題目：217. Contains Duplicate
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否有重複元素。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （unordered_set 去重）：
 * 把所有元素放入 unordered_set，若 set 大小小於原陣列大小，代表有重複。
 */
""",
    "Solution_0217_2.cpp": """/**
 * 題目：217. Contains Duplicate
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否有重複元素。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(logN)
 *
 * 解法思路：
 * （排序 + std::unique）：
 * 排序後用 unique 找到第一個重複元素的位置，若不在 end() 代表有重複。
 */
""",
    "Solution_0217_3.cpp": """/**
 * 題目：217. Contains Duplicate
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否有重複元素。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(logN)
 *
 * 解法思路：
 * （排序後檢查相鄰元素）：
 * 排序後，若有重複元素必然相鄰，逐一比較相鄰元素即可。
 */
""",
    "Solution_0235_1.cpp": """/**
 * 題目：235. Lowest Common Ancestor of a Binary Search Tree
 * 難度：中等 (Medium)
 * 描述：找出 BST 中兩個節點的最低公共祖先。
 *
 * 時間複雜度：O(H)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （迭代，利用 BST 性質）：
 * 若 p、q 都小於 root 往左走，都大於往右走，否則 root 就是 LCA。
 */
""",
    "Solution_0283_1.cpp": """/**
 * 題目：283. Move Zeroes
 * 難度：簡單 (Easy)
 * 描述：將所有 0 移到陣列末端，保持非零元素的相對順序。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （快慢指針 swap）：
 * fast 跳過 0，找到非零元素後與 slow 交換，slow 記錄下一個放置位置。
 */
""",
    "Solution_0287_1.cpp": """/**
 * 題目：287. Find the Duplicate Number
 * 難度：中等 (Medium)
 * 描述：找出陣列中重複的數字，不修改陣列且只用 O(1) 空間。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Negative Marking）：
 * 用負號標記已訪問過的 index，若發現對應位置已為負數，該 index+1 即為重複數字。
 */
""",
    "Solution_0342_1.cpp": """/**
 * 題目：342. Power of Four
 * 難度：簡單 (Easy)
 * 描述：判斷一個整數是否為 4 的冪次方。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （迴圈除以 4）：
 * 反覆除以 4，最後若等於 1 則是 4 的冪次方。
 */
""",
    "Solution_0342_2.cpp": """/**
 * 題目：342. Power of Four
 * 難度：簡單 (Easy)
 * 描述：判斷一個整數是否為 4 的冪次方。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （位元運算）：
 * 4 的冪次方必須是 2 的冪次方（只有一個 1 bit），且 n-1 必須能被 3 整除。
 */
""",
    "Solution_0404_1.cpp": """/**
 * 題目：404. Sum of Left Leaves
 * 難度：簡單 (Easy)
 * 描述：計算二元樹中所有左葉節點的值之和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （DFS，傳遞 left flag）：
 * 遞迴時傳入 bool left 標記當前節點是否為左子節點，遇到左葉節點時累加。
 */
""",
    "Solution_0461_1.cpp": """/**
 * 題目：461. Hamming Distance
 * 難度：簡單 (Easy)
 * 描述：計算兩個整數對應二進位位元不同的個數。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Brian Kernighan's Algorithm）：
 * XOR 找出不同位元，再用 n &= (n-1) 逐一消除最低位的 1 並計數。
 */
""",
    "Solution_0509_1.cpp": """/**
 * 題目：509. Fibonacci Number
 * 難度：簡單 (Easy)
 * 描述：計算第 n 個費氏數列的值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DP 陣列版）：
 * 用 dp 陣列存每個費氏數，dp[i] = dp[i-1] + dp[i-2]，空間可用滾動變數優化到 O(1)。
 */
""",
    "Solution_0557_1.cpp": """/**
 * 題目：557. Reverse Words in a String III
 * 難度：簡單 (Easy)
 * 描述：反轉字串中每個單字的字元順序，保持單字間的相對位置。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （找邊界後反轉）：
 * 遍歷字串，遇到空格或結尾時對 [start, i) 區間做 reverse。
 */
""",
    "Solution_0930_1.cpp": """/**
 * 題目：930. Binary Subarrays With Sum
 * 難度：中等 (Medium)
 * 描述：計算二進位陣列中和等於 goal 的子陣列個數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （前綴和 + 雙層迴圈）：
 * 計算前綴和，對每個 [i,j] 區間檢查 prefix[j+1] - prefix[i] == goal。
 */
""",
    "Solution_0930_2.cpp": """/**
 * 題目：930. Binary Subarrays With Sum
 * 難度：中等 (Medium)
 * 描述：計算二進位陣列中和等於 goal 的子陣列個數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （滑動視窗差分，atMost 技巧）：
 * 恰好等於 goal = 至多 goal 個 - 至多 goal-1 個，用滑動視窗計算至多 k 個 1 的子陣列數。
 */
""",
    "Solution_0938_1.cpp": """/**
 * 題目：938. Range Sum of BST
 * 難度：簡單 (Easy)
 * 描述：計算 BST 中所有值在 [low, high] 範圍內的節點值之和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （中序 DFS）：
 * 中序遍歷 BST，遇到值在範圍內的節點就累加，利用 BST 性質可剪枝。
 */
""",
    "Solution_0961_1.cpp": """/**
 * 題目：961. N-Repeated Element in Size 2N Array
 * 難度：簡單 (Easy)
 * 描述：在長度為 2N 的陣列中，有一個元素重複 N 次，找出該元素。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （unordered_set）：
 * 逐一插入 set，第一個插入失敗（已存在）的元素即為重複 N 次的元素。
 */
""",
    "Solution_1137_1.cpp": """/**
 * 題目：1137. N-th Tribonacci Number
 * 難度：簡單 (Easy)
 * 描述：計算第 n 個 Tribonacci 數列的值（前三項之和）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DP 陣列版）：
 * 用 dp 陣列存每個 Tribonacci 數，dp[i] = dp[i-1] + dp[i-2] + dp[i-3]。
 */
""",
    "Solution_1512_1.cpp": """/**
 * 題目：1512. Number of Good Pairs
 * 難度：簡單 (Easy)
 * 描述：計算陣列中 nums[i] == nums[j] 且 i < j 的配對數量。
 *
 * 時間複雜度：O(N^2)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （暴力雙層迴圈）：
 * 枚舉所有 (i, j) 配對，檢查是否相等，時間 O(N²)，可用 hash map 優化到 O(N)。
 */
""",
    "Solution_1608_1.cpp": """/**
 * 題目：1608. Special Array With X Elements Greater Than or Equal X
 * 難度：簡單 (Easy)
 * 描述：找出 x 使得陣列中恰好有 x 個元素大於或等於 x。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （排序 + Binary Search）：
 * 排序後對 x 做二分搜尋，用 lower_bound 計算大於等於 x 的元素數量是否等於 x。
 */
""",
    "Solution_1721_1.cpp": """/**
 * 題目：1721. Swapping Nodes in a Linked List
 * 難度：中等 (Medium)
 * 描述：交換鏈表中第 k 個和倒數第 k 個節點的值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （兩次遍歷）：
 * 第一次計算鏈表長度，第二次找到第 k 和倒數第 k 個節點，交換其值。
 */
""",
    "Solution_1790_1.cpp": """/**
 * 題目：1790. Check if One String Swap Can Make Strings Equal
 * 難度：簡單 (Easy)
 * 描述：判斷最多一次字元交換後兩字串是否相等。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （對撞雙指針）：
 * 找到第一個不同位置 left 和最後一個不同位置 right，交換後驗證是否相等。
 */
""",
    "Solution_2006.cpp": """/**
 * 題目：2006. Count Number of Pairs With Absolute Difference K
 * 難度：簡單 (Easy)
 * 描述：計算陣列中絕對差等於 k 的配對數量。
 *
 * 時間複雜度：O(N^2)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （暴力雙層迴圈）：
 * 枚舉所有 (i, j) 配對，檢查 abs(nums[i] - nums[j]) == k。
 */
""",
    "Solution_2485_1.cpp": """/**
 * 題目：2485. Find the Pivot Integer
 * 難度：簡單 (Easy)
 * 描述：找出 x 使得 1 到 x 的總和等於 x 到 n 的總和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （線性搜尋）：
 * 從 n/2 開始往上搜尋，利用等差數列公式驗證左右總和是否相等。
 */
""",
    "Solution_2605_1.cpp": """/**
 * 題目：2605. Form Smallest Number From Two Digit Arrays
 * 難度：簡單 (Easy)
 * 描述：從兩個陣列各取一個數字，組成最小的兩位數或一位數。
 *
 * 時間複雜度：O(N*M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （暴力雙層迴圈）：
 * 枚舉所有 (x, y) 組合，若相等取最小公共值，否則取兩種拼接方式的最小值。
 */
""",
    "Solution_2605_2.cpp": """/**
 * 題目：2605. Form Smallest Number From Two Digit Arrays
 * 難度：簡單 (Easy)
 * 描述：從兩個陣列各取一個數字，組成最小的兩位數或一位數。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （bitset 版）：
 * 用 bitset<10> 記錄兩陣列出現的數字，AND 找公共最小值，無公共值則取各自最小組合。
 */
""",
    "Solution_2605_3.cpp": """/**
 * 題目：2605. Form Smallest Number From Two Digit Arrays
 * 難度：簡單 (Easy)
 * 描述：從兩個陣列各取一個數字，組成最小的兩位數或一位數。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(M)
 *
 * 解法思路：
 * （unordered_set 版）：
 * 用 unordered_set 存 nums2，遍歷 nums1 找公共最小值，無公共值則取各自最小組合。
 */
""",
    "Solution_2785_1.cpp": """/**
 * 題目：2785. Sort Vowels in a String
 * 難度：中等 (Medium)
 * 描述：只對字串中的母音按 ASCII 排序，子音保持原位。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （收集母音排序後放回）：
 * 用 bitmask 0x104111 判斷母音，收集後排序，再依序放回原母音位置。
 */
""",
    "Solution_2864_1.cpp": """/**
 * 題目：2864. Maximum Odd Binary Number
 * 難度：簡單 (Easy)
 * 描述：重排二進位字串，使其為最大的奇數二進位數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （確保最低位為 1，其餘 1 移到最高位）：
 * 先將一個 1 移到最後一位，再將其餘的 1 都移到前面。
 */
""",
    "Solution_3513_1.cpp": """/**
 * 題目：3513. Number of Unique XOR Triplets I
 * 難度：中等 (Medium)
 * 描述：計算陣列中不同 XOR 三元組的數量。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （數學，答案為 2^(floor(log2(n))+1)）：
 * 用 log2 計算最高位，結果為 2 的冪次方。
 */
""",
    "Solution_3513_2.cpp": """/**
 * 題目：3513. Number of Unique XOR Triplets I
 * 難度：中等 (Medium)
 * 描述：計算陣列中不同 XOR 三元組的數量。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （位元左移找最小的 2 的冪次方大於 n）：
 * 從 1 開始不斷左移直到超過 n，即為答案，與 log2 版等價。
 */
""",
}

def insert_comment(filepath, comment):
    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    if content.strip().startswith("/**"):
        return "skip"

    new_content = comment + content

    with open(filepath, "w", encoding="utf-8") as f:
        f.write(new_content)

    return "ok"


if __name__ == "__main__":
    ok = skip = not_found = 0

    for filename, comment in COMMENTS.items():
        filepath = os.path.join(BASE, filename)

        if not os.path.exists(filepath):
            print(f"[NOT FOUND] {filename}")
            not_found += 1
            continue

        result = insert_comment(filepath, comment)

        if result == "ok":
            print(f"[OK]   {filename}")
            ok += 1
        elif result == "skip":
            print(f"[SKIP] {filename}  (已有註解)")
            skip += 1

    print(f"\n完成！OK:{ok}  SKIP:{skip}  NOT_FOUND:{not_found}")
