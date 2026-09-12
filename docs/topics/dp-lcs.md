# dp-lcs

## 🔴 生疏（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 97 | [Interleaving String](https://leetcode.com/problems/interleaving-string/) | 🟡 Medium | Dynamic Programming Lcs, Two Strings | [C++](../problems/0097.md) | O(M \* N) | O(M \* N) |
| 115 | [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) | 🔴 Hard | Dynamic Programming Lcs, DP | [C++](../problems/0115.md) | O(S\*T) | O(T) |
| 712 | [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) | 🟡 Medium | Dynamic Programming Lcs, String | [C++](../problems/0712.md) | O(M×N) | O(M×N) |
| 1092 | [Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/) | 🔴 Hard | Dynamic Programming Lcs | [C++](../problems/1092.md) | O(N\*M) | O(N\*M) |
| 1312 | [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) | 🔴 Hard | Dynamic Programming Lcs | [C++](../problems/1312.md) | O(N²) | O(N²) |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 72 | [Edit Distance](https://leetcode.com/problems/edit-distance/) | 🟡 Medium | Dp Lcs, Dynamic Programming Lcs, DP | [C++](../problems/0072.md) | O(N\*M) | O(N\*M) |
| 583 | [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) | 🟡 Medium | Dynamic Programming Lcs | [C++](../problems/0583.md) | O(M\*N) | O(M\*N) |
| 718 | [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) | 🟡 Medium | Dp Lcs | [C++](../problems/0718.md) | O(N\*M) | O(M) |
| 1035 | [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/) | 🟡 Medium | Dynamic Programming Lcs, DP, LCS | [C++](../problems/1035.md) | O(N\*M) | O(M) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 Medium | Dp Lcs, Dynamic Programming Lcs | [C++](../problems/1143.md) | O(M\*N) | O(M\*N) |

## 🟣 易忘（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | 🟢 Easy | Dp Lcs, Dynamic Programming Lcs, DP, LCS | [C++](../problems/0392.md) | O(S\*T) | O(S\*T) |

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。

---

# DP LCS 筆記

**核心遞迴**：兩個序列/字串**同時往前走**的二維 DP，狀態是 `dp[i][j]`
（第一個序列前 i 個 vs 第二個序列前 j 個）。核心判斷永遠是「這兩個
位置的字元對不對得上」：對得上就 `dp[i-1][j-1]+1` 往右下角斜移；
對不上就要在「刪/插/替換」之間選一個方向轉移。

| # | 題目 | 轉移邏輯 | 備註 |
|---|---|---|---|
| 72 | Edit Distance | 對得上 `dp[i-1][j-1]`；對不上 `1+min(刪,插,替換)` | 三種操作都要考慮 |
| 97 | Interleaving String | `dp[i][j]` 是否能同時消耗兩個來源字串拼出目標 | 是/否判斷，不是求最佳值 |
| 115 | Distinct Subsequences | 對得上時累加兩條路徑（用/不用這個字元） | 計數型，不是找最長 |
| 392 | Is Subsequence | 雙指標即可解，是 LCS 家族裡的簡化特例 | O(N) 不用真的做二維 DP |
| 516 | Longest Palindromic Subsequence | 轉換成 `s` 跟 `reverse(s)` 求 LCS | 迴文子序列本質是 LCS 的應用 |
| 583 | Delete Operation for Two Strings | 用 LCS 長度反推：`m+n-2*LCS` | 只能刪不能插/替換，比 72 簡化 |
| 712 | Minimum ASCII Delete Sum for Two Strings | 跟 583 同邏輯，但用 ASCII 值加總取代次數 | 583 的加權版 |
| 1035 | Uncrossed Lines | 本質就是標準 LCS，換了個「畫線不交叉」的包裝 | 完全等價於 1143 |
| 1092 | Shortest Common Supersequence | 先求 LCS，再用 LCS 反推出完整字串 | 求的是字串本身，不只是長度 |
| 1143 | Longest Common Subsequence | `dp[i][j]=dp[i-1][j-1]+1`（對得上）；`max(上,左)`（對不上） | 原型題 |
| 1312 | Minimum Insertion Steps to Make a String Palindrome | 跟 516 同邏輯：`n - LCS(s, reverse(s))` | 只能插入，用 LCS 反推最少插入次數 |

## 容易搞混的地方

- **對不上時的轉移方向不只一種**：1143（純找最長子序列）對不上時是
  `max(dp[i-1][j], dp[i][j-1])`；72（編輯距離）對不上時是
  `1+min(刪,插,替換)`——差別在於題目允不允許「主動修改」，不能只套
  同一個模板。
- **516、1312 都是「跟自己的反轉版本做 LCS」**：這是迴文相關題目的
  萬用技巧——迴文子序列＝原字串跟反轉字串的最長公共子序列。
- **10、44（Regex/Wildcard Matching）不屬於這裡**：雖然也是兩個字串
  同時往前走的二維 DP，但轉移邏輯是「字元比對規則」（`.`、`*` 的
  特殊語意），不是「找共同子序列」，分類獨立在 `dp-string`。
