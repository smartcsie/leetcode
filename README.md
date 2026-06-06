# LeetCode 演算法精鍊筆記 (C++)

![LeetCode Stats](https://leetcard.jacoblin.cool/smartcsie?theme=nord) <!-- 註：將 laurence 換成你的 LeetCode ID -->

本倉庫用於記錄我的 LeetCode 解題過程、思路分析以及演算法優化心得。

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

## 🤖 重要
- **[Leetcode Hot 100](https://leetcode.com/problem-list/arw5ns9e/)**

---

> [!NOTE]
> Kadane's Algoritm<br>
> Topological Sort<br>
> BFS (Breadth-First Search)<br>
> DFS (Depth-First Search)<br>
> Backtracking（回溯法<br>
> Union Find（並查集<br>
> Knapsack Problem<br>
> Longest Common Subsequence (LCS)<br>
> Dijkstra's Algorithm<br>
> Morris Traversal<br>
> [Knuth-Morris-Pratt (KMP) Algorithm]<br>
> [Rabin-Karp Algorithm (Rolling Hash)]<br>
> [Z-Algorithm)]<br>
> [Trie]<br>

> [!NOTE]
> [Brian Kernighan's Algorithm]<br>
> n &= (n - 1)<br>

> [!NOTE]
> [Boyer-Moore Voting Algorithm]<br>
> 169. Majority Element

> [!NOTE]
> [Finite State Machine]<br>
> 137. Single Number II<br>
> 260. Single Number III<br>
> 696. Count Binary Substrings<br>

> [!NOTE]
> [Manacher's Algorithm]<br>
> 5. Longest Palindromic Substring<br>
> 214. Shortest Palindrome (困難)<br>
> 647. Palindromic Substrings (中等)<br>
> 1312. Minimum Insertion Steps to Make a String Palindrome (困難)<br><br>
> 為什麼 Manacher's 在 LeetCode 這麼稀少？你會發現 **Manacher's Algorithm 在 LeetCode 的「推薦程度」其實不高**<br>
> 主要原因如下<br>
> 實作難度高：Manacher 涉及到字串預處理（插入 # 符號）以及狀態陣列的更新，在緊張的面試環境中容易寫錯。<br>
> O(n²) 通常足夠：LeetCode 上大部分回文題的字串長度 N 通常不超過 1000 或 2000，這使得 O(n²) 的簡單中心擴展法足以通過測試。<br>
> 考點差異：面試官通常更傾向於考「動態規劃 (DP)」或「雙指標」，因為這些方法在邏輯思維上更具普遍性。<br>


> [!NOTE]
> C++ build in function<br>
> (1) **1的個數**<br>
__builtin_popcount(x)<br>
> (2) **Binary search**<br>
> auto it_low = std::lower_bound(nums.begin(), nums.end(), 4); //找第一個 >= 4 的位置 (lower_bound)<br>
> auto it_up = std::upper_bound(nums.begin(), nums.end(), 4);  //找第一個 > 4 的位置 (upper_bound)<br>
> (3) **Quick Select**<br>
> 語法：nth_element(起點, 目標位置, 終點)<br>
> std::nth_element(nums.begin(), nums.begin() + 2, nums.end()); // 找出第 3 小的元素 (索引為 2，從 0 開始算)<br>

---

## 🚀 快速導覽

**Basics**<br>
[🔢 Math](#math) | [📊 Bit Manipulation](#Bit-manipulation) | [🔗 String](#string) | [🍱 Array](#array) | [🍱 2D Array](#2d-array) | [🔑 Hash Table - Counting](#hash-table-counting) | [🔑 Hash Table - Mapping](#hash-table-mapping) | [🔑 Hash Table - Set](#hash-table-set)<br>

**Search & Sort**<br>
[🔍 Binary Search](#binary-search) | [🔍 Prefix Sum](#prefix-sum) | [📊 Sorting](#Sorting) | [📚 Quick Select](#quick-select)<br>

**Pointers**<br>
[👥 Fast-Slow Pointers](#fast-slow-pointers) | [👥 Two Pointers - Opposite](#two-pointers-opposite) | [👥 Two Pointers - Same](#two-pointers-same) | [👥 Two Pointers - Partition](#two-pointers-partition) | [👥 Two Pointers - Other](#two-pointers-other)<br>

**Linear Structures**<br>
[⛓️ Linked List](#linked-list) | [📚 Stack](#stack) | [📚 Monotonic Stack](#monotonic-stack) | [📚 Priority Queue](#priority-queue)<br>

**Tree**<br>
[🌳 Tree](#tree) | [🌳 Tree - BFS / Level Order](#tree-bfs-level-order) | [🌳 Tree - DFS / Path](#tree-dfs-path) | [🌳 Binary Search Tree](#binary-search-tree)<br>

**Sliding Window**<br>
[🔢 Fixed Size Sliding Window](#fixed-size-sliding-window) | [🔢 Variable Size Sliding Window](#variable-size-sliding-window)<br>

**Advanced**<br>
[🧩 Dynamic Programming](#dynamic-programming) | [🧩 Greedy](#greedy) | [🔢 Backtracking](#backtracking) | [🔢 Negative Marking](#negative-marking)<br>

<br><br>
---

## <a name="math"></a>🔢 Math (數學)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0007 | <div style="width: 600px">[Reverse Integer](https://leetcode.com/problems/reverse-integer/)</div> | 🟡 Medium | Math | [C++](./solution/Solution_0007.cpp) | O(logn) | O(1) |
| 0009 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0009.cpp) | O(logn) | O(1) |
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 Medium | Math <br> Binary Exponentiation | [C++](./solution/Solution_0050.cpp) | O(log N) | O(1) |
| 0066 | [Plus One](https://leetcode.com/problems/plus-one/) | 🟢 Easy | Math | [C++](./solution/Solution_0066.cpp) | O(n) | O(1) |
| 0067 | [Add Binary](https://leetcode.com/problems/add-binary) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_0067.cpp) | O(max(M, N)) | O(1) |
| 0137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Math <br> Hash Set | [C++](./solution/Solution_0137_1.cpp) | O(n) | O(n) |
| 0172 | [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes) | 🟡 Medium | Math | [C++](./solution/Solution_0172.cpp) | O(log5 N) | O(1) |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | 🟢 Easy | Math | [C++](./solution/Solution_0231.cpp) | O(1) | O(1) |
| 0258 | [Add Digits](https://leetcode.com/problems/add-digits) | 🟢 Easy | Math | [C++](./solution/Solution_0258.cpp) | O(1) | O(1) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 Easy | Math | [C++](./solution/Solution_0263.cpp) | O(log n) | O(1) |
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0268.cpp) | O(n) | O(1) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three/) | 🟢 Easy | Math | [C++](./solution/Solution_0326.cpp) | O(log₃n) | O(1) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four/) | 🟢 Easy | Math | [C++](./solution/Solution_0342.cpp) | O(1) | O(1) |
| 0504 | [Base 7](https://leetcode.com/problems/base-7) | 🟢 Easy | Math <br>  String | [C++](./solution/Solution_0504.cpp) | O(log7 N) | O(1) |
| 0628 | [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_0628.cpp) | O(N) | O(1) |
| 0970 | [Powerful Integers](https://leetcode.com/problems/powerful-integers/) | 🟡 Medium | Math / Hash Table | [C++](./solution/Solution_0970.cpp) | O(log_x(bound) * log_y(bound)) | O(S) |
| 1017 | [Convert to Base -2](https://leetcode.com/problems/convert-to-base-2) | 🟡 Medium | Math | [C++](./solution/Solution_1017.cpp) | O(log N) | O(1) |
| 1295 | [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits) | 🟢 Easy | Array <br>  Math | [C++](./solution/Solution_1295.cpp) | O(N) | O(1) |
| 1572 | [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum) | 🟢 Easy | Matrix | [C++](./solution/Solution_1572.cpp) | O(N) | O(1) |
| 1822 | [Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_1822.cpp) | O(N) | O(1) |
| 1837 | [Sum of Digits in Base K](https://leetcode.com/problems/sum-of-digits-in-base-k) | 🟢 Easy | Math | [C++](./solution/Solution_1837.cpp) | O(logK N) | O(1) |
| 1980 | [Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string) | 🟡 Medium | Math <br>  String | [C++](./solution/Solution_1980.cpp) | O(N^2) | O(N) |
| 1952 | [Three Divisors](https://leetcode.com/problems/three-divisors) | 🟢 Easy | Math | [C++](./solution/Solution_1952.cpp) | O(sqrt(N)) | O(1) |
| 2177 | [Find Three Consecutive Integers That Sum to a Given Number](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number) | 🟡 Medium | Math | [C++](./solution/Solution_2177.cpp) | O(1) | O(1) |
| 2553 | [Separate the Digits in an Array](https://leetcode.com/problems/separate-the-digits-in-an-array) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_2553.cpp) | O(n * log(max_val)) | O(n * log(max_val)) |
| 2652 | [Sum Multiples](https://leetcode.com/problems/sum-multiples) | 🟢 Easy | Math | [C++](./solution/Solution_2652.cpp) | O(n) | O(1) |

> [!NOTE]
> **康托爾對角線證明 (Cantor's Diagonal Argument)**<br>
>  [1980. Find Unique Binary String](./solution/Solution_1980.cpp)<br>

> [!NOTE]
> **勒讓德定理 (Legendre's Formula)<br>
>  [172. Factorial Trailing Zeroes](./solution/Solution_0172.cpp)<br>

<br><br>
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
| 0338 | [Counting Bits](https://leetcode.com/problems/counting-bits) | 🟢 Easy | DP / Bit Manipulation | [C++](./solution/Solution_0338.cpp) | O(n) | O(n) |
| 0371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0371.cpp) | O(1) | O(1) |
| 0461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0461.cpp) | O(k) | O(1) |
| 0476 | [Number Complement](https://leetcode.com/problems/number-complement) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0476.cpp) | O(log N) | O(1) |
| 1009 | [Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_1009.cpp) | O(log N) | O(1) |
| 1684 | [Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings) | 🟢 Easy | Array / Hash Table / Bit Manipulation | [C++](./solution/Solution_1684.cpp) | O(N * M) | O(1) |
| 2220 | [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2220.cpp) | O(log(max(start, goal))) | O(1) |
| 2235 | [Add Two Integers](https://leetcode.com/problems/add-two-integers) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2235.cpp) | O(1) | O(1) |
| 2317 | [Maximum XOR After Operations](https://leetcode.com/problems/maximum-xor-after-operations) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_2317.cpp) | O(n) | O(1) |
| 2595 | [Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2595.cpp) | O(log N) | O(1) |
| 2917 | [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2917.cpp) | O(N * log(max_val)) | O(1) |
| 3151 | [Special Array I](https://leetcode.com/problems/special-array-i) | 🟢 Easy | Array <br> Bit Manipulation | [C++](./solution/Solution_3151.cpp) | O(N) | O(1) |


> [!NOTE]
> [0260 Single Number III](./solution/Solution_0201.cpp) 是 Bit Manipulation 經典題目，目前只有**neetcode.io**有最佳解<br>
> 溢位處理有許多常見的解法，如 [meyr543](https://hackmd.io/@meyr543/rkSRWnXPK), [grandyang](https://www.cnblogs.com/grandyang/p/4741122.html),[doocs](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0260.Single%20Number%20III/Solution.cpp),[BylwiCXPt](https://hackmd.io/@Inversionpeter/BylwiCXPt)<br>
> 使用 'unsigned',`long long` 來處理 `INT_MIN` 的溢位，這在工程上屬於一種 **Workaround**<br>
> 建議優先使用邏輯位移（`while` 迴圈）來避免對負數進行取補數運算，從而徹底解決溢位風險。<br>

> [!NOTE]
> [1684 Count the Number of Consistent Strings](./solution/Solution_1684.cpp)<br>
> 為什麼選擇 int mask 而非 bitset？<br>
> int (或 long) 的運算直接對應 CPU 的暫存器指令，在這種極小範圍 (26 bits) 的情況下，<br>
> 它的運算速度幾乎是瞬間完成，且不需要引入額外的標頭檔 (<bitset>)，代碼更簡潔。<br>

> [!NOTE]
> [1684 Number Complement](./solution/Solution_0476.cpp)<br>
> 和
> [1009 Complement of Base 10 Integer](./solution/Solution_1009.cpp)<br>
> 本質上是相同的題目。<br>

<br><br>
---

## <a name="string"></a>🔗 String (字串)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0008 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi) | 🟡 Medium | String <br> Math | [C++](./solution/Solution_0008.cpp) | O(N) | O(1) |
| 0014 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | String <br> Trie | [C++](./solution/Solution_0014.cpp) | O(S) | O(1) |
| 0028 | [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string) | 🟢 Easy | String <br> KMP | [C++](./solution/Solution_0028.cpp) | O(N * M) | O(1) |
| 0058 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word) | 🟢 Easy | String | [C++](./solution/Solution_0058.cpp) | O(n) | O(1) |
| 0415 | [Add Strings](https://leetcode.com/problems/add-strings) | 🟢 Easy | String / Math | [C++](./solution/Solution_0415.cpp) | O(max(N, M)) | O(max(N, M)) |
| 0434 | [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string) | 🟢 Easy | String | [C++](./solution/Solution_0434.cpp) | O(N) | O(1) |
| 0459 | [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern) | 🟢 Easy | String <br> KMP | [C++](./solution/Solution_0459.cpp) | O(n) | O(n) |
| 0709 | [To Lower Case](https://leetcode.com/problems/to-lower-case) | 🟢 Easy | String | [C++](./solution/Solution_0709.cpp) | O(N) | O(1) |
| 0796 | [Rotate String](https://leetcode.com/problems/rotate-string) | 🟢 Easy | String | [C++](./solution/Solution_0796.cpp) | O(N) | O(N) |
| 1528 | [Shuffle String](https://leetcode.com/problems/shuffle-string) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_1528.cpp) | O(N) | O(N) |
| 1758 | [Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string) | 🟢 Easy | String | [C++](./solution/Solution_1758.cpp) | O(N) | O(1) |
| 2042 | [Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence) | 🟢 Easy | String <br> Parsing | [C++](./solution/Solution_2042.cpp) | O(n) | O(1) |
| 2114 | [Maximum Number of Words Found in Sentences](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_2114.cpp) | O(N * M) | O(1) |
| 2124 | [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs) | 🟢 Easy | String | [C++](./solution/Solution_2124.cpp) | O(N) | O(1) |
| 2264 | [Largest 3-Same-Digit Number in String](https://leetcode.com/problems/largest-3-same-digit-number-in-string) | 🟢 Easy | String | [C++](./solution/Solution_2264.cpp) | O(N) | O(1) |
| 2460 | [Apply Operations to an Array](https://leetcode.com/problems/apply-operations-to-an-array) | 🟢 Easy | Array <br> Simulation | [C++](./solution/Solution_2460.cpp) | O(N) | O(1) |
| 2490 | [Circular Sentence](https://leetcode.com/problems/circular-sentence) | 🟢 Easy | String | [C++](./solution/Solution_2490.cpp) | O(N) | O(1) |
| 2586 | [Count the Number of Vowel Strings in Range](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_2586.cpp) | O(n) | O(1) |
| 2678 | [Number of Senior Citizens](https://leetcode.com/problems/number-of-senior-citizens) | 🟢 Easy | String | [C++](./solution/Solution_2678.cpp) | O(n) | O(1) |
| 2828 | [Check if a String Is an Acronym of Words](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_2828.cpp) | O(n) | O(1) |
| 3110 | [Score of a String](https://leetcode.com/problems/score-of-a-string) | 🟢 Easy | String | [C++](./solution/Solution_3110.cpp) | O(N) | O(1) |
| 3498 | [Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_3498.cpp) | O(n) | O(1) |

<br><br>
---

## <a name="array"></a>🍱 Array (陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0057 | [Insert Interval](https://leetcode.com/problems/insert-interval) | 🟡 Medium | Array / Interval | [C++](./solution/Solution_0057.cpp) | O(N) | O(N) |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element/) | 🟢 Easy | Array / Voting Algorithm | [C++](./solution/Solution_0169.cpp) | O(N) | O(1) |
| 0189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | 🟡 Medium | Array | [C++](./solution/Solution_0189.cpp) | O(n) | O(1) |
| 0485 | [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones) | 🟢 Easy | Array | [C++](./solution/Solution_0485.cpp) | O(N) | O(1) |
| 0896 | [Monotonic Array](https://leetcode.com/problems/monotonic-array) | 🟢 Easy | Array | [C++](./solution/Solution_0896.cpp) | O(N) | O(1) |
| 1299 | [Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side) | 🟢 Easy | Array | [C++](./solution/Solution_1299.cpp) | O(N) | O(1) |
| 1431 | [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) | 🟢 Easy | Array | [C++](./solution/Solution_1431.cpp) | O(N) | O(1)* |
| 1470 | [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/) | 🟢 Easy | Array | [C++](./solution/Solution_1470.cpp) | O(N) | O(N) |
| 1662 | [Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_1662.cpp) | O(N + M) | O(1) |
| 1752 | [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated) | 🟢 Easy | Array | [C++](./solution/Solution_1752.cpp) | O(N) | O(1) |
| 1800 | [Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum) | 🟢 Easy | Array | [C++](./solution/Solution_1800.cpp) | O(N) | O(1) |
| 1913 | [Maximum Product Difference Between Two Pairs](https://leetcode.com/problems/maximum-product-difference-between-two-pairs) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_1913.cpp) | O(N) | O(1) |
| 1929 | [Concatenation of Array](https://leetcode.com/problems/concatenation-of-array) | 🟢 Easy | Array | [C++](./solution/Solution_1929.cpp) | O(N) | O(1)* |
| 2239 | [Find Closest Number to Zero](https://leetcode.com/problems/find-closest-number-to-zero) | 🟢 Easy | Array | [C++](./solution/Solution_2239.cpp) | O(N) | O(1) |

<br><br>
---

## <a name="2d-array"></a>🍱 2D Array (二維陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0048 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | 🟡&nbsp;Medium | Array | [C++](./solution/Solution_0048.cpp) | O(n²) | O(1) |
| 0073 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes) | 🟡 Medium | Array / Matrix | [C++](./solution/Solution_0073.cpp) | O(M*N) | O(1) |
| 0867 | [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) | 🟢 Easy | Matrix | [C++](./solution/Solution_0867.cpp) | O(M*N) | O(M*N) |
| 1886 | [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/) | 🟢 Easy | Array | [C++](./solution/Solution_1886.cpp) | O(n²) | O(1) |
| 2022 | [Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array) | 🟢 Easy | Array <br> Matrix <br> Simulation | [C++](./solution/Solution_2022.cpp) | O(m*n) | O(1) |


<br><br>
---



## <a name="binary-search"></a>🔍 Binary Search (二分查找)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0004 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | 🔴 Hard | Binary Search | [C++](./solution/Solution_0004.cpp) | O(log(m+n)) | O(1) |
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 Medium | Array <br> Binary Search | [C++](./solution/Solution_0033.cpp) | O(logN) | O(1) |
| 0069 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0069.cpp) | O(logn) | O(1) |
| 0074 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) | 🟡 Medium | Binary Search <br> Matrix | [C++](./solution/Solution_0074.cpp) | O(log(MN)) | O(1) |
| 0081 | [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0081.cpp) | O(N) | O(1) |
| 0153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | 🟡&nbsp;Medium | Binary&nbsp;Search | [C++](./solution/Solution_0153.cpp) | O(logn) | O(1) |
| 0154 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii) | 🔴 Hard | Binary Search | [C++](./solution/Solution_0154.cpp) | O(N) | O(1) |
| 0162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0162.cpp) | O(logN) | O(1) |
| 0278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0278.cpp) | O(logn) | O(1) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Dynamic Programming <br> Binary Search | [C++](./solution/Solution_0300_1.cpp) | O(nlogn) | O(n) |
| 0367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0367.cpp) | O(logn) | O(1) | 
| 0374 | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0374.cpp) | O(logn) | O(1) |
| 0540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0540.cpp) | O(logN) | O(1) |
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0704.cpp) | O(logn) | O(1) |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0852.cpp) | O(logn) | O(1) |
| 2529 | [Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer) | 🟢 Easy | Binary Search | [C++](./solution/Solution_2529.cpp) | O(logN) | O(1) |
> [!NOTE]
> mid 取法<br>
> int mid = (left + right)/2; **本身有overflow的風險**<br>
> int mid = left + ((right - left) >> 1); 本身比較安全<br>

<br><br>
---
## <a name="binary-search-build-in"></a>🔍 Binary Search Build in Function (二分查找)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0034 | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0034.cpp) | O(log N) | O(1) |
| 0035 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0035.cpp) | O(logn) | O(1) |
| 0744 | [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0744.cpp) | O(logN) | O(1) |
| 1539 | [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number) | 🟢 Easy | Binary Search | [C++](./solution/Solution_1539.cpp) | O(log N) | O(1) |

<br><br>
---

## <a name="prefix-sum"></a>🔍 Prefix Sum (前綴和)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0303 | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_0303.cpp) | O(N) | O(N) |
| 0304 | [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable) | 🟡 Medium | Array <br> Matrix <br> Prefix Sum | [C++](./solution/Solution_0304.cpp) | O(M * N) 初始化 / O(1) 查詢 | O(M * N) |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) | 🟡 Medium | Array <br> Hash Table <br> Prefix Sum | [C++](./solution/Solution_0560.cpp) | O(N) | O(N) |
| 0724 | [Find Pivot Index](https://leetcode.com/problems/find-pivot-index) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_0724.cpp) | O(N) | O(1) |
| 1480 | [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_1480.cpp) | O(N) | O(1) |
| 2559 | [Count Vowel Strings in Ranges](https://leetcode.com/problems/count-vowel-strings-in-ranges) | 🟡 Medium | Array <br> Prefix Sum | [C++](./solution/Solution_2559.cpp) | O(N + Q) | O(N) |

<br><br>
---

## <a name="linked-list"></a>⛓️ Linked List (鏈表)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0002 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) | 🟡 Medium | Linked List / Math | [C++](./solution/Solution_0002.cpp) | O(max(N, M)) | O(max(N, M)) |
| 0021 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | 🟢 Easy | Linked List | [C++](./solution/Solution_0021.cpp) | O(n+m) | O(1) |
| 0024 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs) | 🟡 Medium | Linked List / Recursion | [C++](./solution/Solution_0024.cpp) | O(N) | O(N) |
| 0082 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii) | 🟡 Medium | Linked List / Two Pointers | [C++](./solution/Solution_0082.cpp) | O(n) | O(1) |
| 0083 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0083.cpp) | O(n) | O(1) |
| 0092 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii) | 🟡 Medium | Linked List | [C++](./solution/Solution_0092.cpp) | O(N) | O(1) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 Easy | Linked List <br> Fast-Slow Pointers| [C++](./solution/Solution_0141.cpp) | O(n) | O(1) |
| 0203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements) | 🟢 Easy | Linked List | [C++](./solution/Solution_0203.cpp) | O(N) | O(1) |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0206.cpp) | O(n) | O(1) | 
| 0234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) | 🟢 Easy | Linked List / Two Pointers / Vector | [C++](./solution/Solution_0234.cpp) | O(n) | O(n) |
| 0237 | [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0237.cpp) | O(1) | O(1) |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 Easy | Linked List <br> Two Pointers  <br> Fast-Slow Pointers | [C++](./solution/Solution_0876.cpp) | O(n) | O(1) |

<br><br>
---

## <a name="fast-slow-pointers"></a>👥 Fast-Slow Pointers (快慢指針)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0019 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list) | 🟡 Medium | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0019.cpp) | O(n) | O(1) |
| 0026 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | 🟢 Easy | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0026.cpp) | O(n) | O(1) |
| 0027 | [Remove Element](https://leetcode.com/problems/remove-element/) | 🟢 Easy | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0027.cpp) | O(n) | O(1) |
| 0080 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | 🟡 Medium | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0080.cpp) | O(n) | O(1) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 Easy | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0141.cpp) | O(n) | O(1) |
| 0142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | 🟡 Medium | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0142.cpp) | O(n) | O(1) |
| 0143 | [Reorder List](https://leetcode.com/problems/reorder-list) | 🟡 Medium | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0143.cpp) | O(n) | O(1) |
| 0202 | [Happy Number](https://leetcode.com/problems/happy-number) | 🟢 Easy | Hash Table <br> Fast-Slow Pointers | [C++](./solution/Solution_0202.cpp) | O(log n) | O(1) |
| 0283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | 🟢 Easy | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0283.cpp) | O(n) | O(1) |
| 0287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | 🟡 Medium | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0287.cpp) | O(n) | O(1) |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 Easy | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0876.cpp) | O(n) | O(1) |
| 2095 | [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list) | 🟡 Medium | Linked List / Fast-Slow Pointers | [C++](./solution/Solution_2095.cpp) | O(N) | O(1) |
> [!NOTE]
> [Fast-Slow Pointers 核心概念]<br>
> 慢指針（slow）當「寫入游標」，快指針（fast）當「掃描游標」：0026、0027、0080、0283<br>
> 快指針先走 N 步，再同步移動找倒數位置：0019<br>
> Floyd's Cycle Detection（龜兔賽跑）偵測環：0141、0142、0202、0287<br>
> 快慢找中點後再處理：0143、0876<br>

<br><br>
---

## <a name="two-pointers-opposite"></a>👥 Two Pointers - Opposite Direction (對撞型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | 🟡 Medium | Array <br> Two Pointers <br> Greedy | [C++](./solution/Solution_0011.cpp) | O(n) | O(1) |
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0015.cpp) | O(n²) | O(log n) |
| 0016 | [3Sum Closest](https://leetcode.com/problems/3sum-closest) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0016.cpp) | O(n²) | O(1) |
| 0125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0125.cpp) | O(n) | O(1) |
| 0167 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) | 🟡 Medium | Array <br> Two Pointers | [C++](./solution/Solution_0167.cpp) | O(n) | O(1) |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0344.cpp) | O(n) | O(1) |
| 0345 | [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0345.cpp) | O(N) | O(1) |
| 0905 | [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0905.cpp) | O(n) | O(1) |
| 0941 | [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0941.cpp) | O(n) | O(1) |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0977.cpp) | O(n) | O(n) |
| 1750 | [Minimum Length of String After Deleting Similar Ends](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_1750.cpp) | O(N) | O(1) |

> [!NOTE]
> [Opposite Direction 核心概念]<br>
> left 從頭、right 從尾，條件不符時移動較劣的那側。<br>
> 通常需要**排序**作為前提（0015、0016、0167、0977）。<br>
> 回文判斷（0125、0344、0345）：左右同時往中間收斂，不符合就提早返回。<br>

<br><br>
---

## <a name="two-pointers-same"></a>👥 Two Pointers - Same Direction (同向型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0031 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | 🟡 Medium | Array / Two Pointers | [C++](./solution/Solution_0031.cpp) | O(N) | O(1) |
| 0228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0228.cpp) | O(N) | O(1) |
| 0392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0392.cpp) | O(n) | O(1) |
| 0844 | [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0844.cpp) | O(N+M) | O(1) |
| 1089 | [Duplicate Zeros](https://leetcode.com/problems/duplicate-zeros) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_1089.cpp) | O(N) | O(1) |
| 1721 | [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list) | 🟡 Medium | Linked List <br> Two Pointers | [C++](./solution/Solution_1721.cpp) | O(N) | O(1) |
| 1768 | [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_1768.cpp) | O(N+M) | O(1) |
| 2109 | [Adding Spaces to a String](https://leetcode.com/problems/adding-spaces-to-a-string) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_2109.cpp) | O(N+M) | O(N+M) |
| 2540 | [Minimum Common Value](https://leetcode.com/problems/minimum-common-value) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_2540.cpp) | O(N+M) | O(1) |



> [!NOTE]
> [Same Direction 核心概念]<br>
> 兩個指針同方向前進，各自掃描不同陣列或字串（0392、1768、2540）。<br>
> 或一個指針掃描、另一個記錄「有效位置」（0228、0844）。<br>
> 0844 從**尾端**往前同向掃描，模擬退格後比對。<br>

> [!NOTE]
> [0392 Is Subsequence](./solution/Solution_0392.cpp)<br>
> 此題如果用 Dynamic Programming LCS，Complexity 會是 O(nm), O(nm)<br>
> 但如果用 Two Pointers 會是 O(n), O(1)<br>

<br><br>
---

## <a name="two-pointers-partition"></a>👥 Two Pointers - Partition (分割型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0075.cpp) | O(n) | O(1) |
| 0088 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0088.cpp) | O(M + N) | O(1) |
| 0922 | [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0922.cpp) | O(n) | O(1) |
| 2149 | [Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign) | 🟡 Medium | Array <br> Two Pointers <br> Simulation | [C++](./solution/Solution_2149.cpp) | O(N) | O(N) |

> [!NOTE]
> [Partition 核心概念]<br>
> 0075 Dutch National Flag：三指針 low / mid / high，一次掃描分成三區。<br>
> 0088 從尾端往前合併，避免覆蓋未讀資料，是 in-place merge 的標準技巧。<br>
> 0922 奇偶雙指針，odd 指針跳兩格，even 指針跳兩格，各自填位。<br>

> [!NOTE]
> [2149. Rearrange Array Elements by Sign](./solution/Solution_2149.cpp)<br>
> 此題要求將正數與負數交替排列，同時**維持各自原本的相對順序**，所以**空間複雜度無法 O(1)**<br>
> 目前解法已是最優：時間 O(N)、空間 O(N)<br>

<br><br>
---

## <a name="two-pointers-other"></a>👥 Two Pointers - Other (變形型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0160 | [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists) | 🟢 Easy | Linked List <br> Two Pointers | [C++](./solution/Solution_0160.cpp) | O(n+m) | O(1) |
| 0442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array) | 🟡 Medium | Array <br> Two Pointers | [C++](./solution/Solution_0442.cpp) | O(n) | O(1) |
| 0557 | [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0557.cpp) | O(n) | O(1) |
| 2441 | [Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative) | 🟢 Easy | Hash Table <br> Two Pointers <br> Sorting | [C++](./solution/Solution_2441_1.cpp) | O(n) | O(n) |

> [!NOTE]
> [Other 各題特色]<br>
> 0160 等長走法：兩指針分別走完各自鏈表後換到對方頭部，相遇點即交叉點。<br>
> 0442 負號標記：用 index 當作 hash key，對應位置取負號來記錄「出現過」。<br>
> 0557 區段內反轉：先找到每個單字的邊界，再對撞交換字元。<br>
> 2441 排序後對撞：先排序，left 從頭找正數，right 從尾找對應負數。<br>

<br><br>
---

## <a name="hash-table-counting"></a>🔑 Hash Table - Counting (頻率統計)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1207 | [Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_1207.cpp) | O(N) | O(N) |
| 1394 | [Find Lucky Integer in an Array](https://leetcode.com/problems/find-lucky-integer-in-an-array) | 🟢 Easy | Array <br> Hash Table <br> Counting | [C++](./solution/Solution_1394.cpp) | O(N) | O(1) |
| 1512 | [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs) | 🟢 Easy | Array <br> Hash Table <br> Math | [C++](./solution/Solution_1512.cpp) | O(N) | O(N) |
| 1748 | [Sum of Unique Elements](https://leetcode.com/problems/sum-of-unique-elements) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_1748.cpp) | O(N) | O(N) |
| 1941 | [Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences) | 🟢 Easy | Hash Table <br> String <br> Counting | [C++](./solution/Solution_1941.cpp) | O(n) | O(1) |
| 2001 | [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles) | 🟡 Medium | Hash Table <br> Math | [C++](./solution/Solution_2001.cpp) | O(N) | O(N) |
| 2150 | [Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array) | 🟡 Medium | Hash Table <br> Counting | [C++](./solution/Solution_2150.cpp) | O(n) | O(n) |
| 2206 | [Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs) | 🟢 Easy | Array <br> Hash Table <br> Counting | [C++](./solution/Solution_2206.cpp) | O(n) | O(1) |
| 2225 | [Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses) | 🟡 Medium | Hash Table <br> Counting <br> Sorting | [C++](./solution/Solution_2225.cpp) | O(nlogn) | O(n) |
| 2351 | [First Letter to Appear Twice](https://leetcode.com/problems/first-letter-to-appear-twice) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2351.cpp) | O(N) | O(1) |
| 2404 | [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_2404.cpp) | O(n) | O(n) |
| 3005 | [Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_3005.cpp) | O(n) | O(1) |

<br><br>
---

## <a name="hash-table-mapping"></a>🔑 Hash Table - Mapping (映射 / 異位詞 / 同構)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0001.cpp) | O(n) | O(n) |
| 0012 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman) | 🟡 Medium | Math <br> Hash Table <br> String | [C++](./solution/Solution_0012.cpp) | O(1) | O(1) |
| 0013 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer) | 🟢 Easy | Hash Table <br> Math <br> String | [C++](./solution/Solution_0013.cpp) | O(N) | O(1) |
| 0036 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku) | 🟡 Medium | Array <br> Hash Table <br> Bitset | [C++](./solution/Solution_0036.cpp) | O(1) | O(1) |
| 0202 | [Happy Number](https://leetcode.com/problems/happy-number) | 🟢 Easy | Hash Table <br> Fast-Slow Pointers | [C++](./solution/Solution_0202.cpp) | O(log n) | O(1) |
| 0205 | [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0205.cpp) | O(n) | O(1) |
| 0242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0242.cpp) | O(n) | O(1) |
| 0290 | [Word Pattern](https://leetcode.com/problems/word-pattern) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0291.cpp) | O(N + M) | O(N + M) |
| 0383 | [Ransom Note](https://leetcode.com/problems/ransom-note) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0383.cpp) | O(M + N) | O(1) |
| 0387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_0387.cpp) | O(n) | O(1) |
| 0454 | [4Sum II](https://leetcode.com/problems/4sum-ii) | 🟡 Medium | Hash Table | [C++](./solution/Solution_0454.cpp) | O(n²) | O(n²) |
| 0884 | [Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0884.cpp) | O(N + M) | O(N + M) |
| 1002 | [Find Common Characters](https://leetcode.com/problems/find-common-characters) | 🟢 Easy | Array <br> Hash Table <br> String | [C++](./solution/Solution_1002.cpp) | O(N*K) | O(1) |
| 1436 | [Destination City](https://leetcode.com/problems/destination-city) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_1436.cpp) | O(N) | O(N) |
| 2133 | [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) | 🟢 Easy | Array <br> Hash Table <br> Bitset | [C++](./solution/Solution_2133.cpp) | O(n²) | O(n) |
| 2154 | [Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two) | 🟢 Easy | Array <br> Hash Table <br> Simulation | [C++](./solution/Solution_2154.cpp) | O(n) | O(n) |
| 2418 | [Sort the People](https://leetcode.com/problems/sort-the-people) | 🟢 Easy | Array <br> Sorting <br> Hash Table | [C++](./solution/Solution_2418.cpp) | O(NlogN) | O(N) |
| 2441 | [Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative) | 🟢 Easy | Hash Table <br> Two Pointers <br> Sorting | [C++](./solution/Solution_2441.cpp) | O(n) | O(n) |

> [!NOTE]
> [Two Sum](./solution/Solution_0001.cpp) 因為**尚未排序**過，所以 Complexity **O(n), O(n)**<br>
> [Two Sum II](./solution/Solution_0167.cpp) 因為**已排序**，所以 Complexity **O(n), O(1)**<br>

> [!NOTE]
> [2001 Number of Pairs of Interchangeable Rectangles](./solution/Solution_2001.cpp) 和 [1512. Number of Good Pairs](./solution/Solution_1512.cpp)<br>
> 同時用到了 Greedy Math Pattern，(1+n)/2<br>
> [2001 Number of Pairs of Interchangeable Rectangles](./solution/Solution_2001_1.cpp)同時也在考<br>
> **浮點數精度問題(Floating-point precision)-某些比例可能在運算中產生微小的誤差（例如1/3在某些計算環境下可能不完全相等）**<br>
> **導致原本應該視為相同的比例被誤判為不同。**<br>

<br><br>
---

## <a name="hash-table-set"></a>🔑 Hash Table - Set (集合 / 存在性判斷)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0217.cpp) | O(n) | O(n) |
| 0219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) | 🟢 Easy | Hash Table <br> Sliding Window | [C++](./solution/Solution_0219.cpp) | O(n) | O(min(n,k)) |
| 0349 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0349.cpp) | O(n+m) | O(n) |
| 0350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0350.cpp) | O(n+m) | O(min(n,m)) |
| 0705 | [Design HashSet](https://leetcode.com/problems/design-hashset) | 🟢 Easy | Hash Table / Design | [C++](./solution/Solution_0705.cpp) | O(1) | O(N) |
| 1346 | [Check If N and Its Double Exist](https://leetcode.com/problems/check-if-n-and-its-double-exist) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_1346.cpp) | O(n) | O(n) |
| 2215 | [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2215.cpp) | O(n+m) | O(n+m) |
| 2248 | [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2248.cpp) | O(n*m) | O(n) |
| 2784 | [Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good) | 🟢 Easy | Array <br> Hash Table <br> Sorting | [C++](./solution/Solution_2784.cpp) | O(n) | O(n) |

<br><br>
---

## <a name="linked-list-circular"></a>⛓️ Linked List - Circular / Cycle Management (環狀處理)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0061 | [Rotate List](https://leetcode.com/problems/rotate-list) | 🟡 Medium | Linked List <br>  Two Pointers | [C++](./solution/Solution_0061.cpp) | O(N) | O(1) |

<br><br>
---

## <a name="stack"></a>📚 Stack (堆疊)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 Easy | Stack | [C++](./solution/Solution_0020.cpp) | O(n) | O(n) |
| 0032 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses) | 🔴 Hard | String <br> Stack / DP | [C++](./solution/Solution_0032.cpp) | O(n) | O(n) |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 Easy | Tree / DFS / Stack | [C++](./solution/Solution_0094_1.cpp) | O(n) | O(h) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0144_1.cpp) | O(n) | O(h) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0145_1.cpp) | O(n) | O(h) |
| 0155 | [Min Stack](https://leetcode.com/problems/min-stack) | 🟡 Medium | Stack / Design | [C++](./solution/Solution_0155.cpp) | O(1) | O(N) |
| 0225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues) | 🟢 Easy | Stack <br> Queue | [C++](./solution/Solution_0225.cpp) | O(N) push <br> O(1) pop | O(N) |
| 0232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) | 🟢 Easy | Stack <br> Queue | [C++](./solution/Solution_0232.cpp) | O(1) amortized | O(N) |
| 0445 | [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii) | 🟡 Medium | Linked List / Stack | [C++](./solution/Solution_0445.cpp) | O(N + M) | O(N + M) |
| 0682 | [Baseball Game](https://leetcode.com/problems/baseball-game) | 🟢 Easy | Array <br> Stack <br> Simulation | [C++](./solution/Solution_0682.cpp) | O(N) | O(N) |
| 1047 | [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string) | 🟢 Easy | String <br> Stack | [C++](./solution/Solution_1047.cpp) | O(n) | O(n) |
| 1209 | [Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii) | 🟡 Medium | String <br> Stack | [C++](./solution/Solution_1209.cpp) | O(n) | O(n) |
| 1963 | [Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced) | 🟡 Medium | Stack <br> Greedy | [C++](./solution/Solution_1963.cpp) | O(N) | O(1) |
| 2390 | [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string) | 🟡 Medium | String <br> Stack | [C++](./solution/Solution_2390.cpp) | O(n) | O(n) |

<br><br>
---

## <a name="monotonic-stack"></a>📚 Monotonic Stack (堆疊)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0496 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) | 🟢 Easy | Array  <br> Hash Table  <br> Stack  <br> Monotonic Stack | [C++](./solution/Solution_0496.cpp) | O(N + M) | O(N) |
| 0503 | [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii) | 🟡 Medium | Array <br> Stack <br> Monotonic Stack | [C++](./solution/Solution_0503.cpp) | O(N) | O(N) |
| 0739 | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures) | 🟡 Medium | Stack / Monotonic Stack | [C++](./solution/Solution_0739.cpp) | O(N) | O(N) |
| 1475 | [Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop) | 🟢 Easy | Array <br> Stack <br> Monotonic Stack | [C++](./solution/Solution_1475.cpp) | O(N) | O(N) |

<br><br>
---

## <a name="tree"></a>🌳 Tree (樹結構)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0094.cpp) | O(n) | O(h) |
| 0100 | [Same Tree](https://leetcode.com/problems/same-tree/) | 🟢 Easy | Tree | [C++](./solution/Solution_0100.cpp) | O(n) | O(h) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0144.cpp) | O(n) | O(h) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0145.cpp) | O(n) | O(h) |
| 0226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | 🟢 Easy | Tree | [C++](./solution/Solution_0226.cpp) | O(n) | O(h) |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 Medium | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_0236.cpp) | O(n) | O(h) |
| 0589 | [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0589.cpp) | O(n) | O(h) |
| 0590 | [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0590.cpp) | O(n) | O(h) |
| 2331 | [Evaluate Boolean Binary Tree](https://leetcode.com/problems/evaluate-boolean-binary-tree) | 🟢 Easy | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_2331.cpp) | O(n) | O(h) |

<br><br>
---

## <a name="tree-bfs-level-order"></a>🌳 Tree - BFS / Level Order (層序遍歷)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0102.cpp) | O(n) | O(w) |
| 0107 | [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii) | 🟢 Easy | Tree / BFS | [C++](./solution/Solution_0107.cpp) | O(N) | O(W) |
| 0199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0199.cpp) | O(n) | O(w) |
| 0429 | [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0429.cpp) | O(N) | O(W) |
| 0513 | [Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value) | 🟡 Medium | Tree <br> BFS <br> DFS | [C++](./solution/Solution_0513.cpp) | O(n) | O(w) |
| 0637 | [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree) | 🟢 Easy | Tree <br> BFS | [C++](./solution/Solution_0637.cpp) | O(N) | O(W) |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0662.cpp) | O(n) | O(w) |
| 1161 | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_1161.cpp) | O(N) | O(W) |
| 1609 | [Even Odd Tree](https://leetcode.com/problems/even-odd-tree/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_1609.cpp) | O(n) | O(w) |

> [!NOTE]
> BFS Level Order 標準模板：用 queue，每層開始時記錄 `size = q.size()`，再跑 size 次。<br>
> 空間複雜度 O(w)，w 為最寬的一層節點數，最壞情況 O(n/2) = O(n)。<br>

> [!NOTE]
> [107. Binary Tree Level Order Traversal II](./solution/Solution_0107.cpp)只有比[102. Binary Tree Level Order Traversal](./solution/Solution_0102.cpp)<br>
> 多一行 Reverse 結果<br>


<br><br>
---

## <a name="tree-dfs-path"></a>🌳 Tree - DFS / Path (深度優先 / 路徑)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0101.cpp) | O(N) | O(H) |
| 0104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0104.cpp) | O(n) | O(h) |
| 0110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0110.cpp) | O(n) | O(h) |
| 0111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) | 🟢 Easy | Tree <br> BFS <br> DFS | [C++](./solution/Solution_0111.cpp) | O(n) | O(h) |
| 0112 | [Path Sum](https://leetcode.com/problems/path-sum/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0112.cpp) | O(n) | O(h) |
| 0113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii) | 🟡 Medium | Tree <br> DFS <br> Backtracking | [C++](./solution/Solution_0113.cpp) | O(N) | O(H) |
| 0124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | 🔴 Hard | Tree / Recursion / DP | [C++](./solution/Solution_0124.cpp) | O(N) | O(H) |
| 0129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) | 🟡 Medium | Tree <br> DFS | [C++](./solution/Solution_0129.cpp) | O(N) | O(H) |
| 0222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes) | 🟢 Easy | Tree <br> DFS <br> Binary Search | [C++](./solution/Solution_0222.cpp) | O(log²n) | O(log n) |
| 0257 | [Binary Tree Paths](https://leetcode.com/problems/binary-tree-path) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0257.cpp) | O(N²) | O(H²) |
| 0404 | [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0404.cpp) | O(N) | O(H) |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0543.cpp) | O(n) | O(h) |
| 0559 | [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree) | 🟢 Easy | Tree <br> DFS <br> BFS | [C++](./solution/Solution_0559.cpp) | O(N) | O(H) |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0572.cpp) | O(n*m) | O(h) |
| 0617 | [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees) | 🟢 Easy | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_0617.cpp) | O(min(N, M)) | O(min(N, M)) |
| 0872 | [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0872.cpp) | O(N+M) | O(N+M) |
| 0965 | [Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0965.cpp) | O(N) | O(H) |
| 1305 | [All Elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees) | 🟡 Medium | Tree <br> In-order Traversal <br> Two Pointers | [C++](./solution/Solution_1305.cpp) | O(N+M) | O(N+M) |

