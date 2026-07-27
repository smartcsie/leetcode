## <a name="array"></a>🍱 Array (陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0054 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | 🟡 Medium | Array / Simulation | [C++](./solution/Solution_0054.cpp.md) | O(M*N) | O(1) | 
| 0059 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | 🟡 Medium | Array / Simulation | [C++](./solution/Solution_0059.cpp.md) | O(N²) | O(1) |
| 0189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | 🟡 Medium | Array | [C++](./solution/Solution_0189.cpp.md) | O(n) | O(1) |
| 0717 | [1-bit and 2-bit Characters](https://leetcode.com/problems/1-bit-and-2-bit-characters/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_0717.cpp.md) | O(N) | O(1) | 
| 0821 | [Shortest Distance to a Character](https://leetcode.com/problems/shortest-distance-to-a-character/) | 🟢 Easy | Two-Pass Scan | [C++](./solution/Solution_0821.cpp.md) | O(N) | O(1) | |
| 0896 | [Monotonic Array](https://leetcode.com/problems/monotonic-array) | 🟢 Easy | Array | [C++](./solution/Solution_0896.cpp.md) | O(N) | O(1) |
| 1299 | [Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side) | 🟢 Easy | Array | [C++](./solution/Solution_1299.cpp.md) | O(N) | O(1) |
| 1304 | [Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/) | 🟢 Easy | Math / Array | [C++](./solution/Solution_1304.cpp.md) | O(N) | O(1) | [Note](#1304-find-n-unique-integers-sum-up-to-zero) |
| 1389 | [Create Target Array in the Given Order](https://leetcode.com/problems/create-target-array-in-the-given-order/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_1389.cpp.md) | O(N²) | O(N) |
| 1470 | [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/) | 🟢 Easy | Array | [C++](./solution/Solution_1470.cpp.md) | O(N) | O(N) |
| 1491 | [Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/) | 🟢 Easy | Array / Sorting / Math | [C++](./solution/Solution_1491.cpp.md) | O(N) | O(1) ||
| 1550 | [Three Consecutive Odds](https://leetcode.com/problems/three-consecutive-odds/) | 🟢 Easy | Array | [C++](./solution/Solution_1550.cpp.md) | O(N) | O(1) | [Note](#1550-three-consecutive-odds) |
| 1662 | [Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_1662.cpp.md) | O(N+ M) | O(1) |
| 1752 | [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated) | 🟢 Easy | Array | [C++](./solution/Solution_1752.cpp.md) | O(N) | O(1) |
| 1800 | [Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum) | 🟢 Easy | Array | [C++](./solution/Solution_1800.cpp.md) | O(N) | O(1) |
| 1844 | [Replace All Digits with Characters](https://leetcode.com/problems/replace-all-digits-with-characters/) | 🟢 Easy | In-place Manipulation | [C++](./solution/Solution_1844.cpp.md) | O(N) | O(1) | |
| 1913 | [Maximum Product Difference Between Two Pairs](https://leetcode.com/problems/maximum-product-difference-between-two-pairs) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_1913.cpp.md) | O(N) | O(1) |
| 1929 | [Concatenation of Array](https://leetcode.com/problems/concatenation-of-array) | 🟢 Easy | Array | [C++](./solution/Solution_1929.cpp.md) | O(N) | O(1)* |
| 2089 | [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/) | 🟢 Easy | Array <br> Counting | [C++](./solution/Solution_2089.cpp.md) | O(N) | O(1) |
| 2148 | [Count Elements With Strictly Smaller and Greater Elements](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_2148.cpp.md) | O(N) | O(1) |
| 3477 | [Fruits Into Baskets II](https://leetcode.com/problems/fruits-into-baskets-ii/) | 🟢 Easy | Simulation / Brute Force | [C++](./solution/Solution_3477.cpp.md) | O(N^2) | O(1) | [Note](#3477-fruits-into-baskets-ii) |
| 3925 | [Concatenate Array With Reverse](https://example.com/problems/3925) | 🟢 Easy | Array <br> Simulation | [C++](./solution/Solution_3925.cpp.md) | O(N) | O(N) |
| 3969 | Valid Subarrays With Matching Sum Digits I | 🟢 Easy | Array / Brute Force | [C++](./solution/Solution_3969.cpp.md) | O(N²) | O(1) | |

### 1304.Find N Unique Integers Sum up to Zero
>  [Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/) <br>
>  產生n個數，使其sum為0，起一個loop，i從 1 ~/2，ans.push_back(i);ans.push_back(-i);，如果n是奇數，多放0，if(n & 1) ans.push_back(0);<br>

---

### 1550. Three Consecutive Odds
> [Three Consecutive Odds](https://leetcode.com/problems/three-consecutive-odds/) <br>
>  **if (num & 1) { count++; if (count == 3) return true; }** <br> 
>  **else { count = 0;}** <br>
---


### 1844. Replace All Digits with Characters
> [Replace All Digits with Characters](https://leetcode.com/problems/replace-all-digits-with-characters/) <br>
>  **for(int i = 1; i <s.size(); i += 2) {** <br>
>  &emsp;&emsp;&emsp;&emsp;**s[i] = s[i - 1] + s[i] - '0';** <br>
>  **}** <br>
---

### 3477. Fruits Into Baskets II
> [Fruits Into Baskets II](https://leetcode.com/problems/fruits-into-baskets-ii/) <br>
> 這一題有O(nlong)解法，SegmentTree

<br><br>
---

