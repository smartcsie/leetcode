## <a name="interval"></a>🗓️ Interval (區間)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0056 | [Merge Intervals](https://leetcode.com/problems/merge-intervals) | 🟡 Medium | Array <br> Sorting | [C++](./solution/Solution_0056.cpp) | O(NlogN) | O(logN) |
| 0057 | [Insert Interval](https://leetcode.com/problems/insert-interval) | 🟡 Medium | Array <br> Interval | [C++](./solution/Solution_0057.cpp) | O(N) | O(N) |
| 0435 | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) | 🟡 Medium | Greedy <br> Interval | [C++](./solution/Solution_0435.cpp) | O(NlogN) | O(1) |
| 0986 | [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) | 🟡 Medium | Two Pointers / Interval Processing | [C++](./solution/Solution_0986.cpp) | O(M + N) | O(1)* | |
| 1288 | [Remove Covered Intervals](https://leetcode.com/problems/remove-covered_intervals/) | 🟡 Medium | Sorting / Greedy | [C++](./solution/Solution_1288.cpp) | O(NlogN) | O(log N) | |

> [!NOTE]
> [Interval 核心概念]
> 大部分 Interval 題目分三種操作：
> 1. **合併型**（0056）：先排序，掃描時比較 cur.start 和 prev.end
> 2. **插入型**（0057）：已排序前提下，找插入點，處理重疊區間合併
> 3. **交集型**（0986）：雙指針各自走訪兩組已排序區間，比較 start/end 找重疊
> 4. **排程貪婪型**（0435）：依 end 排序，貪婪選擇不重疊區間數量最多

<br><br>
---


