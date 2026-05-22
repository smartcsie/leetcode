# LeetCode 演算法精鍊筆記 (C++)

![LeetCode Stats](https://leetcard.jacoblin.cool/smartcsie?theme=nord) <!-- 註：將 laurence 換成你的 LeetCode ID -->

本倉庫用於記錄我的 LeetCode 解題過程、思路分析以及演算法優化心得。作為一名專注於 ADAS 模擬與感知系統的工程師，我習慣從系統效能與內存管理的角度出發，尋找最優解。

---

--

## 🚀 快速導覽

[#Bit-manipulation](#Bit-manipulation) | [#Array](#array) | [#Hash-Table](#hash-table) | [#Math](#math) | [#Binary-Search](#binary-search) | [#Stack](#stack) <br>
[#Tree](#tree) | [#Two-Pointers](#two-pointers) | [#Linked-List](#linked-list) | [#String](#string) <br>
[#Dynamic Programming](#dynamic-programming) | [#Greedy](#greedy) | [#Sorting](#sorting)

---

## <a name="Bit-manipulation"></a>📊 Bit Manipulation (位元運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0136 | [Single Number](https://leetcode.com/problems/single-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0136.cpp) | O(n) | O(1) |
| 0137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Bit-Manipulation | [C++](./solution/Solution_0137.cpp) | O(n) | O(1) |
| 0190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0190.cpp) | O(1) | O(1) |
| 0191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0191.cpp) | O(1) | O(1) |
| 0201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0201.cpp) | O(log n) | O(1) |
| 0260 | [Single Number III](https://leetcode.com/problems/single-number-iii) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0260.cpp) | O(n) | O(1) |
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0268_2.cpp) | O(n) | O(1) |

> [!NOTE]
> [0260 Single Number III](./solution/Solution_0201.cpp) 是 Bit Manipulation 經典題目，目前只有neetcode.io有最佳解，溢位處理有許多常見的解法<br>
> 如 [meyr543](https://hackmd.io/@meyr543/rkSRWnXPK), [grandyang](https://www.cnblogs.com/grandyang/p/4741122.html),[doocs](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0260.Single%20Number%20III/Solution.cpp),[BylwiCXPt](https://hackmd.io/@Inversionpeter/BylwiCXPt)
> 使用 'unsigned',`long long` 來處理 `INT_MIN` 的溢位，這在工程上屬於一種 **Workaround**。
> 建議優先使用邏輯位移（`while` 迴圈）來避免對負數進行取補數運算，從而徹底解決溢位風險。


---

## <a name="math"></a>🔢 Math (數學)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0007 | <div style="width: 600px">[Reverse Integer](https://leetcode.com/problems/reverse-integer/)</div> | 🟡 Medium | Math | [C++](./solution/Solution_0007.cpp) | O(logn) | O(1) |
| 0009 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0009.cpp) | O(logn) | O(1) |
| 0041 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | 🔴 Hard | Math | [C++](./solution/Solution_0041.cpp) | O(n) | O(1) |
| 0066 | [Plus One](https://leetcode.com/problems/plus-one/) | 🟢 Easy | Math | [C++](./solution/Solution_0066.cpp) | O(n) | O(1) |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | 🟢 Easy | Math | [C++](./solution/Solution_0231.cpp) | O(1) | O(1) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 Easy | Math | [C++](./solution/Solution_0263.cpp) | O(log n) | O(1) |
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0268.cpp) | O(n) | O(1) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three/) | 🟢 Easy | Math | [C++](./solution/Solution_0326.cpp) | O(log₃n) | O(1) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four/) | 🟢 Easy | Math | [C++](./solution/Solution_0342.cpp) | O(1) | O(1) |

---

