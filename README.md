# LeetCode 演算法精鍊筆記 (C++)

![LeetCode Stats](https://leetcard.jacoblin.cool/laurence?theme=nord) <!-- 註：將 laurence 換成你的 LeetCode ID -->

本倉庫用於記錄我的 LeetCode 解題過程、思路分析以及演算法優化心得。作為一名專注於 ADAS 模擬與感知系統的工程師，我習慣從系統效能與內存管理的角度出發，尋找最優解。

---

## 🚀 導覽與標籤索引

透過下方標籤可快速跳轉至對應題型分類。

### 題型分類
[#Array](#array) | [#Hash-Table](#hash-table) | [#Two-Pointers](#two-pointers) | [#Dynamic-Programming](#dynamic-programming) | [#String](#string)

---

## 📊 題目清單

| # | 題目 | 難度 | 標籤 | 核心思路 / 筆記 |
| :--- | :--- | :--- | :--- | :--- |
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | [#Array](#array), [#Hash-Table](#hash-table) | 使用一次哈希表，時間 $O(n)$，空間 $O(n)$。 |
| 02215 | [Find Difference](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | 🟢 Easy | [#Hash-Table](#hash-table) | 比較 unordered_set 與排序雙指標的 Cache 效能。 |
| 2218 | [Max Value of K Coins](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/) | 🔴 Hard | [#DP](#dynamic-programming) | 背包問題變體，注意前綴和優化。 |

---

## 🏷️ 標籤詳細清單

### <a name="array"></a>Array
- [0001. Two Sum](./solution/0001.Two%20Sum/)
- [0026. Remove Duplicates](./solution/0026.Remove%20Duplicates/)

### <a name="hash-table"></a>Hash Table
- [0001. Two Sum](./solution/0001.Two%20Sum/)
- [2215. Find the Difference of Two Arrays](./solution/2215.Find%20Difference/)

### <a name="dynamic-programming"></a>Dynamic Programming
- [2218. Maximum Value of K Coins from Piles](./solution/2218.Max%20Value%20Coins/)

---

## 🛠️ 工程師的堅持 (Self-Imposed Constraints)

在解題時，我會額外關注以下幾點以符合工業界標準：
1. **Cache Locality:** 在數據量大時，優先考慮連續內存操作（如 Vector 排序）而非分散節點（如 List/Map）。
2. **Modern C++:** 運用 C++17/20 特性（如 Structured Bindings, `std::views`, `contains()`）。
3. **Complexity Analysis:** 每一題皆附上最壞情況下的時間與空間複雜度分析。

---

## 🤖 自動化工具

本 Repo 建議搭配以下工具使用：
- **[LeetHub v2](https://github.com/arghyadeep99/LeetHub-2.0):** 自動同步代碼至 GitHub。
- **Notion 同步腳本:** (開發中) 定期從我的 Notion 筆記庫更新解題心得。

---

© 2026 Laurence Chang. 保持思考，持續進化。