> [!NOTE]
> DFS 路徑題標準模板：後序（postorder）回傳子樹資訊給父節點，用於計算高度、直徑、路徑和。<br>
> 空間複雜度 O(h)，h 為樹高；平衡樹 O(log n)，最壞（歪斜樹）O(n)。<br>

<br><br>
---

## <a name="binary-search-tree"></a>🌳 Binary Search Tree (二元搜尋樹)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | 🟡 Medium | Tree <br> DFS <br> BST | [C++](./solution/Solution_0098.cpp) | O(n) | O(h) |
| 0108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) | 🟢 Easy | Tree <br> DFS <br> Binary Search | [C++](./solution/Solution_0108.cpp) | O(N) | O(log N) |
| 0230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst) | 🟡 Medium | Tree <br> DFS <br> BST | [C++](./solution/Solution_0230.cpp) | O(k) | O(h) |
| 0235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0235.cpp) | O(h) | O(h) |
| 0501 | [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0501.cpp) | O(n) | O(h) |
| 0530 | [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0530.cpp) | O(n) | O(h) |
| 0653 | [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst) | 🟢 Easy | Tree / Hash Table | [C++](./solution/Solution_0653.cpp) | O(N) | O(N) |
| 0700 | [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree) | 🟢 Easy | Tree <br> BST <br> Binary Search | [C++](./solution/Solution_0700.cpp) | O(H) | O(H) |
| 0701 | [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree) | 🟡 Medium | Tree <br> Binary Search Tree | [C++](./solution/Solution_0701.cpp) | O(H) | O(H) |
| 0783 | [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0783.cpp) | O(N) | O(H) |
| 0938 | [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0938.cpp) | O(N) | O(H) |