## <a name="binary-search"></a>🔍 Binary Search (二分查找)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0004 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | 🔴 Hard | Binary Search | [C++](./solution/Solution_0004.cpp) | O(log(m+n)) | O(1) |
| 0035 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0035.cpp) | O(logn) | O(1) |
| 0069 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0069.cpp) | O(logn) | O(1) |
| 0153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | 🟡&nbsp;Medium | Binary&nbsp;Search | [C++](./solution/Solution_0153.cpp) | O(logn) | O(1) |
| 0278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0278.cpp) | O(logn) | O(1) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Dynamic Programming <br> Binary Search | [C++](./solution/Solution_0300_1.cpp) | O(nlogn) | O(n) |
| 0367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0367.cpp) | O(logn) | O(1) | 
| 0374 | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0374.cpp) | O(logn) | O(1) |
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0704.cpp) | O(logn) | O(1) |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0852.cpp) | O(logn) | O(1) |

---

## <a name="hash-table"></a>🔑 Hash Table (哈希表)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0001.cpp) | O(n) | O(n) 
| 0036 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku) | 🟡 Medium | Array <br> Hash Table <br> Bitset | [C++](./solution/Solution_0036.cpp) | O(1) | O(1)
| 0202 | [Happy Number](https://leetcode.com/problems/happy-number) | 🟢 Easy | Hash Table <br> Two Pointers <br>  Fast-Slow Pointers | [C++](./solution/Solution_0202.cpp) | O(log n) | O(1) |
| 0205 | [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0205.cpp) | O(n) | O(1) |
| 0217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0217.cpp) | O(n) | O(n) |
| 0219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) | 🟢 Easy | Hash Table <br> Sliding Window | [C++](./solution/Solution_0219.cpp) | O(n) | O(min(n,k)) |
| 0242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0242.cpp) | O(n) | O(1) |
| 0349 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0349.cpp) | O(n+m) | O(n) |
| 0350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0350.cpp) | O(n+m) | O(min(n,m)) |
| 0387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0387.cpp) | O(n) | O(1) |
| 0454 | [4Sum II](https://leetcode.com/problems/4sum-ii) | 🟡&nbsp;Medium | Hash Table | [C++](./solution/Solution_0454.cpp) | O(n²) | O(n²) |
| 1002 | [Find Common Characters](https://leetcode.com/problems/find-common-characters) | 🟢 Easy | Array <br> Hash Table <br> String | [C++](./solution/Solution_1002.cpp) | O(N*K) | O(1) |
| 1346 | [Check If N and Its Double Exist](https://leetcode.com/problems/check-if-n-and-its-double-exist) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_1346.cpp) | O(n) | O(n) |
| 1941 | [Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences) | 🟢 Easy | Hash Table <br> String <br> Counting | [C++](./solution/Solution_1941.cpp) | O(n) | O(1) |
| 2133 | [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) | 🟢 Easy | Array <br> Hash Table <br> Bitset | [C++](./solution/Solution_2133.cpp) | O(n²) | O(n) |
| 2150 | [Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array) | 🟡 Medium | Hash Table <br> Counting | [C++](./solution/Solution_2150.cpp) | O(n) | O(n) |
| 2154 | [Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two) | 🟢 Easy | Array <br> Hash Table <br> Simulation | [C++](./solution/Solution_2154.cpp) | O(n) | O(n) |
| 2206 | [Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs) | 🟢 Easy | Array <br> Hash Table <br> Counting | [C++](./solution/Solution_2206.cpp) | O(n) | O(1) |
| 2215 | [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2215.cpp) | O(n+m) | O(n+m) |
| 2225 | [Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses) | 🟡 Medium | Hash Table <br> Counting <br> Sorting | [C++](./solution/Solution_2225.cpp) | O(n log n) | O(n) |
| 2248 | [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2248.cpp) | O(n*m) | O(n) | 
| 2404 | [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_2404.cpp) | O(n) | O(n) 
| 2441 | [Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative) | 🟢 Easy | Hash Table <br> Two Pointers<br> Sorting | [C++](./solution/Solution_2441.cpp) | O(n) | O(n) |
| 2784 | [Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good) | 🟢 Easy | Array <br> Hash Table <br> Sorting | [C++](./solution/Solution_2784.cpp) | O(n) | O(n) |
| 3005 | [Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_3005.cpp) | O(n) | O(1) |

---

## <a name="string"></a>🔗 String (字串)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0014 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | String <br> Trie | [C++](./solution/Solution_0014.cpp) | O(S) | O(1) |
| 0459 | [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern) | 🟢 Easy | String <br> KMP | [C++](./solution/Solution_0459.cpp) | O(n) | O(n) |

---

## <a name="array"></a>🍱 Array (陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0048 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | 🟡&nbsp;Medium | Array | [C++](./solution/Solution_0048.cpp) | O(n²) | O(1) |
| 0189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | 🟡 Medium | Array | [C++](./solution/Solution_0189.cpp) | O(n) | O(1) |
| 0442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array) | 🟡 Medium | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0442.cpp) | O(n) | O(1) |
| 0448 | [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array) | 🟢 Easy | Array | [C++](./solution/Solution_0448.cpp) | O(n) | O(1) |
| 1886 | [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/) | 🟢 Easy | Array | [C++](./solution/Solution_1886.cpp) | O(n²) | O(1) |
| 2022 | [Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array) | 🟢 Easy | Array / Matrix / Simulation | [C++](./solution/Solution_2022.cpp) | O(m*n) | O(1) |

---

## <a name="two-pointers"></a>👥 Two Pointers (雙指針)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | 🟡 Medium | Array <br> Two Pointers <br> Greedy | [C++](./solution/Solution_0011.cpp) | O(n) | O(1) |
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0015.cpp) | O(n²) | O(logn) 
| 0026 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | 🟢 Easy | Two Pointers <br> Fast-Slow Pointers | [C++](./solution/Solution_0026.cpp) | O(n) | O(1) |
| 0027 | [Remove Element](https://leetcode.com/problems/remove-element/) | 🟢 Easy | Two Pointers <br> Fast-Slow Pointers | [C++](./solution/Solution_0027.cpp) | O(n) | O(1) |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0075.cpp) | O(n) | O(1) |
| 0080 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | 🟡&nbsp;Medium | Two Pointers <br> Fast-Slow Pointers | [C++](./solution/Solution_0080.cpp) | O(n) | O(1) |
| 0125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | 🟢 Easy | Two Pointers / String | [C++](./solution/Solution_0125.cpp) | O(n) | O(1) |
| 0160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists) | 🟢 Easy <br> Linked List | [C++](./solution/Solution_0160.cpp) | O(n+m) | O(1) |
| 0167 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) | 🟢 Medium | Two Pointers | [C++](./solution/Solution_0167.cpp) | O(n) | O(1) |
| 0202 | [Happy Number](https://leetcode.com/problems/happy-number) | 🟢 Easy | Hash Table <br> Two Pointers | [C++](./solution/Solution_0202_1.cpp) | O(log n) | O(1) |
| 0283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | 🟢 Easy | Two Pointers <br> Fast-Slow Pointers | [C++](./solution/Solution_0283.cpp) | O(n) | O(1) | 
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0344.cpp) | O(n) | O(1) |
| 0392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0392.cpp) | O(n) | O(1) |
| 0540 | [Minimum Common Value](https://leetcode.com/problems/minimum-common-value/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0540.cpp) | O(n+m) | O(1) |
| 0905 | [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0905.cpp) | O(n) | O(1) |
| 0922 | [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0922.cpp) | O(n) | O(1) |
| 0941 | [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_0941.cpp) | O(n) | O(1) |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0977.cpp) | O(n) | O(n) |
| 2441 | [Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative) | 🟢 Easy | Hash Table / Two Pointers / Sorting | [C++](./solution/Solution_2441_1.cpp) | O(n) | O(n) |

