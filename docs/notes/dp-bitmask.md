# DP Bitmask 筆記

**核心概念**：用一個整數的每個 bit 代表「某個元素有沒有被用過/覆蓋
過」，狀態空間是 `2^N`（N 通常 <= 20），`dp[mask]` 或 `dp[mask][其他
維度]` 代表「用了 mask 這些元素」時的最佳解。

| # | 題目 | mask 代表什麼 | 備註 |
|---|---|---|---|
| 698 | Partition to K Equal Sum Subsets | 哪些數字被用掉 | dp值是「目前子集合的累積和 mod target」 |
| 847 | Shortest Path Visiting All Nodes | 哪些節點被拜訪過 | BFS（不是遞推表），狀態是(節點,mask) |
| 943 | Find the Shortest Superstring | 哪些字串被用過 | dp[mask][last] 是TSP變形，還要維護 last |
| 1125 | Smallest Sufficient Team | 哪些技能被涵蓋 | mask代表「技能」不是「人員」，dp值是「選了哪些人」 |
| 1434 | Number of Ways to Wear Different Hats to Each Other | 哪些人已戴上帽子 | 反過來以「帽子」為主軸逐一決定分配 |
| 1986 | Minimum Number of Work Sessions to Finish the Tasks | 哪些任務被完成 | 用子集合枚舉（sub-mask enumeration），不能逐一累加 |

## 容易搞混的地方

- **mask 代表的對象因題而異**：大部分題目 mask 代表「元素本身」
  （698、847、943、1986），但 1125 反過來讓 mask 代表「技能」（因為
  要覆蓋的是技能，不是人員本身），1434 則是用帽子當主軸逐一決定
  分配——遇到新題目要先想清楚「mask 該代表誰」。
- **1986 不能用「逐一累加任務」的方式做 DP**：必須用子集合枚舉
  （`for (sub=mask; sub>0; sub=(sub-1)&mask)`）才能保證涵蓋所有
  分組方式，逐一累加雖然某些測資能矇對，但不是嚴謹正確的做法。
- **943 需要處理「未計算」跟「合法值為0」搞混的陷阱**：dp 陣列的
  無效狀態要用明確小於任何合法值的哨兵（例如 `INT_MIN/2`），不能
  用 0 當哨兵，因為 0 本身可能是合法的重疊值。
- **1125、1434 曾經被誤放在 `dp-digit`**：雖然題目牽涉到位元概念，
  但核心技巧是 Bitmask DP，已修正到這裡，湊齊了 Bitmask DP 原始
  清單的全部 6 題。
