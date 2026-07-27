## <a name="quick-select"></a>📚 Quick Select(快速選擇)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 Medium | Array <br> Sorting <br> QuickSelect | [C++](./solution-pages/Solution_0215.md) | O(N) 平均 | O(1) |
| 0324 | [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) | 🟡 Medium | Sorting / Quickselect | [C++](./solution-pages/Solution_0324.md) | O(N) | O(1) |
| 0973 | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin) | 🟡 Medium | Math <br> QuickSelect | [C++](./solution-pages/Solution_0973.md) | O(N) | O(1) |
| 1387 | [Sort Integers by The Power Value](https://leetcode.com/problems/sort-integers-by-the-power-value/) | 🟡 Medium | Recursion / Collatz Conjecture / Quickselect | [C++](./solution-pages/Solution_1387.md) | O(N * S)* | O(N + S) | |
| 1636 | [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency) | 🟢 Easy | Array <br> Hash Table <br> Sorting | [C++](./solution-pages/Solution_1636.md) | O(NlogN) | O(1) |
| 1985 | [Find the Kth Largest Integer in the Array](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array) | 🟡 Medium | Array <br> Sorting <br> String | [C++](./solution-pages/Solution_1985.md) | O(N) | O(1) |
> [!NOTE]
> 手寫 QuickSelect, Average case O(n), **Worse case O(n²)**<br>
> std::nth_element, Average case O(n), Worse case O(n)<br>
> 靜態資料使用QuickSelect(std::nth_element),動態資料使用Min heap<br>

> [!NOTE]
> [1985. Find the Kth Largest Integer in the Array](./solution-pages/Solution_1985.md)<br>
> 雖然 nth_element 是最佳解，但在極少數情境下會有變體：**如果K非常小** (例如 K=1 或 K=3)：你可以使用 **Min-Heap(優先佇列)** 維護一個大小為 K 的堆。<br>
> 雖然時間複雜度為 O(NlogK)，但在K遠小於N時，這能讓你不需要移動整個陣列的元素（如果是**串流數據或唯讀資料**，這會比修改原陣列更好）。<br>
> 如果資料是**唯讀且不能修改原陣列**，則不能使用 nth_element，因為它會改變陣列順序。<br>
> 這時候必須使用**std::priority_queue**複製一份資料進行計算，此時空間複雜度會提升到 O(K)。<br>
> 總結在 LeetCode 這一題的環境下，題目允許修**改 nums。輸入為整個陣列。目標是找第K大**。

<br><br>
---