---

## <a name="linked-list"></a>⛓️ Linked List (鏈表)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0021 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | 🟢 Easy | Linked List | [C++](./solution/Solution_0021.cpp) | O(n+m) | O(1) |
| 0082 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii) | 🟡 Medium | Linked List / Two Pointers | [C++](./solution/Solution_0082.cpp) | O(n) | O(1) |
| 0083 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0083.cpp) | O(n) | O(1) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 Easy | Linked List <br> Fast-Slow Pointers| [C++](./solution/Solution_0141.cpp) | O(n) | O(1) |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0206.cpp) | O(n) | O(1) | 
| 0234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) | 🟢 Easy | Linked List / Two Pointers / Vector | [C++](./solution/Solution_0234.cpp) | O(n) | O(n) |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 Easy | Linked List <br> Two Pointers  <br> Fast-Slow Pointers | [C++](./solution/Solution_0876.cpp) | O(n) | O(1) |

---

## <a name="stack"></a>📚 Stack (堆疊)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 Easy | Stack | [C++](./solution/Solution_0020.cpp) | O(n) | O(n) |
| 0032 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses) | 🔴 Hard | String <br> Stack / DP | [C++](./solution/Solution_0032.cpp) | O(n) | O(n) |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 Easy | Tree / DFS / Stack | [C++](./solution/Solution_0094_1.cpp) | O(n) | O(h) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0144_1.cpp) | O(n) | O(h) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0145_1.cpp) | O(n) | O(h) |
| 1047 | [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string) | 🟢 Easy | String <br> Stack | [C++](./solution/Solution_1047.cpp) | O(n) | O(n) |
| 1209 | [Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii) | 🟡 Medium | String <br> Stack | [C++](./solution/Solution_1209.cpp) | O(n) | O(n) |
| 2390 | [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string) | 🟡 Medium | String <br> Stack | [C++](./solution/Solution_2390.cpp) | O(n) | O(n) |

