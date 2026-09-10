# DP LIS 筆記

**核心遞迴**：`dp[i]` 代表「以 nums[i] 結尾」的最長遞增子序列長度，
`dp[i] = 1 + max(dp[j])`（對所有 `j<i` 且 `nums[j]<nums[i]`）。標準版
O(N²)；用「Patience Sorting」（維護 tails 陣列 + 二分搜）可以優化到
O(N log N)。

| # | 題目 | 做法 | 備註 |
|---|---|---|---|
| 300 | Longest Increasing Subsequence | O(N²) DP 或 O(N log N) patience sorting | 原型題，兩種複雜度都該會 |
| 354 | Russian Doll Envelopes | 排序（寬升冪、同寬高降冪）後對高度做 LIS | 二維降成一維的排序技巧是關鍵 |
| 646 | Maximum Length of Pair Chain | 排序後套用跟 LIS 一樣的轉移式 | O(N²) 版本邏輯直接對應 LIS |
| 673 | Number of Longest Increasing Subsequence | 額外維護 `count[i]`，長度打平就累加 | 求數量，不只是長度 |
| 1964 | Find the Longest Valid Obstacle Course at Each Position | Patience sorting，允許相等（用 upper_bound） | 求「每個位置」的答案，不是只求全域最大值 |
| 2826 | Sorting Three Groups | 本質是求最長不遞減子序列 | 換皮題，看穿本質就是 LIS |

## 容易搞混的地方

- **允許相等 vs 嚴格遞增**：標準 LIS 是嚴格遞增，用 `lower_bound`；
  如果題目允許非遞減（例如 1964），要改用 `upper_bound`，這個差異
  很容易漏掉。
- **354 排序時「同寬高要降冪」**：這是這題最容易出錯的地方——如果
  同寬也用升冪排序，會誤判成「同寬的信封可以互相嵌套」，必須讓
  同寬的信封在排序後彼此不會被誤選進遞增子序列。
- **673 的「打平」判斷**：`len[j]+1 == len[i]` 時要把 `count[j]`
  累加進 `count[i]`（多一種達到同樣長度的方式）；`len[j]+1 > len[i]`
  時才是真的找到更長路徑，要重設 `count[i] = count[j]`，這兩種情況
  不能搞混。
- **O(N log N) 版本不保證陣列內容是真正的 LIS**：`tails` 陣列只是
  用來快速算出「長度」，裡面存的值不代表真正的最長遞增子序列本身，
  只是用來輔助二分搜。
