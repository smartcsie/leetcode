# dp-knapsack

## 🔴 生疏（3）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 139 | [Word Break](https://leetcode.com/problems/word-break/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](../problems/0139.md) | O(N³) | O(N) |
| 983 | [Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](../problems/0983.md) | O(D log D) | O(D) |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/) | 🔴 Hard | Dp Knapsack, 0-1 Knapsack | [C++](../problems/2035.md) | O(N \* 2^(N/2)) | O(2^(N/2)) |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（9）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](../problems/0279.md) | O(N\*√N) | O(N) |
| 322 | [Coin Change](https://leetcode.com/problems/coin-change/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](../problems/0322.md) | O(A\*N) | O(A) |
| 377 | [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](../problems/0377.md) | O(A\*N) | O(A) |
| 416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | 🟡 Medium | Dp Knapsack, 0-1 Knapsack | [C++](../problems/0416.md) | O(N\*S) | O(NS) |
| 474 | [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeros/) | 🟡 Medium | Dp Knapsack, 0-1 Knapsack | [C++](../problems/0474.md) | O(LM\*N) | O(M\*N) |
| 494 | [Target Sum](https://leetcode.com/problems/target-sum/) | 🟡 Medium | Dp Knapsack, 0-1 Knapsack | [C++](../problems/0494.md) | O(N\*S) | O(S) |
| 518 | [Coin Change II](https://leetcode.com/problems/coin-change-ii/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](../problems/0518.md) | O(N\*A) | O(A) |
| 1049 | [Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/) | 🟡 Medium | 0-1 Knapsack | [C++](../problems/1049.md) | O(N\*S) | O(S) |
| 2707 | [Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](../problems/2707.md) | O(N³) | O(N+D) |

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。

---

# Knapsack 背包問題分類筆記

**核心判斷**：先分清楚 **0/1（每個物品限用一次）** 還是
**Unbounded（可以無限次使用）**，這個判斷決定了「內層容量迴圈要不要
反過來跑」——這是背包問題最容易出錯、也最該優先確認的地方。

| # | 題目 | 類型 | 問法 | 迴圈順序 |
|---|---|---|---|---|
| 39 | Combination Sum | Unbounded | 組合 | 外層容量，內層物品 |
| 139 | Word Break | Unbounded | 排列 | 外層容量，內層物品 |
| 279 | Perfect Squares | Unbounded | 最值（最小） | 外層容量，內層物品 |
| 322 | Coin Change | Unbounded | 最值（最小） | 外層容量，內層物品 |
| 377 | Combination Sum IV | Unbounded | 排列 | 外層容量，內層物品 |
| 416 | Partition Equal Subset Sum | 0/1 | 判斷 | 外層物品，內層容量從大到小 |
| 474 | Ones and Zeroes | 0/1 | 最值（最大） | 外層物品，內層容量從大到小 |
| 494 | Target Sum | 0/1 | 計數 | 外層物品，內層容量從大到小 |
| 518 | Coin Change II | Unbounded | 組合 | 外層物品，內層容量從小到大 |
| 638 | Shopping Offers | 0/1 變體 | 最值（最小） | 外層物品，內層容量從大到小 |
| 983 | Minimum Cost For Tickets | Unbounded | 最值（最小） | 外層容量，內層物品 |
| 1049 | Last Stone Weight II | 0/1 | 最值（最大） | 外層物品，內層容量從大到小 |
| 2035 | Partition Array Into Two Arrays | 0/1 | 最值（最小） | 外層物品，內層容量從大到小 |
| 2707 | Extra Characters in a String | Unbounded | 最值（最小） | 外層容量，內層物品 |

## 為什麼迴圈順序這麼重要

- **0/1 背包，內層容量要從大到小**：因為一維滾動陣列時，`dp[cap]`
  要參考「還沒被這一輪物品更新過」的 `dp[cap-weight]`，如果從小到大
  跑，會讓同一個物品被誤用兩次以上（等於變成 Unbounded 背包）。
- **Unbounded 背包，內層容量從小到大**（或外層容量、內層物品）：
  因為允許同一物品重複使用，`dp[cap]` 本來就該參考「這一輪已經更新
  過」的 `dp[cap-weight]`，讓同一物品能被連續疊加多次。
- **外層容量 vs 外層物品，決定的是「排列」還是「組合」**：外層跑
  容量、內層跑物品 → 每個容量下會把所有物品的排列組合都算進去
  （適合「排列」類問題，例如 139、377）；外層跑物品、內層跑容量 →
  物品的相對順序固定，不會重複算出「先選A再選B」跟「先選B再選A」
  兩種情況（適合「組合」類問題，例如 518）。

## 容易搞混的地方

- **638 Shopping Offers**：表面上是回溯（遞迴 + 記憶化），但本質是
  「每個優惠可以重複使用」的 Unbounded 背包變形，物品是「優惠組合」
  不是單一物品，容量是「還需要的商品數量」（多維度）。
- **2707 跟 139 Word Break 同一個轉移結構**：都是「逐一嘗試字典裡
  的單字/子字串當作結尾」，只是 2707 多了「允許 k 個字元不在字典
  裡」的容錯額度。
- **96、337、2707 曾經被誤放在籠統的 `dynamic-programming`**，之後
  分別修正到 `dp-interval`（96，Catalan number 結構）、`dp-tree`
  （337，跟 968/1373/2246 同組）、`dp-knapsack`（2707，跟 139 同
  轉移結構）。