---

## <a name="tree"></a>🌳 Tree (樹結構)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0094.cpp) | O(n) | O(h) |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | 🟡 Medium | Tree | [C++](./solution/Solution_0098.cpp) | O(n) | O(h) |
| 0100 | [Same Tree](https://leetcode.com/problems/same-tree/) | 🟢 Easy | Tree | [C++](./solution/Solution_0100.cpp) | O(n) | O(h) |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0102.cpp) | O(n) | O(w) |
| 0104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0104.cpp) | O(n) | O(h) |
| 0110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0110.cpp) | O(n) | O(h) | 
| 0111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) | 🟢 Easy | Tree <br> BFS <br> DFS | [C++](./solution/Solution_0111.cpp) | O(n) | O(h) |
| 0112 | [Path Sum](https://leetcode.com/problems/path-sum/) | 🟢 Easy | Tree | [C++](./solution/Solution_0112.cpp) | O(n) | O(h) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0144.cpp) | O(n) | O(h) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0145.cpp) | O(n) | O(h) |
| 0199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0199.cpp) | O(n) | O(w) |
| 0222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes) | 🟢 Easy | Binary Search <br> Tree <br> DFS | [C++](./solution/Solution_0222.cpp) | O(log^2 n) | O(log n) |
| 0226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | 🟢 Easy | Tree | [C++](./solution/Solution_0226.cpp) | O(n) | O(h) |
| 0230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst) | 🟡 Medium | Tree <br> DFS <br> BST | [C++](./solution/Solution_0230.cpp) | O(k) | O(h) |
| 0235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0235.cpp) | O(h) | O(h) |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 Medium | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_0236.cpp) | O(n) | O(h) |
| 0501 | [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0501.cpp) | O(n) | O(h) |
| 0513 | [Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value) | 🟡 Medium | Tree <br> BFS <br> Depth-First Search | [C++](./solution/Solution_0513.cpp) | O(n) | O(w) |
| 0530 | [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0530.cpp) | O(n) | O(h) |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0543.cpp) | O(n) | O(h) |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0572.cpp) | O(n*m) | O(h) |
| 0589 | [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0589.cpp) | O(n) | O(h) |
| 0590 | [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0590.cpp) | O(n) | O(h) |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0662.cpp) | O(n) | O(w) |
| 1609 | [Even Odd Tree](https://leetcode.com/problems/even-odd-tree/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_1609.cpp) | O(n) | O(w) |
| 2331 | [Evaluate Boolean Binary Tree](https://leetcode.com/problems/evaluate-boolean-binary-tree) | 🟢 Easy | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_2331.cpp) | O(n) | O(h) |
---

## <a name="dynamic-programming"></a>🧩 Dynamic Programming (動態規劃)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 Medium | Array <br> Dynamic Programming | [C++](./solution/Solution_0053.cpp) | O(n) | O(1) |
| 0070 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0070.cpp) | O(n) | O(1) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Array <br> Dynamic Programming | [C++](./solution/Solution_0300.cpp) | O(nlogn) | O(n) |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0509.cpp) | O(n) | O(1) | 
| 0583 | [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) | 🟡 Medium | Dynamic Programming | [C++](./solution/Solution_0583.cpp) | O(m*n) | O(m*n) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 Medium | Dynamic Programming | [C++](./solution/Solution_1143.cpp) | O(m*n) | O(m*n) |

