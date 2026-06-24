# LeetCode 演算法精鍊筆記 (C++)

![LeetCode Stats](https://leetcard.jacoblin.cool/smartcsie?theme=nord) <!-- 註：將 laurence 換成你的 LeetCode ID -->

本倉庫用於記錄我的 LeetCode 解題過程、思路分析以及演算法優化心得。

---

## 🤖 Solutions
- [doocs(github)](https://github.com/doocs/leetcode/tree/main/solution)
- [walkccc(github)](https://github.com/walkccc/LeetCode/tree/main/solutions)
- [kamyu104(github)](https://github.com/kamyu104/LeetCode-Solutions)
- [花花醬](https://zxi.mytechroad.com/blog/leetcode-problem-categories/#google_vignette)
---
## 🤖 Algorithm(Leetcode)
- [thinkings (azl397985856)](https://github.com/azl397985856/leetcode/tree/master/thinkings)
- [fucking algoruthms(gavin0507)](https://github.com/gavin0507/fucking-algorithm/tree/master)
- [hello-algo](https://www.hello-algo.com/en/)
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
- **[Top Interview 150](https://leetcode.com/studyplan/top-interview-150/)**

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
[🔢 Math](#math) | [📊 Bit Manipulation](#Bit-manipulation) | [🔗 String](#string) | [🔑 Hash Table - Counting](#hash-table-counting) | [🔑 Hash Table - Mapping](#hash-table-mapping) | [🔑 Hash Table - Set](#hash-table-set)<br>

**Array**<br>
[🍱 Array](#array)  | 🍱 Array Boyer-Moore Voting Algorithm(陣列多數投票演算法) | [🍱 2D Array](#2d-array) |

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
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0007 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | 🟡 Medium | Math | [C++](./solution/Solution_0007.cpp) | O(logn) | O(1) | |
| 0009 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0009.cpp) | O(logn) | O(1) | |
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 Medium | Math <br> Binary Exponentiation | [C++](./solution/Solution_0050.cpp) | O(log N) | O(1) | |
| 0066 | [Plus One](https://leetcode.com/problems/plus-one/) | 🟢 Easy | Math | [C++](./solution/Solution_0066.cpp) | O(n) | O(1) | [Note](#0066-plus-one) |
| 0067 | [Add Binary](https://leetcode.com/problems/add-binary) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_0067.cpp) | O(max(M, N)) | O(1) | |
| 0137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Math <br> Hash Set | [C++](./solution/Solution_0137_1.cpp) | O(n) | O(n) | |
| 0172 | [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes) | 🟡 Medium | Math | [C++](./solution/Solution_0172.cpp) | O(log₅N) | O(1) | [Note](#0172-factorial-trailing-zeroes) |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | 🟢 Easy | Math | [C++](./solution/Solution_0231.cpp) | O(1) | O(1) | [Note](#0231-power-of-two) |
| 0258 | [Add Digits](https://leetcode.com/problems/add-digits) | 🟢 Easy | Math | [C++](./solution/Solution_0258.cpp) | O(1) | O(1) | [Note](#0258-add-digits) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 Easy | Math | [C++](./solution/Solution_0263.cpp) | O(logn) | O(1) | [Note](#0263-ugly-number) |
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0268.cpp) | O(n) | O(1) | |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three/) | 🟢 Easy | Math | [C++](./solution/Solution_0326.cpp) | O(log₃n) | O(1) | [Note](#0326-power-of-three) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four/) | 🟢 Easy | Math | [C++](./solution/Solution_0342.cpp) | O(1) | O(1) | [Note](#0342-power-of-four) |
| 0412 | [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/) | 🟢 Easy | Math / String | [C++](./solution/Solution_0412.cpp) | O(N) | O(1)* | |
| 0441 | [Arranging Coins](https://leetcode.com/problems/arranging-coins/) | 🟢 Easy | Math / Binary Search | [C++](./solution/Solution_0441.cpp) | O(logN) | O(1) |
| 0504 | [Base 7](https://leetcode.com/problems/base-7) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_0504.cpp) | O(log₇N) | O(1) | [Note](#0504-base-7) |
| 0507 | [Perfect Number](https://leetcode.com/problems/perfect-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0507.cpp) | O(√N) | O(1) | |
| 0633 | [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/) | 🟡 Medium | Math / Two Pointers | [C++](./solution/Solution_0633.cpp) | O(√c) | O(1) | |
| 0628 | [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_0628.cpp) | O(N) | O(1) | |
| 0970 | [Powerful Integers](https://leetcode.com/problems/powerful-integers/) | 🟡 Medium | Math / Hash Table | [C++](./solution/Solution_0970.cpp) | O(log_x(bound) * log_y(bound)) | O(S) | |
| 1017 | [Convert to Base -2](https://leetcode.com/problems/convert-to-base-2) | 🟡 Medium | Math | [C++](./solution/Solution_1017.cpp) | O(logN) | O(1) | [Note](#1017-convert-to-base-2) |
| 1295 | [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_1295.cpp) | O(N) | O(1) | [Note](#1295-find-numbers-with-even-number-of-digits) |
| 1492 | [The kth Factor of n](https://leetcode.com/problems/the-kth-factor-of-n/) | 🟢 Medium | Math | [C++](./solution/Solution_1492.cpp) | O(√N) | O(1) | 
| 1572 | [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum) | 🟢 Easy | Matrix | [C++](./solution/Solution_1572.cpp) | O(N) | O(1) | [Note](#1572-matrix-diagonal-sum) |
| 1822 | [Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_1822.cpp) | O(N) | O(1) | |
| 1837 | [Sum of Digits in Base K](https://leetcode.com/problems/sum-of-digits-in-base-k) | 🟢 Easy | Math | [C++](./solution/Solution_1837.cpp) | O(logₖN) | O(1) | |
| 1952 | [Three Divisors](https://leetcode.com/problems/three-divisors) | 🟢 Easy | Math | [C++](./solution/Solution_1952.cpp) | O(√N) | O(1) | [Note](#1952-three-divisors) |
| 1980 | [Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string) | 🟡 Medium | Math <br> String | [C++](./solution/Solution_1980.cpp) | O(N²) | O(N) | [Note](#1980-find-unique-binary-string) |
| 2119 | [A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal/) | 🟢 Easy | Math | [C++](./solution/Solution_2119.cpp) | O(1) | O(1) |[Note](#2119-three-divisors) |
| 2177 | [Find Three Consecutive Integers That Sum to a Given Number](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number) | 🟡 Medium | Math | [C++](./solution/Solution_2177.cpp) | O(1) | O(1) | |
| 2396 | [Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/) | 🟡 Medium | Math <br> Brainteaser | [C++](./solution/Solution_2396.cpp) | O(1) | O(1) | |
| 2413 | [Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple/) | 🟢 Easy | Math | [C++](./solution/Solution_2413.cpp) | O(1) | O(1) |
| 2443 | [Sum of Number and Its Reverse](https://leetcode.com/problems/sum-of-number-and-its-reverse/) | 🟡 Medium | Math / Simulation | [C++](./solution/Solution_2443.cpp) | O(NlogN) | O(1) |
| 2469 | [Convert the Temperature](https://leetcode.com/problems/convert-the-temperature/) | 🟢 Easy | Math | [C++](./solution/Solution_2469.cpp) | O(1) | O(1) | |
| 2485 | [Find the Pivot Integer](https://leetcode.com/problems/pivot-integer/) | 🟢 Easy | Math | [C++](./solution/Solution_2485.cpp) | O(1) | O(1) |   |
| 2553 | [Separate the Digits in an Array](https://leetcode.com/problems/separate-the-digits-in-an-array) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_2553.cpp) | O(n * log(max_val)) | O(n * log(max_val)) | |
| 2544 | [Alternating Digit Sum](https://leetcode.com/problems/alternating-digit-sum/) | 🟢 Easy | Math / Digit Manipulation | [C++](./solution/Solution_2544.cpp) | O(logN) | O(logN) |
| 2652 | [Sum Multiples](https://leetcode.com/problems/sum-multiples) | 🟢 Easy | Math | [C++](./solution/Solution_2652.cpp) | O(n) | O(1) | |
| 2761 | [Prime Pairs With Target Sum](https://leetcode.com/problems/prime-pairs-with-target-sum/) | 🟡 Medium | Math <br> Sieve | [C++](./solution/Solution_2761.cpp) | O(NloglogN) | O(N) |
| 3099 | [Harshad Number](https://leetcode.com/problems/harshad-number/) | 🟢 Easy | Math | [C++](./solution/Solution_3099.cpp) | O(logN) | O(1) |
| 3340 | [Check Balanced String](https://leetcode.com/problems/check-balanced-string/) | 🟢 Easy | String <br> Math | [C++](./solution/Solution_3340.cpp) | O(N) | O(1) | [Note](#3340-check-balanced-string) |
| 3370 | [Smallest Number With All Set Bits](https://leetcode.com/problems/smallest-number-with-all-set-bits/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3370.cpp) | O(logN) | O(1) |
| 3512 | [Minimum Operations to Make Array Sum Divisible by K](https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/) | 🟢 Easy | Math | [C++](./solution/Solution_3512.cpp) | O(N) | O(1) | [Note](#3512-minimum-operations-to-make-array-sum-divisible-by-k) |
| 3701 | [Compute Alternating Sum](https://leetcode.com/problems/compute-alternating-sum/) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_3701.cpp) | O(N) | O(1) |
| 3908 | [Valid Digit Number](https://leetcode.com/problems/valid-digit-number/) | 🟢 Easy | Math <br> Digit Manipulation | [C++](./solution/Solution_3908.cpp) | O(log N) | O(1) |
| 3945 | [Digit Frequency Score](https://leetcode.com/problems/digit-frequency-score/) | 🟢 Easy | Math | [C++](./solution/Solution_3945.cpp) | O(logN) | O(1) |
| 3959 | [Check Good Integer](https://leetcode.com/problems/check-good-integer/) | 🟢 Easy | Math / Digit Manipulation | [C++](./solution/Solution_3959.cpp) | O(log N) | O(1) | [Note](#3959-check-good-integer) |

### 0066. Plus One 
> [Plus One](https://leetcode.com/problems/plus-one/)<br>
> **從最後一個digit，digit[n-1]往digit[0]，如果小於9 +1 return，否則設成0 往下個loop，最後在front insert 1 <br>
---

### 0172 Factorial Trailing Zeroes
> [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes)<br>
> **勒讓德定理 (Legendre's Formula)<br>
---

### 0231 Power of Two
> [Power of Two](https://leetcode.com/problems/power-of-two/)<br>
> (n > 0) && (n & (n-1)) == 0 <br>
---

### 0258 Add Digits
> [Add Digits](https://leetcode.com/problems/add-digits)<br>
> (num - 1) % 9 + 1<br>
---

### 0263 Ugly Number
> Ugly Number](https://leetcode.com/problems/ugly-number)
> n如果可被2整除，n除以2，n如果可被3整除，n除以3，n如果可被5整除，n除以5，最後是否等於1<br>
---

### 0326 Power of Three
> [Power of Three](https://leetcode.com/problems/power-of-three/)<br>
> (n > 0) && static_cast<int>(pow(3, 19)) % n == 0<br>
---

### 0342 Power of Four
> [Power of Four](https://leetcode.com/problems/power-of-four/)<br>
> (n > 0) && (n & (n-1)) == 0 && (n & 0x55555555) != 0，Power of Two多加 **(n & 0x55555555) != 0**<br>
---

### 0504 Base 7
> [Base 7](https://leetcode.com/problems/base-7) <br>
> 先用bool紀錄正負號，因為有正負號，while(n != 0)，餘數mod 7，如果為負乘上-1，＋'0'轉char push_back到string尾端，最後reverse<br>
---

### 1017 Convert to Base -2
> [Convert to Base -2](https://leetcode.com/problems/convert-to-base-2)<br>
> while(n != 0) {    res = to_string(n & 1) + res;   n  = -(n>>1);}，不等於0是因為有正負<br>
---

### 1295 Find Numbers with Even Number of Digits
> [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits)
> static_cast<int>(log10(num) + 1) % 2 == 0<br>
---

### 1572 Matrix Diagonal Sum
> [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum)<br>
> 如果 i == (n-1-i) 則sum只加matrix[i][i] 否則sum加matrix[i][i]和matrix[i][n-1-i]，為了奇術矩陣去中重中間元素<br>
---

### 1952 Three Divisors
> 1952.[Three Divisors](https://leetcode.com/problems/three-divisors)<br>
> 一個整數若恰好有三個正因數，這個數字必然是一個「質數的平方」。<br>

---
### 1980 Find Unique Binary String
> [Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string)<br>
> **康托爾對角線證明 (Cantor's Diagonal Argument)**，第i個binary string的第i個character反轉，能產生不重覆的binary string<br>

---

### 2119 Three Divisors
> [A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal/) <br>
> 條件 **num == 0 || num % 10 != 0**。<br>

---


### 3340 Check Balanced String
> [Check Balanced String](https://leetcode.com/problems/check-balanced-string/)<br>
> 奇數index所有num之sum和偶數index所有num之sum要相等<br>

---
### 3512 Minimum Operations to Make Array Sum Divisible by K
> [Minimum Operations to Make Array Sum Divisible by K](https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/)<br>
> 全部加起來除以k取餘數，可以一邊加，一邊取餘數<br>

---
### 3959 Check Good Integer
> [Check Good Integer](https://leetcode.com/problems/check-good-integer/)<br>
> 全部加起來除以k取餘數，可以一邊加，一邊取餘數<br>
>

<br><br>
---



## <a name="math"></a>🔢 Math Combination(數學 組合)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths/) | 🟡 Medium | Math / Combinatorics / DP | [C++](./solution/Solution_0062.cpp) | O(min(m, n)) | O(1) |

<br><br>
---


## <a name="Bit-manipulation"></a>📊 Bit Manipulation (位元運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0029 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | 🟡 Medium | Bit Manipulation / Math | [C++](./solution/Solution_0029.cpp) | O(log²N) | O(1) |
| 0136 | [Single Number](https://leetcode.com/problems/single-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0136.cpp) | O(n) | O(1) |
| 0137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Bit-Manipulation | [C++](./solution/Solution_0137.cpp) | O(n) | O(1) |
| 0190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0190.cpp) | O(1) | O(1) | [Note](#0190-reverse-bits) |
| 0191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0191.cpp) | O(1) | O(1) | [Note](#0191-number-of-1-bits) |
| 0201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0201.cpp) | O(logn) | O(1) |
| 0260 | [Single Number III](https://leetcode.com/problems/single-number-iii) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0260.cpp) | O(n) | O(1) |
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0268_2.cpp) | O(n) | O(1) | [Note](#0268-missing-number) |
| 0338 | [Counting Bits](https://leetcode.com/problems/counting-bits) | 🟢 Easy | DP <br> Bit Manipulation | [C++](./solution/Solution_0338.cpp) | O(n) | O(n) |
| 0371 | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0371.cpp) | O(1) | O(1) |
| 0389 | [Find the Difference](https://leetcode.com/problems/find-the-difference/) | 🟢 Easy | Hash Table <br> Bit Manipulation | [C++](./solution/Solution_0389.cpp) | O(N) | O(1) | 
| 0461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0461.cpp) | O(k) | O(1) | [Note](#0461-hamming-distance) |
| 0476 | [Number Complement](https://leetcode.com/problems/number-complement) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0476.cpp) | O(log N) | O(1) | [Note](#0476-number-complement) | 
| 0693 | [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0693.cpp) | O(1) | O(1) 
| 1009 | [Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_1009.cpp) | O(log N) | O(1) | [Note](#1009-complement-of-base-10-integer)|
| 1684 | [Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings) | 🟢 Easy | Array <br> Hash Table <br> Bit Manipulation | [C++](./solution/Solution_1684.cpp) | O(N * M) | O(1) | [Note](#1684-count-the-number-of-consistent-strings) |
| 2220 | [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2220.cpp) | O(log(max(start, goal))) | O(1) |
| 2235 | [Add Two Integers](https://leetcode.com/problems/add-two-integers) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2235.cpp) | O(1) | O(1) |
| 2317 | [Maximum XOR After Operations](https://leetcode.com/problems/maximum-xor-after-operations) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_2317.cpp) | O(n) | O(1) |
| 2595 | [Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2595.cpp) | O(log N) | O(1) |
| 2716 | [Minimize String Length](https://leetcode.com/problems/minimize-string-length/) | 🟢 Easy | Hash Set <br> Bit Manipulation | [C++](./solution/Solution_2716.cpp) | O(N) | O(1) |
| 2917 | [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2917.cpp) | O(N * log(max_val)) | O(1) |
| 2980 | [Check if Bitwise OR Has Trailing Zeros](https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/) | 🟢 Easy | Bit Manipulation <br> Math | [C++](./solution/Solution_2980.cpp) | O(N) | O(1) |
| 3151 | [Special Array I](https://leetcode.com/problems/special-array-i) | 🟢 Easy | Array <br> Bit Manipulation | [C++](./solution/Solution_3151.cpp) | O(N) | O(1) |
| 3226 | [Number of Bit Changes to Make Two Integers Equal](https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3226.cpp) | O(1) | O(1) |
| 3950 | [Exactly One Consecutive Set Bits Pair](https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3950.cpp) | O(log N) | O(1) |

---

> 0029.[Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)<br>
> 此題是處理邊界的魔王題，這一題網路上掛一片，大部分偷用long long<br>
> 溢位處理有許多常見的解法，如 [meyr543](https://hackmd.io/@meyr543/rkSRWnXPK), [grandyang](https://www.cnblogs.com/grandyang/p/4741122.html),[doocs](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0260.Single%20Number%20III/Solution.cpp),[BylwiCXPt](https://hackmd.io/@Inversionpeter/BylwiCXPt)<br>
> 使用 'unsigned',`long long` 來處理 `INT_MIN` 的溢位，這在工程上屬於一種 **Workaround**<br>
---

### 0190 Reverse Bits
> [Reverse Bits](https://leetcode.com/problems/reverse-bits)<br>
> 記得 for(int i = 1; i <= 32; i++) <br>

---

### 0191 Number of 1 Bits
> 0191.[Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits)<br>
> 使用 **Brian Kernighan's Algorithm** ，**n = n & (n - 1)**，有 build in function可以用<br>
> **(1)** C++20，std::popcount(static_cast<unsigned int>(n)) 或  **(2)** 若編譯器(GCC/Clang)支援， __builtin_popcount(n) <br>
---

> 0260.[Single Number III](https://leetcode.com/problems/single-number-iii) 
>  是 Bit Manipulation 經典題目，目前只有**neetcode.io**有最佳解<br>

### 0268 Missing Number
> [Missing Number](https://leetcode.com/problems/missing-number) <br>
> for loop 從0 ~ (size - 1) ， missing ^= (i + 1) ^ nums[i]<br>

---

### 0461 Hamming Distance
> [Hamming Distance](https://leetcode.com/problems/hamming-distance)<br>
> x和y做互斥或成為z，取z的2進制1的個數<br>

---
### 0476 Number Complement
> [Number Complement](https://leetcode.com/problems/number-complement)<br>
> temp = num， while(temp > 0)，mask Or 1 一直左移動，最後mask ^ num<br>
> [476 Number Complement](./solution/Solution_0476.cpp)和[1009 Complement of Base 10 Integer](./solution/Solution_1009.cpp)<br>
> 本質上是相同的題目。<br>
---

### 1009 Complement of Base 10 Integer
> [Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer) <br>
> temp = n， while(temp > 0)，mask Or 1 一直左移動，最後mask ^ n，比476那一題多 **if(n == 0) return 1;** <br>

---

### 1684 Count the Number of Consistent Strings
> 1684. [Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings)<br>
> 先用一個int mask 紀錄哪些字元出現過(| 1 << c-'a')，檢查每個string的每個char(1 << c-'a')和msk &，為0則是沒有在字典中<br>
> 為什麼選擇 int mask 而非 bitset？
> int (或 long) 的運算直接對應 CPU 的暫存器指令，在這種極小範圍 (26 bits) 的情況下，它的運算速度幾乎是瞬間完成，且不需要引入額外的標頭檔 (<bitset>)，代碼更簡潔。<br>


<br><br>
---

## <a name="string"></a>🔗 String (字串)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0008 | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi) | 🟡 Medium | String <br> Math | [C++](./solution/Solution_0008.cpp) | O(N) | O(1) |
| 0014 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | String <br> Trie | [C++](./solution/Solution_0014.cpp) | O(S) | O(1) |
| 0028 | [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string) | 🟢 Easy | String <br> KMP | [C++](./solution/Solution_0028.cpp) | O(N * M) | O(1) |
| 0058 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word) | 🟢 Easy | String | [C++](./solution/Solution_0058.cpp) | O(n) | O(1) |
| 0151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_0151.cpp) | O(N) | O(N) |
| 0415 | [Add Strings](https://leetcode.com/problems/add-strings) | 🟢 Easy | String / Math | [C++](./solution/Solution_0415.cpp) | O(max(N, M)) | O(max(N, M)) |
| 0434 | [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string) | 🟢 Easy | String | [C++](./solution/Solution_0434.cpp) | O(N) | O(1) |
| 0459 | [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern) | 🟢 Easy | String <br> KMP | [C++](./solution/Solution_0459.cpp) | O(n) | O(n) |
| 0520 | [Detect Capital](https://leetcode.com/problems/detect-capital/) | 🟢 Easy | String | [C++](./solution/Solution_0520.cpp) | O(N) | O(1) |
| 0709 | [To Lower Case](https://leetcode.com/problems/to-lower-case) | 🟢 Easy | String | [C++](./solution/Solution_0709.cpp) | O(N) | O(1) |
| 0796 | [Rotate String](https://leetcode.com/problems/rotate-string) | 🟢 Easy | String | [C++](./solution/Solution_0796.cpp) | O(N) | O(N) |
| 0833 | [Find And Replace in String](https://leetcode.com/problems/find-and-replace-in-string/) | 🟡 Medium | String | [C++](./solution/Solution_833.cpp) | O(N+M*K) | O(N) |
| 0944 | [Delete Columns to Make Sorted](https://leetcode.com/problems/delete-columns-to-make-sorted/) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_0944.cpp) | O(N * M) | O(M) |
| 1528 | [Shuffle String](https://leetcode.com/problems/shuffle-string) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_1528.cpp) | O(N) | O(N) |
| 1668 | [Maximum Repeating Substring](https://leetcode.com/problems/maximum-repeating-substring/) | 🟢 Easy | String | [C++](./solution/Solution_1668.cpp) | O(N*M²) | O(M) |
| 1758 | [Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string) | 🟢 Easy | String | [C++](./solution/Solution_1758.cpp) | O(N) | O(1) |
| 1796 | [Second Largest Digit in a String](https://leetcode.com/problems/second-largest-digit-in-a-string/) | 🟢 Easy | String <br> Hash Table | [C++](./solution/Solution_1796.cpp) | O(N) | O(1) | 
| 1903 | [Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/) | 🟢 Easy | String | [C++](./solution/Solution_1903.cpp) | O(N) | O(1) |
| 2042 | [Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence) | 🟢 Easy | String <br> Parsing | [C++](./solution/Solution_2042.cpp) | O(n) | O(1) |
| 2114 | [Maximum Number of Words Found in Sentences](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_2114.cpp) | O(N * M) | O(1) |
| 2124 | [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs) | 🟢 Easy | String | [C++](./solution/Solution_2124.cpp) | O(N) | O(1) |
| 2264 | [Largest 3-Same-Digit Number in String](https://leetcode.com/problems/largest-3-same-digit-number-in-string) | 🟢 Easy | String | [C++](./solution/Solution_2264.cpp) | O(N) | O(1) |
| 2460 | [Apply Operations to an Array](https://leetcode.com/problems/apply-operations-to-an-array) | 🟢 Easy | Array <br> Simulation | [C++](./solution/Solution_2460.cpp) | O(N) | O(1) |
| 2490 | [Circular Sentence](https://leetcode.com/problems/circular-sentence) | 🟢 Easy | String | [C++](./solution/Solution_2490.cpp) | O(N) | O(1) |
| 2586 | [Count the Number of Vowel Strings in Range](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_2586.cpp) | O(n) | O(1) |
| 2678 | [Number of Senior Citizens](https://leetcode.com/problems/number-of-senior-citizens) | 🟢 Easy | String | [C++](./solution/Solution_2678.cpp) | O(n) | O(1) |
| 2828 | [Check if a String Is an Acronym of Words](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_2828.cpp) | O(n) | O(1) |
| 3083 | [Existence of a Substring in a String and Its Reverse](https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_3083.cpp) | O(N) | O(1) |
| 3110 | [Score of a String](https://leetcode.com/problems/score-of-a-string) | 🟢 Easy | String | [C++](./solution/Solution_3110.cpp) | O(N) | O(1) |
| 3498 | [Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_3498.cpp) | O(n) | O(1) |
| 3931 | [Check Adjacent Digit Differences](https://leetcode.com/problems/check-adjacent-digit-differences/) | 🟢 Easy | String <br> Math | [C++](./solution/Solution_3931.cpp) | O(N) | O(1) |

<br><br>
---

## <a name="array"></a>🍱 Array (陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0054 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | 🟡 Medium | Array / Simulation | [C++](./solution/Solution_0054.cpp) | O(M*N) | O(1) | 
| 0057 | [Insert Interval](https://leetcode.com/problems/insert-interval) | 🟡 Medium | Array <br> Interval | [C++](./solution/Solution_0057.cpp) | O(N) | O(N) |
| 0059 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | 🟡 Medium | Array / Simulation | [C++](./solution/Solution_0059.cpp) | O(N²) | O(1) |
| 0189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | 🟡 Medium | Array | [C++](./solution/Solution_0189.cpp) | O(n) | O(1) |
| 0414 | [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/) | 🟢 Easy | Array | [C++](./solution/Solution_414.cpp) | O(N) | O(1) |
| 0485 | [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones) | 🟢 Easy | Array | [C++](./solution/Solution_0485.cpp) | O(N) | O(1) |
| 0896 | [Monotonic Array](https://leetcode.com/problems/monotonic-array) | 🟢 Easy | Array | [C++](./solution/Solution_0896.cpp) | O(N) | O(1) |
| 1299 | [Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side) | 🟢 Easy | Array | [C++](./solution/Solution_1299.cpp) | O(N) | O(1) |
| 1389 | [Create Target Array in the Given Order](https://leetcode.com/problems/create-target-array-in-the-given-order/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_1389.cpp) | O(N²) | O(N) |
| 1431 | [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) | 🟢 Easy | Array | [C++](./solution/Solution_1431.cpp) | O(N) | O(1)* |
| 1470 | [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/) | 🟢 Easy | Array | [C++](./solution/Solution_1470.cpp) | O(N) | O(N) |
| 1662 | [Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_1662.cpp) | O(N+ M) | O(1) |
| 1752 | [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated) | 🟢 Easy | Array | [C++](./solution/Solution_1752.cpp) | O(N) | O(1) |
| 1800 | [Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum) | 🟢 Easy | Array | [C++](./solution/Solution_1800.cpp) | O(N) | O(1) |
| 1848 | [Minimum Distance to the Target Element](https://leetcode.com/problems/minimum-distance-to-the-target-element/) | 🟢 Easy | Array <br> Simulation | [C++](./solution/Solution_1848.cpp) | O(N) | O(1) |
| 1913 | [Maximum Product Difference Between Two Pairs](https://leetcode.com/problems/maximum-product-difference-between-two-pairs) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_1913.cpp) | O(N) | O(1) |
| 1929 | [Concatenation of Array](https://leetcode.com/problems/concatenation-of-array) | 🟢 Easy | Array | [C++](./solution/Solution_1929.cpp) | O(N) | O(1)* |
| 2089 | [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/) | 🟢 Easy | Array <br> Counting | [C++](./solution/Solution_2089.cpp) | O(N) | O(1) |
| 2148 | [Count Elements With Strictly Smaller and Greater Elements](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_2148.cpp) | O(N) | O(1) |
| 2239 | [Find Closest Number to Zero](https://leetcode.com/problems/find-closest-number-to-zero) | 🟢 Easy | Array | [C++](./solution/Solution_2239.cpp) | O(N) | O(1) |
| 3925 | [Concatenate Array With Reverse](https://example.com/problems/3925) | 🟢 Easy | Array <br> Simulation | [C++](./solution/Solution_3925.cpp) | O(N) | O(N) |

<br><br>
---

## <a name="array-boyer-moore"></a>🍱 Array Boyer-Moore Voting Algorithm(陣列多數投票演算法)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element/) | 🟢 Easy | Array <br> Voting Algorithm | [C++](./solution/Solution_0169.cpp) | O(N) | O(1) |
| 0229 | [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | 🟡 Medium | Array <br> Voting Algorithm | [C++](./solution/Solution_0229.cpp) | O(N) | O(1) |

<br><br>
---

## <a name="2d-array"></a>🍱 2D Array (二維陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0048 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | 🟡&nbsp;Medium | Array | [C++](./solution/Solution_0048.cpp) | O(n²) | O(1) | [Note](#0048-rotate-image) |
| 0073 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes) | 🟡 Medium | Array <br> Matrix | [C++](./solution/Solution_0073.cpp) | O(M*N) | O(1) | [Note](#0073-set-matrix-zeros) |
| 0867 | [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) | 🟢 Easy | Matrix | [C++](./solution/Solution_0867.cpp) | O(M*N) | O(M*N) |[Note](#0867-tranpose-matrix) |
| 1582 | [Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/) | 🟢 Easy | Array <br> Matrix | [C++](./solution/Solution_1582.cpp) | O(m * n) | O(m + n) |
| 1886 | [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/) | 🟢 Easy | Array | [C++](./solution/Solution_1886.cpp) | O(n²) | O(1) |[Note](#1886-determine-whether-matrix-can-be-obtained-by-rotation) |
| 2022 | [Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array) | 🟢 Easy | Array <br> Matrix <br> Simulation | [C++](./solution/Solution_2022.cpp) | O(m*n) | O(1) | [Note](#2022-convert-1d-array-into-2d-array) |

### 0048. Rotate Image
> [Rotate Image](https://leetcode.com/problems/rotate-image/)<br>
> 先求轉置矩陣，每個row再取reverse<br>
---

### 0073. Set Matrix Zeroes
> [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes)<br>
> 用兩個bool紀錄 col[0]和cow[0]是否有0，把每個row和col有0的紀錄在cow[0]和col[0]，之後set 0，最後set col[0]和cow[0]是<br>
---

### 0867. Transpose Matrix
> [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)<br>
> Size mxn, New 一個 Vector nxm<br>
---

### 1886. Determine Whether Matrix Can Be Obtained By Rotation
> [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)<br>
> 0048 Rotate Image的延伸，比對target matrix，rotate 比對4次<br>
---

### 2022. Convert 1D Array Into 2D Array
> [Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array)<br>
> 注意邊界條件 **if(m * n != original.size()) return {};** <br>


<br><br>
---



## <a name="binary-search"></a>🔍 Binary Search (二分查找)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0004 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | 🔴 Hard | Binary Search | [C++](./solution/Solution_0004.cpp) | O(log(m+n)) | O(1) |
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 Medium | Array <br> Binary Search | [C++](./solution/Solution_0033.cpp) | O(logN) | O(1) |
| 0069 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0069.cpp) | O(logn) | O(1) | [Note](#0069-sqrtx) |
| 0074 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) | 🟡 Medium | Binary Search <br> Matrix | [C++](./solution/Solution_0074.cpp) | O(log(MN)) | O(1) |[Note](#0074-search-a-2d-matrix) |
| 0081 | [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0081.cpp) | O(N) | O(1) |
| 0153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | 🟡&nbsp;Medium | Binary&nbsp;Search | [C++](./solution/Solution_0153.cpp) | O(logn) | O(1) |
| 0154 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii) | 🔴 Hard | Binary Search | [C++](./solution/Solution_0154.cpp) | O(N) | O(1) |
| 0162 | [Find Peak Element](https://leetcode.com/problems/find-peak-element) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0162.cpp) | O(logN) | O(1) | [Note](#0162-find-peak-element) |
| 0278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0278.cpp) | O(logn) | O(1) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Dynamic Programming <br> Binary Search | [C++](./solution/Solution_0300.cpp) | O(nlogn) | O(n) |
| 0367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0367.cpp) | O(logn) | O(1) | 
| 0374 | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0374.cpp) | O(logn) | O(1) |
| 0378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) | 🟡 Medium | Binary Search / Matrix | [C++](./solution/Solution_0378.cpp) | O(Nlog(max-min)) | O(1) |
| 0540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0540.cpp) | O(logN) | O(1) |
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0704.cpp) | O(logn) | O(1) | [Note](#0704-binary-search) |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0852.cpp) | O(logn) | O(1) | [Note](#0852-peak-index-in-a-mountain-array) |
| 1351 | [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) | 🟢 Easy | Array <br> Matrix <br> Binary Search | [C++](./solution/Solution_1351.cpp) | O(R + C) | O(1) |
| 2529 | [Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer) | 🟢 Easy | Binary Search | [C++](./solution/Solution_2529.cpp) | O(logN) | O(1) |
> [!NOTE]
> mid 取法<br>
> int mid = (left + right)/2; **本身有overflow的風險**<br>
> int mid = left + ((right - left) / 2); 本身比較安全<br>

### 0069. Sqrt(x)
> [Sqrt(x)](https://leetcode.com/problems/sqrtx/) <br>
> **尋找右側邊界**，最後 **return right**<br>

---
### 0074. Search a 2D Matrix
> [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) <br>
> **標準Binary Search**，把二維陣列index mapping到一維，right = m * n -1，matrix[mid /n][mid % n]<br>
---

### 0162. Find Peak Element
> [Find Peak Element](https://leetcode.com/problems/find-peak-element) <br>
> **尋找左側邊界**，用while (left < right)，同 0852 [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array)<br>

---
### 0704. Binary Search
> [Binary Search](https://leetcode.com/problems/binary-search/) <br>
> 標準Binary Search

---
### 0852. Peak Index in a Mountain Array
> [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) <br>
> **標準Binary Search** <br>
> **尋找左側邊界**，用while (left < right)，同 0162 [Find Peak Element](https://leetcode.com/problems/find-peak-element) <br>
> 
<br><br>
---

## <a name="binary-search-build-in"></a>🔍 Binary Search Build in Function (內建函數二分查找)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0034 | [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0034.cpp) | O(log N) | O(1) | [Note](#0034-find-first-and-last-position-of-element-in-sorted-array) |
| 0035 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0035.cpp) | O(logn) | O(1) |
| 0744 | [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0744.cpp) | O(logN) | O(1) |
| 1539 | [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number) | 🟢 Easy | Binary Search | [C++](./solution/Solution_1539.cpp) | O(log N) | O(1) |
| 2476 | [Closest Nodes Queries in a Binary Search Tree](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/) | 🟡 Medium | BST / Binary Search | [C++](./solution/Solution_2476.cpp) | O(N+QlogN) | O(N) |

### 0034. Find First and Last Position of Element in Sorted Array
> [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) <br>
> 用 lower_bound 和 upper_bound，最後回傳 {static_cast<int>(lower - nums.begin()), static_cast<int>(upper - nums.begin() - 1)} <br>

<br><br>
---

## <a name="prefix-sum"></a>🔍 Prefix Sum (前綴和)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | 🟡 Medium | Array <br> Prefix Sum | [C++](./solution/Solution_0238.cpp) | O(N) | O(1) |
| 0303 | [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_0303.cpp) | O(N) | O(N) |
| 0304 | [Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable) | 🟡 Medium | Array <br> Matrix <br> Prefix Sum | [C++](./solution/Solution_0304.cpp) | O(M * N) 初始化 / O(1) 查詢 | O(M * N) |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) | 🟡 Medium | Array <br> Hash Table <br> Prefix Sum | [C++](./solution/Solution_0560.cpp) | O(N) | O(N) |
| 0724 | [Find Pivot Index](https://leetcode.com/problems/find-pivot-index) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_0724.cpp) | O(N) | O(1) |
| 930 | [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/) | 🟡 Medium | Array <br> Prefix Sum | [C++](./solution/Solution_930.cpp) | O(N) | O(N) |
| 1480 | [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_1480.cpp) | O(N) | O(1) |
| 1685 | [Sum of Absolute Differences in a Sorted Array](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/) | 🟡 Medium | Array <br> Prefix Sum <br> Math | [C++](./solution/Solution_1685.cpp) | O(N) | O(N) |
| 2559 | [Count Vowel Strings in Ranges](https://leetcode.com/problems/count-vowel-strings-in-ranges) | 🟡 Medium | Array <br> Prefix Sum | [C++](./solution/Solution_2559.cpp) | O(N + Q) | O(N) |
| 2574 | [Left and Right Sum Differences](https://leetcode.com/problems/left-and-right-sum-differences/) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_2574.cpp) | O(N) | O(N) | 

<br><br>
---

## <a name="linked-list"></a>⛓️ Linked List (鏈表)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0002 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) | 🟡 Medium | Linked List <br> Math | [C++](./solution/Solution_0002.cpp) | O(max(N, M)) | O(max(N, M)) |
| 0021 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | 🟢 Easy | Linked List | [C++](./solution/Solution_0021.cpp) | O(n+m) | O(1) |
| 0024 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs) | 🟡 Medium | Linked List <br> Recursion | [C++](./solution/Solution_0024.cpp) | O(N) | O(N) |
| 0025 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) | 🔴 Hard | Linked List | [C++](./solution/Solution_0025.cpp) | O(N) | O(1) |
| 0082 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii) | 🟡 Medium | Linked List <br> Two Pointers | [C++](./solution/Solution_0082.cpp) | O(n) | O(1) |
| 0083 | [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0083.cpp) | O(n) | O(1) |
| 0092 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii) | 🟡 Medium | Linked List | [C++](./solution/Solution_0092.cpp) | O(N) | O(1) |
| 0143 | [Reorder List](https://leetcode.com/problems/reorder-list/) | 🟡 Medium | Linked List | [C++](./solution/Solution_0143.cpp) | O(N) | O(1) |
| 0203 | [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements) | 🟢 Easy | Linked List | [C++](./solution/Solution_0203.cpp) | O(N) | O(1) |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0206.cpp) | O(n) | O(1) | 
| 0234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) | 🟢 Easy | Linked List <br> Two Pointers <br> Vector | [C++](./solution/Solution_0234.cpp) | O(n) | O(n) |
| 0237 | [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0237.cpp) | O(1) | O(1) |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 Easy | Linked List <br> Two Pointers <br> Fast-Slow Pointers | [C++](./solution/Solution_0876.cpp) | O(n) | O(1) |

<br><br>
---


## <a name="linked-list-circular"></a>⛓️ Linked List - Circular / Cycle Management (環狀處理)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0061 | [Rotate List](https://leetcode.com/problems/rotate-list) | 🟡 Medium | Linked List <br> Two Pointers | [C++](./solution/Solution_0061.cpp) | O(N) | O(1) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 Easy | Linked List <br> Fast-Slow Pointers| [C++](./solution/Solution_0141.cpp) | O(n) | O(1) |

<br><br>
---


## <a name="fast-slow-pointers"></a>👥 Fast-Slow Pointers (快慢指針)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0019 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list) | 🟡 Medium | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0019.cpp) | O(n) | O(1) |
| 0026 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | 🟢 Easy | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0026.cpp) | O(n) | O(1) |
| 0027 | [Remove Element](https://leetcode.com/problems/remove-element/) | 🟢 Easy | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0027.cpp) | O(n) | O(1) |
| 0080 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | 🟡 Medium | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0080.cpp) | O(n) | O(1) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 Easy | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0141.cpp) | O(n) | O(1) |
| 0142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | 🟡 Medium | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0142.cpp) | O(n) | O(1) |
| 0202 | [Happy Number](https://leetcode.com/problems/happy-number) | 🟢 Easy | Hash Table <br> Fast-Slow Pointers | [C++](./solution/Solution_0202.cpp) | O(logn) | O(1) |
| 0283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | 🟢 Easy | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0283.cpp) | O(n) | O(1) |
| 0287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | 🟡 Medium | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0287.cpp) | O(n) | O(1) |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 Easy | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_0876.cpp) | O(n) | O(1) |
| 2095 | [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list) | 🟡 Medium | Linked List <br> Fast-Slow Pointers | [C++](./solution/Solution_2095.cpp) | O(N) | O(1) |
| 2130 | [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) | 🟡 Medium | Linked List <br> Two Pointers | [C++](./solution/Solution_2130.cpp) | O(N) | O(1) |

> [!NOTE]
> **Floyd's Cycle Detection(龜兔賽跑)** 偵測環
> [0141. Linked List Cycle](./solution/Solution_0141.cpp)<br>
> [0142. Linked List Cycle II](./solution/Solution_0142.cpp)<br>
> [0202. Happy Number](./solution/Solution_0202.cpp)<br>
> [0287. Find the Duplicate Number](./solution/Solution_0287.cpp)<br>
> [!NOTE]
**Fast slow pointer找中間節點**
> [0109. Convert Sorted List to Binary Search Tree](./solution/Solution_0109.cpp)，分成左右兩個List，遞迴建立左右子樹<br>
> [0143. Reorder List](./solution/Solution_0143.cpp)，分成左右兩個List，slow->next是右邊的head，右邊的List Reverse，再合併<br>
> [0876. Middle of the Linked List](./solution/Solution_0876.cpp)，slow 就是 middle<br>
> [0148. Sort List](./solution/Solution_0148.cpp)，分成左右兩個List，做Merge Sort<br>

<br><br>
---

## <a name="two-pointers-opposite"></a>👥 Two Pointers - Opposite Direction (對撞型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | 🟡 Medium | Array <br> Two Pointers <br> Greedy | [C++](./solution/Solution_0011.cpp) | O(n) | O(1) |
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0015.cpp) | O(n²) | O(logn) |
| 0016 | [3Sum Closest](https://leetcode.com/problems/3sum-closest) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0016.cpp) | O(n²) | O(1) |
| 0018 | [4Sum](https://leetcode.com/problems/4sum/) | 🟡 Medium | Two Pointers / Sorting | [C++](./solution/Solution_0018.cpp) | O(N³) | O(1) |
| 0125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0125.cpp) | O(n) | O(1) |
| 0167 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) | 🟡 Medium | Array <br> Two Pointers | [C++](./solution/Solution_0167.cpp) | O(n) | O(1) |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0344.cpp) | O(n) | O(1) |
| 0345 | [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0345.cpp) | O(N) | O(1) |
| 0905 | [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0905.cpp) | O(n) | O(1) |
| 0917 | [Reverse Only Letters](https://leetcode.com/problems/reverse-only-letters/) | 🟢 Easy | Two Pointers / String | [C++](./solution/Solution_0917.cpp) | O(N) | O(1) |
| 0941 | [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0941.cpp) | O(n) | O(1) |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0977.cpp) | O(n) | O(n) |
| 1750 | [Minimum Length of String After Deleting Similar Ends](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_1750.cpp) | O(N) | O(1) |
| 2000 | [Reverse Prefix of Word](https://leetcode.com/problems/reverse-prefix-of-word/) | 🟢 Easy | Two Pointers / String | [C++](./solution/Solution_2000.cpp) | O(N) | O(1) |
| 3794 | [Reverse String Prefix](https://leetcode.com/problems/reverse-string-prefix/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_3794.cpp) | O(N) | O(1) |

> [!NOTE]
> [Opposite Direction 核心概念]<br>
> left 從頭、right 從尾，條件不符時移動較劣的那側。<br>
> 通常需要**排序**作為前提（0015、0016、0167、0977）。<br>
> 回文判斷（0125、0344、0345）：左右同時往中間收斂，不符合就提早返回。<br>

<br><br>
---

## <a name="two-pointers-same"></a>👥 Two Pointers - Same Direction (同向型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0031 | [Next Permutation](https://leetcode.com/problems/next-permutation/) | 🟡 Medium | Array / Two Pointers | [C++](./solution/Solution_0031.cpp) | O(N) | O(1) |
| 0086 | [Partition List](https://leetcode.com/problems/partition-list/) | 🟡 Medium | Linked List / Two Pointers | [C++](./solution/Solution_0086.cpp) | O(N) | O(1) |
| 0228 | [Summary Ranges](https://leetcode.com/problems/summary-ranges) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0228.cpp) | O(N) | O(1) |
| 0328 | [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) | 🟡 Medium | Linked List | [C++](./solution/Solution_0328.cpp) | O(N) | O(1) |
| 0392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0392.cpp) | O(n) | O(1) |
| 0443 | [String Compression](https://leetcode.com/problems/string-compression/) | 🟡 Medium | Two Pointers | [C++](./solution/Solution_0443.cpp) | O(N) | O(1) |
| 0541 | [Reverse String II](https://leetcode.com/problems/reverse-string-ii/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_0541.cpp) | O(N) | O(1) |
| 0844 | [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0844.cpp) | O(N+M) | O(1) |
| 1089 | [Duplicate Zeros](https://leetcode.com/problems/duplicate-zeros) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_1089.cpp) | O(N) | O(1) |
| 1721 | [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list) | 🟡 Medium | Linked List <br> Two Pointers | [C++](./solution/Solution_1721.cpp) | O(N) | O(1) |
| 1768 | [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_1768.cpp) | O(N+M) | O(1) |
| 2109 | [Adding Spaces to a String](https://leetcode.com/problems/adding-spaces-to-a-string) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_2109.cpp) | O(N+M) | O(N+M) |
| 2540 | [Minimum Common Value](https://leetcode.com/problems/minimum-common-value) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_2540.cpp) | O(N+M) | O(1) |
| 3940 | [Limit Occurrences in Sorted Array](https://leetcode.com/problems/limit-occurrences-in-sorted-array/) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_3940.cpp) | O(N) | O(1) |


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
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
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

## <a name="two-pointers-center-expansion"></a>👥 Two Pointers - Center Expansion (中心擴展型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) | 🟡 Medium | DP / String | [C++](./solution/Solution_0647.cpp) | O(N²) | O(N) | 

<br><br>
---

## <a name="two-pointers-other"></a>👥 Two Pointers - Other (變形型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
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
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0049 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | 🟡 Medium | Hash Table / String | [C++](./solution/Solution_0049.cpp) | O(N*K) | O(N*K) | 
| 0771 | [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/) | 🟢 Easy | Hash Set <br> String | [C++](./solution/Solution_0771.cpp) | O(J + S) | O(J) |
| 1207 | [Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_1207.cpp) | O(N) | O(N) |
| 1394 | [Find Lucky Integer in an Array](https://leetcode.com/problems/find-lucky-integer-in-an-array) | 🟢 Easy | Array <br> Hash Table <br> Counting | [C++](./solution/Solution_1394.cpp) | O(N) | O(1) |
| 1460 | [Make Two Arrays Equal by Reversing Subarrays](https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/) | 🟢 Easy | Array / Hash Table | [C++](./solution/Solution_1460.cpp) | O(N) | O(K) |
| 1512 | [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs) | 🟢 Easy | Array <br> Hash Table <br> Math | [C++](./solution/Solution_1512.cpp) | O(N) | O(N) |
| 1748 | [Sum of Unique Elements](https://leetcode.com/problems/sum-of-unique-elements) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_1748.cpp) | O(N) | O(N) |
| 1941 | [Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences) | 🟢 Easy | Hash Table <br> String <br> Counting | [C++](./solution/Solution_1941.cpp) | O(n) | O(1) |
| 2001 | [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles) | 🟡 Medium | Hash Table <br> Math | [C++](./solution/Solution_2001.cpp) | O(N) | O(N) |
| 2053 | [Kth Distinct String in an Array](https://leetcode.com/problems/kth-distinct-string-in-an-array/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2053.cpp) | O(N) | O(N) |
| 2094 | [Finding 3-Digit Even Numbers](https://leetcode.com/problems/finding-3-digit-even-numbers/) | 🟢 Easy | Hash Table <br> Math | [C++](./solution/Solution_2094.cpp) | O(N) | O(1) |
| 2150 | [Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array) | 🟡 Medium | Hash Table <br> Counting | [C++](./solution/Solution_2150.cpp) | O(n) | O(n) | [Note](#2150-find-all-lonely-numbers-in-the-array) |
| 2206 | [Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs) | 🟢 Easy | Array <br> Hash Table <br> Counting | [C++](./solution/Solution_2206.cpp) | O(n) | O(1) |
| 2225 | [Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses) | 🟡 Medium | Hash Table <br> Counting <br> Sorting | [C++](./solution/Solution_2225.cpp) | O(nlogn) | O(n) |
| 2351 | [First Letter to Appear Twice](https://leetcode.com/problems/first-letter-to-appear-twice) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2351.cpp) | O(N) | O(1) |
| 2395 | [Find Subarrays With Equal Sum](https://leetcode.com/problems/find-subarrays-with-equal-sum/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2395.cpp) | O(N) | O(N) | [Note](#2395-find-subarrays-with-equal-sum) |
| 2404 | [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_2404.cpp) | O(n) | O(n) |
| 3005 | [Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_3005.cpp) | O(n) | O(1) |
| 3541 | [Find Most Frequent Vowel and Consonant](https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/) | 🟢 Easy | Hash Table <br> Frequency Counting | [C++](./solution/Solution_3541.cpp) | O(N) | O(1) |
| 3591 | [Check if Any Element Has Prime Frequency](https://leetcode.com/problems/check-if-any-element-has-prime-frequency/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_3591.cpp) | O(N + Kloglog K) | O(K) |
| 3663 | [Find The Least Frequent Digit](https://leetcode.com/problems/find-the-least-frequent-digit/) | 🟢 Easy | Hash Table <br> Frequency Counting | [C++](./solution/Solution_3663.cpp) | O(log N) | O(1) |
| 3866 | [First Unique Even Element](https://leetcode.com/problems/first-unique-even-element/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_3866.cpp) | O(N) | O(1) | [Note](#3866-first-unique-even-element) |

### 2150. Find All Lonely Numbers in the Array
> [Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array)<br>
> 用unordered map紀錄數字頻率，travsal unordered map，如果 num - 1和 num + 1都不在unordered map，且num頻率等於1，則加入result vector<br>
---


### 2395. Find Subarrays With Equal Sum
> [Find Subarrays With Equal Sum](https://leetcode.com/problems/find-subarrays-with-equal-sum/) <br>
> 從 index 1 開始，左右兩數的sum，unordered map存在，回傳false，不存在，則存入unordered map<br>
---

### 3866. First Unique Even Element
> [First Unique Even Element](https://leetcode.com/problems/first-unique-even-element/) <br>
> 因為數字介於0~100，new一個size 101的vector，尋訪nums一輪，統計偶數頻率，再尋訪nums一輪，return 頻率為1的num<br>
---


<br><br>
---

## <a name="hash-table-mapping"></a>🔑 Hash Table - Mapping (映射 / 異位詞 / 同構)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0001.cpp) | O(n) | O(n) |
| 0012 | [Integer to Roman](https://leetcode.com/problems/integer-to-roman) | 🟡 Medium | Math <br> Hash Table <br> String | [C++](./solution/Solution_0012.cpp) | O(1) | O(1) |
| 0013 | [Roman to Integer](https://leetcode.com/problems/roman-to-integer) | 🟢 Easy | Hash Table <br> Math <br> String | [C++](./solution/Solution_0013.cpp) | O(N) | O(1) |
| 0036 | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku) | 🟡 Medium | Array <br> Hash Table <br> Bitset | [C++](./solution/Solution_0036.cpp) | O(1) | O(1) |
| 0128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | 🟡 Medium | Array <br> Hash Table | [C++](./solution/Solution_0128.cpp) | O(N) | O(N) |
| 0202 | [Happy Number](https://leetcode.com/problems/happy-number) | 🟢 Easy | Hash Table <br> Fast-Slow Pointers | [C++](./solution/Solution_0202.cpp) | O(logn) | O(1) |
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
| 3678 | [Smallest Absent Positive Greater Than Average](https://leetcode.com/problems/smallest-absent-positive-greater-than-average/) | 🟢 Easy | Array <br> Hash Set | [C++](./solution/Solution_3678.cpp) | O(N) | O(N) |

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
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0217.cpp) | O(n) | O(n) |
| 0219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) | 🟢 Easy | Hash Table <br> Sliding Window | [C++](./solution/Solution_0219.cpp) | O(n) | O(min(n,k)) |
| 0349 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0349.cpp) | O(n+m) | O(n) |
| 0350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0350.cpp) | O(n+m) | O(min(n,m)) |
| 0705 | [Design HashSet](https://leetcode.com/problems/design-hashset) | 🟢 Easy | Hash Table / Design | [C++](./solution/Solution_0705.cpp) | O(1) | O(N) |
| 0939 | [Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/) | 🟡 Medium | Array / Hash Table | [C++](./solution/Solution_939.cpp) | O(N²) | O(N) |
| 1346 | [Check If N and Its Double Exist](https://leetcode.com/problems/check-if-n-and-its-double-exist) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_1346.cpp) | O(n) | O(n) |
| 2215 | [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2215.cpp) | O(n+m) | O(n+m) |
| 2248 | [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2248.cpp) | O(n*m) | O(n) |
| 2784 | [Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good) | 🟢 Easy | Array <br> Hash Table <br> Sorting | [C++](./solution/Solution_2784.cpp) | O(n) | O(n) |
| 3718 | [Smallest Missing Multiple of K](https://leetcode.com/problems/smallest-missing-multiple-of-k/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_3718.cpp) | O(N+M) | O(M) |
| 3731 | [Find Missing Elements](https://leetcode.com/problems/find-missing-elements/) | 🟢 Easy | Array / Hash Table | [C++](./solution/Solution_3731.cpp) | O(N+K) | O(K) |

<br><br>
---

## <a name="stack"></a>📚 Stack (堆疊)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 Easy | Stack | [C++](./solution/Solution_0020.cpp) | O(n) | O(n) |
| 0032 | [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses) | 🔴 Hard | String <br> Stack / DP | [C++](./solution/Solution_0032.cpp) | O(n) | O(n) |
| 0150 | [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | 🟡 Medium | Stack | [C++](./solution/Solution_0150.cpp) | O(N) | O(N) |
| 0155 | [Min Stack](https://leetcode.com/problems/min-stack) | 🟡 Medium | Stack / Design | [C++](./solution/Solution_0155.cpp) | O(1) | O(N) |
| 0225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues) | 🟢 Easy | Stack <br> Queue | [C++](./solution/Solution_0225.cpp) | O(N) push <br> O(1) pop | O(N) |
| 0232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) | 🟢 Easy | Stack <br> Queue | [C++](./solution/Solution_0232.cpp) | O(1) amortized | O(N) |
| 0316 | [Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/) | 🟡 Medium | Stack <br> Greedy <br> String | [C++](./solution/Solution_0316.cpp) | O(N) | O(1) |
| 0445 | [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii) | 🟡 Medium | Linked List <br> Stack | [C++](./solution/Solution_0445.cpp) | O(N + M) | O(N + M) |
| 0682 | [Baseball Game](https://leetcode.com/problems/baseball-game) | 🟢 Easy | Array <br> Stack <br> Simulation | [C++](./solution/Solution_0682.cpp) | O(N) | O(N) |
| 1047 | [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string) | 🟢 Easy | String <br> Stack | [C++](./solution/Solution_1047.cpp) | O(n) | O(n) |
| 1209 | [Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii) | 🟡 Medium | String <br> Stack | [C++](./solution/Solution_1209.cpp) | O(n) | O(n) |
| 1544 | [Make The String Great](https://leetcode.com/problems/make-the-string-great/) | 🟢 Easy | String <br> Stack | [C++](./solution/Solution_1544.cpp) | O(N) | O(N) |
| 1963 | [Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced) | 🟡 Medium | Stack <br> Greedy | [C++](./solution/Solution_1963.cpp) | O(N) | O(1) |
| 2130 | [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) | 🟡 Medium | Linked List <br> Stack | [C++](./solution/Solution_2130.cpp) | O(N) | O(N) |
| 2390 | [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string) | 🟡 Medium | String <br> Stack | [C++](./solution/Solution_2390.cpp) | O(n) | O(n) |
| 3174 | [Clear Digits](https://leetcode.com/problems/clear-digits/) | 🟢 Easy | String <br> Stack | [C++](./solution/Solution_3174.cpp) | O(N) | O(N) |
<br><br>
---

## <a name="monotonic-stack"></a>📚 Monotonic Stack (單調堆疊)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0496 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) | 🟢 Easy | Array  <br> Hash Table  <br> Stack  <br> Monotonic Stack | [C++](./solution/Solution_0496.cpp) | O(N + M) | O(N) |
| 0503 | [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii) | 🟡 Medium | Array <br> Stack <br> Monotonic Stack | [C++](./solution/Solution_0503.cpp) | O(N) | O(N) |
| 0739 | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures) | 🟡 Medium | Stack / Monotonic Stack | [C++](./solution/Solution_0739.cpp) | O(N) | O(N) |
| 1475 | [Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop) | 🟢 Easy | Array <br> Stack <br> Monotonic Stack | [C++](./solution/Solution_1475.cpp) | O(N) | O(N) |

<br><br>
---

## <a name="monotonic-queue"></a>📚 Monotonic Queue (單調柱列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) | 🔴 Hard | Monotonic Queue / Sliding Window | [C++](./solution/Solution_0239.cpp) | O(N) | O(K) |

<br><br>
---



## <a name="tree"></a>🌳 Tree (樹結構)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0094.cpp) | O(n) | O(h) | [Note](#0094-binary-tree-inorder-traversal) |
| 0100 | [Same Tree](https://leetcode.com/problems/same-tree/) | 🟢 Easy | Tree | [C++](./solution/Solution_0100.cpp) | O(n) | O(h) | [Note](#0100-same-tree) |
| 0105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | 🟡 Medium | Tree <br> Recursion | [C++](./solution/Solution_105.cpp) | O(N) | O(N) |
| 0106 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | 🟡 Medium | Tree <br> Recursion | [C++](./solution/Solution_106.cpp) | O(N) | O(N) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0144.cpp) | O(n) | O(h) | [Note](#0144-binary-tree-preorder-traversal) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0145.cpp) | O(n) | O(h) | [Note](#0145-binary-tree-postorder-traversal) |
| 0226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | 🟢 Easy | Tree | [C++](./solution/Solution_0226.cpp) | O(n) | O(h) | [Note](#0226-binary-invert-binary-tree) |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 Medium | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_0236.cpp) | O(n) | O(h) |
| 0589 | [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0589.cpp) | O(n) | O(h) |
| 0590 | [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0590.cpp) | O(n) | O(h) |
| 0889 | [Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) | 🟡 Medium | Tree <br> Recursion | [C++](./solution/Solution_889.cpp) | O(N) | O(N) |
| 2236 | [Root Equals Sum of Children](https://leetcode.com/problems/root-equals-sum-of-children/) | 🟢 Easy | Tree | [C++](./solution/Solution_2236.cpp) | O(1) | O(1) |
| 2331 | [Evaluate Boolean Binary Tree](https://leetcode.com/problems/evaluate-boolean-binary-tree) | 🟢 Easy | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_2331.cpp) | O(n) | O(h) |

### 0094 Binary Tree Inorder Traversal
> [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) <br>
> root為空則return，遞迴左子樹，把root->val加入到result vector，遞迴右子樹<br>
---

### 0100 Same Tree
> [Same Tree](https://leetcode.com/problems/same-tree/) <br>
> 如果p q 都為空，回傳true，只有p或只有或兩個val不相等，回傳false，最後return isSameTree(p左子樹和q左子樹) 且 isSameTree(p右子樹和q右子樹)<br>
---

### 0144 Binary Tree Preorder Traversal
> [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) <br>
root為空則return，把root->val加入到result vector，遞迴左子樹，遞迴右子樹<br>

---

### 0145 Binary Tree Postorder Traversal
> [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) <br>
root為空則return，遞迴左子樹，遞迴右子樹，把root->val加入到result vector<br>

---

### 0226 Binary Invert Binary Tree
> [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) <br>
root為空則return，swap左右子樹的node，invertTree遞迴左子樹，invertTree遞迴右子樹<br>

---


<br><br>
---

## <a name="tree-bfs-level-order"></a>🌳 Tree - BFS / Level Order (層序遍歷)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0102.cpp) | O(n) | O(w) |
| 0103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-zigzag-level-order-traversal/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0103.cpp) | O(N) | O(W) |
| 0107 | [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii) | 🟢 Easy | Tree / BFS | [C++](./solution/Solution_0107.cpp) | O(N) | O(W) |
| 0199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0199.cpp) | O(n) | O(w) |
| 0429 | [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0429.cpp) | O(N) | O(W) |
| 0513 | [Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value) | 🟡 Medium | Tree <br> BFS <br> DFS | [C++](./solution/Solution_0513.cpp) | O(n) | O(w) |
| 0515 | [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/) | 🟡 Medium | Tree / BFS | [C++](./solution/Solution_515.cpp) | O(N) | O(W) |
| 0637 | [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree) | 🟢 Easy | Tree <br> BFS | [C++](./solution/Solution_0637.cpp) | O(N) | O(W) |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_0662.cpp) | O(n) | O(w) |
| 0958 | [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) | 🟡 Medium | BFS <br> Level Order Traversal | [C++](./solution/Solution_0958.cpp) | O(N) | O(W) |
| 0993 | [Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/) | 🟢 Easy | Tree <br> BFS | [C++](./solution/Solution_993.cpp) | O(N) | O(W) |
| 1161 | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_1161.cpp) | O(N) | O(W) |
| 1302 | [Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_1302.cpp) | O(N) | O(W) |
| 1609 | [Even Odd Tree](https://leetcode.com/problems/even-odd-tree/) | 🟡 Medium | Tree <br> BFS | [C++](./solution/Solution_1609.cpp) | O(n) | O(w) |
| 2583 | [Kth Largest Sum in a Binary Tree](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/) | 🟡 Medium | Tree <br> BFS <br> Math | [C++](./solution/Solution_2583.cpp) | O(N) | O(N) | 


> [!NOTE]
> BFS Level Order 標準模板：用 queue，每層開始時記錄 `size = q.size()`，再跑 size 次。<br>
> 空間複雜度 O(w)，w 為最寬的一層節點數，最壞情況 O(n/2) = O(n)。<br>

> [!NOTE]
> [107. Binary Tree Level Order Traversal II](./solution/Solution_0107.cpp)只有比[102. Binary Tree Level Order Traversal](./solution/Solution_0102.cpp)<br>
> 多一行 Reverse 結果<br>


<br><br>
---

## <a name="tree-dfs-path"></a>🌳 Tree - DFS / Path (深度優先 / 路徑)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 Easy | Tree <br> DFS<br> Stack | [C++](./solution/Solution_0094_1.cpp) | O(n) | O(h) |
| 0101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0101.cpp) | O(N) | O(H) |
| 0104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0104.cpp) | O(n) | O(h) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0144_1.cpp) | O(n) | O(h) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0145_1.cpp) | O(n) | O(h) |
| 0110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0110.cpp) | O(n) | O(h) |
| 0111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) | 🟢 Easy | Tree <br> BFS <br> DFS | [C++](./solution/Solution_0111.cpp) | O(n) | O(h) |
| 0112 | [Path Sum](https://leetcode.com/problems/path-sum/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0112.cpp) | O(n) | O(h) |
| 0113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii) | 🟡 Medium | Tree <br> DFS <br> Backtracking | [C++](./solution/Solution_0113.cpp) | O(N) | O(H) |
| 0114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | 🟡 Medium | Tree <br> DFS | [C++](./solution/Solution_0114.cpp) | O(N) | O(H) |
| 0124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | 🔴 Hard | Tree <br> Recursion <br> DP | [C++](./solution/Solution_0124.cpp) | O(N) | O(H) |
| 0129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) | 🟡 Medium | Tree <br> DFS | [C++](./solution/Solution_0129.cpp) | O(N) | O(H) |
| 0173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | 🟡 Medium | Tree <br> Stack | [C++](./solution/Solution_0173.cpp) | O(1) avg | O(h) |
| 0222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes) | 🟢 Easy | Tree <br> DFS <br> Binary Search | [C++](./solution/Solution_0222.cpp) | O(log²n) | O(log n) |
| 0257 | [Binary Tree Paths](https://leetcode.com/problems/binary-tree-path) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0257.cpp) | O(N²) | O(H²) |
| 0404 | [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0404.cpp) | O(N) | O(H) |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0543.cpp) | O(n) | O(h) |
| 0559 | [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree) | 🟢 Easy | Tree <br> DFS <br> BFS | [C++](./solution/Solution_0559.cpp) | O(N) | O(H) |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0572.cpp) | O(n*m) | O(h) |
| 0606 | [Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0606.cpp) | O(N) | O(H) |
| 0617 | [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees) | 🟢 Easy | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_0617.cpp) | O(min(N, M)) | O(min(N, M)) |
| 0671 | [Second Minimum Node In a Binary Tree](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0671.cpp) | O(N) | O(H) |
| 0872 | [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0872.cpp) | O(N+M) | O(N+M) |
| 0965 | [Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0965.cpp) | O(N) | O(H) |
| 988 | [Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/) | 🟡 Medium | Tree <br> DFS | [C++](./solution/Solution_988.cpp) | O(N) | O(H) |
| 1305 | [All Elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees) | 🟡 Medium | Tree <br> In-order Traversal <br> Two Pointers | [C++](./solution/Solution_1305.cpp) | O(N+M) | O(N+M) |
| 2415 | [Reverse Odd Levels of Binary Tree](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/) | 🟡 Medium | Tree <br> DFS | [C++](./solution/Solution_2415.cpp) | O(N) | O(H) |

> [!NOTE]
> DFS 路徑題標準模板：後序（postorder）回傳子樹資訊給父節點，用於計算高度、直徑、路徑和。<br>
> 空間複雜度 O(h)，h 為樹高；平衡樹 O(log n)，最壞（歪斜樹）O(n)。<br>

<br><br>
---

## <a name="binary-search-tree"></a>🌳 Binary Search Tree (二元搜尋樹)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | 🟡 Medium | Tree <br> DFS <br> BST | [C++](./solution/Solution_0098.cpp) | O(n) | O(h) |
| 0099 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) | 🟡 Medium | BST <br> In-order Traversal | [C++](./solution/Solution_0099.cpp) | O(N) | O(1) |
| 0108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) | 🟢 Easy | Tree <br> DFS <br> Binary Search | [C++](./solution/Solution_0108.cpp) | O(N) | O(logN) |
| 0109 | [Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | 🟡 Medium | Linked List / Tree | [C++](./solution/Solution_0109.cpp) | O(N log N) | O(logN) |
| 0230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst) | 🟡 Medium | Tree <br> DFS <br> BST | [C++](./solution/Solution_0230.cpp) | O(k) | O(h) |
| 0235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0235.cpp) | O(h) | O(h) |
| 0501 | [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0501.cpp) | O(n) | O(h) |
| 0530 | [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0530.cpp) | O(n) | O(h) |
| 0538 | [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/) | 🟡 Medium | BST <br> Reverse In-order Traversal | [C++](./solution/Solution_0538.cpp) | O(N) | O(H) |
| 0653 | [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst) | 🟢 Easy | Tree / Hash Table | [C++](./solution/Solution_0653.cpp) | O(N) | O(N) |
| 0700 | [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree) | 🟢 Easy | Tree <br> BST <br> Binary Search | [C++](./solution/Solution_0700.cpp) | O(H) | O(H) |
| 0701 | [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree) | 🟡 Medium | Tree <br> Binary Search Tree | [C++](./solution/Solution_0701.cpp) | O(H) | O(H) 
| 0783 | [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0783.cpp) | O(N) | O(H) |
| 0938 | [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst) | 🟢 Easy | Tree <br> DFS <br> BST | [C++](./solution/Solution_0938.cpp) | O(N) | O(H) |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/) | 🟡 Medium | Tree <br> BST <br> DFS | [C++](./solution/Solution_1008.cpp) | O(N) | O(N) |
| 1038 | [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/) | 🟡 Medium | Tree / BST | [C++](./solution/Solution_1038.cpp) | O(N) | O(H) |
| 1382 | [Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/) | 🟡 Medium | Tree / BST | [C++](./solution/Solution_1382.cpp) | O(N) | O(N) |

> [!NOTE]
> [1382. Balance a Binary Search Tree](./solution/Solution_1382.cpp) 有解法是 Day-Stout-Warren algorith，Space Complexity可以到O(1)<br>

<br><br>
---

## <a name="dfs-bfs"></a>🌳 DFS、BFS (深度搜尋、廣度搜尋)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands/) | 🟡 Medium | DFS <br> BFS <br> Union-Find | [C++](./solution/Solution_0200.cpp) | O(M×N) | O(1)* |

<br><br>
---

## <a name="Sorting"></a>📊 Sorting (排序)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0056 | [Merge Intervals](https://leetcode.com/problems/merge-intervals) | 🟡 Medium | Array <br> Sorting | [C++](./solution/Solution_0056.cpp) | O(NlogN) | O(logN) |
| 0148 | [Sort List](https://leetcode.com/problems/sort-list/) | 🟡 Medium | Linked List <br> Merge Sort | [C++](./solution/Solution_0148.cpp) | O(NlogN) | O(logN) | |
| 0179 | [Largest Number](https://leetcode.com/problems/largest-number/) | 🟡 Medium | Sorting <br> String | [C++](./solution/Solution_0179.cpp) | O(NlogN*k) | O(N*k) |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 Medium | Hash Table <br> QuickSelect | [C++](./solution/Solution_0347.cpp) | O(N) | O(N) |
| 0539 | [Minimum Time Difference](https://leetcode.com/problems/minimum-time-difference/) | 🟡 Medium | Math <br> Sorting | [C++](./solution/Solution_539.cpp) | O(NlogN) | O(N) |
| 0524 | [Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/) | 🟠 Medium | Two Pointers / Sorting | [C++](./solution/Solution_0524.cpp) | O(D log D + D * M) | O(1) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 Medium | Array <br> Divide and Conquer <br> Sorting | [C++](./solution/Solution_0912.cpp) | O(nlogn) | O(logn) |
| 1200 | [Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_1200.cpp) | O(NlogN) | O(N) | 
| 1356 | [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits) | 🟢 Easy | Bit Manipulation <br>  Sorting | [C++](./solution/Solution_1356.cpp) | O(NlogN) | O(1) |
| 1408 | [String Matching in an Array](https://leetcode.com/problems/string-matching-in-an-array/) | 🟢 Easy | String <br> Sorting | [C++](./solution/Solution_1408.cpp) | O(N²*K) | O(N) |
| 2164 | [Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently/) | 🟢 Easy | Sorting | [C++](./solution/Solution_2164.cpp) | O(NlogN) | O(N) | 
| 2545 | [Sort the Students by Their Kth Score](https://leetcode.com/problems/sort-the-students-by-their-kth-score/) | 🟢 Medium | Array <br> Sorting | [C++](./solution/Solution_2545.cpp) | O(NlogN) | O(1) |

| 3769 | [Sort Integers by Binary Reflection](https://leetcode.com/problems/sort-integers-by-binary-reflection/) | 🟡 Medium | Bit Manipulation <br> Sorting | [C++](./solution/Solution_3769.cpp) | O(NlogN) | O(N) |
| 3913 | [Sort Vowels by Frequency](https://leetcode.com/problems/sort-vowels-by-frequency/) | 🟡 Medium | Sorting <br> Hash | [C++](./solution/Solution_3913.cpp) | O(NlogN) | O(N) | 
| 3684 | [Maximize Sum of At Most K Distinct Elements](https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/) | 🟢 Easy | Sorting <br> Set | [C++](./solution/Solution_3684.cpp) | O(N logN) | O(N) |

> [!NOTE]
> Array or HashMap ?<br>
> 通常 Range 範圍在 幾百 例如 [1636 Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency)<br>
> 計數範圍-100 <= nums[i] <= 100<br>
> 會用Array，因為是連續記憶體<br>
> 這是難得[doocs](https://github.com/doocs/leetcode/blob/main/solution/1600-1699/1636.Sort%20Array%20by%20Increasing%20Frequency/README_EN.md)優於[neetcode.io](https://neetcode.io/solutions/sort-array-by-increasing-frequency)<br>

> [!NOTE]
> [0148. Sort List](./solution/Solution_0148.cpp) [0004. Median of Two Sorted Arrays](./solution/Solution_0004.cpp)<br>
> 是一樣的核心概念，都是Two Way merge sort<br>
<br><br>
---

## <a name="Sorting"></a>📊 Sorting - Counting Sort , Radix Sort , Bucket Sort (排序)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0451 | [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency) | 🟡 Medium | Hash Table <br> Bucket Sort | [C++](./solution/Solution_0451.cpp) | O(N) | O(N) |
| 1051 | [Height Checker](https://leetcode.com/problems/height-checker/) | 🟢 Easy | Array / Counting Sort | [C++](./solution/Solution_1051.cpp) | O(N) | O(1) |
| 1122 | [Relative Sort Array](https://leetcode.com/problems/relative-sort-array/) | 🟢 Easy | Counting Sort | [C++](./solution/Solution_1122.cpp) | O(N + M) | O(1) |
| 1859 | [Sorting the Sentence](https://leetcode.com/problems/sorting-the-sentence) | 🟢 Easy | String <br> Sorting <br> Bucket Sort | [C++](./solution/Solution_1859.cpp) | O(N) | O(N) |
| 2785 | [Sort Vowels in a String](https://leetcode.com/problems/sort-vowels-in-a-string/) | 🟡 Medium | String <br> Counting Sort | [C++](./solution/Solution_2785.cpp) | O(N) | O(1) | 
| 3517 | [Smallest Palindromic Rearrangement I](https://leetcode.com/problems/smallest-palindromic-rearrangement-i/) | 🟡 Medium | Greedy <br> Counting Sort | [C++](./solution/Solution_3517.cpp) | O(N) | O(1) | 

<br><br>
---


## <a name="priority-queue"></a>📚 Priority Queue (優先佇列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0023 | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists) | 🔴 Hard | Heap <br> Linked List | [C++](./solution/Solution_0023.cpp) | O(Nlogk) | O(k) |
| 0373 | [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sum/) | 🟡 Medium | Heap <br> Greedy | [C++](./solution/Solution_0373.cpp) | O(KlogK) | O(K) |
| 0692 | [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words) | 🟡 Medium | Hash Table <br> Heap | [C++](./solution/Solution_0692.cpp) | O(NlogK) | O(N) |
| 0703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) | 🟢 Easy | Heap (Priority Queue) | [C++](./solution/Solution_0703.cpp) | O(NlogK) / O(log K) | O(K) |
| 1046 | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight) | 🟢 Easy | Heap (Priority Queue) | [C++](./solution/Solution_1046.cpp) | O(NlogN) | O(N) |

> [!NOTE]
> [692. [Top K Frequent Words](./solution/Solution_0692.cpp)<br>
> 在 N=500時，NlogN與NlogK的差異微乎其微（甚至因為 CPU 快取命中率與常數項的緣故，std::sort 往往比 std::priority_queue 跑得更快）。<br>
> std::sort O(NlogN)：雖然時間複雜度看起來較高，但它在底層實作上非常平滑，且不需要額外的記憶體配置與大量的節點比較運算，在500個元素的規模下，這幾乎是瞬間完成。<br>
> std::priority_queue：O(NlogK)：雖然複雜度在K N時較佳，但它涉及大量的 push 與 pop 操作，以及頻繁的物件移動，這些都是額外的開銷。<br>


<br><br>
---

## <a name="quick-select"></a>📚 Quick Select(快速選擇)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 Medium | Array <br> Sorting <br> QuickSelect | [C++](./solution/Solution_0215.cpp) | O(N) 平均 | O(1) |
| 0324 | [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) | 🟡 Medium | Sorting / Quickselect | [C++](./solution/Solution_0324.cpp) | O(N) | O(1) |
| 0973 | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin) | 🟡 Medium | Math <br> QuickSelect | [C++](./solution/Solution_0973.cpp) | O(N) | O(1) |
| 1636 | [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency) | 🟢 Easy | Array <br> Hash Table <br> Sorting | [C++](./solution/Solution_1636.cpp) | O(NlogN) | O(1) |
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
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0064 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | 🟡 Medium | DP | [C++](./solution/Solution_0064.cpp) | O(M*N) | O(1) |
| 0070 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0070.cpp) | O(n) | O(1) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 Medium | Dynamic Programming <br> Math | [C++](./solution/Solution_0096.cpp) | O(N²) | O(N) |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | 🟡 Medium | Dynamic Programming <br> Math | [C++](./solution/Solution_0264.cpp) | O(n) | O(n) |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0509.cpp) | O(n) | O(1) | 
| 1137 | [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | 🟢 Easy | DP <br> Math | [C++](./solution/Solution_1137.cpp) | O(N) | O(1) |
<br><br>
---


## <a name="dynamic-programming"></a>🧩 Dynamic Programming - House Robber (打家劫舍)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0198 | [House Robber](https://leetcode.com/problems/house-robber/) | 🟢 Medium | DP <br> Linear Optimization | [C++](./solution/Solution_0198.cpp) | O(N) | O(1) |
| 0213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | 🟡 Medium | DP | [C++](./solution/Solution_0213.cpp) | O(N) | O(1) |
| 0337 | [House Robber III](https://leetcode.com/problems/house-robber-iii/) | 🟡 Medium | Tree <br> DP | [C++](./solution/Solution_0337.cpp) | O(N) | O(H) |
<br><br>
---


## <a name="dynamic-programming"></a>🧩 Dynamic Programming - LCS (最長共同子序列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0072 | [Edit Distance](https://leetcode.com/problems/edit-distance/) | 🟡 Medium | DP <br> String | [C++](./solution/Solution_0072.cpp) | O(N * M) | O(N * M) |
| 0115 | [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) | 🔴 Hard | DP / String | [C++](./solution/Solution_0115.cpp) | O(S * T) | O(T) | 
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Array <br> Dynamic Programming | [C++](./solution/Solution_0300_1.cpp) | O(N²) | O(n) |
| 0392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | 🟢 Easy | DP / LCS | [C++](./solution/Solution_0392_1.cpp) | O(S * T) | O(S * T) |
| 0516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) | 🟡 Medium | DP / String | [C++](./solution/Solution_0516.cpp) | O(N²) | O(N) |
| 0583 | [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) | 🟡 Medium | Dynamic Programming | [C++](./solution/Solution_0583.cpp) | O(m*n) | O(m*n) |
| 0647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) | 🟡 Medium | DP / String | [C++](./solution/Solution_0647.cpp) | O(N²) | O(N²) | 
| 0674 | [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/) | 🟢 Easy | DP <br> Array | [C++](./solution/Solution_0674_1.cpp) | O(N) | O(N) |
| 0718 | [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) | 🟡 Medium | DP <br> Array | [C++](./solution/Solution_0718.cpp) | O(N * M) | O(M) |
| 1035 | [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/) | 🟡 Medium | DP <br> LCS | [C++](./solution/Solution_1035.cpp) | O(N * M) | O(M) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 Medium | Dynamic Programming | [C++](./solution/Solution_1143.cpp) | O(m*n) | O(m*n) |

> [!NOTE]
> [0300. Longest Increasing Subsequence](./solution/Solution_0300_1.cpp) 最佳解是Greedy + Binary Search<br>
> [0392. Is Subsequence](./solution/Solution_392.cpp) 最佳解是Two Pointers<br>
> [0674. Longest Continuous Increasing Subsequence](./solution/Solution_674.cpp) 最佳解是Greedy<br>

<br><br>
---

## <a name="knapsack-problem"></a>🧩 Dynamic Programming - 0/1 Knapsack Problem  (0/1背包問題)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0416 | [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | 🟡 Medium | DP <br> Bit Manipulation | [C++](./solution/Solution_0416.cpp) | O(N * S/W) | O(S/W) |
| 0474 | [Ones and Zeroes](https://leetcode.com/problems/ones-and-zeros/) | 🟡 Medium | DP <br> 0-1 Knapsack | [C++](./solution/Solution_0474.cpp) | O(L * m * n) | O(m * n) |
| 0494 | [Target Sum](https://leetcode.com/problems/target-sum/) | 🟡 Medium | DP <br> 0-1 Knapsack | [C++](./solution/Solution_0494.cpp) | O(N * S) | O(S) |
| 1049 | [Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/) | 🟡 Medium | DP <br> 0-1 Knapsack | [C++](./solution/Solution_1049.cpp) | O(N * S) | O(S) |
<br><br>
---


## <a name="knapsack-problem"></a>🧩 Dynamic Programming - Unbounded Knapsack Problem (無限大小背包問題)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0070 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | 🟢 Easy | DP <br> Unbounded Knapsack (Permutation) | [C++](./solution/Solution_0070.cpp) | O(N) | O(N) |
| 0279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares/) | 🟡 Medium | DP <br> Unbounded Knapsack | [C++](./solution/Solution_0279.cpp) | O(N * √N) | O(N) |
| 0322 | [Coin Change](https://leetcode.com/problems/coin-change/) | 🟡 Medium | DP <br> Unbounded Knapsack | [C++](./solution/Solution_0322.cpp) | O(A * N) | O(A) |
| 0377 | [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) | 🟡 Medium |  DP <br> Unbounded Knapsack (Permutation | [C++](./solution/Solution_0377.cpp) | O(A * N) | O(A) |
| 0518 | [Coin Change II](https://leetcode.com/problems/coin-change-ii/) | 🟡 Medium | DP <br> Unbounded Knapsack | [C++](./solution/Solution_0518.cpp) | O(N * A) | O(A) |
| 0139 | [Word Break](https://leetcode.com/problems/word-break/) | 🟡 Medium | DP  <br> Unbounded Knapsack | [C++](./solution/Solution_0139.cpp) | O(N^3) | O(N) | 

> [!NOTE]
> [0279.Perfect Squares](./solution/Solution_0279.cpp)和[0322.Coin Change](./solution/Solution_0322.cpp)<br>
> 279. Perfect Squares 本質上就是「湊出金額 n 所需的最少物品數」，與 322. Coin Change 完全一致，<br>
> 差別僅在於「硬幣」變成了一組「完全平方數」{1, 4, 9, 16,....\}。<br>
> <br>



<br><br>
---

## <a name="dynamic-programming-kadane-algorithm"></a>🧩 Dynamic Programming - Kadane's Algorithm(動態規劃)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 Medium | Array <br> Dynamic Programming | [C++](./solution/Solution_0053.cpp) | O(n) | O(1) |
| 0118 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | 🟢 Easy | Array <br> DP | [C++](./solution/Solution_0118.cpp) | O(N^2) | O(1)* |
| 0152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | 🟡 Medium | Dynamic Programming <br> Array | [C++](./solution/Solution_0152.cpp) | O(N) | O(1) |
| 0918 | [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-subarray-sum-circular/) | 🟡 Medium | Array <br> Kadane's Algorithm | [C++](./solution/Solution_0918.cpp) | O(N) | O(1) |
| 1641 | [Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/) | 🟡 Medium | Math <br> Dynamic Programming | [C++](./solution/Solution_1641.cpp) | O(1) | O(1) |

<br><br>
---

## <a name="greedy"></a>🧩 Greedy (貪婪法)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0435 | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) | 🟡 Medium | Greedy <br> Interval | [C++](./solution/Solution_0435.cpp) | O(NlogN) | O(1) |
| 0624 | [Maximum Distance in Arrays](https://leetcode.com/problems/maximum-distance-in-arrays) | 🟡 Medium | Array <br> Greedy | [C++](./solution/Solution_0624.cpp) | O(n) | O(1) |
| 0674 | [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence) | 🟢 Easy | Array <br> Greedy | [C++](./solution/Solution_0674.cpp) | O(n) | O(1) |
| 0678 | [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/) | 🟡 Medium | Greedy <br> String | [C++](./solution/Solution_0678.cpp) | O(N) | O(1) |
| 1323 | [Maximum 69 Number](https://leetcode.com/problems/maximum-69-number/) | 🟢 Easy | Greedy <br> Math | [C++](./solution/Solution_1323.cpp) | O(D) | O(D) |
| 3011 | [Find if Array Can Be Sorted](https://leetcode.com/problems/find-if-array-can-be-sorted/) | 🟡 Medium | Array <br> Greedy <br> Bit Manipulation | [C++](./solution/Solution_3011.cpp) | O(N) | O(1) | 
| 3798 | [Largest Even Number](https://leetcode.com/problems/largest-even-number/) | 🟢 Easy | Greedy / String | [C++](./solution/Solution_3798.cpp) | O(N) | O(1) |
<br><br>
---

## <a name="backtracking"></a>🔢 Backtracking (回朔法)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0022 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | 🟡 Medium | Backtracking / String | [C++](./solution/Solution_0022.cpp) | O(4ᴺ/√N) | O(N) |
| 0046 | [Permutations](https://leetcode.com/problems/permutations/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0046.cpp) | O(N*N!) | O(N) | [Note](#0046-permutations) |
| 0047 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0047.cpp) | O(N*N!) | O(N) |
| 0077 | [Combinations](https://leetcode.com/problems/combinations/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0077.cpp) | O(k * C(n, k)) | O(k) |
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 Medium | Backtracking / Recursion <br> Bit Manipulation | [C++](./solution/Solution_0078.cpp) | O(N*2ᴺ) | O(N) |
| 0079 | [Word Search](https://leetcode.com/problems/word-search/) | 🟡 Medium | DFS / Backtracking | [C++](./solution/Solution_0079.cpp) | O(N*3ᴸ) | O(L) |
| 0090 | [Subsets II](https://leetcode.com/problems/subsets-ii/) | 🟡 Medium | Backtracking / Sorting | [C++](./solution/Solution_0090.cpp) | O(N*2ᴺ) | O(N) |
| 0039 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0039.cpp) | O(N^(T/M)) | O(T/M) |
| 0040 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | 🟡 Medium | Backtracking / Sorting | [C++](./solution/Solution_0040.cpp) | O(2ᴺ) | O(N) |
| 0216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0216.cpp) | O(C(9, k)) | O(k) |


### 0046. Permutations
> [Permutations](https://leetcode.com/problems/permutations/)<br>
> start == size，則一組排列結果完成，for loop i，從 start 到size - 1，先swap start 和 i，start + 1 帶入遞迴，再swap start 和 i做恢復<br>
---


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
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | 🟡 Medium | Sliding Window / Hash Table | [C++](./solution/Solution_0003.cpp) | O(N) | O(1) |
| 0220 | [Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) | 🔴 Hard | Sliding Window / Ordered Map / Bucket | [C++](./solution/Solution_0220.cpp) | O(Nlog(min(N,k))) | O(min(N,k)) |
| 0567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string/) | 🟡 Medium | Sliding Window / Frequency Array | [C++](./solution/Solution_0567.cpp) | O(L1 + L2) | O(1) |
| 0643 | [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i) | 🟢 Easy | Array <br> Sliding Window | [C++](./solution/Solution_0643.cpp) | O(N) | O(1) |
| 1456 | [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length) | 🟡 Medium | String <br> Sliding Window | [C++](./solution/Solution_1456.cpp) | O(N) | O(1) |
| 1876 | [Substrings of Size Three with Distinct Characters](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters) | 🟢 Easy | String <br> Sliding Window | [C++](./solution/Solution_1876.cpp) | O(N) | O(1) |
| 1287 | [Element Appearing More Than 25% In Sorted Array](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/) | 🟢 Easy | Array <br> Sliding Window | [C++](./solution/Solution_1287.cpp) | O(N) | O(1) |
| 1984 | [Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/) | 🟢 Easy | Sorting / Sliding Window | [C++](./solution/Solution_1984.cpp) | O(NlogN) | O(1) |
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

## <a name="sql"></a>🔢SQL
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0182 | [Duplicate Emails](https://leetcode.com/problems/duplicate-emails/) | 🟢 Easy | Database | [SQL](./solution/Solution_0182.sql) | O(N) | O(N) | 使用 GROUP BY 聚合相同 Email，並透過 HAVING 過濾出計數大於 1 的項目，達成簡潔的重複項篩選 |

<img src="https://github.com/smartcsie/leetcode/blob/main/images/206Reverse_Linked_List.png" width="570" height="705">


© 2026 Laurence Chang.


© 2026 Laurence Chang. 保持思考，持續進化。
