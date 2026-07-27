## <a name="Sorting"></a>📊 Sorting (排序)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0148 | [Sort List](https://leetcode.com/problems/sort-list/) | 🟡 Medium | Linked List <br> Merge Sort | [C++](./solution/Solution_0148.cpp) | O(NlogN) | O(logN) | |
| 0179 | [Largest Number](https://leetcode.com/problems/largest-number/) | 🟡 Medium | Sorting <br> String | [C++](./solution/Solution_0179.cpp) | O(NlogN*k) | O(N*k) |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 Medium | Hash Table <br> QuickSelect | [C++](./solution/Solution_0347.cpp) | O(N) | O(N) |
| 0539 | [Minimum Time Difference](https://leetcode.com/problems/minimum-time-difference/) | 🟡 Medium | Math <br> Sorting | [C++](./solution/Solution_539.cpp) | O(NlogN) | O(N) |
| 0524 | [Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/) | 🟡 Medium | Two Pointers / Sorting | [C++](./solution/Solution_0524.cpp) | O(D log D + D * M) | O(1) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 Medium | Array <br> Divide and Conquer <br> Sorting | [C++](./solution/Solution_0912.cpp) | O(nlogn) | O(logn) |
| 1200 | [Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_1200.cpp) | O(NlogN) | O(N) | 
| 1356 | [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits) | 🟢 Easy | Bit Manipulation <br>  Sorting | [C++](./solution/Solution_1356.cpp) | O(NlogN) | O(1) |
| 1408 | [String Matching in an Array](https://leetcode.com/problems/string-matching-in-an-array/) | 🟢 Easy | String <br> Sorting | [C++](./solution/Solution_1408.cpp) | O(N²*K) | O(N) |
| 1481 | [Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/) | 🟡 Medium | Greedy / Sorting | [C++](./solution/Solution_1481.cpp) | O(N log N) | O(N) | [Note](#1481-least-number-of-unique-integers-after-k-removals) |
| 2164 | [Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently/) | 🟢 Easy | Sorting | [C++](./solution/Solution_2164.cpp) | O(NlogN) | O(N) | 
| 2491 | [Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/) | 🟡 Medium | Array / Two Pointers / Sorting | [C++](./solution/Solution_2491.cpp) | O(N log N) | O(1)或O(N)* | |
| 2545 | [Sort the Students by Their Kth Score](https://leetcode.com/problems/sort-the-students-by-their-kth-score/) | 🟢 Medium | Array <br> Sorting | [C++](./solution/Solution_2545.cpp) | O(NlogN) | O(1) |
| 2932 | [Maximum Strong Pair XOR I](https://leetcode.com/problems/maximum-strong-pair-xor-i/) | 🟢 Easy | Sorting / Brute Force | [C++](./solution/Solution_2932.cpp) | O(NlogN +N²) | O(logN) |  |
| 2966 | [Divide Array Into Arrays With Max Difference](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/) | 🟡 Medium | Array / Greedy / Sorting | [C++](./solution/Solution_2966.cpp) | O(N log N) | O(1)或O(N)* | |
| 3684 | [Maximize Sum of At Most K Distinct Elements](https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/) | 🟢 Easy | Sorting <br> Set | [C++](./solution/Solution_3684.cpp) | O(N logN) | O(N) |
| 3769 | [Sort Integers by Binary Reflection](https://leetcode.com/problems/sort-integers-by-binary-reflection/) | 🟡 Medium | Bit Manipulation <br> Sorting | [C++](./solution/Solution_3769.cpp) | O(NlogN) | O(N) |
| 3913 | [Sort Vowels by Frequency](https://leetcode.com/problems/sort-vowels-by-frequency/) | 🟡 Medium | Sorting <br> Hash | [C++](./solution/Solution_3913.cpp) | O(NlogN) | O(N) | 
| 3867 | [Sum of GCD of Formed Pairs](leetcode.com/problems/sum-of-gcd-of-formed-pairs/) | 🟡 Medium | GCD <br> Sorting | [C++](./solution/Solution_3867.cpp)  | O(NlogN) | O(N) | |

> [!NOTE]
> Array or HashMap ?<br>
> 通常 Range 範圍在 幾百 例如 [1636 Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency)<br>
> 計數範圍-100 <= nums[i] <= 100<br>
> 會用Array，因為是連續記憶體<br>
> 這是難得[doocs](https://github.com/doocs/leetcode/blob/main/solution/1600-1699/1636.Sort%20Array%20by%20Increasing%20Frequency/README_EN.md)優於[neetcode.io](https://neetcode.io/solutions/sort-array-by-increasing-frequency)<br>

> [!NOTE]
> [0148. Sort List](./solution/Solution_0148.cpp) [0004. Median of Two Sorted Arrays](./solution/Solution_0004.cpp)<br>
> 是一樣的核心概念，都是Two Way merge sort<br>


### 1481. Least Number of Unique Integers after K Removals
> [Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/)<br>
> 用 std::unordered_map<int, int> counts;;統計數字出現頻率<br>
> 把頻率，寫入std::vector<int> freq; 對freq做sort<br>
> 用k去減頻率，同時紀錄山除了幾個數<br>

<br><br>
---