<br><br>
---

## <a name="Sorting"></a>📊 Sorting (排序)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0056 | [Merge Intervals](https://leetcode.com/problems/merge-intervals) | 🟡 Medium | Array / Sorting | [C++](./solution/Solution_0056.cpp) | O(NlogN) | O(logN) |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 Medium | Hash Table <br> QuickSelect | [C++](./solution/Solution_0347.cpp) | O(N) | O(N) |
| 0451 | [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency) | 🟡 Medium | Hash Table <br> Bucket Sort | [C++](./solution/Solution_0451.cpp) | O(N) | O(N) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 Medium | Array <br> Divide and Conquer <br> Sorting | [C++](./solution/Solution_0912.cpp) | O(nlogn) | O(logn) |
| 1356 | [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits) | 🟢 Easy | Bit Manipulation <br>  Sorting | [C++](./solution/Solution_1356.cpp) | O(N log N) | O(1) |
| 1859 | [Sorting the Sentence](https://leetcode.com/problems/sorting-the-sentence) | 🟢 Easy | String <br> Sorting <br> Bucket Sort | [C++](./solution/Solution_1859.cpp) | O(N) | O(N) |

> [!NOTE]
> Array or HashMap ?<br>
> 通常 Range 範圍在 幾百 例如 [1636 Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency)<br>
> 計數範圍-100 <= nums[i] <= 100<br>
> 會用Array, 因為是連續記憶體<br>
> 這是難得[doocs](https://github.com/doocs/leetcode/blob/main/solution/1600-1699/1636.Sort%20Array%20by%20Increasing%20Frequency/README_EN.md)優於[neetcode.io](https://neetcode.io/solutions/sort-array-by-increasing-frequency)<br>

<br><br>
---

## <a name="priority-queue"></a>📚 Priority Queue (優先佇列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0023 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists) | 🔴 Hard | Heap <br> Linked List | [C++](./solution/Solution_0023.cpp) | O(Nlogk) | O(k) |
| 0692 | [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words) | 🟡 Medium | Hash Table / Heap | [C++](./solution/Solution_0692.cpp) | O(NlogK) | O(N) |
| 0703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) | 🟢 Easy | Heap (Priority Queue) | [C++](./solution/Solution_0703.cpp) | O(N log K) / O(log K) | O(K) |
| 1046 | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight) | 🟢 Easy | Heap (Priority Queue) | [C++](./solution/Solution_1046.cpp) | O(NlogN) | O(N) |

