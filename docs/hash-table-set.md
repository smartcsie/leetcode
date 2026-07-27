## <a name="hash-table-set"></a>🔑 Hash Table - Set (集合 / 存在性判斷)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) | 🟢 Easy | Hash Table | [C++](./solution-pages/Solution_0217.md) | O(n) | O(n) | [Note](#0217-contains-duplicate)  |
| 0219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) | 🟢 Easy | Hash Table <br> Sliding Window | [C++](./solution-pages/Solution_0219.md) | O(n) | O(min(n,k)) |
| 0349 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution-pages/Solution_0349.md) | O(n+m) | O(n) |
| 0350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | 🟢 Easy | Hash Table | [C++](./solution-pages/Solution_0350.md) | O(n+m) | O(min(n,m)) |
| 0599 | [Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/) | 🟢 Easy | Hash Table / Array | [C++](./solution-pages/Solution_0599.md) | O(N + M) | O(N) | |
| 0705 | [Design HashSet](https://leetcode.com/problems/design-hashset) | 🟢 Easy | Hash Table <br> Design | [C++](./solution-pages/Solution_0705.md) | O(1) | O(N) |
| **0706** | [Design HashMap](https://leetcode.com/problems/design-hashmap/) | 🟢 Easy | Hash Table / Linked List | [C++](./solution-pages/Solution_0706.md) | O(N/K) | O(M+K) | |
| 0859 | [Buddy Strings](https://leetcode.com/problems/buddy-strings/) | 🟢 Easy | String / Hash Table / Two Pointers | [C++](./solution-pages/Solution_859.md) | O(N) | O(1)* | |
| 0888 | [Fair Candy Swap](https://leetcode.com/problems/fair-candy-swap/) | 🟢 Easy | Hash Set / Math | [C++](./solution-pages/Solution_0888.md) | O(A + B) | O(B) | |
| 0939 | [Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/) | 🟡 Medium | Array <br> Hash Table | [C++](./solution-pages/Solution_939.md) | O(N²) | O(N) |
| 1346 | [Check If N and Its Double Exist](https://leetcode.com/problems/check-if-n-and-its-double-exist) | 🟢 Easy | Array <br> Hash Table | [C++](./solution-pages/Solution_1346.md) | O(n) | O(n) |
| 1496 | [Path Crossing](https://leetcode.com/problems/path-crossing/) | 🟢 Easy | Hash Set <br> Coordinates | [C++](./solution-pages/Solution_1496.md) | O(N) | O(N) |  |
| 1624 | [Largest Substring Between Two Equal Characters](https://leetcode.com/problems/largest-substring-between-two-equal-characters/) | 🟢 Easy | String / Hash Table | [C++](./solution-pages/Solution_1624.md) | O(N) | O(1) |
| **1805** | [Number of Different Integers in a String](https://leetcode.com/problems/number-of-different-integers-in-a-string/) | 🟢 Easy | String / Hash Set | [C++](./solution-pages/Solution_1805.md) | O(N) | O(N) |  |
| 2215 | [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution-pages/Solution_2215.md) | O(n+m) | O(n+m) |
| 2248 | [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | 🟢 Easy | Hash Table | [C++](./solution-pages/Solution_2248.md) | O(n*m) | O(n) |
| 2357 | [Make Array Zero by Subtracting Equal Amounts](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/) | 🟢 Easy | Hash Set / Math | [C++](./solution-pages/Solution_2357.md) | O(N) | O(N) |  |
| 2670 | [Find the Distinct Difference Array](https://leetcode.com/problems/find-the-distinct-difference-array/) | 🟢 Easy | Array / Hash Set | [C++](./solution-pages/Solution_2670.md) | O(N) | O(N) ||
| 2784 | [Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good) | 🟢 Easy | Array <br> Hash Table <br> Sorting | [C++](./solution-pages/Solution_2784.md) | O(n) | O(n) |
| 3483 | [Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/) | 🟢 Easy | Brute Force | [C++](./solution-pages/Solution_3483.md) | O(N³) | O(U) |
| 3487 | [Maximum Unique Subarray Sum After Deletion](https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/) | 🟡 Medium | Array / Hash Set / Greedy | [C++](./solution-pages/Solution_3487.md) | O(N) | O(N) |  |
| 3718 | [Smallest Missing Multiple of K](https://leetcode.com/problems/smallest-missing-multiple-of-k/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution-pages/Solution_3718.md) | O(N+M) | O(M) |
| 3731 | [Find Missing Elements](https://leetcode.com/problems/find-missing-elements/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution-pages/Solution_3731.md) | O(N+K) | O(K) |

### 0217. Contains Duplicate
> [Contains Duplicate](https://leetcode.com/problems/contains-duplicate)<br>
 **此題總共有四種作法**<br>
> [法一 Hashset Insert](./solution-pages/Solution_0217.md)，一邊Insert，一邊檢查，Time:O(N)，Time:O(N)<br>
> [法二 Hashset 去重](./solution-pages/Solution_0217_1.md)，全部塞入unordered_set，檢查個數和原nums個數，Time:O(N)，Time:O(N)<br>
> [法三 Unique 去重](./solution-pages/Solution_0217_2.md)，用std::unique判斷，檢查it != nums.end()，Time:O(NlogN)，Time:O(logN)<br>
> [法四 排序](./solution-pages/Solution_0217_3.md)，排序，檢查相鄰元素是否相等，Time:O(NlogN)，Time:O(logN)<br>
---


<br><br>
---

