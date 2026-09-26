# 📝 複習清單

📌 **快速跳轉：** [🟡 練習過清單（154）](#review-lianxiguo)　[🟠 再練習清單（211）](#review-zailianxi)　[🔴 生疏清單（223）](#review-shengshu)

## 📊 總覽

- **LeetCode 網站 AC 總數：** 980 / 4046 題（最後更新：2026-09-08 17:55）
- **目前收錄總題目數：** 980 題　🔴 生疏：221 題　🟠 再練習：203 題　🟡 練習過：138 題　🟣 易忘：110 題　🟢 熟練：308 題　⚪ 未標記：0 題

---

<a id="review-lianxiguo"></a>
## 🟡 練習過清單

目前共有 154 個解法標記為練習過，持續複習鞏固。

📌 **快速跳轉：** [🔢 Math（11）](#lianxiguo-math)　[📊 Bit Manipulation（7）](#lianxiguo-bit-manipulation)　[🔗 String（7）](#lianxiguo-string)　[🍱 Array（21）](#lianxiguo-array)　[🌳 Tree（10）](#lianxiguo-tree)　[🔍 Binary Search（5）](#lianxiguo-binary-search)　[⛓️ Linked List（5）](#lianxiguo-linked-list)　[👥 Pointers（17）](#lianxiguo-pointers)　[🔑 Hash Table（13）](#lianxiguo-hash-table)　[📚 Priority Queue（1）](#lianxiguo-priority-queue)　[📚 Quick Select（1）](#lianxiguo-quick-select)　[📊 Sorting（13）](#lianxiguo-sorting)　[🧩 Dynamic Programming（30）](#lianxiguo-dynamic-programming)　[🧩 Greedy（12）](#lianxiguo-greedy)　[🔢 Backtracking（1）](#lianxiguo-backtracking)

<a id="lianxiguo-math"></a>
#### 🔢 Math（11）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 8 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi) | 🟡 Medium | Math Digit Decomposition, Math | [C++](problems/0008.md) | O(N) | O(1) |  |
| 60 | [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | 🟡 Medium | Math Permutation | [C++](problems/0060.md) | O(N × N!) | O(N) |  |
| 119 | [Pascal's Triangle II](https://leetcode.com/problems/pascal-triangle-ii/) | 🟢 Easy | Math Combination, Combinatorics | [C++](problems/0119.md) | O(N) | O(1) |  |
| 204 | [Count Primes](https://leetcode.com/problems/count-primes/) | 🟡 Medium | Math Prime, Sieve | [C++](problems/0204.md) | O(NloglogN) | O(N) |  |
| 812 | [Largest Triangle Area](https://leetcode.com/problems/largest-triangle-area/) | 🟢 Easy | Math Geometry | [C++](problems/0812.md) | O(N³) | O(1) |  |
| 914 | [X of a Kind in a Deck of Cards](https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/) | 🟢 Easy | Math Gcd, GCD, Hash Table | [C++](problems/0914.md) | O(N) | O(N) |  |
| 989 | [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | 🟢 Easy | Math Digit Decomposition, Simulation, Carry Propagation | [C++](problems/0989.md) | O(max(N,logK)) | O(max(N,logK)) |  |
| 2160 | [Minimum Sum of Four Digit Number After Splitting Digits](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/) | 🟢 Easy | Math Digit Decomposition, Greedy, Sorting | [C++](problems/2160.md) | O(1) | O(1) |  |
| 2293 | [Min Max Game](https://leetcode.com/problems/min-max-game/) | 🟢 Easy | Math Simulation, Simulation | [C++](problems/2293.md) | O(N) | O(N) |  |
| 3084 | [Count Substrings...](https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/) | 🟢 Easy | Math Combination | [C++](problems/3084.md) | O(N) | O(1) |  |
| 3556 | [Sum of Largest Prime Substrings](https://leetcode.com/problems/sum-of-largest-prime-substrings/) | 🟡 Medium | Math Prime, Brute Force | [C++](problems/3556.md) | O(N²\*sqrt(M)) | O(1) |  |

<a id="lianxiguo-bit-manipulation"></a>
#### 📊 Bit Manipulation（7）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 78 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 Medium | Bit Bitmask Subset Enumeration, Bitmask, Backtracking | [C++](problems/0078.md) | O(2ᴺ\*N) | O(2^N\*N) |  |
| 1016 | [Binary String With Substrings Representing 1 To N](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/) | 🟡 Medium | Bit Manipulation, Bit Manipulation, Sliding Window | [C++](problems/1016.md) | O(N\*LEN) | O(1) |  |
| 1442 | [Count Triplets That Can Form Two Arrays of Equal XOR](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/) | 🟡 Medium | Bit Manipulation Xor, Prefix XOR | [C++](problems/1442.md) | O(N²) | O(1) |  |
| 2044 | [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) | 🟡 Medium | Bit Bitmask Subset Enumeration | [C++](problems/2044.md) | O(N\*2^N) | O(1) |  |
| 2397 | [Maximum Rows Covered by Columns](https://leetcode.com/problems/maximum-rows-covered-by-columns/) | 🟡 Medium | Bit Bitmask Subset Enumeration, Bitmask, Combinatorics | [C++](problems/2397.md) | O(2ᴺ\*M+M\*N) | O(M) |  |
| 2917 | [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array) | 🟢 Easy | Bit Manipulation Or | [C++](problems/2917.md) | O(N\*log(max_VAL)) | O(1) |  |
| 3750 | [Minimum Number of Flips to Reverse Binary String](https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/) | 🟢 Easy | Bit Manipulation | [C++](problems/3750.md) | O(logN) | O(1) |  |

<a id="lianxiguo-string"></a>
#### 🔗 String（7）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | 🟡 Medium | String, Two Pointers | [C++](problems/0151.md) | O(N) | O(N) |  |
| 459 | [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern) | 🟢 Easy | String Kmp, KMP | [C++](problems/0459.md) | O(N) | O(N) |  |
| 833 | [Find And Replace in String](https://leetcode.com/problems/find-and-replace-in-string/) | 🟡 Medium | String | [C++](problems/0833.md) | O(N+M\*K) | O(N) |  |
| 944 | [Delete Columns to Make Sorted](https://leetcode.com/problems/delete-columns-to-make-sorted/) | 🟢 Easy | String, String | [C++](problems/0944.md) | O(N\*M) | O(M) |  |
| 1592 | [Rearrange Spaces Between Words](https://leetcode.com/problems/rearrange-spaces-between-words/) | 🟢 Easy | String, Simulation | [C++](problems/1592.md) | O(N) | O(N) |  |
| 3304 | [Find the K-th Character in String Game I](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/) | 🟢 Easy | Simulation, Recursion | [C++](problems/3304.md) | O(K) | O(K) |  |
| 3407 | [Substring Matching Pattern](https://leetcode.com/problems/substring-matching-pattern/) | 🟢 Easy | String, Pattern Matching | [C++](problems/3407.md) | O(N+M) | O(M) |  |

<a id="lianxiguo-array"></a>
#### 🍱 Array（21）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 56 | [Merge Intervals](https://leetcode.com/problems/merge-intervals) | 🟡 Medium | Array Interval, Sorting | [C++](problems/0056.md) | O(NlogN) | O(logN) |  |
| 57 | [Insert Interval](https://leetcode.com/problems/insert-interval) | 🟡 Medium | Array Interval, Interval | [C++](problems/0057.md) | O(N) | O(N) |  |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | 🟡 Medium | Array Prefix Sum, Prefix Sum | [C++](problems/0238.md) | O(N) | O(1) |  |
| 303 | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable) | 🟢 Easy | Array Prefix Sum, Prefix Sum | [C++](problems/0303.md) | O(N) | O(N) |  |
| 435 | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) | 🟡 Medium | Array Interval, Interval | [C++](problems/0435.md) | O(NlogN) | O(1) |  |
| 930 | [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/) | 🟡 Medium | Array Prefix Sum | [C++](problems/0930.md) | O(N^2) | O(N) |  |
| 986 | [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) | 🟡 Medium | Array Interval, Two Pointers, Interval Processing | [C++](problems/0986.md) | O(M+N) | O(1) |  |
| 1288 | [Remove Covered Intervals](https://leetcode.com/problems/remove-covered_intervals/) | 🟡 Medium | Array Interval, Greedy | [C++](problems/1288.md) | O(NlogN) | O(logN) |  |
| 1365 | [How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/) | 🟢 Easy | Array Prefix Sum, Counting Sort, Prefix Sum | [C++](problems/1365.md) | O(N+K) | O(K) |  |
| 1491 | [Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/) | 🟢 Easy | Array, Sorting, Math | [C++](problems/1491.md) | O(N) | O(1) |  |
| 1512 | [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs) | 🟢 Easy | Array Linear Scan | [C++](problems/1512.md) | O(N) | O(1) |  |
| 1608 | [Special Array With X Elements Greater Than or Equal X](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/) | 🟢 Easy | Array Linear Scan, Brute Force, Simulation | [C++](problems/1608.md) | O(N²) | O(1) |  |
| 1732 | [Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/) | 🟢 Easy | Array Prefix Sum, Prefix Sum | [C++](problems/1732.md) | O(N) | O(1) |  |
| 1759 | [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/) | 🟡 Medium | Array Continuous Counting, String | [C++](problems/1759.md) | O(N) | O(1) |  |
| 1848 | [Minimum Distance to the Target Element](https://leetcode.com/problems/minimum-distance-to-the-target-element/) | 🟢 Easy | Array Linear Scan, Simulation | [C++](problems/1848.md) | O(N) | O(1) |  |
| 1920 | [Build Array from Permutation](https://leetcode.com/problems/build-array-from-permutation/) | 🟢 Easy | Array Linear Scan | [C++](problems/1920.md) | O(N) | O(1) |  |
| 2006 | [Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/) | 🟢 Easy | Array Linear Scan, Hash Table, Frequency Map | [C++](problems/2006.md) | O(N) | O(N) | 2026-09-17 |
| 2210 | [Count Hills and Valleys in an Array](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/) | 🟢 Easy | Array Continuous Counting | [C++](problems/2210.md) | O(N) | O(1) |  |
| 2485 | [Find the Pivot Integer](https://leetcode.com/problems/pivot-integer/) | 🟢 Easy | Array Linear Scan | [C++](problems/2485.md) | O(N) | O(1) |  |
| 2574 | [Left and Right Sum Differences](https://leetcode.com/problems/left-and-right-sum-differences/) | 🟢 Easy | Array Prefix Sum, Prefix Sum | [C++](problems/2574.md) | O(N) | O(N) |  |
| 3069 | [Distribute Elements Into Two Arrays I](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/) | 🟢 Easy | Array, Simulation | [C++](problems/3069.md) | O(N) | O(N) |  |

<a id="lianxiguo-tree"></a>
#### 🌳 Tree（10）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 99 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) | 🟡 Medium | Binary Search Tree, BST, In-order Traversal | [C++](problems/0099.md) | O(N) | O(1) |  |
| 109 | [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | 🟡 Medium | Binary Search Tree, Tree | [C++](problems/0109.md) | O(NlogN) | O(logN) |  |
| 113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii) | 🟡 Medium | Tree Dfs Backtracking, DFS, Backtracking | [C++](problems/0113.md) | O(N) | O(H) |  |
| 563 | [Binary Tree Tilt](https://leetcode.com/problems/binary-tree-tilt/) | 🟢 Easy | Tree Dfs Global, DFS, Post-order | [C++](problems/0563.md) | O(N) | O(H) |  |
| 606 | [Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/) | 🟢 Easy | Tree Dfs Path, DFS | [C++](problems/0606.md) | O(N) | O(H) |  |
| 938 | [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst) | 🟢 Easy | Tree Dfs Path | [C++](problems/0938.md) | O(N) | O(H) | 2026-09-25 |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/) | 🟡 Medium | Binary Search Tree, BST, DFS | [C++](problems/1008.md) | O(N) | O(N) |  |
| 1382 | [Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/) | 🟡 Medium | Binary Search Tree, BST | [C++](problems/1382.md) | O(N) | O(N) |  |
| 1448 | [Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/) | 🟡 Medium | Tree Dfs Path, DFS, Recursion | [C++](problems/1448.md) | O(N) | O(H) | 2026-09-26 |
| 2415 | [Reverse Odd Levels of Binary Tree](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/) | 🟡 Medium | Tree Dfs Path, DFS | [C++](problems/2415.md) | O(N) | O(H) |  |

<a id="lianxiguo-binary-search"></a>
#### 🔍 Binary Search（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 33 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 Medium | Binary Search, Binary Search | [C++](problems/0033.md) | O(logN) | O(1) |  |
| 74 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) | 🟡 Medium | Binary Search, Matrix | [C++](problems/0074.md) | O(log(MN)) | O(1) |  |
| 153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | 🟡 Medium | Binary Search, Binary&nbsp;Search | [C++](problems/0153.md) | O(logN) | O(1) |  |
| 611 | [Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/) | 🟡 Medium | Binary Search Find Right Bound | [C++](problems/0611.md) | O(N²logN) | O(1) |  |
| 1351 | [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) | 🟢 Easy | Binary Search Find Left Bound | [C++](problems/1351.md) | O(R\*logC) | O(1) | 2026-09-24 |

<a id="lianxiguo-linked-list"></a>
#### ⛓️ Linked List（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 24 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs) | 🟡 Medium | Linked List, Recursion | [C++](problems/0024.md) | O(N) | O(N) |  |
| 82 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii) | 🟡 Medium | Linked List, Two Pointers | [C++](problems/0082.md) | O(N) | O(1) |  |
| 92 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii) | 🟡 Medium | Linked List | [C++](problems/0092.md) | O(N) | O(1) | 2026-09-25 |
| 143 | [Reorder List](https://leetcode.com/problems/reorder-list/) | 🟡 Medium | Linked List | [C++](problems/0143.md) | O(N) | O(1) |  |
| 2130 | [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) | 🟡 Medium | Linked List | [C++](problems/2130.md) | O(N) | O(1) |  |

<a id="lianxiguo-pointers"></a>
#### 👥 Pointers（17）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 11 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | 🟡 Medium | Two Pointers Opposite, Two Pointers, Greedy | [C++](problems/0011.md) | O(N) | O(1) |  |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | 🟢 Easy | Fast Slow Pointers, Fast-Slow Pointers | [C++](problems/0026.md) | O(N) | O(1) |  |
| 26 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | 🟢 Easy | Fast Slow Pointers | [C++](problems/0026.md) | O(N) | O(1) |  |
| 142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | 🟡 Medium | Linked List, Fast-Slow Pointers | [C++](problems/0142.md) | O(N) | O(1) |  |
| 557 | [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii) | 🟢 Easy | Two Pointers Other, Two Pointers | [C++](problems/0557.md) | O(N) | O(1) |  |
| 611 | [Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/) | 🟡 Medium | Two Pointers Opposite, Two Pointers | [C++](problems/0611.md) | O(N²) | O(1) |  |
| 633 | [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/) | 🟡 Medium | Two Pointers Opposite, Two Pointers | [C++](problems/0633.md) | O(√C) | O(1) |  |
| 1332 | [Remove Palindromic Subsequences](https://leetcode.com/problems/remove-palindromic-subsequences/) | 🟢 Easy | Two Pointers Opposite | [C++](problems/1332.md) | O(N) | O(1) |  |
| 1877 | [Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/) | 🟡 Medium | Two Pointers Opposite, Two Pointers, Greedy, Sorting | [C++](problems/1877.md) | O(NlogN) | O(1) |  |
| 2108 | [Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/) | 🟢 Easy | Two Pointers | [C++](problems/2108.md) | O(N\*L) | O(1) |  |
| 2130 | [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) | 🟡 Medium | Fast Slow Pointers, Two Pointers | [C++](problems/2130.md) | O(N) | O(1) |  |
| 2149 | [Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign) | 🟡 Medium | Two Pointers Partition, Two Pointers, Simulation | [C++](problems/2149.md) | O(N) | O(N) |  |
| 2441 | [Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative) | 🟢 Easy | Two Pointers Swap, Hash Table | [C++](problems/2441.md) | O(N) | O(N) | 2026-09-16 |
| 2460 | [Apply Operations to an Array](https://leetcode.com/problems/apply-operations-to-an-array) | 🟢 Easy | Fast Slow Pointers, Simulation | [C++](problems/2460.md) | O(N) | O(1) |  |
| 2864 | [Maximum Odd Binary Number](https://leetcode.com/problems/maximum-odd-binary-number/) | 🟢 Easy | Two Pointers Same | [C++](problems/2864.md) | O(N) | O(1) | 2026-09-21 |
| 3819 | [Rotate Non Negative Elements](https://leetcode.com/problems/rotate-non-negative-elements/) | 🟢 Easy | Array, Two Pointers | [C++](problems/3819.md) | O(N) | O(N) |  |
| 3936 | [Minimum Swaps to Move Zeros to End](https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/) | 🟢 Easy | Two Pointers, Simulation | [C++](problems/3936.md) | O(N) | O(1) |  |

<a id="lianxiguo-hash-table"></a>
#### 🔑 Hash Table（13）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 49 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | 🟡 Medium | Hash Table Mapping | [C++](problems/0049.md) | O(N\*logK) | O(N\*K) | 2026-09-16 |
| 219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) | 🟢 Easy | Hash Table Existence | [C++](problems/0219.md) | O(N) | O(min(N,K)) |  |
| 242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | 🟢 Easy | Hash Table Intersection, Hash Table | [C++](problems/0242.md) | O(N) | O(1) |  |
| 594 | [Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/) | 🟢 Easy | Hash Table Existence | [C++](problems/0594.md) | O(N) | O(N) |  |
| 884 | [Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences) | 🟢 Easy | Hash Table Uniqueness | [C++](problems/0884.md) | O(N+M) | O(N+M) |  |
| 1460 | [Make Two Arrays Equal by Reversing Subarrays](https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/) | 🟢 Easy | Hash Table Intersection, Hash Table | [C++](problems/1460.md) | O(N) | O(K) |  |
| 1496 | [Path Crossing](https://leetcode.com/problems/path-crossing/) | 🟢 Easy | Hash Table Uniqueness, Hash Set, Coordinates | [C++](problems/1496.md) | O(N) | O(N) |  |
| 2154 | [Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two) | 🟢 Easy | Hash Table Existence | [C++](problems/2154.md) | O(N) | O(N) |  |
| 2341 | [Maximum Number of Pairs in Array](https://leetcode.com/problems/maximum-number-of-pairs-in-array/) | 🟢 Easy | Array, Hash Table, Counting | [C++](problems/2341.md) | O(N) | O(1) |  |
| 2352 | [Equal Row and Column Pairs](https://leetcode.com/problems/equal-row-and-column-pairs/) | 🟡 Medium | Hash Table Intersection, Hash Map, Matrix Simulation | [C++](problems/2352.md) | O(N³logN) | O(N²) |  |
| 2442 | [Count Number of Distinct Integers After Reverse Operations](https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/) | 🟡 Medium | Hash Table Uniqueness, Hash Table, Math, Bitset | [C++](problems/2442.md) | O(N\*D) | O(M) |  |
| 3289 | [The Two Sneaky Numbers of Digitville](https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/) | 🟢 Easy | Bit Manipulation, Hash Table | [C++](problems/3289.md) | O(N) | O(1) |  |
| 3438 | [Find Valid Pair of Adjacent Digits in String](https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/) | 🟢 Easy | Hash Table Counting, Hash Map | [C++](problems/3438.md) | O(N) | O(1) |  |

<a id="lianxiguo-priority-queue"></a>
#### 📚 Priority Queue（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 Medium | Priority Queue | [C++](problems/0347.md) | O(NlogN) | O(N) |  |

<a id="lianxiguo-quick-select"></a>
#### 📚 Quick Select（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 Medium | Quick Select, Hash Table, QuickSelect | [C++](problems/0347.md) | O(N) | O(N) |  |

<a id="lianxiguo-sorting"></a>
#### 📊 Sorting（13）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 179 | [Largest Number](https://leetcode.com/problems/largest-number/) | 🟡 Medium | Sorting Custom Comparator, String | [C++](problems/0179.md) | O(NlogN\*K) | O(N\*K) |  |
| 451 | [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency) | 🟡 Medium | Sorting Bucket Sort, Hash Table, Bucket Sort | [C++](problems/0451.md) | O(N) | O(N) |  |
| 539 | [Minimum Time Difference](https://leetcode.com/problems/minimum-time-difference/) | 🟡 Medium | Sorting, Sorting | [C++](problems/0539.md) | O(NlogN) | O(N) |  |
| 1051 | [Height Checker](https://leetcode.com/problems/height-checker/) | 🟢 Easy | Sorting Counting Sort, Counting Sort | [C++](problems/1051.md) | O(N) | O(1) |  |
| 1122 | [Relative Sort Array](https://leetcode.com/problems/relative-sort-array/) | 🟢 Easy | Sorting Counting Sort, Counting Sort | [C++](problems/1122.md) | O(N+M) | O(1) |  |
| 1481 | [Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/) | 🟡 Medium | Sorting Custom Comparator, Sorting | [C++](problems/1481.md) | O(NlogN) | O(N) |  |
| 1984 | [Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/) | 🟢 Easy | Sorting, Sliding Window | [C++](problems/1984.md) | O(NlogN) | O(1) |  |
| 2418 | [Sort the People](https://leetcode.com/problems/sort-the-people) | 🟢 Easy | Sorting Custom Comparator, Sorting, Hash Table | [C++](problems/2418.md) | O(NlogN) | O(N) |  |
| 2491 | [Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/) | 🟡 Medium | Sorting, Two Pointers, Sorting | [C++](problems/2491.md) | O(NlogN) | O(1) |  |
| 2785 | [Sort Vowels in a String](https://leetcode.com/problems/sort-vowels-in-a-string/) | 🟡 Medium | Sorting Counting Sort, Counting Sort | [C++](problems/2785.md) | O(N) | O(1) |  |
| 2785 | [Sort Vowels in a String](https://leetcode.com/problems/sort-vowels-in-a-string/) | 🟡 Medium | Sorting | [C++](problems/2785.md) | O(N) | O(N) |  |
| 2974 | [Minimum Number Game](https://leetcode.com/problems/minimum-number-game/) | 🟢 Easy | Sorting | [C++](problems/2974.md) | O(N) | O(N) |  |
| 3913 | [Sort Vowels by Frequency](https://leetcode.com/problems/sort-vowels-by-frequency/) | 🟡 Medium | Sorting Custom Comparator, Hash | [C++](problems/3913.md) | O(NlogN) | O(N) |  |

<a id="lianxiguo-dynamic-programming"></a>
#### 🧩 Dynamic Programming（30）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | 🟡 Medium | Dp Grid Path, Dynamic Programming Grid Path, DP | [C++](problems/0064.md) | O(M\*N) | O(1) |  |
| 72 | [Edit Distance](https://leetcode.com/problems/edit-distance/) | 🟡 Medium | Dp Lcs, Dynamic Programming Lcs, DP | [C++](problems/0072.md) | O(N\*M) | O(N\*M) |  |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | 🟢 Easy | Dp State Machine, Dynamic Programming State Machine | [C++](problems/0121.md) | O(N) | O(1) |  |
| 122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | 🟡 Medium | Dp State Machine | [C++](problems/0122.md) | O(N) | O(1) |  |
| 152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | 🟡 Medium | Dp Kadane, Array | [C++](problems/0152.md) | O(N) | O(1) |  |
| 198 | [House Robber](https://leetcode.com/problems/house-robber/) | 🟡 Medium | Dynamic Programming Fibonacci, DP, Linear Optimization | [C++](problems/0198.md) | O(N) | O(1) |  |
| 198 | [House Robber](https://leetcode.com/problems/house-robber/) | 🟡 Medium | Dynamic Programming Fibonacci | [C++](problems/0198.md) | O(N) | O(N) |  |
| 221 | [Maximal Square](https://leetcode.com/problems/maximal-square/) | 🟡 Medium | Dp Grid Path | [C++](problems/0221.md) | O(M\*N) | O(M\*N) |  |
| 264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | 🟡 Medium | Dp Greedy Pointer, Math | [C++](problems/0264.md) | O(N) | O(N) |  |
| 279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](problems/0279.md) | O(N\*√N) | O(N) |  |
| 300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Dp Lis, Dynamic Programming Lis | [C++](problems/0300.md) | O(N²) | O(N) |  |
| 313 | [Super Ugly Number](https://leetcode.com/problems/super-ugly-number/) | 🟡 Medium | Dp Greedy Pointer, Multi-pointers | [C++](problems/0313.md) | O(N\*K) | O(N+K) |  |
| 322 | [Coin Change](https://leetcode.com/problems/coin-change/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](problems/0322.md) | O(A\*N) | O(A) |  |
| 337 | [House Robber III](https://leetcode.com/problems/house-robber-iii/) | 🟡 Medium | Dp Tree, DP | [C++](problems/0337.md) | O(N) | O(H) |  |
| 377 | [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](problems/0377.md) | O(A\*N) | O(A) |  |
| 416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | 🟡 Medium | Dp Knapsack, 0-1 Knapsack | [C++](problems/0416.md) | O(N\*S) | O(NS) | 2026-09-18 |
| 474 | [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeros/) | 🟡 Medium | Dp Knapsack, 0-1 Knapsack | [C++](problems/0474.md) | O(LM\*N) | O(M\*N) |  |
| 494 | [Target Sum](https://leetcode.com/problems/target-sum/) | 🟡 Medium | Dp Knapsack, 0-1 Knapsack | [C++](problems/0494.md) | O(N\*S) | O(S) |  |
| 516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) | 🟡 Medium | Dp Lis, Dynamic Programming Lcs, DP | [C++](problems/0516.md) | O(N²) | O(N) |  |
| 518 | [Coin Change II](https://leetcode.com/problems/coin-change-ii/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](problems/0518.md) | O(N\*A) | O(A) |  |
| 583 | [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) | 🟡 Medium | Dynamic Programming Lcs | [C++](problems/0583.md) | O(M\*N) | O(M\*N) |  |
| 718 | [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) | 🟡 Medium | Dp Lcs | [C++](problems/0718.md) | O(N\*M) | O(M) |  |
| 746 | [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) | 🟢 Easy | Dp Fibonacci, Dynamic Programming Fibonacci | [C++](problems/0746.md) | O(N) | O(N) |  |
| 746 | [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) | 🟢 Easy | Dp Fibonacci | [C++](problems/0746.md) | O(N) | O(1) |  |
| 1035 | [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/) | 🟡 Medium | Dynamic Programming Lcs, DP, LCS | [C++](problems/1035.md) | O(N\*M) | O(M) |  |
| 1049 | [Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/) | 🟡 Medium | 0-1 Knapsack | [C++](problems/1049.md) | O(N\*S) | O(S) |  |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 Medium | Dp Lcs, Dynamic Programming Lcs | [C++](problems/1143.md) | O(M\*N) | O(M\*N) |  |
| 1567 | [Maximum Length of Subarray With Positive Product](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/) | 🟡 Medium | Dp Kadane, Dynamic Programming Kadane | [C++](problems/1567.md) | O(N) | O(1) |  |
| 2707 | [Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](problems/2707.md) | O(N³) | O(N+D) |  |
| 2826 | [Sorting Three Groups](https://leetcode.com/problems/sorting-three-groups/) | 🟡 Medium | Dp Lis, Dynamic Programming Lis, Longest Non-Decreasing Subsequence | [C++](problems/2826.md) | O(N) | O(1) |  |

<a id="lianxiguo-greedy"></a>
#### 🧩 Greedy（12）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 402 | [Remove K Digits](https://leetcode.com/problems/remove-k-digits/) | 🟡 Medium | Greedy Digit Construction | [C++](problems/0402.md) | O(N) | O(N) |  |
| 1005 | [Maximize Sum Of Array After K Negations](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/) | 🟢 Easy | Greedy Sorting Decision, Sorting | [C++](problems/1005.md) | O(NlogN) | O(1) |  |
| 1029 | [Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/) | 🟡 Medium | Greedy Sorting Decision | [C++](problems/1029.md) | O(N log N) | O(1) |  |
| 1710 | [Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/) | 🟢 Easy | Greedy Sorting Decision | [C++](problems/1710.md) | O(N log N) | O(1) |  |
| 2208 | [Minimum Operations to Halve Array Sum](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/) | 🟡 Medium | Greedy Priority Queue | [C++](problems/2208.md) | O(N + K log N) | O(N) |  |
| 2231 | [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/) | 🟢 Easy | Greedy Sorting Decision, Partition by Parity | [C++](problems/2231.md) | O(DlogD) | O(D) | 2026-09-25 |
| 2259 | [Remove Digit From Number to Maximize Result](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/) | 🟢 Easy | Greedy Digit Construction, String | [C++](problems/2259.md) | O(N) | O(N) |  |
| 2279 | [Maximum Bags With Full Capacity of Rocks](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/) | 🟡 Medium | Greedy Sorting Decision | [C++](problems/2279.md) | O(N log N) | O(N) |  |
| 2554 | [Maximum Number of Integers to Choose From a Range I](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/) | 🟡 Medium | Greedy Selection Constraints, Hash Table, Greedy, Sorting | [C++](problems/2554.md) | O(N+M) | O(M) |  |
| 2645 | [Minimum Additions to Make Valid String](https://leetcode.com/problems/minimum-additions-to-make-valid-string/) | 🟡 Medium | Greedy, Simulation | [C++](problems/2645.md) | O(N) | O(1) |  |
| 2966 | [Divide Array Into Arrays With Max Difference](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/) | 🟡 Medium | Greedy Sorting Decision, Greedy, Sorting | [C++](problems/2966.md) | O(NlogN) | O(1) |  |
| 3114 | [Latest Time You Can Obtain After Replacing Characters](https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/) | 🟢 Easy | Greedy, String | [C++](problems/3114.md) | O(1) | O(1) |  |

<a id="lianxiguo-backtracking"></a>
#### 🔢 Backtracking（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 2094 | [Finding 3-Digit Even Numbers](https://leetcode.com/problems/finding-3-digit-even-numbers/) | 🟢 Easy | Backtracking Combination, Hash Table | [C++](problems/2094.md) | O(N) | O(1) |  |

---

<a id="review-zailianxi"></a>
## 🟠 再練習清單

目前共有 211 個解法標記為再練習，需要加強熟練度。

📌 **快速跳轉：** [🎨 Design（5）](#zailianxi-design)　[🔢 Math（38）](#zailianxi-math)　[📊 Bit Manipulation（19）](#zailianxi-bit-manipulation)　[🔗 String（17）](#zailianxi-string)　[🍱 Array（32）](#zailianxi-array)　[🌳 Tree（20）](#zailianxi-tree)　[🔍 Binary Search（1）](#zailianxi-binary-search)　[⛓️ Linked List（5）](#zailianxi-linked-list)　[👥 Pointers（11）](#zailianxi-pointers)　[🔑 Hash Table（23）](#zailianxi-hash-table)　[📚 Stack（5）](#zailianxi-stack)　[📚 Queue（1）](#zailianxi-queue)　[📚 Quick Select（4）](#zailianxi-quick-select)　[📊 Sorting（6）](#zailianxi-sorting)　[🧩 Dynamic Programming（3）](#zailianxi-dynamic-programming)　[🧩 Greedy（20）](#zailianxi-greedy)　[📄 Other（1）](#zailianxi-other)

<a id="zailianxi-design"></a>
#### 🎨 Design（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 146 | [LRU Cache](https://leetcode.com/problems/lru-cache/) | 🟡 Medium | Design, Hash Table, Doubly Linked List, Design | [C++](problems/0146.md) | O(1) | O(Capacity) |  |
| 155 | [Min Stack](https://leetcode.com/problems/min-stack) | 🟡 Medium | Design, Design | [C++](problems/0155.md) | O(1) | O(N) |  |
| 232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) | 🟢 Easy | Design, Queue | [C++](problems/0232.md) | O(1) | O(N) |  |
| 705 | [Design HashSet](https://leetcode.com/problems/design-hashset) | 🟢 Easy | Design, Hash Table | [C++](problems/0705.md) | O(1) | O(N) |  |
| 706 | [Design HashMap](https://leetcode.com/problems/design-hashmap/) | 🟢 Easy | Design, Hash Table | [C++](problems/0706.md) | O(N/K) | O(M+K) |  |

<a id="zailianxi-math"></a>
#### 🔢 Math（38）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 7 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | 🟡 Medium | Math Digit Decomposition | [C++](problems/0007.md) | O(logN) | O(1) | 2026-09-17 |
| 9 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | Math | [C++](problems/0009.md) | O(logN) | O(1) |  |
| 62 | [Unique Paths](https://leetcode.com/problems/unique-paths/) | 🟡 Medium | Math Combination, Combinatorics, DP | [C++](problems/0062.md) | O(min(M,N)) | O(1) |  |
| 66 | [Plus One](https://leetcode.com/problems/plus-one/) | 🟢 Easy | Math | [C++](problems/0066.md) | O(N) | O(1) |  |
| 137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Math, Hash Set | [C++](problems/0137.md) | O(N) | O(N) |  |
| 168 | [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/) | 🟢 Easy | Math Digit Decomposition, Base Conversion | [C++](problems/0168.md) | O(log26N) | O(1) | 2026-09-17 |
| 172 | [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes) | 🟡 Medium | Math | [C++](problems/0172.md) | O(log₅N) | O(1) |  |
| 258 | [Add Digits](https://leetcode.com/problems/add-digits) | 🟢 Easy | Math | [C++](problems/0258.md) | O(1) | O(1) |  |
| 342 | [Power of Four](https://leetcode.com/problems/power-of-four/) | 🟢 Easy | Math | [C++](problems/0342.md) | O(1) | O(1) | 2026-09-22 |
| 365 | [Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/) | 🟡 Medium | Math, GCD, Bézout's Identity | [C++](problems/0365.md) | O(log(min(x,y))) | O(1) |  |
| 405 | [Convert a Number to Hexadecimal](https://leetcode.com/problems/convert-a-number-to-hexadecimal/) | 🟢 Easy | Math Digit Decomposition, Bit Manipulation | [C++](problems/0405.md) | O(1) | O(1) | 2026-09-17 |
| 504 | [Base 7](https://leetcode.com/problems/base-7) | 🟢 Easy | Math Digit Decomposition, String | [C++](problems/0504.md) | O(log₇N) | O(1) | 2026-09-17 |
| 507 | [Perfect Number](https://leetcode.com/problems/perfect-number/) | 🟢 Easy | Math Factor Enumeration | [C++](problems/0507.md) | O(√N) | O(1) | 2026-09-23 |
| 836 | [Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/) | 🟡 Medium | Math Geometry, Geometry | [C++](problems/0836.md) | O(1) | O(1) | 2026-09-23 |
| 866 | [Prime Palindrome](https://leetcode.com/problems/prime-palindrome/) | 🟡 Medium | Math Prime, Prime, Palindrome Construction | [C++](problems/0866.md) | O(sqrt(10^9)) | O(1) |  |
| 949 | [Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/) | 🟡 Medium | Math Permutation, Permutation | [C++](problems/0949.md) | O(1) | O(1) | 2026-09-24 |
| 1015 | [Smallest Integer Divisible by K](https://leetcode.com/problems/smallest-integer-divisible-by-k/) | 🟡 Medium | Modular Arithmetic | [C++](problems/1015.md) | O(K) | O(1) |  |
| 1017 | [Convert to Base -2](https://leetcode.com/problems/convert-to-base-2) | 🟡 Medium | Math, 504, 1837 | [C++](problems/1017.md) | O(logN) | O(1) |  |
| 1018 | [Binary Prefix Divisible By 5](https://leetcode.com/problems/binary-prefix-divisible-by-5/) | 🟢 Easy | Math, Modulo | [C++](problems/1018.md) | O(N) | O(1) | 2026-09-20 |
| 1071 | [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/) | 🟢 Easy | Math Gcd, String, GCD | [C++](problems/1071.md) | O(N+M) | O(N+M) |  |
| 1344 | [Angle Between Hands of a Clock](https://leetcode.com/problems/angle-between-hands-of-a-clock/) | 🟡 Medium | Math | [C++](problems/1344.md) | O(1) | O(1) |  |
| 1374 | [Generate a String With Characters That Have Odd Counts](https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/) | 🟢 Easy | Math, Construction | [C++](problems/1374.md) | O(N) | O(N) |  |
| 1523 | [Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/) | 🟢 Easy | Math | [C++](problems/1523.md) | O(1) | O(1) | 2026-09-22 |
| 1780 | [Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/) | 🟡 Medium | Math, Base-3 | [C++](problems/1780.md) | O(log₃N) | O(1) |  |
| 1925 | [Count Square Sum Triples](https://leetcode.com/problems/count-square-sum-triples/) | 🟢 Easy | Math, Brute Force | [C++](problems/1925.md) | O(N²) | O(1) |  |
| 1927 | [Sum Game](https://leetcode.com/problems/sum-game/) | 🟡 Medium | Math Game Theory, Game Theory | [C++](problems/1927.md) | O(N) | O(1) |  |
| 1952 | [Three Divisors](https://leetcode.com/problems/three-divisors) | 🟢 Easy | Math Prime | [C++](problems/1952.md) | O(√N) | O(1) |  |
| 2063 | [Vowels of All Substrings](https://leetcode.com/problems/vowels-of-all-substrings/) | 🟡 Medium | Math, Contribution Technique | [C++](problems/2063.md) | O(N) | O(1) |  |
| 2119 | [A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal/) | 🟢 Easy | Math | [C++](problems/2119.md) | O(1) | O(1) | 2026-09-22 |
| 2169 | [Count Operations to Obtain Zero](https://leetcode.com/problems/count-operations-to-obtain-zero/) | 🟢 Easy | Math Factor Enumeration, Euclidean Algorithm, Simulation | [C++](problems/2169.md) | O(log(min(NUM1,NUM2))) | O(1) |  |
| 2396 | [Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/) | 🟡 Medium | Math, Brainteaser | [C++](problems/2396.md) | O(1) | O(1) |  |
| 2427 | [Number of Common Factors](https://leetcode.com/problems/number-of-common-factors/) | 🟢 Easy | Math Gcd, Number Theory, GCD | [C++](problems/2427.md) | O(min(A,B)) | O(1) |  |
| 2485 | [Find the Pivot Integer](https://leetcode.com/problems/pivot-integer/) | 🟢 Easy | Math | [C++](problems/2485.md) | O(1) | O(1) |  |
| 2523 | [Closest Prime Numbers in Range](https://leetcode.com/problems/closest-prime-numbers-in-range/) | 🟡 Medium | Math, Sieve | [C++](problems/2523.md) | O(NloglogN) | O(N) |  |
| 2761 | [Prime Pairs With Target Sum](https://leetcode.com/problems/prime-pairs-with-target-sum/) | 🟡 Medium | Math Prime, Sieve | [C++](problems/2761.md) | O(NloglogN) | O(N) | 2026-09-23 |
| 3658 | [GCD of Odd and Even Sums](https://leetcode.com/problems/gcd-of-odd-and-even-sums) | 🟢 Easy | Math Gcd | [C++](problems/3658.md) | O(1) | O(1) | 2026-09-22 |
| 3697 | [Compute Decimal Representation](https://leetcode.com/problems/compute-decimal-representation/) | 🟢 Easy | Math Digit Decomposition, Digit Extraction | [C++](problems/3697.md) | O(logN) | [Note](#3697-compute-decimal-representation) | 2026-09-17 |
| 3765 | [Complete Prime Number](https://leetcode.com/problems/complete-prime-number/) | 🟢 Easy | Math Prime, Prime Number | [C++](problems/3765.md) | O(D\*sqrt(N)) | O(D) | 2026-09-24 |

<a id="zailianxi-bit-manipulation"></a>
#### 📊 Bit Manipulation（19）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 36 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku) | 🟡 Medium | Bit Manipulation, Hash Table, Bitset | [C++](problems/0036.md) | O(1) | O(1) |  |
| 89 | [Gray Code](https://leetcode.com/problems/gray-code/) | 🟡 Medium | Bit Manipulation, Math | [C++](problems/0089.md) | O(2ᴺ) | O(1) |  |
| 137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Bit Manipulation, Bit-Manipulation | [C++](problems/0137.md) | O(N) | O(1) |  |
| 201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range) | 🟡 Medium | Bit Manipulation | [C++](problems/0201.md) | O(logN) | O(1) |  |
| 260 | [Single Number III](https://leetcode.com/problems/single-number-iii) | 🟡 Medium | Bit Manipulation | [C++](problems/0260.md) | O(N) | O(1) |  |
| 371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers) | 🟡 Medium | Bit Manipulation | [C++](problems/0371.md) | O(1) | O(1) |  |
| 693 | [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/) | 🟢 Easy | Bit Manipulation | [C++](problems/0693.md) | O(1) | O(1) |  |
| 693 | [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/) | 🟢 Easy | Bit Manipulation And | [C++](problems/0693.md) | O(logn) | O(1) |  |
| 1342 | [Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/) | 🟢 Easy | Bit Manipulation, Math | [C++](problems/1342.md) | O(1) | O(1) |  |
| 2133 | [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) | 🟢 Easy | Bit Manipulation, Hash Table, Bitset | [C++](problems/2133.md) | O(N²) | O(N) | 2026-09-17 |
| 2206 | [Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs) | 🟢 Easy | Bit Manipulation, Hash Table, Counting | [C++](problems/2206.md) | O(N) | O(1) |  |
| 2235 | [Add Two Integers](https://leetcode.com/problems/add-two-integers) | 🟢 Easy | Bit Manipulation | [C++](problems/2235.md) | O(1) | O(1) |  |
| 2605 | [Form Smallest Number From Two Digit Arrays](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/) | 🟢 Easy | Bit Manipulation, Bitmask | [C++](problems/2605.md) | O(N+M) | O(1) | 2026-09-17 |
| 2683 | [Neighboring Bitwise XOR](https://leetcode.com/problems/neighboring-bitwise-xor/) | 🟡 Medium | Bit Manipulation Xor, Math | [C++](problems/2683.md) | O(N) | O(1) | 2026-09-18 |
| 3120 | [Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/) | 🟢 Easy | Bit Manipulation | [C++](problems/3120.md) | O(N) | O(1) | 2026-09-17 |
| 3120 | [Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/) | 🟢 Easy | Bit Manipulation And | [C++](problems/3120.md) | O(N) | O(1) | 2026-09-17 |
| 3226 | [Number of Bit Changes to Make Two Integers Equal](https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/) | 🟢 Easy | Bit Manipulation | [C++](problems/3226.md) | O(1) | O(1) | 2026-09-18 |
| 3702 | [Longest Subsequence With Non-Zero Bitwise XOR](https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/) | 🟡 Medium | Bit Manipulation, Greedy | [C++](problems/3702.md) | O(N) | O(1) | 2026-09-18 |
| 3827 | [Count Monobit Integers](https://leetcode.com/problems/count-monobit-integers/) | 🟢 Easy | Bit Manipulation | [C++](problems/3827.md) | O(1) | O(1) | 2026-09-17 |

<a id="zailianxi-string"></a>
#### 🔗 String（17）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 14 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | String | [C++](problems/0014.md) | O(S) | O(1) | 2026-09-21 |
| 58 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word) | 🟢 Easy | String | [C++](problems/0058.md) | O(N) | O(1) | 2026-09-21 |
| 524 | [Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/) | 🟡 Medium | String, Two Pointers | [C++](problems/0524.md) | O(DlogD+D\*M) | O(1) |  |
| 791 | [Custom Sort String](https://leetcode.com/problems/custom-sort-string/) | 🟡 Medium | String, Counting Sort | [C++](problems/0791.md) | O(N+M) | O(1) | 2026-09-26 |
| 796 | [Rotate String](https://leetcode.com/problems/rotate-string) | 🟢 Easy | String | [C++](problems/0796.md) | O(N) | O(N) |  |
| 806 | [Number of Lines To Write String](https://leetcode.com/problems/number-of-lines-to-write-string/) | 🟢 Easy | String, String, Simulation | [C++](problems/0806.md) | O(N) | O(1) | 2026-09-25 |
| 1704 | [Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/) | 🟢 Easy | String Character Classification | [C++](problems/1704.md) | O(N) | O(1) | 2026-09-23 |
| 1758 | [Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string) | 🟢 Easy | String | [C++](problems/1758.md) | O(N) | O(1) | 2026-09-21 |
| 1910 | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/) | 🟡 Medium | String, String | [C++](problems/1910.md) | O(N\*M) | O(N) | 2026-09-21 |
| 1945 | [Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/) | 🟢 Easy | String, Simulation | [C++](problems/1945.md) | O(N+K\*log(SUM)) | O(1) |  |
| 1957 | [Delete Characters...](https://leetcode.com/problems/delete-characters-to-make-fancy-string/) | 🟢 Easy | String Character Classification, Two Pointers | [C++](problems/1957.md) | O(N) | O(N) | 2026-09-20 |
| 2138 | [Divide a String Into Groups of Size k](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/) | 🟢 Easy | String, Simulation, Math | [C++](problems/2138.md) | O(N) | O(N) |  |
| 2243 | [Calculate Digit Sum of a String](https://leetcode.com/problems/calculate-digit-sum-of-a-string/) | 🟢 Easy | String, Simulation | [C++](problems/2243.md) | O(N\*logN) | O(N) | 2026-09-20 |
| 2496 | [Maximum Value of a String in an Array](https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/) | 🟢 Easy | Array, String, Simulation | [C++](problems/2496.md) | O(N\*L) | O(1) |  |
| 2839 | [Check if Strings Can be Made Equal With Operations I](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/) | 🟢 Easy | String Character Classification | [C++](problems/2839.md) | O(1) | O(1) | 2026-09-21 |
| 3775 | [Reverse Words With Same Vowel Count](https://leetcode.com/problems/reverse-words-with-same-vowel-count/) | 🟢 Easy | String Character Classification, Two Pointers | [C++](problems/3775.md) | O(N\*L) | O(N) | 2026-09-20 |
| 3813 | [Vowel-Consonant Score](https://leetcode.com/problems/vowel-consonant-score/) | 🟢 Easy | String Character Classification | [C++](problems/3813.md) | O(N) | O(1) | 2026-09-20 |

<a id="zailianxi-array"></a>
#### 🍱 Array（32）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 169 | [Majority Element](https://leetcode.com/problems/majority-element/) | 🟢 Easy | Array Boyer Moore, Voting Algorithm | [C++](problems/0169.md) | O(N) | O(1) |  |
| 189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | 🟡 Medium | Array | [C++](problems/0189.md) | O(N) | O(1) |  |
| 268 | [Missing Number](https://leetcode.com/problems/missing-number) | 🟢 Easy | Array Negative Marking | [C++](problems/0268.md) | O(N) | O(1) | 2026-09-23 |
| 287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | 🟡 Medium | Array Negative Marking | [C++](problems/0287.md) | O(N) | O(1) | 2026-09-25 |
| 442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array) | 🟡 Medium | Array Negative Marking, Fast-Slow Pointers, Two Pointers | [C++](problems/0442.md) | O(N) | O(1) |  |
| 448 | [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array) | 🟢 Easy | Array Negative Marking | [C++](problems/0448.md) | O(N) | O(1) |  |
| 645 | [Set Mismatch](https://leetcode.com/problems/set-mismatch) | 🟢 Easy | Array Negative Marking, Hash Table | [C++](problems/0645.md) | O(N) | O(1) |  |
| 697 | [Degree of an Array](https://leetcode.com/problems/degree-of-an-array/) | 🟢 Easy | Array Continuous Counting, Hash Map, One-pass | [C++](problems/0697.md) | O(N) | O(N) |  |
| 717 | [1-bit and 2-bit Characters](https://leetcode.com/problems/1-bit-and-2-bit-characters/) | 🟢 Easy | Array, Simulation | [C++](problems/0717.md) | O(N) | O(1) | 2026-09-18 |
| 724 | [Find Pivot Index](https://leetcode.com/problems/find-pivot-index) | 🟢 Easy | Array Prefix Sum, Prefix Sum | [C++](problems/0724.md) | O(N) | O(1) |  |
| 821 | [Shortest Distance to a Character](https://leetcode.com/problems/shortest-distance-to-a-character/) | 🟢 Easy | Array, Two-Pass Scan | [C++](problems/0821.md) | O(N) | O(1) | 2026-09-18 |
| 830 | [Positions of Large Groups](https://leetcode.com/problems/positions-of-large-groups/) | 🟢 Easy | Array, String, Two Pointers | [C++](problems/0830.md) | O(N) | O(1) |  |
| 1013 | [Partition Array Into Three Parts With Equal Sum](https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/) | 🟢 Easy | Array Linear Scan, Greedy, Prefix Sum | [C++](problems/1013.md) | O(N) | O(1) | 2026-09-22 |
| 1094 | [Car Pooling](https://leetcode.com/problems/car-pooling/) | 🟡 Medium | Array Difference Array, Difference Array, Sweep Line | [C++](problems/1094.md) | O(N+M) | O(M) |  |
| 1109 | [Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/) | 🟡 Medium | Array Difference Array, Difference Array | [C++](problems/1109.md) | O(N+K) | O(N) |  |
| 1299 | [Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side) | 🟢 Easy | Array | [C++](problems/1299.md) | O(N) | O(1) |  |
| 1309 | [Decrypt String from Alphabet to Integer Mapping](https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/) | 🟢 Easy | Array Linear Scan, Hash Table, String Parsing | [C++](problems/1309.md) | O(N) | O(1) |  |
| 1389 | [Create Target Array in the Given Order](https://leetcode.com/problems/create-target-array-in-the-given-order/) | 🟢 Easy | Array, Simulation | [C++](problems/1389.md) | O(N²) | O(N) | 2026-09-17 |
| 1422 | [Maximum Score After Splitting a String](https://leetcode.com/problems/maximum-score-after-splitting-a-string/) | 🟢 Easy | Array Linear Scan | [C++](problems/1422.md) | O(N) | O(1) |  |
| 1431 | [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) | 🟢 Easy | Array | [C++](problems/1431.md) | O(N) | O(1) |  |
| 1470 | [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/) | 🟢 Easy | Array | [C++](problems/1470.md) | O(N) | O(N) | 2026-09-25 |
| 1513 | [Number of Substrings With Only 1s](https://leetcode.com/problems/number-of-substrings-with-only-1s/) | 🟡 Medium | Array Continuous Counting, String, Dynamic Programming | [C++](problems/1513.md) | O(N) | O(1) |  |
| 1800 | [Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum) | 🟢 Easy | Array Continuous Counting | [C++](problems/1800.md) | O(N) | O(1) |  |
| 1854 | [Maximum Population Year](https://leetcode.com/problems/maximum-population-year/) | 🟢 Easy | Array Difference Array, Difference Array, Sweep Line | [C++](problems/1854.md) | O(N+Y) | O(Y) |  |
| 2609 | [Find the Longest Balanced Substring](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/) | 🟢 Easy | Greedy, Two Counters | [C++](problems/2609.md) | O(N) | O(1) |  |
| 2639 | [Find the Width of Columns of a Grid](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/) | 🟢 Easy | 2d Array, Simulation | [C++](problems/2639.md) | O(M\*N\*D) | O(1) | 2026-09-16 |
| 2855 | [Minimum Right Shifts to Sort the Array](https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/) | 🟢 Easy | Array, Circular Array | [C++](problems/2855.md) | O(N) | O(1) | 2026-09-17 |
| 3142 | [Check if Grid Satisfies Conditions](https://leetcode.com/problems/check-if-grid-satisfies-conditions/) | 🟢 Easy | 2d Array, Simulation | [C++](problems/3142.md) | O(M\*N) | O(1) | 2026-09-16 |
| 3417 | [Zigzag Grid Traversal With Skip](https://leetcode.com/problems/zigzag-grid-traversal-with-skip/) | 🟢 Easy | 2d Array, Simulation | [C++](problems/3417.md) | O(M\*N) | O(M\*N) | 2026-09-16 |
| 3452 | [Sum of Good Numbers](https://leetcode.com/problems/sum-of-good-numbers/) | 🟢 Easy | Array, Simulation | [C++](problems/3452.md) | O(N) | O(1) | 2026-09-22 |
| 3477 | [Fruits Into Baskets II](https://leetcode.com/problems/fruits-into-baskets-ii/) | 🟢 Easy | Array, Simulation, Brute Force | [C++](problems/3477.md) | O(N^2) | O(1) |  |
| 3978 | [Unique Middle Element](https://leetcode.com/problems/unique-middle-element/) | 🟢 Easy | Array | [C++](problems/3978.md) | O(N) | O(1) | 2026-09-21 |

<a id="zailianxi-tree"></a>
#### 🌳 Tree（20）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-zigzag-level-order-traversal/) | 🟡 Medium | Tree Bfs Level Order, BFS | [C++](problems/0103.md) | O(N) | O(W) |  |
| 103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-zigzag-level-order-traversal/) | 🟡 Medium | Tree Bfs Level Order | [C++](problems/0103.md) | O(N) | O(N) |  |
| 108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) | 🟢 Easy | Binary Search Tree, DFS, Binary Search | [C++](problems/0108.md) | O(N) | O(logN) | 2026-09-26 |
| 110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | 🟢 Easy | Tree Dfs Path, DFS | [C++](problems/0110.md) | O(N) | O(H) | 2026-09-25 |
| 116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) | 🟡 Medium | Tree Bfs Level Order, Recursion, Constant Space | [C++](problems/0116.md) | O(N) | O(1) | 2026-09-14 |
| 129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) | 🟡 Medium | Tree Dfs Path, DFS | [C++](problems/0129.md) | O(N) | O(H) | 2026-09-25 |
| 222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes) | 🟢 Easy | Tree Dfs Path, DFS, Binary Search | [C++](problems/0222.md) | O(log²N) | O(logN) | 2026-09-26 |
| 235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | 🟢 Easy | Binary Search Tree | [C++](problems/0235.md) | O(H) | O(1) |  |
| 617 | [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees) | 🟢 Easy | Tree Dfs Path, DFS, Recursion | [C++](problems/0617.md) | O(min(N,M)) | O(min(N,M)) | 2026-09-25 |
| 652 | [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/) | 🟡 Medium | Tree Dfs Global, DFS, Hash Table, Serialization | [C++](problems/0652.md) | O(N²) | O(N²) | 2026-09-26 |
| 662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) | 🟡 Medium | Tree Bfs Level Order, BFS | [C++](problems/0662.md) | O(N) | O(W) | 2026-09-14 |
| 701 | [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree) | 🟡 Medium | Binary Search Tree, Binary Search Tree | [C++](problems/0701.md) | O(H) | O(H) | 2026-09-25 |
| 938 | [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst) | 🟢 Easy | Binary Search Tree, DFS, BST | [C++](problems/0938.md) | O(N) | O(H) | 2026-09-25 |
| 958 | [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) | 🟡 Medium | Tree Bfs Level Order, BFS, Level Order Traversal | [C++](problems/0958.md) | O(N) | O(N) | 2026-09-14 |
| 965 | [Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree) | 🟢 Easy | Tree Dfs Path, DFS | [C++](problems/0965.md) | O(N) | O(H) | 2026-09-25 |
| 988 | [Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/) | 🟡 Medium | Tree Dfs Backtracking, DFS | [C++](problems/0988.md) | O(N) | O(H) | 2026-09-25 |
| 1379 | [Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/) | 🟢 Easy | Tree Dfs Path, DFS, Tree Traversal | [C++](problems/1379.md) | O(N) | O(H) |  |
| 1609 | [Even Odd Tree](https://leetcode.com/problems/even-odd-tree/) | 🟡 Medium | Tree Bfs Level Order, BFS | [C++](problems/1609.md) | O(N) | O(W) | 2026-09-14 |
| 2331 | [Evaluate Boolean Binary Tree](https://leetcode.com/problems/evaluate-boolean-binary-tree) | 🟢 Easy | Tree Dfs Path, DFS, Recursion | [C++](problems/2331.md) | O(N) | O(H) | 2026-09-25 |
| 2583 | [Kth Largest Sum in a Binary Tree](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/) | 🟡 Medium | Tree Bfs Level Order, BFS, Math | [C++](problems/2583.md) | O(N) | O(N) |  |

<a id="zailianxi-binary-search"></a>
#### 🔍 Binary Search（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) | 🟢 Easy | Binary Search | [C++](problems/0367.md) | O(logN) | O(1) | 2026-09-26 |

<a id="zailianxi-linked-list"></a>
#### ⛓️ Linked List（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 83 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list) | 🟢 Easy | Linked List | [C++](problems/0083.md) | O(N) | O(1) |  |
| 203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements) | 🟢 Easy | Linked List | [C++](problems/0203.md) | O(N) | O(1) |  |
| 237 | [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list) | 🟢 Easy | Linked List | [C++](problems/0237.md) | O(1) | O(1) | 2026-09-16 |
| 1721 | [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list) | 🟡 Medium | Linked List, Two Pointers | [C++](problems/1721.md) | O(N) | O(1) | 2026-09-25 |
| 2181 | [Merge Nodes in Between Zeros](https://leetcode.com/problems/merge-nodes-in-between-zeros/) | 🟡 Medium | Linked List, In-place Modification | [C++](problems/2181.md) | O(N) | O(1) | 2026-09-25 |

<a id="zailianxi-pointers"></a>
#### 👥 Pointers（11）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 88 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) | 🟢 Easy | Two Pointers Partition, Two Pointers | [C++](problems/0088.md) | O(M+N) | O(1) |  |
| 283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | 🟢 Easy | Fast Slow Pointers | [C++](problems/0283.md) | O(N) | O(1) | 2026-09-18 |
| 541 | [Reverse String II](https://leetcode.com/problems/reverse-string-ii/) | 🟢 Easy | String, Two Pointers | [C++](problems/0541.md) | O(N) | O(1) |  |
| 941 | [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array) | 🟢 Easy | Two Pointers Opposite, Two Pointers | [C++](problems/0941.md) | O(N) | O(1) |  |
| 942 | [DI String Match](https://leetcode.com/problems/di-string-match/) | 🟢 Easy | Two Pointers Opposite, Two Pointers | [C++](problems/0942.md) | O(N) | O(N) |  |
| 977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array) | 🟢 Easy | Array, Two Pointers | [C++](problems/0977.md) | O(N) | O(N) |  |
| 1417 | [Reformat The String](https://leetcode.com/problems/reformat-the-string/) | 🟢 Easy | Two Pointers Same, Two Pointers | [C++](problems/1417.md) | O(N) | O(N) | 2026-09-18 |
| 1750 | [Minimum Length of String After Deleting Similar Ends](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends) | 🟡 Medium | Two Pointers Opposite, Two Pointers | [C++](problems/1750.md) | O(N) | O(1) |  |
| 2109 | [Adding Spaces to a String](https://leetcode.com/problems/adding-spaces-to-a-string) | 🟡 Medium | Two Pointers Same, Two Pointers | [C++](problems/2109.md) | O(N+M) | O(N+M) |  |
| 2570 | [Merge Two 2D Arrays by Summing Values](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/) | 🟢 Easy | Two Pointers Same | [C++](problems/2570.md) | O(N+M) | O(1) | 2026-09-18 |
| 3823 | [Reverse Letters Then Special Characters](leetcode.com/problems/reverse-letters-then-special-characters-in-a-string) | 🟢 Easy | Two-Pointer | [C++](problems/3823.md) | O(N) | O(1) |  |

<a id="zailianxi-hash-table"></a>
#### 🔑 Hash Table（23）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 12 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman) | 🟡 Medium | Hash Table Mapping, Hash Table, String | [C++](problems/0012.md) | O(1) | O(1) |  |
| 13 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer) | 🟢 Easy | Hash Table Mapping, Hash Table, String | [C++](problems/0013.md) | O(N) | O(1) |  |
| 350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | 🟢 Easy | Hash Table Intersection | [C++](problems/0350.md) | O(N+M) | O(min(N,M)) | 2026-09-20 |
| 454 | [4Sum II](https://leetcode.com/problems/4sum-ii) | 🟡 Medium | Hash Table Existence, Hash Table | [C++](problems/0454.md) | O(N²) | O(N²) |  |
| 532 | [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) | 🟡 Medium | Hash Table Existence | [C++](problems/0532.md) | O(NlogN) | O(N) |  |
| 599 | [Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/) | 🟢 Easy | Hash Table Intersection, Hash Table | [C++](problems/0599.md) | O(N+M) | O(N) |  |
| 819 | [Most Common Word](https://leetcode.com/problems/most-common-word/) | 🟢 Easy | String, Hash Table | [C++](problems/0819.md) | O(M+N) | O(M+N) |  |
| 859 | [Buddy Strings](https://leetcode.com/problems/buddy-strings/) | 🟢 Easy | Hash Table Uniqueness, Hash Table, Two Pointers | [C++](problems/0859.md) | O(N) | O(1) |  |
| 939 | [Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/) | 🟡 Medium | Hash Table Uniqueness, Hash Table | [C++](problems/0939.md) | O(N²) | O(N) |  |
| 1002 | [Find Common Characters](https://leetcode.com/problems/find-common-characters) | 🟢 Easy | Hash Table Counting, Hash Table, String | [C++](problems/1002.md) | O(N\*K) | O(1) |  |
| 1497 | [Check If Array Pairs Are Divisible by k](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/) | 🟡 Medium | Hash Table Counting, Hash Table, Remainder Counting | [C++](problems/1497.md) | O(N+K) | O(K) |  |
| 1512 | [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs) | 🟢 Easy | Hash Table Counting, Hash Table, Math | [C++](problems/1512.md) | O(N) | O(N) |  |
| 1647 | [Minimum Deletions...](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/) | 🟡 Medium | Greedy, Hash Set | [C++](problems/1647.md) | O(N+KlogK) | O(K) |  |
| 1805 | [Number of Different Integers in a String](https://leetcode.com/problems/number-of-different-integers-in-a-string/) | 🟢 Easy | Hash Table Uniqueness, Hash Set | [C++](problems/1805.md) | O(N) | O(N) |  |
| 2001 | [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles) | 🟡 Medium | Hash Table Counting, Hash Table | [C++](problems/2001.md) | O(N) | O(N) |  |
| 2451 | [Odd String Difference](https://leetcode.com/problems/odd-string-difference/) | 🟢 Easy | Hash Table Mapping, Hash Map, Difference Array | [C++](problems/2451.md) | O(N\*M) | O(N\*M) |  |
| 2605 | [Form Smallest Number From Two Digit Arrays](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/) | 🟢 Easy | Hash Table Intersection | [C++](problems/2605.md) | O(NM) | O(1) | 2026-09-17 |
| 2605 | [Form Smallest Number From Two Digit Arrays](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/) | 🟢 Easy | Hash Table Intersection | [C++](problems/2605.md) | O(N+M) | O(1) | 2026-09-17 |
| 2784 | [Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good) | 🟢 Easy | Hash Table Uniqueness, Hash Table, Sorting | [C++](problems/2784.md) | O(N) | O(N) |  |
| 3442 | [Maximum Difference Between Even and Odd Frequency I](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/) | 🟢 Easy | Hash Table Counting, Hash Map | [C++](problems/3442.md) | O(N) | O(1) |  |
| 3483 | [Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/) | 🟢 Easy | Hash Table Uniqueness, Brute Force | [C++](problems/3483.md) | O(N³) | O(U) |  |
| 3663 | [Find The Least Frequent Digit](https://leetcode.com/problems/find-the-least-frequent-digit/) | 🟢 Easy | Hash Table Counting, Hash Table, Frequency Counting | [C++](problems/3663.md) | O(logN) | O(1) |  |
| 3678 | [Smallest Absent Positive Greater Than Average](https://leetcode.com/problems/smallest-absent-positive-greater-than-average/) | 🟢 Easy | Hash Table Existence, Hash Set | [C++](problems/3678.md) | O(N) | O(N) |  |

<a id="zailianxi-stack"></a>
#### 📚 Stack（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 20 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 Easy | Stack | [C++](problems/0020.md) | O(N) | O(N) | 2026-09-21 |
| 445 | [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii) | 🟡 Medium | Stack, Stack | [C++](problems/0445.md) | O(N+M) | O(N+M) | 2026-09-22 |
| 1003 | [Check If Word Is Valid After Substitutions](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/) | 🟡 Medium | Stack, String | [C++](problems/1003.md) | O(N) | O(N) | 2026-09-21 |
| 1021 | [Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/) | 🟢 Easy | Stack, Counter | [C++](problems/1021.md) | O(N) | O(1) |  |
| 1544 | [Make The String Great](https://leetcode.com/problems/make-the-string-great/) | 🟢 Easy | String, Stack | [C++](problems/1544.md) | O(N) | O(N) |  |

<a id="zailianxi-queue"></a>
#### 📚 Queue（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1291 | [Sequential Digits](https://leetcode.com/problems/sequential-digits/) | 🟡 Medium | Queue, Brute Force | [C++](problems/1291.md) | O(1) | O(1) |  |

<a id="zailianxi-quick-select"></a>
#### 📚 Quick Select（4）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 973 | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin) | 🟡 Medium | Quick Select, QuickSelect | [C++](problems/0973.md) | O(N) | O(1) |  |
| 1387 | [Sort Integers by The Power Value](https://leetcode.com/problems/sort-integers-by-the-power-value/) | 🟡 Medium | Quick Select, Recursion, Collatz Conjecture, Quickselect | [C++](problems/1387.md) | O(N\*S) | O(N+S) |  |
| 1985 | [Find the Kth Largest Integer in the Array](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array) | 🟡 Medium | Quick Select, Sorting, String | [C++](problems/1985.md) | O(N) | O(1) |  |
| 2733 | [Neither Minimum nor Maximum](https://leetcode.com/problems/neither-minimum-nor-maximum/) | 🟢 Easy | Quick Select, Math | [C++](problems/2733.md) | O(N) | O(1) | 2026-09-17 |

<a id="zailianxi-sorting"></a>
#### 📊 Sorting（6）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1356 | [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits) | 🟢 Easy | Sorting Custom Comparator, Sorting | [C++](problems/1356.md) | O(NlogN) | O(1) | 2026-09-26 |
| 2164 | [Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently/) | 🟢 Easy | Sorting Custom Comparator | [C++](problems/2164.md) | O(NlogN) | O(N) | 2026-09-26 |
| 2191 | [Sort the Jumbled Numbers](https://leetcode.com/problems/sort-the-jumbled-numbers/) | 🟡 Medium | Sorting Custom Comparator, Digit Manipulation, Pair | [C++](problems/2191.md) | O(NlogN) | O(N) |  |
| 2225 | [Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses) | 🟡 Medium | Sorting, Hash Table, Counting | [C++](problems/2225.md) | O(NlogN) | O(N) | 2026-09-26 |
| 2418 | [Sort the People](https://leetcode.com/problems/sort-the-people) | 🟢 Easy | Sorting Custom Comparator | [C++](problems/2418.md) | O(NlogN) | O(N) |  |
| 3769 | [Sort Integers by Binary Reflection](https://leetcode.com/problems/sort-integers-by-binary-reflection/) | 🟡 Medium | Sorting Custom Comparator, Sorting | [C++](problems/3769.md) | O(NlogN) | O(N) | 2026-09-26 |

<a id="zailianxi-dynamic-programming"></a>
#### 🧩 Dynamic Programming（3）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 Medium | Dynamic Programming Kadane Algorithm, Dynamic Programming | [C++](problems/0053.md) | O(N) | O(1) |  |
| 213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | 🟡 Medium | Dynamic Programming Fibonacci, DP | [C++](problems/0213.md) | O(N) | O(1) |  |
| 213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | 🟡 Medium | Dynamic Programming Fibonacci | [C++](problems/0213.md) | O(N) | O(N) |  |

<a id="zailianxi-greedy"></a>
#### 🧩 Greedy（20）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 134 | [Gas Station](https://leetcode.com/problems/gas-station/) | 🟡 Medium | Greedy Fractional Knapsack | [C++](problems/0134.md) | O(N) | O(1) |  |
| 453 | [Minimum Moves to Equal Array Elements](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/) | 🟢 Easy | Greedy | [C++](problems/0453.md) | O(N) | O(1) |  |
| 455 | [Assign Cookies](https://leetcode.com/problems/assign-cookies/) | 🟢 Easy | Greedy Fractional Knapsack | [C++](problems/0455.md) | O(N log N) | O(1) |  |
| 624 | [Maximum Distance in Arrays](https://leetcode.com/problems/maximum-distance-in-arrays) | 🟡 Medium | Greedy, Greedy | [C++](problems/0624.md) | O(N) | O(1) |  |
| 670 | [Maximum Swap](https://leetcode.com/problems/maximum-swap/) | 🟡 Medium | Greedy | [C++](problems/0670.md) | O(N) | O(1) |  |
| 881 | [Boats to Save People](https://leetcode.com/problems/boats-to-save-people/) | 🟡 Medium | Greedy Sorting Decision | [C++](problems/0881.md) | O(N log N) | O(1) | 2026-09-26 |
| 945 | [Minimum Increment to Make Array Unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique/) | 🟡 Medium | Sorting, Greedy | [C++](problems/0945.md) | O(NlogN) | O(1) |  |
| 961 | [N-Repeated Element](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/) | 🟢 Easy | Greedy, Greedy | [C++](problems/0961.md) | O(N) | O(1) | 2026-09-26 |
| 1529 | [Minimum Suffix Flips](https://leetcode.com/problems/minimum-suffix-flips/) | 🟡 Medium | Greedy, State Machine | [C++](problems/1529.md) | O(N) | O(1) |  |
| 1576 | [Replace All ?'s](https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/) | 🟢 Easy | Greedy | [C++](problems/1576.md) | O(N) | O(1) |  |
| 1624 | [Largest Substring Between Two Equal Characters](https://leetcode.com/problems/largest-substring-between-two-equal-characters/) | 🟢 Easy | Greedy, Hash Table | [C++](problems/1624.md) | O(N) | O(1) |  |
| 1785 | [Minimum Elements to Add to Form a Given Sum](https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/) | 🟡 Medium | Greedy, Greedy | [C++](problems/1785.md) | O(N) | O(1) |  |
| 2027 | [Minimum Moves to Convert String](https://leetcode.com/problems/minimum-moves-to-convert-string/) | 🟢 Easy | Greedy | [C++](problems/2027.md) | O(N) | O(1) |  |
| 2578 | [Split With Minimum Sum](https://leetcode.com/problems/split-with-minimum-sum/) | 🟢 Easy | Greedy, Sorting | [C++](problems/2578.md) | O(NlogN) | O(N) |  |
| 2600 | [K Items With the Maximum Sum](https://leetcode.com/problems/k-items-with-the-maximum-sum/) | 🟢 Easy | Greedy, Greedy | [C++](problems/2600.md) | O(1) | O(1) |  |
| 2815 | [Max Pair Sum in an Array](https://leetcode.com/problems/max-pair-sum-in-an-array/) | 🟢 Easy | Greedy, Hashing | [C++](problems/2815.md) | O(N\*D) | O(1) | 2026-09-17 |
| 2864 | [Maximum Odd Binary Number](https://leetcode.com/problems/maximum-odd-binary-number/) | 🟢 Easy | Greedy String Construction, String | [C++](problems/2864.md) | O(N) | O(1) | 2026-09-21 |
| 3014 | [Minimum Number of Pushes to Type Word I](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/) | 🟡 Medium | Greedy Sorting Decision, Sorting, Counting | [C++](problems/3014.md) | O(N+26log26) | O(1) | 2026-09-25 |
| 3016 | [Minimum Number of Pushes to Type Word II](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/) | 🟡 Medium | Greedy Sorting Decision, Sorting, Counting | [C++](problems/3016.md) | O(N+26log26) | O(1) | 2026-09-25 |
| 3216 | [Lexicographically Smallest String After a Swap](https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/) | 🟢 Easy | Greedy, String | [C++](problems/3216.md) | O(N) | O(1) |  |

<a id="zailianxi-other"></a>
#### 📄 Other（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 Medium | Dynamic Programming | [C++](problems/0053.md) | O(N) | O(N) |  |

---

<a id="review-shengshu"></a>
## 🔴 生疏清單

目前共有 223 個解法標記為生疏，建議找時間重新練習。

📌 **快速跳轉：** [🍱 Array（7）](#shengshu-array)　[🔍 Binary Search（11）](#shengshu-binary-search)　[👥 Pointers（15）](#shengshu-pointers)　[🔑 Hash Table（7）](#shengshu-hash-table)　[📚 Stack（11）](#shengshu-stack)　[📚 Priority Queue（5）](#shengshu-priority-queue)　[📚 Queue（1）](#shengshu-queue)　[📚 Quick Select（1）](#shengshu-quick-select)　[🕸️ Graph（5）](#shengshu-graph)　[📊 Sorting（11）](#shengshu-sorting)　[🧩 Dynamic Programming（61）](#shengshu-dynamic-programming)　[🧩 Greedy（43）](#shengshu-greedy)　[🔢 Backtracking（25）](#shengshu-backtracking)　[🔢 Sliding Window（20）](#shengshu-sliding-window)

<a id="shengshu-array"></a>
#### 🍱 Array（7）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 229 | [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | 🟡 Medium | Array, Voting Algorithm | [C++](problems/0229.md) | O(N) | O(1) |  |
| 304 | [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable) | 🟡 Medium | Array Prefix Sum, Matrix, Prefix Sum | [C++](problems/0304.md) | O(M\*N) | O(M\*N) |  |
| 523 | [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) | 🟡 Medium | Prefix Sum, Hash Map | [C++](problems/0523.md) | O(N) | O(min(N,K)) |  |
| 1685 | [Sum of Absolute Differences in a Sorted Array](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/) | 🟡 Medium | Array, Prefix Sum, Math | [C++](problems/1685.md) | O(N) | O(N) |  |
| 1738 | [Find Kth Largest XOR Coordinate Value](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/) | 🟡 Medium | Array Prefix Sum, Prefix Sum | [C++](problems/1738.md) | O(M\*N) | O(M\*N) |  |
| 3364 | [Minimum Positive Sum Subarray](https://leetcode.com/problems/minimum-positive-sum-subarray/) | 🟢 Easy | Prefix Sum, Sliding Window, Multiset | [C++](problems/3364.md) | O(NlogN) | O(N) |  |
| 3969 | [Valid Subarrays With Matching Sum Digits I](https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/) | 🟢 Easy | Array, Brute Force | [C++](problems/3969.md) | O(N²) | O(1) |  |

<a id="shengshu-binary-search"></a>
#### 🔍 Binary Search（11）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | 🔴 Hard | Binary Search | [C++](problems/0004.md) | O(log(min(M,N))) | O(1) |  |
| 220 | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) | 🔴 Hard | Sliding Window, Ordered Map, Bucket | [C++](problems/0220.md) | O(Nlog(min(N,K))) | O(min(N,K)) |  |
| 275 | [H-Index II](https://leetcode.com/problems/h-index-ii/) | 🟡 Medium | Binary Search Find Right Bound | [C++](problems/0275.md) | O(log N) | O(1) |  |
| 378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | 🟡 Medium | Binary Search, Matrix | [C++](problems/0378.md) | O(Nlog(max-min)) | O(1) |  |
| 1170 | [Compare Strings by Frequency](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/) | 🟡 Medium | Sorting, Binary Search | [C++](problems/1170.md) | O(NlogN+MlogN) | O(N) |  |
| 1201 | [Ugly Number III](https://leetcode.com/problems/ugly-number-iii/) | 🟡 Medium | Binary Search, Math | [C++](problems/1201.md) | O(log(2E9)) | O(1) |  |
| 1608 | [Special Array With X Elements Greater Than or Equal X](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/) | 🟢 Easy | Binary Search On Answer | [C++](problems/1608.md) | O(N²) | O(1) |  |
| 1818 | [Minimum Absolute Sum Difference](https://leetcode.com/problems/minimum-absolute-sum-difference/) | 🟡 Medium | Binary Search, Greedy | [C++](problems/1818.md) | O(NlogN) | O(N) |  |
| 1930 | [Unique Length-3 Palindromic Subsequences](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/) | 🟡 Medium | Binary Search Build In, Hash | [C++](problems/1930.md) | O(N) | O(1) |  |
| 2195 | [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum/) | 🟡 Medium | Binary Search On Answer, Binary Search | [C++](problems/2195.md) | O(NlogN) | O(1) |  |
| 2476 | [Closest Nodes Queries in a Binary Search Tree](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/) | 🟡 Medium | BST, Binary Search | [C++](problems/2476.md) | O(N+QlogN) | O(N) |  |

<a id="shengshu-pointers"></a>
#### 👥 Pointers（15）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | 🔴 Hard | Two Pointers Same | [C++](problems/0004.md) | O(log(M+N)) | O(1) |  |
| 5 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | 🟡 Medium | Two Pointers Center Expansion, Expand Around Center, Two Pointers | [C++](problems/0005.md) | O(N²) | O(1) |  |
| 19 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list) | 🟡 Medium | Linked List, Fast-Slow Pointers | [C++](problems/0019.md) | O(N) | O(1) |  |
| 31 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | 🟡 Medium | Array, Two Pointers | [C++](problems/0031.md) | O(N) | O(1) |  |
| 75 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 Medium | Array, Two Pointers, Sorting | [C++](problems/0075.md) | O(N) | O(1) |  |
| 86 | [Partition List](https://leetcode.com/problems/partition-list/) | 🟡 Medium | Linked List, Two Pointers | [C++](problems/0086.md) | O(N) | O(1) |  |
| 151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | 🟡 Medium | Fast Slow Pointers | [C++](problems/0151.md) | O(N) | O(1) |  |
| 228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges) | 🟢 Easy | Array, Two Pointers | [C++](problems/0228.md) | O(N) | O(1) |  |
| 328 | [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) | 🟡 Medium | Linked List | [C++](problems/0328.md) | O(N) | O(1) |  |
| 443 | [String Compression](https://leetcode.com/problems/string-compression/) | 🟡 Medium | Two Pointers | [C++](problems/0443.md) | O(N) | O(1) |  |
| 647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) | 🟡 Medium | Two Pointers Center Expansion, DP | [C++](problems/0647.md) | O(N²) | O(N²) |  |
| 777 | [Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/) | 🟡 Medium | Two Pointers Same, Two Pointers | [C++](problems/0777.md) | O(N) | O(1) |  |
| 844 | [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare) | 🟢 Easy | String, Two Pointers | [C++](problems/0844.md) | O(N+M) | O(1) |  |
| 1089 | [Duplicate Zeros](https://leetcode.com/problems/duplicate-zeros) | 🟢 Easy | Array, Two Pointers | [C++](problems/1089.md) | O(N) | O(1) |  |
| 2562 | [Find the Array Concatenation Value](https://leetcode.com/problems/find-the-array-concatenation-value/) | 🟢 Easy | Two Pointers | [C++](problems/2562.md) | O(N\*D) | O(1) |  |

<a id="shengshu-hash-table"></a>
#### 🔑 Hash Table（7）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | 🟡 Medium | Hash Table Existence, Hash Table | [C++](problems/0128.md) | O(N) | O(N) |  |
| 916 | [Word Subsets](https://leetcode.com/problems/word-subsets/) | 🟡 Medium | Hash Table Counting, Hash Table, Counting | [C++](problems/0916.md) | O(N \* L) | O(1) |  |
| 1640 | [Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/) | 🟢 Easy | Hash Table Existence, Hash Map | [C++](problems/1640.md) | O(N) | O(N) |  |
| 2023 | [Number of Pairs of Strings With Concatenation Equal to Target](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/) | 🟡 Medium | Hash Table, String, Single-Pass | [C++](problems/2023.md) | O(N\*L) | O(N) |  |
| 2670 | [Find the Distinct Difference Array](https://leetcode.com/problems/find-the-distinct-difference-array/) | 🟢 Easy | Hash Table Uniqueness, Hash Set | [C++](problems/2670.md) | O(N) | O(N) |  |
| 3487 | [Maximum Unique Subarray Sum After Deletion](https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/) | 🟡 Medium | Hash Table Uniqueness, Hash Set, Greedy | [C++](problems/3487.md) | O(N) | O(N) |  |
| 3926 | [Count Valid Word Occurrences](https://leetcode.com/problems/count-valid-word-occurrences/) | 🟡 Medium | String, Hash Map | [C++](problems/3926.md) | O(N+M) | O(N) |  |

<a id="shengshu-stack"></a>
#### 📚 Stack（11）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 32 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses) | 🔴 Hard | String, Stack, DP | [C++](problems/0032.md) | O(N) | O(N) |  |
| 85 | [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) | 🔴 Hard | Monotonic Stack | [C++](problems/0085.md) | O(M\*N) | O(N) |  |
| 316 | [Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/) | 🟡 Medium | Monotonic Stack, Greedy, String | [C++](problems/0316.md) | O(N) | O(1) |  |
| 496 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) | 🟢 Easy | Array, Hash Table, Stack, Monotonic Stack | [C++](problems/0496.md) | O(N+M) | O(N) |  |
| 503 | [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii) | 🟡 Medium | Array, Stack, Monotonic Stack | [C++](problems/0503.md) | O(N) | O(N) |  |
| 739 | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures) | 🟡 Medium | Stack, Monotonic Stack | [C++](problems/0739.md) | O(N) | O(N) |  |
| 1019 | [Next Greater Node In Linked List](https://leetcode.com/problems/next-greater-node-in-linked-list/) | 🟡 Medium | Linked List, Monotonic Stack | [C++](problems/1019.md) | O(N) | O(N) |  |
| 1081 | [Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/) | 🟡 Medium | Monotonic Stack, Greedy | [C++](problems/1081.md) | O(N) | O(1) |  |
| 1209 | [Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii) | 🟡 Medium | String, Stack | [C++](problems/1209.md) | O(N) | O(N) |  |
| 1475 | [Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop) | 🟢 Easy | Array, Stack, Monotonic Stack | [C++](problems/1475.md) | O(N) | O(N) |  |
| 1963 | [Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced) | 🟡 Medium | Stack, Greedy | [C++](problems/1963.md) | O(N) | O(1) |  |

<a id="shengshu-priority-queue"></a>
#### 📚 Priority Queue（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 23 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists) | 🔴 Hard | Heap, Linked List | [C++](problems/0023.md) | O(NlogK) | O(K) |  |
| 373 | [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sum/) | 🟡 Medium | Heap, Greedy | [C++](problems/0373.md) | O(KlogK) | O(K) |  |
| 692 | [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words) | 🟡 Medium | Hash Table, Heap | [C++](problems/0692.md) | O(NlogK) | O(N) |  |
| 703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) | 🟢 Easy | Heap (Priority Queue) | [C++](problems/0703.md) | O(NlogK) | O(K) |  |
| 786 | [K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/) | 🟡 Medium | Priority Queue, Binary Search | [C++](problems/0786.md) | O(NlogN) | O(N) |  |

<a id="shengshu-queue"></a>
#### 📚 Queue（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | 🔴 Hard | Monotonic Queue, Sliding Window | [C++](problems/0239.md) | O(N) | O(K) |  |

<a id="shengshu-quick-select"></a>
#### 📚 Quick Select（1）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 324 | [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) | 🟡 Medium | Sorting, Quickselect | [C++](problems/0324.md) | O(N) | O(1) |  |

<a id="shengshu-graph"></a>
#### 🕸️ Graph（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 127 | [Word Ladder](https://leetcode.com/problems/word-ladder/) | 🔴 Hard | Graph Bfs | [C++](problems/0127.md) | O(N·L·26) | O(N·L) |  |
| 200 | [Number of Islands](https://leetcode.com/problems/number-of-islands/) | 🟡 Medium | Graph Dfs, DFS, BFS, Union-Find | [C++](problems/0200.md) | O(M×N) | O(1) |  |
| 207 | [Course Schedule](https://leetcode.com/problems/course-schedule/) | 🟡 Medium | Topological Sort | [C++](problems/0207.md) | O(V+E) | O(V+E) |  |
| 547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | 🟡 Medium | Union Find | [C++](problems/0547.md) | O(N²·α(N)) | O(N) |  |
| 743 | [Network Delay Time](https://leetcode.com/problems/network-delay-time/) | 🟡 Medium | Graph Shortest Path | [C++](problems/0743.md) | O(E·logV) | O(V+E) |  |

<a id="shengshu-sorting"></a>
#### 📊 Sorting（11）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 147 | [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/) | 🟡 Medium | Sorting, Insertion Sort | [C++](problems/0147.md) | O(N²) | O(1) |  |
| 148 | [Sort List](https://leetcode.com/problems/sort-list/) | 🟡 Medium | Linked List, Merge Sort | [C++](problems/0148.md) | O(NlogN) | O(logN) |  |
| 164 | [Maximum Gap](https://leetcode.com/problems/maximum-gap/) | 🟡 Medium | Sorting Implementation, Sorting Algorithm Implementation, Bucket Sort, Pigeonhole Principle | [C++](problems/0164.md) | O(N) | O(N) |  |
| 164 | [Maximum Gap](https://leetcode.com/problems/maximum-gap/) | 🟡 Medium | Sorting Radix Sort | [C++](problems/0164.md) | O(N \* D) | O(N) |  |
| 648 | [Replace Words](https://leetcode.com/problems/replace-words/) | 🟡 Medium | Sorting | [C++](problems/0648.md) | O(N\*L) | O(M\*L) |  |
| 765 | [Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/) | 🔴 Hard | Sorting Cycle Decomposition | [C++](problems/0765.md) | O(N α(N)) | O(N) |  |
| 2471 | [Minimum Number of Operations to Sort a Binary Tree by Level](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/) | 🟡 Medium | Sorting Cycle Decomposition | [C++](problems/2471.md) | O(N log N) | O(N) |  |
| 2932 | [Maximum Strong Pair XOR I](https://leetcode.com/problems/maximum-strong-pair-xor-i/) | 🟢 Easy | Sorting, Brute Force | [C++](problems/2932.md) | O(NlogN+N²) | O(logN) |  |
| 3132 | [Find the Integer Added to Array II](https://leetcode.com/problems/find-the-integer-added-to-array-ii/) | 🟡 Medium | Sorting, Two Pointers | [C++](problems/3132.md) | O(NlogN) | O(1) |  |
| 3517 | [Smallest Palindromic Rearrangement I](https://leetcode.com/problems/smallest-palindromic-rearrangement-i/) | 🟡 Medium | Greedy, Counting Sort | [C++](problems/3517.md) | O(N) | O(1) |  |
| 3551 | [Minimum Swaps to Sort by Digit Sum](https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/) | 🟡 Medium | Cycle Decomposition | [C++](problems/3551.md) | O(NlogN) | O(N) |  |

<a id="shengshu-dynamic-programming"></a>
#### 🧩 Dynamic Programming（61）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 10 | [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | 🔴 Hard | Dp String | [C++](problems/0010.md) | O(M) | O(M) |  |
| 44 | [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) | 🔴 Hard | Dp String | [C++](problems/0044.md) | O(M) | O(M) |  |
| 95 | [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/) | 🟡 Medium | Dp Interval | [C++](problems/0095.md) | O(Catalan(N) \* N) | O(Catalan(N) \* N) |  |
| 97 | [Interleaving String](https://leetcode.com/problems/interleaving-string/) | 🟡 Medium | Dynamic Programming Lcs, Two Strings | [C++](problems/0097.md) | O(M \* N) | O(M \* N) |  |
| 115 | [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) | 🔴 Hard | Dynamic Programming Lcs, DP | [C++](problems/0115.md) | O(S\*T) | O(T) |  |
| 118 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | 🟢 Easy | Array, DP | [C++](problems/0118.md) | O(N²) | O(1) |  |
| 120 | [Triangle](https://leetcode.com/problems/triangle/) | 🟡 Medium | Dp Grid Path | [C++](problems/0120.md) | O(N²) | O(N) |  |
| 123 | [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | 🔴 Hard | Dp State Machine | [C++](problems/0123.md) | O(N) | O(1) |  |
| 139 | [Word Break](https://leetcode.com/problems/word-break/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](problems/0139.md) | O(N³) | O(N) |  |
| 188 | [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | 🔴 Hard | Dp State Machine | [C++](problems/0188.md) | O(N\*K) | O(K) |  |
| 233 | [Number of Digit One](https://leetcode.com/problems/number-of-digit-one/) | 🔴 Hard | Dp Digit | [C++](problems/0233.md) | O(log N) | O(1) |  |
| 309 | [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | 🟡 Medium | Dp State Machine | [C++](problems/0309.md) | O(N) | O(1) |  |
| 312 | [Burst Balloons](https://leetcode.com/problems/burst-balloons/) | 🔴 Hard | Dp Interval | [C++](problems/0312.md) | O(N³) | O(N²) |  |
| 354 | [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/) | 🔴 Hard | Dp Lis | [C++](problems/0354.md) | O(N log N) | O(N) |  |
| 375 | [Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/) | 🟡 Medium | Dp Interval | [C++](problems/0375.md) | O(N³) | O(N²) |  |
| 446 | [Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/) | 🔴 Hard | Dp Subsequences | [C++](problems/0446.md) | O(N²) | O(N²) |  |
| 464 | [Can I Win](https://leetcode.com/problems/can-i-win/) | 🟡 Medium | Dp Game Theory | [C++](problems/0464.md) | O(2^N \* N) | O(2^N) |  |
| 486 | [Predict the Winner](https://leetcode.com/problems/predict-the-winner/) | 🟡 Medium | Dp Game Theory | [C++](problems/0486.md) | O(N²) | O(N²) |  |
| 646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/) | 🟡 Medium | Dp Lis | [C++](problems/0646.md) | O(N²) | O(N) |  |
| 673 | [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) | 🟡 Medium | Dp Lis | [C++](problems/0673.md) | O(N²) | O(N) |  |
| 688 | [Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/) | 🟡 Medium | Dp Probability | [C++](problems/0688.md) | O(K | O(N²) |  |
| 698 | [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) | 🟡 Medium | Dp Bitmask | [C++](problems/0698.md) | O(2^N \* N) | O(2^N) |  |
| 712 | [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) | 🟡 Medium | Dynamic Programming Lcs, String | [C++](problems/0712.md) | O(M×N) | O(M×N) |  |
| 714 | [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | 🟡 Medium | Dp State Machine | [C++](problems/0714.md) | O(N) | O(1) |  |
| 808 | [Soup Servings](https://leetcode.com/problems/soup-servings/) | 🟡 Medium | Dp Probability | [C++](problems/0808.md) | O((N/25)²) | O((N/25)²) |  |
| 837 | [New 21 Game](https://leetcode.com/problems/new-21-game/) | 🟡 Medium | Dp Probability | [C++](problems/0837.md) | O(N) | O(N) |  |
| 847 | [Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) | 🔴 Hard | Dp Bitmask | [C++](problems/0847.md) | O(N² \* 2^N) | O(N \* 2^N) |  |
| 877 | [Stone Game](https://leetcode.com/problems/stone-game/) | 🟡 Medium | Dp Game Theory | [C++](problems/0877.md) | O(N²) | O(N²) |  |
| 898 | [Bitwise ORs of Subarrays](https://leetcode.com/problems/bitwise-or-s-of-subarrays/) | 🟡 Medium | Bit Manipulation, Dynamic Programming | [C++](problems/0898.md) | O(N\*30) | O(N\*30) |  |
| 902 | [Numbers At Most N Given Digit Set](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/) | 🔴 Hard | Dp Digit | [C++](problems/0902.md) | O(len(N) \* len(digits)) | O(1) |  |
| 918 | [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-subarray-sum-circular/) | 🟡 Medium | Array, Kadane's Algorithm | [C++](problems/0918.md) | O(N) | O(1) |  |
| 926 | [Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/) | 🟡 Medium | Dynamic Programming State Machine | [C++](problems/0926.md) | O(N) | O(1) |  |
| 931 | [Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/) | 🟡 Medium | Dp Grid Path | [C++](problems/0931.md) | O(N²) | O(N) |  |
| 940 | [Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/) | 🔴 Hard | Dp Subsequences | [C++](problems/0940.md) | O(N) | O(1) |  |
| 943 | [Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring/) | 🔴 Hard | Dp Bitmask | [C++](problems/0943.md) | O(N² \* 2^N) | O(N \* 2^N) |  |
| 968 | [Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/) | 🔴 Hard | Dp Tree | [C++](problems/0968.md) | O(N) | O(H) |  |
| 983 | [Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/) | 🟡 Medium | Dp Knapsack, Unbounded Knapsack | [C++](problems/0983.md) | O(D log D) | O(D) |  |
| 1000 | [Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/) | 🔴 Hard | Dp Interval | [C++](problems/1000.md) | O(N³ / K) | O(N²) |  |
| 1012 | [Numbers With Repeated Digits](https://leetcode.com/problems/numbers-with-repeated-digits/) | 🔴 Hard | Dp Digit | [C++](problems/1012.md) | O(D²) | O(1) |  |
| 1039 | [Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/) | 🟡 Medium | Dp Interval | [C++](problems/1039.md) | O(N³) | O(N²) |  |
| 1092 | [Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/) | 🔴 Hard | Dynamic Programming Lcs | [C++](problems/1092.md) | O(N\*M) | O(N\*M) |  |
| 1125 | [Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team/) | 🔴 Hard | Dp Digit | [C++](problems/1125.md) | O(2^M \* N) | O(2^M) |  |
| 1130 | [Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) | 🟡 Medium | Dp Interval | [C++](problems/1130.md) | O(N³) | O(N²) |  |
| 1140 | [Stone Game II](https://leetcode.com/problems/stone-game-ii/) | 🟡 Medium | Dp Game Theory | [C++](problems/1140.md) | O(N³) | O(N²) |  |
| 1277 | [Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) | 🟡 Medium | Dynamic Programming Grid Path, Matrix | [C++](problems/1277.md) | O(M\*N) | O(1) |  |
| 1312 | [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) | 🔴 Hard | Dynamic Programming Lcs | [C++](problems/1312.md) | O(N²) | O(N²) |  |
| 1373 | [Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/) | 🔴 Hard | Dp Tree | [C++](problems/1373.md) | O(N) | O(H) |  |
| 1406 | [Stone Game III](https://leetcode.com/problems/stone-game-iii/) | 🔴 Hard | Dp Game Theory | [C++](problems/1406.md) | O(N) | O(N) |  |
| 1425 | [Constrained Subsequence Sum](https://leetcode.com/problems/constrained-subsequence-sum/) | 🔴 Hard | Dp Subsequences | [C++](problems/1425.md) | O(N) | O(N) |  |
| 1434 | [Number of Ways to Wear Different Hats to Each Other](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/) | 🔴 Hard | Dp Digit | [C++](problems/1434.md) | O(40 \* 2^N \* 平均每頂帽子對應的人數) | O(40 \* 2^N) |  |
| 1467 | [Probability of a Two Boxes Having The Same Number of Distinct Balls](https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/) | 🔴 Hard | Dp Probability | [C++](problems/1467.md) | O(∏(balls[i]+1)) | O(K) |  |
| 1510 | [Stone Game IV](https://leetcode.com/problems/stone-game-iv/) | 🔴 Hard | Dp Game Theory | [C++](problems/1510.md) | O(N \* √N) | O(N) |  |
| 1641 | [Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/) | 🟡 Medium | Math, Dynamic Programming | [C++](problems/1641.md) | O(1) | O(1) |  |
| 1668 | [Maximum Repeating Substring](https://leetcode.com/problems/maximum-repeating-substring/) | 🟢 Easy | String | [C++](problems/1668.md) | O(N\*M²) | O(M) |  |
| 1964 | [Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/) | 🔴 Hard | Dp Lis | [C++](problems/1964.md) | O(N log N) | O(N) |  |
| 1986 | [Minimum Number of Work Sessions to Finish the Tasks](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/) | 🟡 Medium | Dp Bitmask | [C++](problems/1986.md) | O(3^N) | O(2^N) |  |
| 1987 | [Number of Unique Good Subsequences](https://leetcode.com/problems/number-of-unique-good-subsequences/) | 🔴 Hard | Dp Subsequences | [C++](problems/1987.md) | O(N) | O(1) |  |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/) | 🔴 Hard | Dp Knapsack, 0-1 Knapsack | [C++](problems/2035.md) | O(N \* 2^(N/2)) | O(2^(N/2)) |  |
| 2246 | [Difference Between Maximum and Minimum Price Sum](https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/) | 🔴 Hard | Dp Tree | [C++](problems/2246.md) | O(N) | O(N) |  |
| 2266 | [Count Number of Texts](https://leetcode.com/problems/count-number-of-texts/) | 🟡 Medium | Dp Fibonacci | [C++](problems/2266.md) | O(N) | O(最長連續按鍵長度) |  |
| 2376 | [Count Special Integers](https://leetcode.com/problems/count-special-integers/) | 🔴 Hard | Dp Digit | [C++](problems/2376.md) | O(D²) | O(1) |  |

<a id="shengshu-greedy"></a>
#### 🧩 Greedy（43）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 45 | [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | 🟡 Medium | Greedy Prefix Suffix | [C++](problems/0045.md) | O(N) | O(1) |  |
| 135 | [Candy](https://leetcode.com/problems/candy/) | 🔴 Hard | Greedy Fractional Knapsack | [C++](problems/0135.md) | O(N) | O(N) |  |
| 406 | [Queue Reconstruction by Height](https://leetcode.com/problems/queue-reconstruction-by-height/) | 🟡 Medium | Greedy Sorting Decision | [C++](problems/0406.md) | O(N²) | O(N) |  |
| 409 | [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/) | 🟢 Easy | Hash Table, Greedy | [C++](problems/0409.md) | O(N) | O(K) |  |
| 410 | [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | 🔴 Hard | Greedy Optimal Partitioning | [C++](problems/0410.md) | O(N log(sum(nums))) | O(1) |  |
| 452 | [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | 🟡 Medium | Greedy Interval Scheduling | [C++](problems/0452.md) | O(N log N) | O(1) |  |
| 462 | [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) | 🟡 Medium | Greedy Parity Contribution | [C++](problems/0462.md) | O(N log N) | O(1) |  |
| 502 | [IPO](https://leetcode.com/problems/ipo/) | 🔴 Hard | Greedy Job Sequencing | [C++](problems/0502.md) | O(N log N) | O(N) |  |
| 556 | [Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/) | 🟡 Medium | Greedy Digit Construction | [C++](problems/0556.md) | O(N) | O(N) |  |
| 621 | [Task Scheduler](https://leetcode.com/problems/task-scheduler/) | 🟡 Medium | Greedy Priority Queue | [C++](problems/0621.md) | O(N) | O(1) |  |
| 630 | [Course Schedule III](https://leetcode.com/problems/course-schedule-iii/) | 🔴 Hard | Greedy Job Sequencing | [C++](problems/0630.md) | O(N log N) | O(N) |  |
| 738 | [Monotone Increasing Digits](https://leetcode.com/problems/monotone-increasing-digits/) | 🟡 Medium | Greedy Digit Construction | [C++](problems/0738.md) | O(N) | O(N) |  |
| 763 | [Partition Labels](https://leetcode.com/problems/partition-labels/) | 🟡 Medium | Greedy Prefix Suffix | [C++](problems/0763.md) | O(N) | O(1) |  |
| 767 | [Reorganize String](https://leetcode.com/problems/reorganize-string/) | 🟡 Medium | Greedy Frequency Merging | [C++](problems/0767.md) | O(N log K) | O(K) |  |
| 778 | [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) | 🔴 Hard | Greedy Graph | [C++](problems/0778.md) | O(N² log N) | O(N²) |  |
| 787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | 🟡 Medium | Greedy Graph | [C++](problems/0787.md) | O(K \* E) | O(N) |  |
| 846 | [Hand of Straights](https://leetcode.com/problems/hand-of-straights/) | 🟡 Medium | Greedy Priority Queue | [C++](problems/0846.md) | O(N log N) | O(N) |  |
| 871 | [Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/) | 🔴 Hard | Greedy Fractional Knapsack | [C++](problems/0871.md) | O(N log N) | O(N) |  |
| 899 | [Orderly Queue](https://leetcode.com/problems/orderly-queue/) | 🔴 Hard | Greedy String Construction | [C++](problems/0899.md) | O(N²) | O(N) |  |
| 921 | [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) | 🟡 Medium | Stack, Greedy | [C++](problems/0921.md) | O(N) | O(1) |  |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string/) | 🟡 Medium | Greedy String Construction | [C++](problems/1061.md) | O(N + M \* α(26)) | O(26) |  |
| 1210 | [Minimum Moves to Reach Target With Rotations](https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/) | 🔴 Hard | Greedy Coin Change | [C++](problems/1210.md) | O(N²) | O(N²) |  |
| 1296 | [Divide Array in Sets of K Consecutive Numbers](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/) | 🟡 Medium | Greedy Frequency Merging | [C++](problems/1296.md) | O(N log N) | O(N) |  |
| 1338 | [Reduce Array Size to the Half](https://leetcode.com/problems/reduce-array-size-to-the-half/) | 🟡 Medium | Greedy Frequency Merging | [C++](problems/1338.md) | O(N log N) | O(N) |  |
| 1392 | [Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix/) | 🔴 Hard | Greedy Selection Constraints | [C++](problems/1392.md) | O(N) | O(N) |  |
| 1405 | [Longest Happy String](https://leetcode.com/problems/longest-happy-string/) | 🟡 Medium | Greedy String Construction | [C++](problems/1405.md) | O((a+b+c) log 3) | O(1) |  |
| 1531 | [String Compression II](https://leetcode.com/problems/string-compression-ii/) | 🔴 Hard | Greedy Optimal Partitioning | [C++](problems/1531.md) | O(N² \* K) | O(N \* K) |  |
| 1551 | [Minimum Operations to Make Array Equal](https://leetcode.com/problems/minimum-operations-to-make-array-equal/) | 🟡 Medium | Greedy Coin Change | [C++](problems/1551.md) | O(N) | O(1) |  |
| 1584 | [Minimum Cost to Connect All Points](https://leetcode.com/problems/minimum-cost-to-connect-all-points/) | 🟡 Medium | Greedy Graph | [C++](problems/1584.md) | O(N²) | O(N) |  |
| 1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) | 🟡 Medium | Greedy Graph | [C++](problems/1631.md) | O(M\*N log(M\*N)) | O(M\*N) |  |
| 1653 | [Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/) | 🟡 Medium | Greedy Prefix Suffix | [C++](problems/1653.md) | O(N) | O(1) |  |
| 1696 | [Jump Game VI](https://leetcode.com/problems/jump-game-vi/) | 🟡 Medium | Greedy Selection Constraints | [C++](problems/1696.md) | O(N) | O(N) |  |
| 1753 | [Maximum Score From Removing Stones](https://leetcode.com/problems/maximum-score-from-removing-stones/) | 🟡 Medium | Greedy Parity Contribution | [C++](problems/1753.md) | O((a+b+c) log 3) | O(1) |  |
| 1770 | [Maximum Score From Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) | 🔴 Hard | Greedy Selection Constraints | [C++](problems/1770.md) | O(M²) | O(M²) |  |
| 1851 | [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/) | 🔴 Hard | Greedy Priority Queue | [C++](problems/1851.md) | O((N+Q) log N) | O(N) |  |
| 1881 | [Maximum Value after Insertion](https://leetcode.com/problems/maximum-value-after-insertion/) | 🟡 Medium | Greedy, String | [C++](problems/1881.md) | O(N) | O(1) |  |
| 1936 | [Add Minimum Number of Rungs](https://leetcode.com/problems/add-minimum-number-of-rungs/) | 🟡 Medium | Greedy, Math | [C++](problems/1936.md) | O(N) | O(1) |  |
| 2064 | [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) | 🟡 Medium | Greedy Fractional Knapsack | [C++](problems/2064.md) | O(Q log M) | O(1) |  |
| 2111 | [Minimum Operations to Make the Array K-Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/) | 🔴 Hard | Greedy Optimal Partitioning | [C++](problems/2111.md) | O(N log N) | O(N) |  |
| 2116 | [Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/) | 🟡 Medium | Greedy | [C++](problems/2116.md) | O(N) | O(1) |  |
| 2178 | [Maximum Split of Positive Even Integers](https://leetcode.com/problems/maximum-split-of-positive-even-integers/) | 🟡 Medium | Greedy, Math | [C++](problems/2178.md) | O(√N) | O(√N) |  |
| 2182 | [Construct String With Repeat Limit](https://leetcode.com/problems/construct-string-with-repeat-limit/) | 🟡 Medium | Greedy, String, Two Pointers, Counting | [C++](problems/2182.md) | O(N) | O(1) |  |
| 3011 | [Find if Array Can Be Sorted](https://leetcode.com/problems/find-if-array-can-be-sorted/) | 🟡 Medium | Array, Greedy, Bit Manipulation | [C++](problems/3011.md) | O(N) | O(1) |  |

<a id="shengshu-backtracking"></a>
#### 🔢 Backtracking（25）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | 🟡 Medium | Backtracking | [C++](problems/0017.md) | O(4^N) | O(N) |  |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | 🟡 Medium | Backtracking, String | [C++](problems/0022.md) | O(4ᴺ/√N) | O(N) |  |
| 37 | [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | 🔴 Hard | Backtracking Constraint | [C++](problems/0037.md) | O(9^M) | O(1) |  |
| 39 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | 🟡 Medium | Backtracking | [C++](problems/0039.md) | O(N^(T/M)) | O(T/M) |  |
| 40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | 🟡 Medium | Backtracking, Sorting | [C++](problems/0040.md) | O(2ᴺ) | O(N) |  |
| 46 | [Permutations](https://leetcode.com/problems/permutations/) | 🟡 Medium | Backtracking | [C++](problems/0046.md) | O(N\*N!) | O(N) |  |
| 47 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | 🟡 Medium | Backtracking | [C++](problems/0047.md) | O(N\*N!) | O(N) |  |
| 51 | [N-Queens](https://leetcode.com/problems/n-queens/) | 🔴 Hard | Backtracking Constraint | [C++](problems/0051.md) | O(N!) | O(N) |  |
| 77 | [Combinations](https://leetcode.com/problems/combinations/) | 🟡 Medium | Backtracking | [C++](problems/0077.md) | O(K\*C(N,K)) | O(K) |  |
| 78 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 Medium | Backtracking Combination, Backtracking, Recursion | [C++](problems/0078.md) | O(N\*2ᴺ) | O(N) |  |
| 79 | [Word Search](https://leetcode.com/problems/word-search/) | 🟡 Medium | Backtracking Grid, DFS, Backtracking | [C++](problems/0079.md) | O(N\*3ᴸ) | O(L) |  |
| 131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) | 🟡 Medium | Backtracking Combination | [C++](problems/0131.md) | O(N × 2^N) | O(N) |  |
| 216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | 🟡 Medium | Backtracking | [C++](problems/0216.md) | O(C(9,K)) | O(K) |  |
| 526 | [Beautiful Arrangement](https://leetcode.com/problems/beautiful-arrangement/) | 🟡 Medium | Backtracking Permutation | [C++](problems/0526.md) | O(K) | O(N) |  |
| 638 | [Shopping Offers](https://leetcode.com/problems/shopping-offers/) | 🟡 Medium | Backtracking Combination | [C++](problems/0638.md) | O(∏(needs[i]+1)) | O(∏(needs[i]+1)) |  |
| 784 | [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) | 🟡 Medium | Backtracking | [C++](problems/0784.md) | O(2ᴺ) | O(N) |  |
| 980 | [Unique Paths III](https://leetcode.com/problems/unique-paths-iii/) | 🔴 Hard | Backtracking Grid | [C++](problems/0980.md) | O(4^(可走格數)) | O(M × N) |  |
| 1219 | [Path with Maximum Gold](https://leetcode.com/problems/path-with-maximum-gold/) | 🟡 Medium | Backtracking Grid | [C++](problems/1219.md) | O(4^(有金子的格數)) | O(M × N) |  |
| 1238 | [Circular Permutation in Binary Representation](https://leetcode.com/problems/circular-permutation-in-binary-representation/) | 🟡 Medium | Backtracking Permutation | [C++](problems/1238.md) | O(2^N) | O(2^N) |  |
| 1255 | [Maximum Score Words Formed by Letters](https://leetcode.com/problems/maximum-score-words-formed-by-letters/) | 🔴 Hard | Backtracking Combination | [C++](problems/1255.md) | O(2^N) | O(26) |  |
| 1415 | [The k-th Lexicographical String of All Happy Strings of Length n](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/) | 🟡 Medium | Backtracking Combination | [C++](problems/1415.md) | O(3 × 2^(N-1)) | O(N) |  |
| 1593 | [Split a String Into the Max Number of Unique Substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/) | 🟡 Medium | Backtracking Combination | [C++](problems/1593.md) | O(N\*2^(N-1)) | O(N) |  |
| 1947 | [Maximum Compatibility Score Sum](https://leetcode.com/problems/maximum-compatibility-score-sum/) | 🟡 Medium | Backtracking Permutation | [C++](problems/1947.md) | O(M!) | O(M) |  |
| 2044 | [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) | 🟡 Medium | Backtracking Combination | [C++](problems/2044.md) | O(2^N) | O(N) |  |
| 2305 | [Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/) | 🟡 Medium | Backtracking Constraint | [C++](problems/2305.md) | O(K^N) | O(N) |  |

<a id="shengshu-sliding-window"></a>
#### 🔢 Sliding Window（20）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 | 複習日期 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 3 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | 🟡 Medium | Sliding Window, Hash Table | [C++](problems/0003.md) | O(N) | O(1) |  |
| 209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum) | 🟡 Medium | Array, Sliding Window, Binary Search | [C++](problems/0209.md) | O(N) | O(1) |  |
| 424 | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement) | 🟡 Medium | Sliding Window, Hash Table | [C++](problems/0424.md) | O(N) | O(1) |  |
| 567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string/) | 🟡 Medium | Sliding Window, Frequency Array | [C++](problems/0567.md) | O(L1+L2) | O(1) |  |
| 643 | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i) | 🟢 Easy | Array, Sliding Window | [C++](problems/0643.md) | O(N) | O(1) |  |
| 1004 | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) | 🟡 Medium | Sliding Window | [C++](problems/1004.md) | O(N) | O(1) |  |
| 1248 | [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/) | 🟡 Medium | Array, Two Pointers, Sliding Window | [C++](problems/1248.md) | O(N) | O(1) |  |
| 1287 | [Element Appearing More Than 25% In Sorted Array](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/) | 🟢 Easy | Array, Sliding Window | [C++](problems/1287.md) | O(N) | O(1) |  |
| 1358 | [Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) | 🟡 Medium | Sliding Window | [C++](problems/1358.md) | O(N) | O(1) |  |
| 1456 | [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length) | 🟡 Medium | String, Sliding Window | [C++](problems/1456.md) | O(N) | O(1) |  |
| 1461 | [Check If a String Contains All Binary Codes of Size K](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/) | 🟡 Medium | Sliding Window, Hash Set, Bit Manipulation | [C++](problems/1461.md) | O(N\*K) | O(2^K) |  |
| 1493 | [Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/) | 🟡 Medium | Sliding Window, Two Pointers | [C++](problems/1493.md) | O(N) | O(1) |  |
| 1839 | [Longest Substring Of All Vowels in Order](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/) | 🟡 Medium | Variable Size Sliding Window, Sliding Window, Two Pointers | [C++](problems/1839.md) | O(N) | O(1) |  |
| 1876 | [Substrings of Size Three with Distinct Characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters) | 🟢 Easy | String, Sliding Window | [C++](problems/1876.md) | O(N) | O(1) |  |
| 2062 | [Count Vowel Substrings](https://leetcode.com/problems/count-vowel-substrings-of-a-string/) | 🟢 Easy | Math, Sliding Window | [C++](problems/2062.md) | O(N) | O(1) |  |
| 3090 | [Maximum Length Substring](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/) | 🟢 Easy | Sliding Window | [C++](problems/3090.md) | O(N) | O(1) |  |
| 3306 | [Count of Substrings Containing Every Vowel and K Consonants II](https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/) | 🟡 Medium | Sliding Window, Two Pointers, Difference Technique | [C++](problems/3306.md) | O(N) | O(1) |  |
| 3325 | [Count Substrings With K-Frequency Characters I](https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/) | 🟡 Medium | Sliding Window, Two Pointers | [C++](problems/3325.md) | O(N) | O(1) |  |
| 3392 | [Count Subarrays of Length Three With a Condition](https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/) | 🟢 Easy | Array, Sliding Window, Simulation | [C++](problems/3392.md) | O(N) | O(1) |  |
| 3456 | [Find Special Substring of Length K](https://leetcode.com/problems/find-special-substring-of-length-k/description/) | 🟢 Easy | Fixed Size Sliding Window, Block-Skipping | [C++](problems/3456.md) | O(N) | O(1) |  |

---

## 📊 各分類生疏 / 再練習 / 練習過 / 易忘 / 熟練統計

| 分類 | 🔴 生疏 | 🟠 再練習 | 🟡 練習過 | 🟣 易忘 | 🟢 熟練 | ⚪ 未標記 | 總數 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [2d-array](topics/2d-array.md) | 0 | 3 | 0 | 0 | 14 | 0 | 17 |
| [array](topics/array.md) | 1 | 10 | 2 | 3 | 9 | 0 | 25 |
| [array-boyer-moore](topics/array-boyer-moore.md) | 1 | 1 | 0 | 0 | 0 | 0 | 2 |
| [array-continuous-counting](topics/array-continuous-counting.md) | 0 | 5 | 2 | 1 | 3 | 0 | 11 |
| [array-difference-array](topics/array-difference-array.md) | 0 | 3 | 0 | 0 | 0 | 0 | 3 |
| [array-interval](topics/array-interval.md) | 0 | 0 | 5 | 0 | 0 | 0 | 5 |
| [array-linear-scan](topics/array-linear-scan.md) | 1 | 6 | 3 | 0 | 16 | 0 | 26 |
| [array-min-max](topics/array-min-max.md) | 0 | 0 | 0 | 0 | 5 | 0 | 5 |
| [array-negative-marking](topics/array-negative-marking.md) | 0 | 6 | 0 | 1 | 0 | 0 | 7 |
| [array-prefix-sum](topics/array-prefix-sum.md) | 5 | 1 | 6 | 5 | 2 | 0 | 19 |
| [backtracking-combination](topics/backtracking-combination.md) | 14 | 0 | 1 | 0 | 0 | 0 | 15 |
| [backtracking-constraint](topics/backtracking-constraint.md) | 3 | 0 | 0 | 0 | 0 | 0 | 3 |
| [backtracking-grid](topics/backtracking-grid.md) | 3 | 0 | 0 | 0 | 0 | 0 | 3 |
| [backtracking-permutation](topics/backtracking-permutation.md) | 5 | 0 | 0 | 0 | 0 | 0 | 5 |
| [binary-search](topics/binary-search.md) | 1 | 1 | 2 | 1 | 2 | 0 | 7 |
| [binary-search-build-in](topics/binary-search-build-in.md) | 5 | 0 | 2 | 0 | 3 | 0 | 10 |
| [binary-search-find-left-bound](topics/binary-search-find-left-bound.md) | 0 | 0 | 2 | 1 | 5 | 0 | 8 |
| [binary-search-find-right-bound](topics/binary-search-find-right-bound.md) | 1 | 0 | 1 | 1 | 0 | 0 | 3 |
| [binary-search-on-answer](topics/binary-search-on-answer.md) | 4 | 0 | 0 | 1 | 0 | 0 | 5 |
| [binary-search-tree](topics/binary-search-tree.md) | 0 | 4 | 4 | 1 | 7 | 0 | 16 |
| [bit-bitmask-subset-enumeration](topics/bit-bitmask-subset-enumeration.md) | 2 | 0 | 1 | 2 | 0 | 0 | 5 |
| [bit-manipulation](topics/bit-manipulation.md) | 0 | 11 | 2 | 8 | 17 | 0 | 38 |
| [bit-manipulation-and](topics/bit-manipulation-and.md) | 0 | 3 | 0 | 2 | 4 | 0 | 9 |
| [bit-manipulation-mask](topics/bit-manipulation-mask.md) | 0 | 1 | 0 | 0 | 2 | 0 | 3 |
| [bit-manipulation-or](topics/bit-manipulation-or.md) | 0 | 0 | 1 | 2 | 4 | 0 | 7 |
| [bit-manipulation-xor](topics/bit-manipulation-xor.md) | 0 | 3 | 1 | 5 | 8 | 0 | 17 |
| [design](topics/design.md) | 0 | 5 | 0 | 3 | 1 | 0 | 9 |
| [dp-bitmask](topics/dp-bitmask.md) | 6 | 0 | 0 | 0 | 0 | 0 | 6 |
| [dp-digit](topics/dp-digit.md) | 4 | 0 | 0 | 0 | 0 | 0 | 4 |
| [dp-fibonacci](topics/dp-fibonacci.md) | 1 | 1 | 2 | 1 | 3 | 0 | 8 |
| [dp-game-theory](topics/dp-game-theory.md) | 6 | 0 | 0 | 0 | 0 | 0 | 6 |
| [dp-greedy-pointer](topics/dp-greedy-pointer.md) | 0 | 0 | 2 | 0 | 0 | 0 | 2 |
| [dp-grid-path](topics/dp-grid-path.md) | 3 | 0 | 2 | 1 | 0 | 0 | 6 |
| [dp-interval](topics/dp-interval.md) | 6 | 0 | 0 | 0 | 0 | 0 | 6 |
| [dp-kadane](topics/dp-kadane.md) | 1 | 1 | 2 | 0 | 1 | 0 | 5 |
| [dp-knapsack](topics/dp-knapsack.md) | 3 | 0 | 9 | 0 | 0 | 0 | 12 |
| [dp-lcs](topics/dp-lcs.md) | 5 | 0 | 5 | 1 | 0 | 0 | 11 |
| [dp-lis](topics/dp-lis.md) | 4 | 0 | 3 | 0 | 0 | 0 | 7 |
| [dp-probability](topics/dp-probability.md) | 4 | 0 | 0 | 0 | 0 | 0 | 4 |
| [dp-state-machine](topics/dp-state-machine.md) | 5 | 0 | 2 | 0 | 0 | 0 | 7 |
| [dp-string](topics/dp-string.md) | 2 | 0 | 0 | 0 | 0 | 0 | 2 |
| [dp-subsequences](topics/dp-subsequences.md) | 4 | 0 | 0 | 0 | 0 | 0 | 4 |
| [dp-tree](topics/dp-tree.md) | 3 | 0 | 1 | 0 | 0 | 0 | 4 |
| [dynamic-programming](topics/dynamic-programming.md) | 4 | 0 | 0 | 1 | 0 | 0 | 5 |
| [fast-slow-pointers](topics/fast-slow-pointers.md) | 2 | 2 | 4 | 2 | 3 | 0 | 13 |
| [fixed-size-sliding-window](topics/fixed-size-sliding-window.md) | 10 | 0 | 0 | 0 | 0 | 0 | 10 |
| [graph-bfs](topics/graph-bfs.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [graph-dfs](topics/graph-dfs.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [graph-shortest-path](topics/graph-shortest-path.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [greedy](topics/greedy.md) | 4 | 6 | 0 | 3 | 2 | 0 | 15 |
| [greedy-coin-change](topics/greedy-coin-change.md) | 0 | 0 | 0 | 0 | 1 | 0 | 1 |
| [greedy-digit-construction](topics/greedy-digit-construction.md) | 3 | 2 | 3 | 0 | 1 | 0 | 9 |
| [greedy-fractional-knapsack](topics/greedy-fractional-knapsack.md) | 3 | 2 | 0 | 0 | 0 | 0 | 5 |
| [greedy-frequency-merging](topics/greedy-frequency-merging.md) | 4 | 0 | 0 | 0 | 0 | 0 | 4 |
| [greedy-graph](topics/greedy-graph.md) | 4 | 0 | 0 | 0 | 0 | 0 | 4 |
| [greedy-interval-scheduling](topics/greedy-interval-scheduling.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [greedy-job-sequencing](topics/greedy-job-sequencing.md) | 2 | 0 | 0 | 0 | 0 | 0 | 2 |
| [greedy-optimal-partitioning](topics/greedy-optimal-partitioning.md) | 3 | 0 | 0 | 0 | 0 | 0 | 3 |
| [greedy-parity-contribution](topics/greedy-parity-contribution.md) | 2 | 1 | 0 | 2 | 0 | 0 | 5 |
| [greedy-prefix-suffix](topics/greedy-prefix-suffix.md) | 3 | 2 | 0 | 1 | 0 | 0 | 6 |
| [greedy-priority-queue](topics/greedy-priority-queue.md) | 4 | 0 | 1 | 0 | 0 | 0 | 5 |
| [greedy-selection-constraints](topics/greedy-selection-constraints.md) | 3 | 0 | 1 | 0 | 0 | 0 | 4 |
| [greedy-sorting-decision](topics/greedy-sorting-decision.md) | 2 | 4 | 6 | 0 | 0 | 0 | 12 |
| [greedy-string-construction](topics/greedy-string-construction.md) | 4 | 3 | 0 | 0 | 1 | 0 | 8 |
| [greedy-validity-repair](topics/greedy-validity-repair.md) | 2 | 0 | 1 | 1 | 0 | 0 | 4 |
| [hamming-distance](topics/hamming-distance.md) | 0 | 1 | 1 | 0 | 2 | 0 | 4 |
| [hash-table-counting](topics/hash-table-counting.md) | 3 | 8 | 4 | 0 | 10 | 0 | 25 |
| [hash-table-existence](topics/hash-table-existence.md) | 2 | 3 | 4 | 1 | 9 | 0 | 19 |
| [hash-table-intersection](topics/hash-table-intersection.md) | 0 | 3 | 3 | 0 | 7 | 0 | 13 |
| [hash-table-mapping](topics/hash-table-mapping.md) | 0 | 3 | 1 | 0 | 5 | 0 | 9 |
| [hash-table-uniqueness](topics/hash-table-uniqueness.md) | 2 | 6 | 3 | 1 | 8 | 0 | 20 |
| [linked-list](topics/linked-list.md) | 0 | 5 | 5 | 3 | 4 | 0 | 17 |
| [linked-list-circular](topics/linked-list-circular.md) | 0 | 0 | 0 | 1 | 0 | 0 | 1 |
| [math](topics/math.md) | 0 | 17 | 1 | 9 | 13 | 0 | 40 |
| [math-combination](topics/math-combination.md) | 0 | 1 | 2 | 2 | 0 | 0 | 5 |
| [math-digit-decomposition](topics/math-digit-decomposition.md) | 0 | 6 | 3 | 3 | 30 | 0 | 42 |
| [math-factor-enumeration](topics/math-factor-enumeration.md) | 0 | 2 | 0 | 2 | 1 | 0 | 5 |
| [math-game-theory](topics/math-game-theory.md) | 0 | 1 | 0 | 5 | 0 | 0 | 6 |
| [math-gcd](topics/math-gcd.md) | 0 | 4 | 1 | 0 | 3 | 0 | 8 |
| [math-geometry](topics/math-geometry.md) | 0 | 1 | 1 | 0 | 2 | 0 | 4 |
| [math-palindrome](topics/math-palindrome.md) | 0 | 2 | 0 | 0 | 0 | 0 | 2 |
| [math-permutation](topics/math-permutation.md) | 0 | 1 | 1 | 0 | 0 | 0 | 2 |
| [math-prime](topics/math-prime.md) | 0 | 5 | 2 | 2 | 5 | 0 | 14 |
| [math-simulation](topics/math-simulation.md) | 0 | 0 | 1 | 0 | 1 | 0 | 2 |
| [monotonic-queue](topics/monotonic-queue.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [monotonic-stack](topics/monotonic-stack.md) | 8 | 0 | 0 | 0 | 0 | 0 | 8 |
| [priority-queue](topics/priority-queue.md) | 5 | 0 | 1 | 0 | 1 | 0 | 7 |
| [queue](topics/queue.md) | 0 | 1 | 0 | 0 | 0 | 0 | 1 |
| [quick-select](topics/quick-select.md) | 1 | 4 | 1 | 0 | 1 | 0 | 7 |
| [sorting](topics/sorting.md) | 4 | 1 | 5 | 1 | 4 | 0 | 15 |
| [sorting-bucket-sort](topics/sorting-bucket-sort.md) | 0 | 0 | 1 | 0 | 0 | 0 | 1 |
| [sorting-counting-sort](topics/sorting-counting-sort.md) | 1 | 0 | 3 | 0 | 0 | 0 | 4 |
| [sorting-custom-comparator](topics/sorting-custom-comparator.md) | 0 | 5 | 3 | 0 | 2 | 0 | 10 |
| [sorting-cycle-decomposition](topics/sorting-cycle-decomposition.md) | 3 | 0 | 0 | 0 | 0 | 0 | 3 |
| [sorting-implementation](topics/sorting-implementation.md) | 2 | 0 | 0 | 1 | 0 | 0 | 3 |
| [sorting-radix-sort](topics/sorting-radix-sort.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [sql](topics/sql.md) | 0 | 0 | 0 | 0 | 1 | 0 | 1 |
| [stack](topics/stack.md) | 3 | 5 | 0 | 0 | 6 | 0 | 14 |
| [string](topics/string.md) | 1 | 10 | 5 | 3 | 15 | 0 | 34 |
| [string-character-classification](topics/string-character-classification.md) | 0 | 6 | 0 | 0 | 25 | 0 | 31 |
| [string-kmp](topics/string-kmp.md) | 0 | 0 | 1 | 1 | 0 | 0 | 2 |
| [string-state-machine](topics/string-state-machine.md) | 0 | 0 | 0 | 1 | 0 | 0 | 1 |
| [string-substring](topics/string-substring.md) | 0 | 1 | 1 | 0 | 1 | 0 | 3 |
| [string-substring-enumeration](topics/string-substring-enumeration.md) | 0 | 0 | 0 | 1 | 0 | 0 | 1 |
| [topological-sort](topics/topological-sort.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [tree](topics/tree.md) | 0 | 0 | 0 | 1 | 3 | 0 | 4 |
| [tree-bfs-level-order](topics/tree-bfs-level-order.md) | 0 | 6 | 0 | 1 | 9 | 0 | 16 |
| [tree-construction](topics/tree-construction.md) | 0 | 0 | 0 | 3 | 0 | 0 | 3 |
| [tree-dfs-backtracking](topics/tree-dfs-backtracking.md) | 0 | 1 | 1 | 0 | 1 | 0 | 3 |
| [tree-dfs-global](topics/tree-dfs-global.md) | 0 | 1 | 1 | 5 | 0 | 0 | 7 |
| [tree-dfs-path](topics/tree-dfs-path.md) | 0 | 9 | 3 | 5 | 12 | 0 | 29 |
| [tree-traversal](topics/tree-traversal.md) | 0 | 0 | 0 | 3 | 4 | 0 | 7 |
| [trie](topics/trie.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [two-pointers-center-expansion](topics/two-pointers-center-expansion.md) | 2 | 0 | 0 | 0 | 0 | 0 | 2 |
| [two-pointers-opposite](topics/two-pointers-opposite.md) | 1 | 3 | 6 | 4 | 3 | 0 | 17 |
| [two-pointers-other](topics/two-pointers-other.md) | 0 | 0 | 1 | 1 | 0 | 0 | 2 |
| [two-pointers-partition](topics/two-pointers-partition.md) | 1 | 1 | 1 | 0 | 0 | 0 | 3 |
| [two-pointers-same](topics/two-pointers-same.md) | 9 | 5 | 1 | 3 | 2 | 0 | 20 |
| [two-pointers-swap](topics/two-pointers-swap.md) | 0 | 2 | 2 | 0 | 10 | 0 | 14 |
| [union-find](topics/union-find.md) | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| [variable-size-sliding-window](topics/variable-size-sliding-window.md) | 10 | 0 | 1 | 0 | 0 | 0 | 11 |