> [!NOTE]
> [692. [Top K Frequent Words](./solution/Solution_0692.cpp)<br>
> 在 N=500時，NlogN與NlogK的差異微乎其微（甚至因為 CPU 快取命中率與常數項的緣故，std::sort 往往比 std::priority_queue 跑得更快）。<br>
> std::sort O(NlogN)：雖然時間複雜度看起來較高，但它在底層實作上非常平滑，且不需要額外的記憶體配置與大量的節點比較運算，在500個元素的規模下，這幾乎是瞬間完成。<br>
> std::priority_queue：O(NlogK)：雖然複雜度在K N時較佳，但它涉及大量的 push 與 pop 操作，以及頻繁的物件移動，這些都是額外的開銷。<br>


<br><br>
---

## <a name="quick-select"></a>📚 Quick Select(快速選擇)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 Medium | Array <br> Sorting <br> QuickSelect | [C++](./solution/Solution_0215.cpp) | O(N) 平均 | O(1) |
| 0973 | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin) | 🟡 Medium | Math <br> QuickSelect | [C++](./solution/Solution_0973.cpp) | O(N) | O(1) |
| 1636 | [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency) | 🟢 Easy | Array <br> Hash Table <br> Sorting | [C++](./solution/Solution_1636.cpp) | O(N log N) | O(1) |
| 1985 | [Find the Kth Largest Integer in the Array](https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array) | 🟡 Medium | Array <br> Sorting <br> String | [C++](./solution/Solution_1985.cpp) | O(N) | O(1) |
> [!NOTE]
> 手寫 QuickSelect, Average case O(n), **Worse case O(n²)**<br>
> std::nth_element, Average case O(n), Worse case O(n)<br>
> 靜態資料使用QuickSelect(std::nth_element),動態資料使用Min heap<br>

