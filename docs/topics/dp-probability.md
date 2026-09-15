# dp-probability

## 🔴 生疏（4）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 688 | [Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/) | 🟡 Medium | Dp Probability | [C++](../problems/0688.md) | O(K | O(N²) |  |
| 808 | [Soup Servings](https://leetcode.com/problems/soup-servings/) | 🟡 Medium | Dp Probability | [C++](../problems/0808.md) | O((N/25)²) | O((N/25)²) |  |
| 837 | [New 21 Game](https://leetcode.com/problems/new-21-game/) | 🟡 Medium | Dp Probability | [C++](../problems/0837.md) | O(N) | O(N) |  |
| 1467 | [Probability of a Two Boxes Having The Same Number of Distinct Balls](https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/) | 🔴 Hard | Dp Probability | [C++](../problems/1467.md) | O(∏(balls[i]+1)) | O(K) |  |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（0）

目前沒有標記為練習過的解法。

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。

---

# DP Probability 筆記

**核心特徵**：`dp` 存的是「機率值」（浮點數），不是計數或最優值。
狀態轉移通常是把機率**乘上**分支機率，再加總所有可能的路徑。

| # | 題目 | 狀態 | 備註 |
|---|---|---|---|
| 688 | Knight Probability in Chessboard | `dp[r][c]`：目前這步停在(r,c)的機率 | 8個方向各自機率1/8，逐步走k次 |
| 808 | Soup Servings | `dp(a,b)`：A先用完的機率 | 記憶化搜尋，把毫升數壓縮成25的倍數 |
| 837 | New 21 Game | `dp[i]`：分數曾經停在i的機率 | 滑動視窗優化，避免O(N*maxPts) |
| 1467 | Probability of a Two Boxes Having The Same Number of Distinct Balls | 非遞推型，用DFS窮舉+組合數學 | 分子分母都要另外算，不是單純的機率遞推 |

## 容易搞混的地方

- **1467 不是傳統的「機率遞推」DP**，是這個分類裡的異類：用 DFS
  枚舉每種顏色球的分配方式，权重是組合數 `C(balls[i], x)`，分子
  （合法分配的權重總和）除以分母（`C(total, total/2)`，所有分法
  總數）才是最終機率。
- **808 需要邊界優化避免超時**：當 n 很大時，A 用完的機率會趨近 1，
  可以直接設一個閾值（例如 n>=4800）回傳 1.0，避免對超大的 n 做
  遞迴。
- **837 的滑動視窗要注意「什麼時候該加減」**：`windowSum` 只在
  `i<k`（還在抽牌階段）時累加新的 dp 值，`i-maxPts` 對應的分數
  如果也 `<k` 才需要扣掉——因為 >=k 的分數已經停牌了，不會再被
  當作「來源」延伸。
- **688 每一步都是「機率往外分散」，不是「機率往內累積」**：從目前
  格子出發，把機率平均分給 8 個方向，跟一般 DP「從別的狀態轉移進來」
  的方向相反，要用 `next[nr][nc] += dp[r][c]/8.0` 這種寫法。
