# dp-interval

## 🔴 生疏（6）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 95 | [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/) | 🟡 Medium | Dp Interval | [C++](../problems/0095.md) | O(Catalan(N) \* N) | O(Catalan(N) \* N) |
| 312 | [Burst Balloons](https://leetcode.com/problems/burst-balloons/) | 🔴 Hard | Dp Interval | [C++](../problems/0312.md) | O(N³) | O(N²) |
| 375 | [Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/) | 🟡 Medium | Dp Interval | [C++](../problems/0375.md) | O(N³) | O(N²) |
| 1000 | [Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/) | 🔴 Hard | Dp Interval | [C++](../problems/1000.md) | O(N³ / K) | O(N²) |
| 1039 | [Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/) | 🟡 Medium | Dp Interval | [C++](../problems/1039.md) | O(N³) | O(N²) |
| 1130 | [Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) | 🟡 Medium | Dp Interval | [C++](../problems/1130.md) | O(N³) | O(N²) |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（0）

目前沒有標記為練習過的解法。

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。

---

# DP Interval 筆記

**核心遞迴**：`dp[i][j]` 代表「區間 [i,j]」的最佳解，狀態轉移要枚舉
一個切割點 `k`，把區間拆成 `[i,k]` 和 `[k,j]`（或 `[k+1,j]`）兩段，
`dp[i][j] = 合併(dp[i][k], dp[k][j]) + 額外成本`。一定要**按區間長度
由小到大**遞推，確保算大區間時，所有更短的子區間都已經算好。

| # | 題目 | 切割邏輯 | 備註 |
|---|---|---|---|
| 95 | Unique Binary Search Trees II | 枚舉根節點，左右子樹遞迴列舉 | Catalan number 結構，回傳的是「所有可能」不是單一值 |
| 96 | Unique Binary Search Trees | 跟 95 同結構，只是計數不是列舉 | 曾誤放在籠統 dynamic-programming，已修正 |
| 312 | Burst Balloons | 枚舉「最後戳破」的氣球（反向思考） | 逆向思考是這題的關鍵：想「最後戳誰」而非「先戳誰」 |
| 375 | Guess Number Higher or Lower II | 枚舉這輪猜的數字，`k+max(左,右)` | 同時是 Minimax（跟 Game Theory 有交集，但轉移結構是標準區間切割） |
| 1000 | Minimum Cost to Merge Stones | 枚舉切割點，且要跳 K-1 格 | 多了「每次固定合併K堆」的限制，是這組最難的一題 |
| 1039 | Minimum Score Triangulation of Polygon | 枚舉第三個頂點 k，組三角形 | 跟 312 是同一種「枚舉關鍵點」思路 |
| 1130 | Minimum Cost Tree From Leaf Values | 枚舉切割點，搭配預處理的區間最大值 | 需要先算好 maxVal[i][j] 才能O(1)查詢 |

## 容易搞混的地方

- **312 Burst Balloons 的逆向思考**：直覺會想「先戳哪個」，但這樣
  邊界會一直變動；反過來想「這個區間裡最後戳破的是誰」，戳它的時候
  左右鄰居都還沒被戳破、邊界固定，子問題才會獨立。
- **1000 Minimum Cost to Merge Stones 的切割點要跳格**：因為每次
  合併固定要湊滿 K 堆，切割點 `mid` 要以 `K-1` 為步長跳著枚舉，不是
  逐一枚舉，還要另外判斷「這個區間長度是否恰好能合併成 1 堆」才能
  加上這次合併的成本。
- **95 跟 96 是同一個遞迴結構的兩種用法**：95 要「列舉」所有樹（回傳
  vector<TreeNode*>），96 只要「計數」（回傳 int），95 因此需要記憶化
  避免重複建構同一批子樹，96 則是單純的數字遞推。
- **375 同時符合兩種分類直覺**：轉移結構是標準的區間切割（該分類在
  這裡），但決策邏輯是 Minimax 對抗（也可以理解成 Game Theory），
  分類時選了「轉移結構」優先，因為狀態定義本身就是二維區間。