> [!NOTE]
> [1985. Find the Kth Largest Integer in the Array](./solution/Solution_1985.cpp)<br>
> 雖然 nth_element 是最佳解，但在極少數情境下會有變體：**如果K非常小** (例如 K=1 或 K=3)：你可以使用 **Min-Heap(優先佇列)** 維護一個大小為 K 的堆。<br>
> 雖然時間複雜度為 O(NlogK)，但在K遠小於N時，這能讓你不需要移動整個陣列的元素（如果是**串流數據或唯讀資料**，這會比修改原陣列更好）。<br>
> 如果資料是**唯讀且不能修改原陣列**，則不能使用 nth_element，因為它會改變陣列順序。<br>
> 這時候必須使用**std::priority_queue**複製一份資料進行計算，此時空間複雜度會提升到 O(K)。<br>
> 總結在 LeetCode 這一題的環境下，題目允許修**改 nums。輸入為整個陣列。目標是找第K大**。

<br><br>
---

## <a name="dynamic-programming"></a>🧩 Dynamic Programming (動態規劃)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 Medium | Array <br> Dynamic Programming | [C++](./solution/Solution_0053.cpp) | O(n) | O(1) |
| 0070 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0070.cpp) | O(n) | O(1) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 Medium | Dynamic Programming <br> Math | [C++](./solution/Solution_0096.cpp) | O(N^2) | O(N) |
| 0152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | 🟡 Medium | Dynamic Programming / Array | [C++](./solution/Solution_0152.cpp) | O(N) | O(1) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Array <br> Dynamic Programming | [C++](./solution/Solution_0300.cpp) | O(nlogn) | O(n) |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0509.cpp) | O(n) | O(1) | 
| 0583 | [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) | 🟡 Medium | Dynamic Programming | [C++](./solution/Solution_0583.cpp) | O(m*n) | O(m*n) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 Medium | Dynamic Programming | [C++](./solution/Solution_1143.cpp) | O(m*n) | O(m*n) |

