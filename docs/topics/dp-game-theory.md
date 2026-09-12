# dp-game-theory

## 🔴 生疏（6）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 464 | [Can I Win](https://leetcode.com/problems/can-i-win/) | 🟡 Medium | Dp Game Theory | [C++](../problems/0464.md) | O(2^N \* N) | O(2^N) |
| 486 | [Predict the Winner](https://leetcode.com/problems/predict-the-winner/) | 🟡 Medium | Dp Game Theory | [C++](../problems/0486.md) | O(N²) | O(N²) |
| 877 | [Stone Game](https://leetcode.com/problems/stone-game/) | 🟡 Medium | Dp Game Theory | [C++](../problems/0877.md) | O(N²) | O(N²) |
| 1140 | [Stone Game II](https://leetcode.com/problems/stone-game-ii/) | 🟡 Medium | Dp Game Theory | [C++](../problems/1140.md) | O(N³) | O(N²) |
| 1406 | [Stone Game III](https://leetcode.com/problems/stone-game-iii/) | 🔴 Hard | Dp Game Theory | [C++](../problems/1406.md) | O(N) | O(N) |
| 1510 | [Stone Game IV](https://leetcode.com/problems/stone-game-iv/) | 🔴 Hard | Dp Game Theory | [C++](../problems/1510.md) | O(N \* √N) | O(N) |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（0）

目前沒有標記為練習過的解法。

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。

---

# DP Game Theory 筆記

**核心建模技巧**：`dp` 不是直接記錄「誰的分數是多少」，而是記錄
**「先手玩家分數 - 後手玩家分數」的最大值**（分數差）。這樣定義的
好處是不用額外追蹤「現在輪到誰」，因為每個子問題裡「先手」永遠是指
「目前正在做選擇的那個人」。

| # | 題目 | 狀態 | 決策範圍 |
|---|---|---|---|
| 464 | Can I Win | Bitmask（哪些數字被選過） | 每次選一個還沒選過的數字 |
| 486 | Predict the Winner | `dp[i][j]`（區間） | 拿左端或右端 |
| 877 | Stone Game | `dp[i][j]`（區間） | 跟 486 完全同結構，只是判斷條件從 >=0 改成 >0 |
| 1140 | Stone Game II | `dp(i, M)`（位置+參數） | 拿 1~2M 堆，記憶化搜尋 |
| 1406 | Stone Game III | `dp[i]`（一維，只能從前面拿） | 拿 1~3 堆 |
| 1510 | Stone Game IV | `dp[i]`（一維布林） | 拿完全平方數顆石頭 |

## 容易搞混的地方

- **「分數差」建模是這整個分類的核心，記不住這招會很難下手**：
  `dp[i][j] = max(拿左端: nums[i]-dp[i+1][j], 拿右端: nums[j]-dp[i][j-1])`
  ——拿了之後，對手在子區間裡的分數差要「取負號」，因為角色互換
  了（對手在子區間裡變成「先手」）。
- **486 跟 877 幾乎是同一支程式碼**：唯一差別是最後的判斷條件
  （486 問「不會輸」用 `>=0`；877 問「嚴格獲勝」用 `>0`）。
- **1140 不是「分數差」建模，是直接算「能拿到的石頭數」**：因為
  這題的狀態還包含一個會變動的參數 M，用記憶化搜尋（不是遞推表）
  比較自然，直接算「目前這位玩家能拿多少」，靠 `suffix[i] - 對手
  拿到的量` 反推出自己的量。
- **1406、1510 只能從單一方向拿（不是雙端夾）**：狀態只需要一維
  `dp[i]`，比 486/877 的二維區間簡單，因為少了「可以選左也可以選
  右」的維度。
- **375（Guess Number Higher or Lower II）技術上也是 Minimax**，但
  因為狀態定義是標準的二維區間切割，分類上歸進 `dp-interval`，不在
  這裡重複列出。
