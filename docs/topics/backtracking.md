# backtracking

# Backtracking 分類總覽

## 判斷屬於哪一種回溯

拿到一題回溯，先問「狀態長什麼樣子」，決定子分類：

| 狀態的本質 | 子分類 | 判斷特徵 |
|---|---|---|
| 從候選清單裡「挑」一些出來（順序不重要） | `backtracking-combination` | 遞迴參數通常有一個 `start` 索引，只往後挑不往回挑 |
| 把「全部」候選排成一個順序（順序重要） | `backtracking-permutation` | 用 `used[]` 陣列標記誰用過，每層都要重新掃過全部候選 |
| 在二維座標網格上探路 | `backtracking-grid` | 狀態是「目前站在哪個座標」，上下左右四個方向遞迴，通常要「原地標記走過、回溯時復原」 |
| 每一步都要跟全域規則交叉檢查才能放 | `backtracking-constraint` | 不是單純檢查「這個位置合不合法」，而是要檢查跟盤面上其他位置的關係（同行、同列、同區塊） |

## 目前收錄狀況分類表

| 分類 | 題目 |
|---|---|
| `backtracking-combination` | 17、22、39、40、77、78、90、131、216、638、784、1255、1415、1593、2044 |
| `backtracking-permutation` | 46、47、526、1238、1947 |
| `backtracking-grid` | 79、980、1219 |
| `backtracking-constraint` | 37、51、2305 |

## 容易分錯的題目（判斷邏輯備忘）

- **79. Word Search**：一開始容易誤分到 `backtracking-combination`（因為
  是在字串裡找子字串的感覺），但實際上是在二維網格上 DFS 探路、原地
  標記走過的格子，屬於 `backtracking-grid`。
- **131. Palindrome Partitioning**：雖然是處理字串，但本質是「挑切割
  點組成一種切法」，跟 39/40 Combination Sum 系列同一個框架，屬於
  `backtracking-combination`，不是字串專屬的分類。
- **1238. Circular Permutation in Binary Representation**：字面上看
  起來像是位元運算題，但要求的是「生成一個排列」，本質屬於
  `backtracking-permutation`（雖然實際解法是格雷碼公式，不用真的
  回溯，但分類看的是「這題在解決什麼問題」，不是「用什麼演算法解」）。
- **1947. Maximum Compatibility Score Sum**：本質是「幫每個學生分配
  一個還沒被分配過的導師」，等價於排列導師的順序，屬於
  `backtracking-permutation`。
- **2044. Count Number of Maximum Bitwise-OR Subsets**：DFS 版本是
  標準「選或不選」回溯，屬於 `backtracking-combination`；但如果收錄
  的是用 mask 窮舉子集合的迭代版本，應該改分到
  `bit-bitmask-subset-enumeration`（技巧不同，即使問題一樣）。
- **2266. Count Number of Texts**：原始清單把它列在 Backtracking
  Level 1，但實際解法是純線性 DP（換皮版 91. Decode Ways），核心
  邏輯完全沒有用到回溯的「選擇 + 遞迴 + 復原」結構，正確分類是
  `dp-fibonacci`，不算進 backtracking 任何子分類。

## 常見的效能陷阱

- **去重邏輯**：`combination`/`permutation` 題目如果候選裡有重複值
  （例如 40 Combination Sum II、47 Permutations II、90 Subsets II），
  一定要先排序、再用 `if (i > start && nums[i] == nums[i-1]) continue;`
  這類判斷跳過重複分支，否則會產生大量重複的結果。
- **grid 題的原地標記**：`backtracking-grid` 常見手法是把走過的格子
  「原地改成障礙物」（例如設成 0 或 -1），遞迴完務必要復原，因為同一
  個座標可能在不同分支的路徑中被重複走到，不復原會讓其他分支誤判。
- **constraint 題的剪枝順序**：N-Queens、Sudoku Solver 這類題目，
  「檢查合法性」的時機（放置前檢查 vs 放置後遞迴才發現不合法再退回）
  對效能影響很大，優先選擇「放置前就先檢查會不會違反規則」，能省下
  大量不必要的遞迴呼叫。