<br><br>
---

## <a name="greedy"></a>🧩 Greedy (貪婪法)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0624 | [Maximum Distance in Arrays](https://leetcode.com/problems/maximum-distance-in-arrays) | 🟡 Medium | Array <br> Greedy | [C++](./solution/Solution_0624.cpp) | O(n) | O(1) |
| 0674 | [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence) | 🟢 Easy | Array <br> Greedy | [C++](./solution/Solution_0674.cpp) | O(n) | O(1) |

<br><br>
---

## <a name="backtracking"></a>🔢 Backtracking (回朔法)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0046 | [Permutations](https://leetcode.com/problems/permutations/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0046.cpp) | O(N * N!) | O(N) |
| 0047 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0047.cpp) | O(N * N!) | O(N) |
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 Medium | Backtracking / Recursion <br> Bit Manipulation | [C++](./solution/Solution_0078.cpp) | O(N * 2^N) | O(N) |

<br><br>
---

> [!NOTE]
## <a name="negative-marking"></a>🔢 Negative Marking 
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0041 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | 🔴 Hard | Math | [C++](./solution/Solution_0041.cpp) | O(n) | O(1) |
| 0442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array) | 🟡 Medium | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0442.cpp) | O(n) | O(1) |
| 0448 | [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array) | 🟢 Easy | Array | [C++](./solution/Solution_0448.cpp) | O(n) | O(1) |
| 0645 | [Set Mismatch](https://leetcode.com/problems/set-mismatch) | 🟢 Easy | Array / Hash Table / Math | [C++](./solution/Solution_0645.cpp) | O(N) | O(1) |

<br><br>
---

## <a name="fixed-size-sliding-window"></a>🔢Fixed Size Sliding Window
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) | 🟡 Medium | Sliding Window / Hash Table | [C++]
| 0643 | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i) | 🟢 Easy | Array <br> Sliding Window | [C++](./solution/Solution_0643.cpp) | O(N) | O(1) |
| 1456 | [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length) | 🟡 Medium | String <br> Sliding Window | [C++](./solution/Solution_1456.cpp) | O(N) | O(1) |
| 1876 | [Substrings of Size Three with Distinct Characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters) | 🟢 Easy | String <br> Sliding Window | [C++](./solution/Solution_1876.cpp) | O(N) | O(1) |

<br><br>
---

## <a name="variable-size-sliding-window"></a>🔢Variable Size Sliding Window
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum) | 🟡 Medium | Array <br> Sliding Window <br> Binary Search | [C++](./solution/Solution_0209.cpp) | O(N) | O(1) |
| 0424 | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement) | 🟡 Medium | Sliding Window / Hash Table | [C++](./solution/Solution_0424.cpp) | O(N) | O(1) |
| 1004 | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) | 🟡 Medium | Sliding Window | [C++](./solution/Solution_1004.cpp) | O(N) | O(1) |

<br><br>
---

© 2026 Laurence Chang.


© 2026 Laurence Chang. 保持思考，持續進化。
