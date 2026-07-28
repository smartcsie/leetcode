## <a name="binary-search-build-in"></a>🔍 Binary Search Build in Function (內建函數二分查找)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0034 | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) | 🟡 Medium | Binary Search | [C++](./solution-pages/Solution_0034.md) | O(log N) | O(1) | [Note](#0034-find-first-and-last-position-of-element-in-sorted-array) |
| 0035 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | 🟢 Easy | Binary Search | [C++](./solution-pages/Solution_0035.md) | O(logn) | O(1) |
| 0744 | [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target) | 🟢 Easy | Binary Search | [C++](./solution-pages/Solution_0744.md) | O(logN) | O(1) |
| **1170** | [Compare Strings by Frequency](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/) | 🟡 Medium | Sorting / Binary Search | [C++](./solution-pages/Solution_1170.md) | O(NlogN + MlogN) | O(N) | |
| 1539 | [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number) | 🟢 Easy | Binary Search | [C++](./solution-pages/Solution_1539.md) | O(log N) | O(1) |
| **1818** | [Minimum Absolute Sum Difference](https://leetcode.com/problems/minimum-absolute-sum-difference/) | 🟡 Medium | Binary Search / Greedy | [C++](./solution-pages/Solution_1818.md) | O(N log N) | O(N) |  |
| 2476 | [Closest Nodes Queries in a Binary Search Tree](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/) | 🟡 Medium | BST / Binary Search | [C++](./solution-pages/Solution_2476.md) | O(N+QlogN) | O(N) |

### 0034. Find First and Last Position of Element in Sorted Array
> [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) <br>
> 用 lower_bound 和 upper_bound，最後回傳 {static_cast<int>(lower - nums.begin()), static_cast<int>(upper - nums.begin() - 1)} <br>

<br><br>
---

