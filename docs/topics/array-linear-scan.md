# array-linear-scan

## 🔴 生疏（3）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 1608 | [Special Array With X Elements Greater Than or Equal X](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/) | 🟢 Easy | Brute Force, Simulation | [C++](../problems/1608.md) | O(N²) | O(1) |
| 1848 | [Minimum Distance to the Target Element](https://leetcode.com/problems/minimum-distance-to-the-target-element/) | 🟢 Easy | Array, Simulation | [C++](../problems/1848.md) | O(N) | O(1) |
| 3162 | [Find the Number of Good Pairs I](https://leetcode.com/problems/find-the-number-of-good-pairs-i/) | 🟢 Easy | Array Linear Scan, Brute Force | [C++](../problems/3162.md) | O(N*M) | O(1) |

## 🟡 注意（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 414 | [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/) | 🟢 Easy | Array | [C++](../problems/0414.md) | O(N) | O(1) |
| 581 | [Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/) | 🟡 Medium | Array, Sorting, Two Pointers | [C++](../problems/0581.md) | O(NlogN) | O(N) |
| 1013 | [Partition Array Into Three Parts With Equal Sum](https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/) | 🟢 Easy | Array, Greedy, Prefix Sum | [C++](../problems/1013.md) | O(N) | O(1) |
| 1422 | [Maximum Score After Splitting a String](https://leetcode.com/problems/maximum-score-after-splitting-a-string/) | 🟢 Easy | Array Linear Scan | [C++](../problems/1422.md) | O(N) - 先使用 std::count 花費 O(N) 計算總 1 數量，接著用單一迴圈花費 O(N) 掃描分割點。 | O(1) - 僅使用常數個變數（zeros, ones, ans）來追蹤狀態，不需額外配置動態記憶體。 |
| 1431 | [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) | 🟢 Easy | Array | [C++](../problems/1431.md) | O(N) | O(1)* |

## 🟢 熟悉（13）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 1437 | [Check If All 1's Are at Least Length K Places Away](https://leetcode.com/problems/check-if-to-all-1s-are-at-least-length-k-places-away/) | 🟢 Easy | Array, Simulation | [C++](../problems/1437.md) | O(N) | O(1) |
| 1464 | [Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/) | 🟢 Easy | Array, Greedy, Simulation | [C++](../problems/1464.md) | O(N) | O(1) |
| 1614 | [Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/) | 🟢 Easy | Array Linear Scan | [C++](../problems/1614.md) | O(N) | O(1) |
| 2006 | [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | 🟢 Easy | Array Linear Scan, Hash Table, Frequency Map | [C++](../problems/2006.md) | O(N) | O(N) |
| 2057 | [Smallest Index With Equal Value](https://leetcode.com/problems/smallest-index-with-equal-value/) | 🟢 Easy | Array | [C++](../problems/2057.md) | O(N) | O(1) |
| 2176 | [Count Equal and Divisible Pairs in an Array](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/) | 🟢 Easy | Array Linear Scan | [C++](../problems/2176.md) | O(N^2) - 使用雙重迴圈遍歷所有可能的索引對 (i, j)，在資料規模較小（通常 N <= 100）時能高效執行。 | O(1) - 僅使用常數個變數來記錄計數與迴圈索引，不需額外配置動態記憶體。 |
| 2239 | [Find Closest Number to Zero](https://leetcode.com/problems/find-closest-number-to-zero) | 🟢 Easy | Array | [C++](../problems/2239.md) | O(N) | O(1) |
| 2264 | [Largest 3-Same-Digit Number in String](https://leetcode.com/problems/largest-3-same-digit-number-in-string/) | 🟢 Easy | Array Linear Scan | [C++](../problems/2264.md) | O(N) | O(1) |
| 2643 | [Row With Maximum Ones](https://leetcode.com/problems/row-with-maximum-ones/) | 🟢 Easy | Matrix, Linear Scan | [C++](../problems/2643.md) | O(M*N) | O(1) |
| 2733 | [Neither Minimum nor Maximum](https://leetcode.com/problems/neither-minimum-nor-maximum/) | 🟢 Easy | Array, Math | [C++](../problems/2733.md) | O(N) | O(1) |
| 2974 | [Minimum Number Game](https://leetcode.com/problems/minimum-number-game/) | 🟢 Easy | Array Linear Scan | [C++](../problems/2974.md) | O(N) - 計算所有元素和，生成交替奇偶數列。 | O(N) - 結果陣列大小為 N。 |
| 3168 | [Minimum Number of Chairs](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/) | 🟢 Easy | Simulation | [C++](../problems/3168.md) | O(N) | O(1) |
| 3861 | [Minimum Capacity Box](https://leetcode.com/problems/minimum-capacity-box/) | 🟢 Easy | Array, Linear Search | [C++](../problems/3861.md) | O(N) | O(1) |
