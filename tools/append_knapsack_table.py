#!/usr/bin/env python3
"""
append_knapsack_table.py
在 dp-knapsack.md 最底下加入 Knapsack 總整理表格。
用法：python3 tools/append_knapsack_table.py
"""

import os

FILEPATH = "/home/laurence/leetcode-docs/repo/docs/topics/dp-knapsack.md"

TABLE = """
---

## 📊 Knapsack 總整理

| # | 題目 | 類型 | 問法 | 迴圈順序 |
|---|---|---|---|---|
| 0039 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | Unbounded | 組合 | 外層容量，內層物品 |
| 0139 | [Word Break](https://leetcode.com/problems/word-break/) | Unbounded | 排列 | 外層容量，內層物品 |
| 0279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares/) | Unbounded | 最值（最小） | 外層容量，內層物品 |
| 0322 | [Coin Change](https://leetcode.com/problems/coin-change/) | Unbounded | 最值（最小） | 外層容量，內層物品 |
| 0377 | [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) | Unbounded | 排列 | 外層容量，內層物品 |
| 0416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | 0/1 | 判斷 | 外層物品，內層容量從大到小 |
| 0474 | [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/) | 0/1 | 最值（最大） | 外層物品，內層容量從大到小 |
| 0494 | [Target Sum](https://leetcode.com/problems/target-sum/) | 0/1 | 計數 | 外層物品，內層容量從大到小 |
| 0518 | [Coin Change II](https://leetcode.com/problems/coin-change-ii/) | Unbounded | 組合 | 外層物品，內層容量從小到大 |
| 0638 | [Shopping Offers](https://leetcode.com/problems/shopping-offers/) | 0/1 變體 | 最值（最小） | 外層物品，內層容量從大到小 |
| 0983 | [Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/) | Unbounded | 最值（最小） | 外層容量，內層物品 |
| 1049 | [Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/) | 0/1 | 最值（最大） | 外層物品，內層容量從大到小 |
| 2035 | [Partition Array Into Two Arrays](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/) | 0/1 | 最值（最小） | 外層物品，內層容量從大到小 |
| 2707 | [Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/) | Unbounded | 最值（最小） | 外層容量，內層物品 |

### 快速記憶

```
Unbounded（物品可重複）：
  排列 / 最值  → 外層容量，內層物品
  組合（518）  → 外層物品，內層容量從小到大（例外）

0/1（物品只用一次）：
  全部         → 外層物品，內層容量從大到小
```
"""

if __name__ == "__main__":
    if not os.path.exists(FILEPATH):
        print(f"[NOT FOUND] {FILEPATH}")
        exit(1)

    with open(FILEPATH, "r", encoding="utf-8") as f:
        content = f.read()

    if "Knapsack 總整理" in content:
        print("[SKIP] 已有總整理表格")
        exit(0)

    with open(FILEPATH, "a", encoding="utf-8") as f:
        f.write(TABLE)

    print(f"[OK] 已在 {FILEPATH} 最底下加入 Knapsack 總整理表格")
