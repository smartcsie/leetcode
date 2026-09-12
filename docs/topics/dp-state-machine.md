# dp-state-machine

## 🔴 生疏（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 123 | [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | 🔴 Hard | Dp State Machine | [C++](../problems/0123.md) | O(N) | O(1) |
| 188 | [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | 🔴 Hard | Dp State Machine | [C++](../problems/0188.md) | O(N\*K) | O(K) |
| 309 | [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | 🟡 Medium | Dp State Machine | [C++](../problems/0309.md) | O(N) | O(1) |
| 714 | [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | 🟡 Medium | Dp State Machine | [C++](../problems/0714.md) | O(N) | O(1) |
| 926 | [Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/) | 🟡 Medium | Dynamic Programming State Machine | [C++](../problems/0926.md) | O(N) | O(1) |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（2）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | 🟢 Easy | Dp State Machine, Dynamic Programming State Machine | [C++](../problems/0121.md) | O(N) | O(1) |
| 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | 🟡 Medium | Dp State Machine | [C++](../problems/0122.md) | O(N) | O(1) |

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。

---

# DP State Machine 筆記

**核心遞迴**：維護「目前處於哪個狀態」的多個變數（例如 持有股票/
沒持有股票），每一步根據輸入決定要不要切換狀態，切換有成本或有
限制。跟 Kadane 的差異是：Kadane 只有一條數值遞推，這裡要同時追蹤
**好幾個平行的狀態**。

| # | 題目 | 狀態 | 額外限制 |
|---|---|---|---|
| 121 | Best Time to Buy and Sell Stock | hold, cash | 只能交易一次 |
| 122 | Best Time to Buy and Sell Stock II | hold, cash | 無限次交易 |
| 123 | Best Time to Buy and Sell Stock III | buy1, sell1, buy2, sell2 | 最多兩次交易，四個狀態 |
| 188 | Best Time to Buy and Sell Stock IV | buy[i], sell[i]（陣列） | 123 的推廣，最多 k 次交易 |
| 309 | Best Time to Buy and Sell Stock with Cooldown | hold, sold, rest | 賣出後隔天強制冷卻 |
| 714 | Best Time to Buy and Sell Stock with Transaction Fee | hold, cash | 每次交易要扣手續費 |
| 926 | Flip String to Monotone Increasing | zeros, ones | 字串版本，狀態是「目前處於哪個階段」 |

## 容易搞混的地方

- **121 跟 122 的關鍵差異只在一行**：121（只能交易一次）
  `hold = max(hold, -price)`；122（無限次交易）
  `hold = max(hold, cash - price)`——差在買進的本錢能不能疊加前面
  已實現的利潤，這一行的差異決定了整個交易次數的限制。
- **309 冷卻邏輯要注意更新順序**：`sold` 依賴「前一天」的 `hold`，
  `rest` 依賴「前一天」的 `sold`，如果不先存一份 `prevSold` 就直接
  更新，會用到「今天已經算好的新值」造成邏輯錯誤。
- **714 初始化不能用 INT_MIN**：因為轉移式有 `-fee`，`INT_MIN + 負數`
  會整數下溢，要改用 `-prices[0]` 當初始值，迴圈從第二天開始跑。
- **188 是 123 的推廣**：123 把 k=2 直接展開成 4 個變數，188 用陣列
  `buy[]`、`sell[]` 支援任意 k，轉移式完全對應（`buy[i]` 依賴同一天
  的 `sell[i-1]`，更新順序要由小到大）。
- **926 是字串版的狀態機**：不是股票問題，但「目前是 zeros 階段還是
  ones 階段」的狀態切換邏輯跟股票的 hold/cash 是同一種形狀。
