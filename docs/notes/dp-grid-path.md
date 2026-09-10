# DP Grid Path 筆記

**核心遞迴**：`dp[i][j]` 只依賴「正上方」`dp[i-1][j]` 和「左方」
`dp[i][j-1]`（或加上「左上方」`dp[i-1][j-1]`），因為在網格上只能往
右、往下移動，狀態轉移方向天生固定。

| # | 題目 | 轉移公式 | 備註 |
|---|---|---|---|
| 63 | Unique Paths II | `dp[i][j]=dp[i-1][j]+dp[i][j-1]`（有障礙物則為0） | 計數型 |
| 64 | Minimum Path Sum | `dp[i][j]=grid[i][j]+min(dp[i-1][j], dp[i][j-1])` | 最值型 |
| 85 | Maximal Rectangle | 逐行轉直方圖 + Largest Rectangle in Histogram | 降維成一維問題重複求解 |
| 120 | Triangle | `dp[j]=triangle[i][j]+min(dp[j], dp[j+1])`（由下往上） | 由下往上推比由上往下更簡潔 |
| 221 | Maximal Square | `dp[i][j]=min(上,左,左上)+1`（取三者最小值） | 正方形要三個方向都滿足，取最小 |
| 931 | Minimum Falling Path Sum | `dp[j]=matrix[i][j]+min(上方三格)` | 允許左下、正下、右下三個方向 |
| 1277 | Count Square Submatrices with All Ones | 跟 221 同一個轉移式，只是計數不是求最大 | dp值本身就是「以此為右下角的正方形數量」 |

## 容易搞混的地方

- **221 跟 1277 的轉移式幾乎一樣**：221 要的是「最大邊長」（取
  min+1 後跟全域最大值比較），1277 要的是「總數」（把每個位置的
  dp 值直接加總，因為 dp[i][j] 本身就代表「以這裡為右下角，能組成
  幾個正方形」）。
- **85 是這個分類裡最特殊的一題**：本質是把二維問題拆解成「逐行
  維護一個直方圖，每行都做一次一維的 Largest Rectangle in
  Histogram」，不是單純的二維 DP 轉移，用到單調堆疊技巧。
- **由上往下 vs 由下往上**：大部分網格 DP 是由上往下推（起點在左上、
  終點在右下），但 120 Triangle 由下往上推反而更簡潔（不用處理
  「每列長度不同」的邊界問題）。