---

## <a name="greedy"></a>🧩 Greedy (貪婪法)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0674 | [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence) | 🟢 Easy | Array <br> Greedy | [C++](./solution/Solution_0674.cpp) | O(n) | O(1) |

---

## <a name="Sorting"></a>📊 Sorting (排序)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 Medium | Array <br> Divide and Conquer <br> Sorting | [C++](./solution/Solution_0912.cpp) | O(nlogn) | O(logn) |

---

© 2026 Laurence Chang.


Algorithm<br>
Kadane's Algoritm<br>
Quick Select<br>
Sliding Window<br>
Two Pointers<br>
Prefix Sum<br>
Binary Search<br>
Merge Sort<br>
Quick Sort<br>
Topological Sort<br>
BFS (Breadth-First Search)<br>
DFS (Depth-First Search)<br>
Backtracking（回溯法<br>
Union Find（並查集<br>
Knapsack Problem<br>
Longest Common Subsequence (LCS)<br>
Dijkstra's Algorithm<br>
Morris Traversal<br>


<details>
<summary>下拉是選單</summary>
- 項目 1<br>
- 項目 2
</details>

---

## 🤖 Resource
- **<span>[youngyangyang04](https://github.com/youngyangyang04/leetcode-master)</span>**
- [BytebyteGo](https://bytebytego.com/courses/coding-patterns/two-pointers/introduction-to-two-pointers)
- [花花醬](https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/)
- [daipeinew](https://ithelp.ithome.com.tw/users/20140096/ironman/3912)
- [meyr543](https://hackmd.io/@meyr543/ryUhMY4zY)
- [grandyang](https://www.cnblogs.com/grandyang/p/4389572.html)
- [youngyangyang04](https://github.com/youngyangyang04/leetcode-master)
- [算法模板](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E7%AE%97%E6%B3%95%E6%A8%A1%E6%9D%BF.md)
- [Ji0m0](https://hackmd.io/@Ji0m0/B1dUOaRjN/https%3A%2F%2Fhackmd.io%2F%40Ji0m0%2FHyAgG6bU_)
- [algo.monster](http://algo.monsterhttps://algo.monster/liteproblems/662)
- [doocs](https://github.com/doocs/leetcode/tree/main/solution)
- [Top 10 Algorithms in Interview Questions](https://www.geeksforgeeks.org/dsa/top-10-algorithms-in-interview-questions/)
- [九章基础班.md](https://github.com/cookieisaac/leetcode/blob/master/%E4%B9%9D%E7%AB%A0%E5%9F%BA%E7%A1%80%E7%8F%AD.md)
- [leetcode-patterns](https://seanprashad.com/leetcode-patterns/)
- **<span>[neetcode.io</span>](https://neetcode.io/solutions/concatenation-of-array)</span>**
---
## 🤖 電子書
- [Cracking the Coding Interview 6th 中文](https://github.com/F8F-1BearCat/CtCI-6th-Edition-CN/tree/master)


## 🤖 面試考題
- [Google](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Google)
- [Nvidia](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Nvidia)
- [Amazon](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Amazon)

© 2026 Laurence Chang. 保持思考，持續進化。
