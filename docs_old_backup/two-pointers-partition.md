## <a name="two-pointers-partition"></a>👥 Two Pointers - Partition (分割型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution-pages/Solution_0075.md) | O(n) | O(1) |
| 0088 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution-pages/Solution_0088.md) | O(M + N) | O(1) |
| 2149 | [Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign) | 🟡 Medium | Array <br> Two Pointers <br> Simulation | [C++](./solution-pages/Solution_2149.md) | O(N) | O(N) |

> [!NOTE]
> [Partition 核心概念]<br>
> 0075 Dutch National Flag：三指針 low / mid / high，一次掃描分成三區。<br>
> 0088 從尾端往前合併，避免覆蓋未讀資料，是 in-place merge 的標準技巧。<br>
> 0922 奇偶雙指針，odd 指針跳兩格，even 指針跳兩格，各自填位。<br>

> [!NOTE]
> [2149. Rearrange Array Elements by Sign](./solution-pages/Solution_2149.md)<br>
> 此題要求將正數與負數交替排列，同時**維持各自原本的相對順序**，所以**空間複雜度無法 O(1)**<br>
> 目前解法已是最優：時間 O(N)、空間 O(N)<br>

<br><br>
---


