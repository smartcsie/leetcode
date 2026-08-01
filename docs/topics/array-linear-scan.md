# array-linear-scan

| # | 題目 | 難度 | 標籤 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- |
| 414 | [Third Maximum Number](../problems/0414.md) | 🟢 Easy | Array | O(N) | O(1) |
| 581 | [Shortest Unsorted Continuous Subarray](../problems/0581.md) | 🟡 Medium | Array, Sorting, Two Pointers | O(NlogN) | O(N) |
| 747 | [Largest Number At Least Twice of Others](../problems/0747.md) | 🟢 Easy | Array Linear Scan, Linear Scan | O(N) | O(1) |
| 1013 | [Partition Array Into Three Parts With Equal Sum](../problems/1013.md) | 🟢 Easy | Array, Prefix Sum, Greedy | O(N) | O(1) |
| 1422 | [Maximum Score After Splitting a String](../problems/1422.md) | 🟢 Easy | Array Linear Scan | O(N) - 先使用 std::count 花費 O(N) 計算總 1 數量，接著用單一迴圈花費 O(N) 掃描分割點。 | O(1) - 僅使用常數個變數（zeros, ones, ans）來追蹤狀態，不需額外配置動態記憶體。 |
| 1431 | [Kids With the Greatest Number of Candies](../problems/1431.md) | 🟢 Easy | Array | O(N) | O(1)* |
| 1437 | [Check If All 1's Are at Least Length K Places Away](../problems/1437.md) | 🟢 Easy | Array, Simulation | O(N) | O(1) |
| 1464 | [Maximum Product of Two Elements in an Array](../problems/1464.md) | 🟢 Easy | Array, Simulation, Greedy | O(N) | O(1) |
| 1608 | [Special Array With X Elements Greater Than or Equal X](../problems/1608.md) | 🟢 Easy | Brute Force, Simulation | O(N²) | O(1) |
| 1614 | [Maximum Nesting Depth of the Parentheses](../problems/1614.md) | 🟢 Easy | String, Stack, Simulation | O(N) | O(1) |
| 1848 | [Minimum Distance to the Target Element](../problems/1848.md) | 🟢 Easy | Array, Simulation | O(N) | O(1) |
| 2057 | [Smallest Index With Equal Value](../problems/2057.md) | 🟢 Easy | Array | O(N) | O(1) |
| 2176 | [Count Equal and Divisible Pairs in an Array](../problems/2176.md) | 🟢 Easy | Array Linear Scan | O(N^2) - 使用雙重迴圈遍歷所有可能的索引對 (i, j)，在資料規模較小（通常 N <= 100）時能高效執行。 | O(1) - 僅使用常數個變數來記錄計數與迴圈索引，不需額外配置動態記憶體。 |
| 2239 | [Find Closest Number to Zero](../problems/2239.md) | 🟢 Easy | Array | O(N) | O(1) |
| 2264 | [Largest 3-Same-Digit Number in String](../problems/2264.md) | 🟢 Easy | Array Linear Scan, String | O(N) | O(1) |
| 2643 | [Row With Maximum Ones](../problems/2643.md) | 🟢 Easy | Matrix, Linear Scan | O(M*N) | O(1) |
| 2733 | [Neither Minimum nor Maximum](../problems/2733.md) | 🟢 Easy | Math, Array | O(N) | O(1) |
| 2974 | [Minimum Number Game](../problems/2974.md) | 🟢 Easy | Array Linear Scan | O(N) - 計算所有元素和，生成交替奇偶數列。 | O(N) - 結果陣列大小為 N。 |
| 3168 | [Minimum Number of Chairs](../problems/3168.md) | 🟢 Easy | Simulation | O(N) | O(1) |
| 3861 | [Minimum Capacity Box](../problems/3861.md) | 🟢 Easy | Array, Linear Search | O(N) | O(1) |
