# dp-fibonacci

## 🔴 生疏（14）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 官方解答 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 E | Dp Fibonacci | [C++](../problems/0070.md) | O(N) | O(1) |  |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 E | Dp Fibonacci, Dynamic Programming Fibonacci | [C++](../problems/0070.md) | O(N) | O(N) |  |
| 91 | [Decode Ways](https://leetcode.com/problems/decode-ways/) | 🟡 M | Dp Fibonacci | [C++](../problems/0091.md) | O(N) | O(N) |  |
| 198 | [House Robber](https://leetcode.com/problems/house-robber/) | 🟡 M | Dp Fibonacci | [C++](../problems/0198.md) | O(N) | O(1) |  |
| 198 | [House Robber](https://leetcode.com/problems/house-robber/) | 🟡 M | Dp Fibonacci | [C++](../problems/0198.md) | O(N) | O(N) |  |
| 213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | 🟡 M | Dp Fibonacci | [C++](../problems/0213.md) | O(N) | O(1) |  |
| 213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | 🟡 M | Dp Fibonacci | [C++](../problems/0213.md) | O(N) | O(N) |  |
| 509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 E | Dynamic Programming, Dynamic Programming Fibonacci | [C++](../problems/0509.md) | O(N) | O(1) |  |
| 509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 E | Dynamic Programming Fibonacci | [C++](../problems/0509.md) | O(N) | O(N) |  |
| 746 | [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) | 🟢 E | Dp Fibonacci | [C++](../problems/0746.md) | O(N) | O(N) |  |
| 746 | [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) | 🟢 E | Dp Fibonacci | [C++](../problems/0746.md) | O(N) | O(1) |  |
| 1137 | [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | 🟢 E | Dp Fibonacci, Dynamic Programming Fibonacci, DP | [C++](../problems/1137.md) | O(N) | O(1) |  |
| 1137 | [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | 🟢 E | Dp Fibonacci, Dynamic Programming Fibonacci | [C++](../problems/1137.md) | O(N) | O(N) |  |
| 2266 | [Count Number of Texts](https://leetcode.com/problems/count-number-of-texts/) | 🟡 M | Dp Fibonacci | [C++](../problems/2266.md) | O(N) | O(最長連續按鍵長度) | ❌ 官方沒有解答 |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（0）

目前沒有標記為練習過的解法。

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。

---

# DP Fibonacci 筆記

**核心遞迴**：`dp[i]` 只依賴**前 1~2 個狀態**，跟費氏數列 `f(i)=f(i-1)+f(i-2)`
是同一個骨架。這是所有 DP pattern 裡最簡單的一種，通常可以用滾動變數
把空間壓到 O(1)。

| # | 題目 | 轉移公式 | 備註 |
|---|---|---|---|
| 70 | Climbing Stairs | `dp[i]=dp[i-1]+dp[i-2]` | 最單純的原型題 |
| 91 | Decode Ways | `dp[i]=dp[i-1]*(合法)+dp[i-2]*(合法)` | 多了「合法性檢查」（單一數字/兩位數字是否落在 1~26） |
| 198 | House Robber | `dp[i]=max(dp[i-1], dp[i-2]+nums[i])` | 「選或不選」型，選了就要跳過相鄰 |
| 213 | House Robber II | 拆成兩次 198（頭尾環狀，分別排除頭或尾跑一次） | 環狀陣列的標準拆解手法 |
| 509 | Fibonacci Number | `f(i)=f(i-1)+f(i-2)` | 費氏數列本尊 |
| 746 | Min Cost Climbing Stairs | `dp[i]=min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])` | 70 的加權版 |
| 1137 | N-th Tribonacci Number | `dp[i]=dp[i-1]+dp[i-2]+dp[i-3]` | 三項遞迴，同一家族的延伸 |
| 2266 | Count Number of Texts | 分組後對每組做「1~limit 位」的線性 DP | 換皮版 91，limit 依按鍵種類是 3 或 4 |

## 容易搞混的地方

- **213 House Robber II**：不是直接對環狀陣列做 DP，而是拆成「排除
  最後一個」「排除第一個」兩個線性子問題各跑一次 198，取較大值——
  這個「拆環成鏈」的手法在其他環狀陣列題目也很常見。
- **2266**：題目分類容易誤判成 Backtracking（因為原始出處把它跟一堆
  回溯題放在一起），但實際上完全沒有用到「選擇 + 遞迴 + 復原」的
  結構，是純線性 DP，只是「一次可以吃 1~limit 位」取代了「一次吃
  1~2 位」。
- **91 Decode Ways**：轉移時不是單純 `dp[i-1]+dp[i-2]`，要先檢查
  「這位數字自己合不合法（不為 0）」「跟前一位組成兩位數合不合法
  （10~26）」，只有合法的部分才能加進轉移式，這是這題比 70 難的
  地方。
