# LeetCode 演算法精鍊筆記 (C++)

![LeetCode Stats](https://leetcard.jacoblin.cool/smartcsie?theme=nord) <!-- 註：將 laurence 換成你的 LeetCode ID -->

本倉庫用於記錄我的 LeetCode 解題過程、思路分析以及演算法優化心得。

---

## 🤖 Solutions
- [doocs(github)](https://github.com/doocs/leetcode/tree/main/solution)
- [walkccc(github)](https://github.com/walkccc/LeetCode/tree/main/solutions)
- [kamyu104(github)](https://github.com/kamyu104/LeetCode-Solutions)
- [wisdompeak(github)](https://github.com/wisdompeak/LeetCode)
- [leetcodehelp](https://leetcodehelp.github.io/)
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
- [Cracking The Coding Interview 6th Edition Mapping 到 LeetCode 的題目](https://leetcode.com/discuss/post/1152824/cracking-the-coding-interview-6th-editio-97nm/)


## 🤖 面試考題
- [Google](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Google)
- [Nvidia](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Nvidia)
- [Amazon](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Amazon)
- [Google Frequency](https://github.com/liquidslr/leetcode-company-wise-problems/blob/main/Google/5.%20All.csv)

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
| **0050** | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 Medium | Math <br> Binary Exponentiation | [C++](./solution/Solution_0050.cpp) | O(logN) | O(1) | [Note](#0050-powx-n) |
| **0060** | [Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) | 🟡 Medium | Math  <br> Factorial | [C++](./solution/Solution_0060.cpp) | O(N²) | O(N) | [Note](#0060-plus-one) |
| **0066** | [Plus One](https://leetcode.com/problems/plus-one/) | 🟢 Easy | Math | [C++](./solution/Solution_0066.cpp) | O(n) | O(1) | [Note](#0066-plus-one) | [Note](#0066-plus-one)  |
| 0137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Math <br> Hash Set | [C++](./solution/Solution_0137_1.cpp) | O(n) | O(n) | [Note](#0137-1-single-number-ii) |
| 0172 | [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes) | 🟡 Medium | Math | [C++](./solution/Solution_0172.cpp) | O(log₅N) | O(1) | [Note](#0172-factorial-trailing-zeroes) |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | 🟢 Easy | Math | [C++](./solution/Solution_0231.cpp) | O(1) | O(1) | [Note](#0231-power-of-two) |
| 0258 | [Add Digits](https://leetcode.com/problems/add-digits) | 🟢 Easy | Math | [C++](./solution/Solution_0258.cpp) | O(1) | O(1) | [Note](#0258-add-digits) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 Easy | Math | [C++](./solution/Solution_0263.cpp) | O(logn) | O(1) | [Note](#0263-ugly-number) |
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0268.cpp) | O(n) | O(1) | [Note](#0268-missing-number) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three/) | 🟢 Easy | Math | [C++](./solution/Solution_0326.cpp) | O(log₃n) | O(1) | [Note](#0326-power-of-three) |
| **0396** | [Rotate Function](https://leetcode.com/problems/rotate-function/) | 🟡 Medium | Math / Array | [C++](./solution/Solution_0396.cpp) | O(N) | O(1) |  |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four/) | 🟢 Easy | Math | [C++](./solution/Solution_0342.cpp) | O(1) | O(1) | [Note](#0342-power-of-four) |
| 0412 | [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/) | 🟢 Easy | Math / String | [C++](./solution/Solution_0412.cpp) | O(N) | O(1)* | [Note](#0412-fizz-buzz) |
| **0441** | [Arranging Coins](https://leetcode.com/problems/arranging-coins/) | 🟢 Easy | Math / Binary Search | [C++](./solution/Solution_0441.cpp) | O(logN) | O(1) | [Note](#0441-arranging-coins)
| 0628 | [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_0628.cpp) | O(N) | O(1) |[Note](#0628-maximum-product-of-three-numbers) |
| **0633** | [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/) | 🟡 Medium | Math / Two Pointers | [C++](./solution/Solution_0633.cpp) | O(√c) | O(1) | |
| **0970**| [Powerful Integers](https://leetcode.com/problems/powerful-integers/) | 🟡 Medium | Math / Hash Table | [C++](./solution/Solution_0970.cpp) | O(log_x(bound) * log_y(bound)) | O(S) | |
| 1015 | [Smallest Integer Divisible by K](https://leetcode.com/problems/smallest-integer-divisible-by-k/) | 🟡 Medium | Modular Arithmetic | [C++](./solution/Solution_1015.cpp) | O(K) | O(1) | [Note](#1015-smallest-integer-divisible-by-k) |
| 1018 | [Binary Prefix Divisible By 5](https://leetcode.com/problems/binary-prefix-divisible-by-5/) | 🟢 Easy | Math / Modulo | [C++](./solution/Solution_1018.cpp) | O(N) | O(1) | [Note](#1018-binary-prefix-divisible-by-5) |
| 1295 | [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_1295.cpp) | O(N) | O(1) | [Note](#1295-find-numbers-with-even-number-of-digits) |
| 1344 | [Angle Between Hands of a Clock](https://leetcode.com/problems/angle-between-hands-of-a-clock/) | 🟡 Medium | Math | [C++](./solution/Solution_1344.cpp) | O(1) | O(1) | [Note](#1344-angle-clock) |
| 1523 | [Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/) | 🟢 Easy | Math | [C++](./solution/Solution_1523.cpp)| O(1) | O(1) | [Note](#1523-count-odds) |
| 1572 | [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum) | 🟢 Easy | Matrix | [C++](./solution/Solution_1572.cpp) | O(N) | O(1) | [Note](#1572-matrix-diagonal-sum) |
| 1780 | [Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/) | 🟡 Medium | Math / Base-3 | [C++](./solution/Solution_1780.cpp) | O(log₃ N) | O(1) | [Note](#1780-powers-of-three) |
| 1822 | [Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_1822.cpp) | O(N) | O(1) | [Note](#1822-sign-of-the-product-of-an-array) |
| 1952 | [Three Divisors](https://leetcode.com/problems/three-divisors) | 🟢 Easy | Math | [C++](./solution/Solution_1952.cpp) | O(√N) | O(1) | [Note](#1952-three-divisors) |
| 1980 | [Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string) | 🟡 Medium | Math <br> String | [C++](./solution/Solution_1980.cpp) | O(N²) | O(N) | [Note](#1980-find-unique-binary-string) |
| **2063** | [Vowels of All Substrings](https://leetcode.com/problems/vowels-of-all-substrings/) | 🟡 Medium | Math / Contribution Technique | [C++](./solution/Solution_2063.cpp) | O(N) | O(1) | |
| 2119 | [A Number After a Double Reversal](https://leetcode.com/problems/a-number-after-a-double-reversal/) | 🟢 Easy | Math | [C++](./solution/Solution_2119.cpp) | O(1) | O(1) |[Note](#2119-three-divisors) |
| 2177 | [Find Three Consecutive Integers That Sum to a Given Number](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number) | 🟡 Medium | Math | [C++](./solution/Solution_2177.cpp) | O(1) | O(1) | [Note](#2177-find-three-consecutive-integers-that-sum-to-a-given-number) |
| **2310** | [Sum of Numbers With Units Digit K](https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/) | 🟡 Medium | Math / Enumeration | [C++](./solution/Solution_2310.cpp) | O(10) | O(1) ||
| 2413 | [Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple/) | 🟢 Easy | Math | [C++](./solution/Solution_2413.cpp) | O(1) | O(1) |[Note](#2413-smallest-even-multiple) |
| 2455 | [Average Value of Even Numbers That Are Divisible by Three](https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/) | 🟢 Easy | Math / Array |  [C++](./solution/Solution_2455.cpp)  | O(N) | O(1) | |
| 2469 | [Convert the Temperature](https://leetcode.com/problems/convert-the-temperature/) | 🟢 Easy | Math | [C++](./solution/Solution_2469.cpp) | O(1) | O(1) | [Note](#2469-convert-the-temperature) |
| **2485** | [Find the Pivot Integer](https://leetcode.com/problems/pivot-integer/) | 🟢 Easy | Math | [C++](./solution/Solution_2485.cpp) | O(1) | O(1) | [Note](#2485-find-the-pivot-integer)  |
| 2652 | [Sum Multiples](https://leetcode.com/problems/sum-multiples) | 🟢 Easy | Math | [C++](./solution/Solution_2652.cpp) | O(n) | O(1) | [Note](#2652-find-the-pivot-integer) |
| 3131 | [Find the Integer Added to Array I](https://leetcode.com/problems/find-the-integer-added-to-array-i/) | 🟢 Easy | Math / Array | [C++](./solution/Solution_3131.cpp) | O(N) | O(1) |  |
| 3232 | [Find if Digit Game Can Be Won](https://leetcode.com/problems/find-if-digit-game-can-be-won/) | 🟢 Easy | Math / Array | [C++](./solution/Solution_3232.cpp) | O(N) | O(1) | [Note](#3232-digit-game) |
| 3512 | [Minimum Operations to Make Array Sum Divisible by K](https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/) | 🟢 Easy | Math | [C++](./solution/Solution_3512.cpp) | O(N) | O(1) | [Note](#3512-minimum-operations-to-make-array-sum-divisible-by-k) |
| 3658 | [GCD of Odd and Even Sums](https://leetcode.com/problems/gcd-of-odd-and-even-sums) | 🟢 Easy | Math | [C++](./solution/Solution_3658.cpp) | O(1) | O(1) | [Note](#3658-gcd-of-odd-and-even-sums) |
| 3701 | [Compute Alternating Sum](https://leetcode.com/problems/compute-alternating-sum/) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_3701.cpp) | O(N) | O(1) | [Note](#3701-compute-alternating-sum) |

### 0050. Pow(x, n)
> [Pow(x, n)](https://leetcode.com/problems/powx-n)<br>
> **if (n == 0) return 1;** <br>
> **if (n == INT_MIN) return myPow(x * x, n / 2);** <br>
> **if (n < 0) return 1 / myPow(x, -n);** <br>
> **double half = myPow(x, n / 2);** <br>
> **return n % 2 == 0 ? half * half : half * half * x;** <br>
> **overflow handing** <br>

---

### 0066. Plus One 
> [Plus One](https://leetcode.com/problems/plus-one/)<br>
> 從最後一個digit，digit[n-1]往digit[0]，如果小於9 +1 return，否則設成0 往下個loop，最後在front insert 1 <br>
> **for(int i = digits.size() - 1; i >= 0 ; i--) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if(digits[i]++ < 9) return digits;** <br>
> &emsp;&emsp;&emsp;&emsp;**digits[i] = 0;** <br>
> **}** <br>
> **digits.insert(digits.begin(), 1);** <br>
> **return digits;** <br>

---



### 0137-1. Single Number II
> [Single Number II](https://leetcode.com/problems/single-number-ii)<br>
> 先travsal nums，num加到sum_all，num順便insert到unique_set(unordered_set<int>)<br>
> (3 * sum_unique - sum_all) / 2<br>
> 此題有三種解法，位元有限狀態機是最佳解<br>
---


### 0172 Factorial Trailing Zeroes
> [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes)<br>
> **勒讓德定理 (Legendre's Formula)<br>
---

### 0231 Power of Two
> [Power of Two](https://leetcode.com/problems/power-of-two/)<br>
> **(n > 0) && (n & (n-1)) == 0** <br>
---

### 0258 Add Digits
> [Add Digits](https://leetcode.com/problems/add-digits)<br>
> **(num - 1) % 9 + 1** <br>
---

### 0263 Ugly Number
> [Ugly Number](https://leetcode.com/problems/ugly-number)<br>
> n如果可被2整除，n除以2，n如果可被3整除，n除以3，n如果可被5整除，n除以5，最後是否等於1<br>
---

### 0268 Missing Number
> [Missing Number](https://leetcode.com/problems/missing-number/)<br>
> n = nums.size()，accumulate算出sum，回傳 n * (n + 1) / 2 - sum<br>
---



### 0326 Power of Three
> [Power of Three](https://leetcode.com/problems/power-of-three/)<br>
> **(n > 0) && static_cast<int>(pow(3, 19)) % n == 0**<br>
---

### 0342 Power of Four
> [Power of Four](https://leetcode.com/problems/power-of-four/)<br>
> **(n > 0) && (n & (n-1)) == 0 && (n & 0x55555555) != 0**，Power of Two多加 **(n & 0x55555555) != 0**<br>
---


### 0412 Fizz Buzz
> [Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)<br>
> 起一個for loop i 從 1 ~ n<br>
> **if(i % 3 == 0 && i % 5 != 0) res.push_back("Fizz");** <br>
> **else if(i % 3 != 0 && i % 5 == 0) res.push_back("Buzz");** <br>
> **else if(i % 3 == 0 && i % 5 == 0) res.push_back("FizzBuzz");** <br>
> **else res.push_back(to_string(i));** <br>
---

### 0441 Arranging Coins
> [Arranging Coins](https://leetcode.com/problems/arranging-coins/) <br>
> **return (int)((-1 + sqrt(1 + 8 * (long)n)) / 2);** <br>
---


### 0628 Maximum Product of Three Numbers
> [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers) <br>
> travsal nums 找出 max1，max2，max3，min1，min2，回傳 max(max1 * max2 * max3, max1 * min1 * min2) <br>

---


### 1015. Smallest Integer Divisible by K
> [Smallest Integer Divisible by K](https://leetcode.com/problems/smallest-integer-divisible-by-k/)  <br>
> **for (int length = 1, remainder = 0; length <= k; ++length) {** <br>
> &emsp;&emsp;&emsp;&emsp;**remainder = (remainder * 10 + 1) % K** <br>
> &emsp;&emsp;&emsp;&emsp;**if (remainder == 0) {** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**return length;** <br>
> &emsp;&emsp;&emsp;&emsp;**}** <br>
> **}** <br>

---



### 1018. Binary Prefix Divisible By 5
> [Binary Prefix Divisible By 5](https://leetcode.com/problems/binary-prefix-divisible-by-5/)  <br>
> **sum = ((sum << 1) + num) % 5;divisible.push_back((sum == 0));** <br>
---

### 1295 Find Numbers with Even Number of Digits
> [Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits)  <br>
> **static_cast<int>(log10(num) + 1) % 2 == 0** <br>
---

### 1344 Angle Between Hands of a Clock
> [Angle Between Hands of a Clock](https://leetcode.com/problems/angle-between-hands-of-a-clock/)  <br>
> **double hourAngle =  12 * 30.0 + minutes * 0.5;**  // 時針角度：hour * 30 + 分鐘帶來的偏移 (每分鐘 0.5 度)<br>
> **double minAngle = minutes * 6.0;**  // 分針角度：每分鐘 6 度<br>
> **double angle = std::abs(hourAngle - minAngle);**  // 計算兩者差值<br>
> **return std::min(360.0 - angle, angle);**  // 返回較小的夾角<br>
---

### 1572 Matrix Diagonal Sum
> [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum)<br>
> 如果 i == (n-1-i) 則sum只加matrix[i][i] 否則sum加matrix[i][i]和matrix[i][n-1-i]，為了奇術矩陣去中重中間元素<br>
---

### 1780 Check if Number is a Sum of Powers of Three
> [Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/)<br>
> 連除3，過程中，if(n % 3 == 2) return false;<br>
---


### 1822 Sign of the Product of an Array
> [Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array)<br>
> 如果 nums.size() == 0，return 0，起一個變數sign = 1，尋訪nums，如果num < 0，sign = -sign<br>

 
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

### 2177 Find Three Consecutive Integers That Sum to a Given Number
> [Find Three Consecutive Integers That Sum to a Given Number](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number) 
 <br>
> 如果num被3整除，回傳空vector {}，否則回傳{num / 3 - 1, num / 3, num / 3 + 1}。<br>

---

### 2413 Smallest Even Multiple
> [Smallest Even Multiple](https://leetcode.com/problems/smallest-even-multiple/) <br>
> return (n & 1) == 0 ? n : 2 * n;。<br>

---

### 2469 Convert the Temperature
> [Convert the Temperature](https://leetcode.com/problems/convert-the-temperature/) <br>
> return { celsius + 273.15, celsius * 1.80 + 32.00 };<br>

---

### 2485 Find the Pivot Integer
> [Find the Pivot Integer](https://leetcode.com/problems/pivot-integer/)<br>
> Pivot integer為 summation開根號<br>
> int sum = n * (n + 1) / 2;<br>
> int x = static_cast<int>(sqrt(sum));<br>
> if(x * x == sum) return x;<br>
> return -1;<br>

---

### 2652 Find the Pivot Integer
> [Sum Multiples](https://leetcode.com/problems/sum-multiples)
> travsal 1~n，如果是3或5或7能整除，則加到sum，最後回傳sum <br>
> for(int i = 1 ;i <= n; i++) { <br>
> if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0) sum += i; <br>
> }<br>

---

### 3232 Find if Digit Game Can Be Won
> [Find if Digit Game Can Be Won](https://leetcode.com/problems/find-if-digit-game-can-be-won/) <br>
> Alice可以選個位數或雙位數，只有一種狀況，Alice不可能贏，個位數和和雙位數和相等<br>

---




### 3512 Minimum Operations to Make Array Sum Divisible by K
> [Minimum Operations to Make Array Sum Divisible by K](https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/)<br>
> 全部加起來除以k取餘數，可以一邊加，一邊取餘數<br>

---

### 3658 GCD of Odd and Even Sums
> [GCD of Odd and Even Sums](https://leetcode.com/problems/gcd-of-odd-and-even-sums) <br>
> odd sum = n²，even sum = n² + n，GCD(n² , n² + n) = n<br>


---


### 3701 Compute Alternating Sum
> [Compute Alternating Sum](https://leetcode.com/problems/compute-alternating-sum/) <br>
> for(int i = 0; i < nums.size(); i++) {  sum += (i & 1) ? -nums[i] : nums[i];  } <br>


<br><br>
---



## <a name="math-combination"></a>🔢 Math Combination(數學 組合)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths/) | 🟡 Medium | Math / Combinatorics / DP | [C++](./solution/Solution_0062.cpp) | O(min(m, n)) | O(1) | [Note](#0062-unique-paths) |
| 0357 | [Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/) | 🟡 Medium | Math / Combinatorics | [C++](./solution/Solution_0357.cpp) | O(N) | O(1) |  |
| 1588 | [Sum of All Odd Length Subarrays](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/) | 🟢 Easy | Array / Math (Contribution) | [C++](./solution/Solution_1588.cpp) | O(N) | O(1) |  |
| 3084 | [Count Substrings...](https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/) | 🟢 Easy | Combinatorics | [C++](./solution/Solution_3084.cpp) | O(N) | O(1) |  |

### 0062. Unique Paths
> [Unique Paths](https://leetcode.com/problems/unique-paths/)<br>
> 在 **mxn** 的網格中，計算從左上角到右下角的總路徑數，<br>
> **總步數為 (m-1) + (n-1)，從中選取 m-1 步向下走**。<br>
> **C(m + n - 2, m - 1)** <br>

<br><br>
---

## <a name="math-permutation"></a>🔢 Math Permutation(數學 排列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0949 | [Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/) | 🟡 Medium | Permutation / Math | [C++](./solution/Solution_949.cpp) | O(1) | O(1) | [Note](#0949-largest-time-for-given-digits)|


### 0949. Largest Time for Given Digits
> [Largest Time for Given Digits](https://leetcode.com/problems/largest-time-for-given-digits/)<br>
> **std::sort(arr.begin(), arr.end());int max_time = -1;** <br>
> **do {** <br>
> &emsp;&emsp;&emsp;&emsp;**int hour = arr[0] * 10 + arr[1];** <br>
> &emsp;&emsp;&emsp;&emsp;**int minute = arr[2] * 10 + arr[3];** <br>
> &emsp;&emsp;&emsp;&emsp;**if (hour < 24 && minute < 60) {** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**max_time = std::max(max_time, hour * 60 + minute);** <br>
> &emsp;&emsp;&emsp;&emsp;**}** <br>
> **} while (std::next_permutation(arr.begin(), arr.end()));** <br>
> **snprintf(buf, sizeof(buf), "%02d:%02d", max_time / 60, max_time % 60);** <br>

<br><br>
---


## <a name="math-factor-enumeration"></a>🔢 Math - Factor Enumeration(數學 因式分解)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **0507** | [Perfect Number](https://leetcode.com/problems/perfect-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0507.cpp) | O(√N) | O(1) | [Note](#0507-perfect-number) |
| **1492** | [The kth Factor of n](https://leetcode.com/problems/the-kth-factor-of-n/) | 🟡 Medium | Math | [C++](./solution/Solution_1492.cpp) | O(√N) | O(1) |  [Note](#1492-the-kth-factor-of-n)|
| **2507** | [Smallest Value After Replacing With Sum of Prime Factors](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/) | 🟡 Medium | Math / Prime Factorization | [C++](./solution/Solution_2507.cpp) | O(log N * sqrt(N)) | O(1) ||

### 0507 Perfect Number
> [Perfect Number](https://leetcode.com/problems/perfect-number/)<br>
> 法一<br>
> int res = 1;<br>
> for(int i = 2; i * i < sqrt(num); i++) if(num % i == 0) res += i + num / i;<br>
> return res == num;<br>
> 法二<br>
> return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;<br>


### 1492 The kth Factor of n
> [The kth Factor of n](https://leetcode.com/problems/the-kth-factor-of-n/)<br>
> 分前半部和後半部<br>
> for(int i =1; i * i <=n; i++) if(n % i == 0 && (--k == 0)) return i;<br>
> for (int i = (int)sqrt(n); i >= 1; i--) if (n % i == 0 && i * i != n && --k == 0) return n / i;<br>


<br><br>
---


## <a name="math-simulation"></a>🔢 Math - Simulation (數學模擬)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **0067** | [Add Binary](https://leetcode.com/problems/add-binary) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_0067.cpp) | O(max(M, N)) | O(1) | [Note](#0067-add-binary) |
| 0415 | [Add Strings](https://leetcode.com/problems/add-strings) | 🟢 Easy | String / Math | [C++](./solution/Solution_0415.cpp) | O(max(N, M)) | O(max(N, M)) | [Note](#0415-add-strings) |
| 0989 | [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | 🟢 Easy | Simulation / Carry Propagation | [C++](./solution/Solution_0989.cpp) | O(max(N, log K)) | O(max(N, log K)) | |
| 3894 | [Traffic Signal Color](https://leetcode.com/problems/traffic-signal-color/) | 🟢 Easy | Logic Control | [C++](./solution/Solution_3894.cpp) | O(1) | O(1) |  |


### 0067. Add Binary
> [Add Binary](https://leetcode.com/problems/add-binary)<br>
> 和 0415[Add Strings](https://leetcode.com/problems/add-strings) 幾乎一樣<br>
> i和j設定為a和b最後的index，i = a.size() - 1，j = b.size() - 1<br>
> **while(i >= 0 || j >= 0 || carry == 1) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if(i >= 0) carry += a[i--] - '0';** <br>
> &emsp;&emsp;&emsp;&emsp;**if(j >= 0) carry += b[j--] - '0';** <br>
> &emsp;&emsp;&emsp;&emsp;**res.push_back((carry % 2) + '0');** <br>
> &emsp;&emsp;&emsp;&emsp;**carry /= 2;** <br>
> **}** <br>
> **reverse(res.begin(), res.end());** <br>
---

### 0415. Add Strings
> [Add Strings](https://leetcode.com/problems/add-strings) <br>
> 和 0067[Add Binary](https://leetcode.com/problems/add-binary) 幾乎一樣<br>
> i和j設定為num1和num2最後的index，i = num1.size() - 1，j = num2.size() - 1 <br>
> **while(i >= 0 || j >= 0 || carry !=0) {** <br>
> &emsp;&emsp;&emsp;&emsp;**f(i >=0) carry += num1[i--] - '0';** <br>
> &emsp;&emsp;&emsp;&emsp;**if(j >=0) carry += num2[j--] - '0';** <br>
> &emsp;&emsp;&emsp;&emsp;**res.push_back((carry % 10) + '0');** <br>
> &emsp;&emsp;&emsp;&emsp;**carry /= 10;** <br>
> **}** <br>
> **reverse(res.begin(), res.end());** <br>

---


<br><br>
---



## <a name="math-digit Decomposition"></a>🔢 Math- Digit Decomposition(數學 數字拆解)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0007 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | 🟡 Medium | Math | [C++](./solution/Solution_0007.cpp) | O(logn) | O(1) | [Note](#0007-reverse-integer) |
| 0504 | [Base 7](https://leetcode.com/problems/base-7) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_0504.cpp) | O(log₇N) | O(1) | [Note](#0504-base-7) |
| 0728 | [Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers/) | 🟢 Easy | Simulation | [C++](./solution/Solution_0728.cpp) | O(N*D) | O(1) | [Note](#0728-self-dividing-numbers) |
| 0868 | [Binary Gap](https://leetcode.com/problems/binary-gap/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_868.cpp) | O(log N) | O(1) | [Note](#0868-binary-gap) |
| 1017 | [Convert to Base -2](https://leetcode.com/problems/convert-to-base-2) | 🟡 Medium | Math | [C++](./solution/Solution_1017.cpp) | O(logN) | O(1) | [Note](#1017-convert-to-base-2) |
| 1281 | [Subtract the Product and Sum of Digits of an Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/) | 🟢 Easy | Math / Digit Manipulation | [C++](./solution/Solution_1281.cpp) | O(log N) | O(1) ||
| 1837 | [Sum of Digits in Base K](https://leetcode.com/problems/sum-of-digits-in-base-k) | 🟢 Easy | Math | [C++](./solution/Solution_1837.cpp) | O(logₖN) | O(1) | [Note](#1837-sum-of-digits-in-base-k) |
| 1880 | [Check if Word Equals Summation of Two Words](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/) | 🟢 Easy | String / Math | [C++](./solution/Solution_1880.cpp)  | O(N) | O(1) | |
| 2180 | [Count Integers With Even Digit Sum](https://leetcode.com/problems/count-integers-with-even-digit-sum/) | 🟢 Easy | Math / Digit Manipulation | [C++](./solution/Solution_2180.cpp) | O(D) | O(1) | [Note](#2180-count-integers-with-even-digit-sum) |
| 2443 | [Sum of Number and Its Reverse](https://leetcode.com/problems/sum-of-number-and-its-reverse/) | 🟡 Medium | Math / Simulation | [C++](./solution/Solution_2443.cpp) | O(NlogN) | O(1) | [Note](#2443-sum-of-number-and-its-reverse)
| 2520 | [Count the Digits That Divide a Number](https://leetcode.com/problems/count-the-digits-that-divide-a-number/) | 🟢 Easy | Math / Digit Manipulation | [C++](./solution/Solution_2520.cpp) | O(log N) | O(1) | |
| 2535 | [Difference Between Element Sum and Digit Sum of an Array](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/) | 🟢 Easy | Math / Array | [C++](./solution/Solution_2535.cpp) | O(N * log M) | O(1) ||
| 2544 | [Alternating Digit Sum](https://leetcode.com/problems/alternating-digit-sum/) | 🟢 Easy | Math / Digit Manipulation | [C++](./solution/Solution_2544.cpp) | O(logN) | O(logN) | [Note](#2544-alternating-digit-sum) |
| 2553 | [Separate the Digits in an Array](https://leetcode.com/problems/separate-the-digits-in-an-array) | 🟢 Easy | Array <br> Math | [C++](./solution/Solution_2553.cpp) | O(n * log(max_val)) | O(n * log(max_val)) | [Note](#2553-separate-the-digits-in-an-array) |
| 2595 | [Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2595.cpp) | O(logN) | O(1) | [Note](#2595-number-of-even-and-odd-bits) |
| 2843 | [Count Symmetric Integers](https://leetcode.com/problems/count-symmetric-integers/) | 🟢 Easy | Simulation <br> Math | [C++](./solution/Solution_2843.cpp) | O(N * D) | O(1) | |
| 3099 | [Harshad Number](https://leetcode.com/problems/harshad-number/) | 🟢 Easy | Math | [C++](./solution/Solution_3099.cpp) | O(logN) | O(1) | [Note](#3099-harshad-number) |
| 3300 | [Minimum Element After Replacement With Digit Sum](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/) | 🟢 Easy | Math / Simulation | [C++](./solution/Solution_3300.cpp) | O(N * log M) | O(1) | [Note](#3300-digit-sum) |
| 3340 | [Check Balanced String](https://leetcode.com/problems/check-balanced-string/) | 🟢 Easy | String <br> Math | [C++](./solution/Solution_3340.cpp) | O(N) | O(1) | [Note](#3340-check-balanced-string) |
| 3345 | [Smallest Divisible Digit Product I](https://leetcode.com/problems/smallest-divisible-digit-product-i/) | 🟢 Easy | Brute Force / Digit Manipulation | [C++](./solution/Solution_3345.cpp) | O(K × D) | O(1) | [Note](#3345-smallest-divisible-digit-product-i) |
| 3622 | [Check Divisibility by Digit Sum and Product](https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/) | 🟢 Easy | Math / Digit Manipulation | [C++](./solution/Solution_3622.cpp) | O(log N) | O(1) | |
| 3697 | [Compute Decimal Representation](https://leetcode.com/problems/compute-decimal-representation/) | 🟢 Easy | Math / Digit Extraction | O(log N) | O(log N) | [Note](#3697-compute-decimal-representation) | [Note](#3726-remove-zeros-in-decimal-representation)|
| 3726 | [Remove Zeros in Decimal Representation](https://leetcode.com/problems/remove-zeros-in-decimal-representation) | 🟢 Easy | Math / Digit Extraction | [C++](./solution/Solution_3726.cpp) | O(log N) | O(1) |  |
| 3895 | [Count Digit Appearances](https://leetcode.com/problems/count-digit-appearances/) | 🟢 Easy | Digit Manipulation | [C++](./solution/Solution_3895.cpp) | O(N × D) | O(1) | [Note](#3895-count-digit-appearances) |
| 3908 | [Valid Digit Number](https://leetcode.com/problems/valid-digit-number/) | 🟢 Easy | Math <br> Digit Manipulation | [C++](./solution/Solution_3908.cpp) | O(log N) | O(1) | [Note](#3908-valid-digit-number) |
| 3945 | [Digit Frequency Score](https://leetcode.com/problems/digit-frequency-score/) | 🟢 Easy | Math | [C++](./solution/Solution_3945.cpp) | O(logN) | O(1) | [Note](#3945-digit-frequency-score) |
| 3950 | [Exactly One Consecutive Set Bits Pair](https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3950.cpp) | O(log N) | O(1) | [Note](#3950-exactly-one-consecutive-set-bits-pair) |
| 3959 | [Check Good Integer](https://leetcode.com/problems/check-good-integer/) | 🟢 Easy | Math / Digit Manipulation | [C++](./solution/Solution_3959.cpp) | O(log N) | O(1) | [Note](#3959-check-good-integer) |
| 3982 | Sum of Integers with Maximum Digit Range | 🟢 Easy | Math / Array | [C++](./solution/Solution_3982.cpp) | O(N * D) | O(N) | |

### 0007. Reverse Integer
> [Reverse Integer](https://leetcode.com/problems/reverse-integer/)<br>
> 不用管正負號，因為有正負，所以while(x != 0) <br>
> **while回圈內，邊界條件如下** <br>
> **if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && (x % 10) > 7)) return 0;** <br>
> **if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && (x % 10) < -8)) return 0;** <br>

---


### 0504 Base 7
> [Base 7](https://leetcode.com/problems/base-7) <br>
> 先用bool紀錄正負號，因為有正負號，while(n != 0)，餘數mod 7，如果為負乘上-1，＋'0'轉char push_back到string尾端，最後reverse<br>
---


### 0728 Self Dividing Numbers
> [Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers/)  <br>
> 每個數做Base 10 Digit Decomposition，如果digit == 0或 n % figit != 0 ，return false<br>

---


### 0868 Binary Gap
> [Binary Gap](https://leetcode.com/problems/binary-gap/)  <br>
> pre_one_idx 紀錄上一次1的index，max_gap紀錄相鄰1的index最大值<br>

---



### 1017 Convert to Base -2
> [Convert to Base -2](https://leetcode.com/problems/convert-to-base-2)<br>
> while(n != 0) {    res = to_string(n & 1) + res;   n  = -(n>>1);}，不等於0是因為有正負<br>
---

### 1837 Sum of Digits in Base K
> [Sum of Digits in Base K](https://leetcode.com/problems/sum-of-digits-in-base-k)<br>
> K進制的位數和，一直 % k加到sum，while(n > 0) {  sum = n % k + sum; n /= k; }  return sum <br>
---




### 2180 Count Integers With Even Digit Sum
> [Count Integers With Even Digit Sum](https://leetcode.com/problems/count-integers-with-even-digit-sum/) <br>
> 回傳 num/2，如果digit sum不是0且是偶數，num/2要再-1{<br>
> **while(temp > 0) { digitSum += temp % 10; temp /= 10; }** {<br>
> **int answer = num / 2;** {<br>
> &emsp;&emsp;&emsp;&emsp;**if (num % 2 == 0 && digitSum % 2 != 0) {** {<br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**answer -= 1;** {<br>
> **}** {<br>

---


### 2443 Sum of Number and Its Reverse
> [Sum of Number and Its Reverse](https://leetcode.com/problems/sum-of-number-and-its-reverse/) <br>
> 實作一個base 10的reverse，for loop i，從 num/2 ~ num， i + reverse(i) 則 return true<br>

---


### 2544 Alternating Digit Sum
> [Alternating Digit Sum](https://leetcode.com/problems/alternating-digit-sum/)  <br>
> sign=1，每一次加sign*MSB(n % 10)後，sign*=-1，**最後出迴圈，sign如果是1，sum多一個負號**。<br>

---

### 2553 Separate the Digits in an Array
> [Separate the Digits in an Array](https://leetcode.com/problems/separate-the-digits-in-an-array) <br>
> 方法一<br>
> **for(int i = nums.size() - 1 ; i >= 0; i--)** {<br>
> &emsp;&emsp;&emsp;&emsp;**int temp = nums[i];** <br>
> &emsp;&emsp;&emsp;&emsp;**while(temp > 0) {** {<br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**res.push_back(temp % 10);** {<br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**temp /= 10;** {<br>
> &emsp;&emsp;&emsp;&emsp;**}** {<br>
> **}<br>
> reverse(res.begin(), res.end());<br>
> 方法二<br>
> **for(const int& num : nums) {** <br>
> &emsp;&emsp;&emsp;&emsp;**for(char c : to_string(num)) res.push_back(c - '0');** <br>
> **}** <br>

---

### 2595 Number of Even and Odd Bits
> [Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits)<br>
> for(int i = 0; n > 0; n >>= 1, i ^= 1) res[i] += (n & 1);<br>

---

### 3099. Harshad Number
> [Harshad Number](https://leetcode.com/problems/harshad-number/)<br>
> 用sum把十進制每個digit相加，最後return (x % sum) == 0 ? sum : -1;<br>

---

### 3340 Check Balanced String
> [Check Balanced String](https://leetcode.com/problems/check-balanced-string/)<br>
> 奇數index所有num之sum和偶數index所有num之sum要相等<br>

---


### 3340 Minimum Element After Replacement With Digit Sum
> [Minimum Element After Replacement With Digit Sum](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/)<br>
> Travsal vector<int>& nums，sum算出digit之和，用min紀錄最小的digit sum<br>

---




### 3345 Smallest Divisible Digit Product I
> [Smallest Divisible Digit Product I](https://leetcode.com/problems/smallest-divisible-digit-product-i/)<br>
> 針對每個num，digit decomposition取得每個digit，做product，看是否可被t整除<br>

---



### 3697 Compute Decimal Representation
> [Compute Decimal Representation](https://leetcode.com/problems/compute-decimal-representation/)  <br>
> n一路往右除10，base初始1，一路*10，每次擷取digit = n % 10;，如果digit != 0，digit*base push_back到res<br>
> **注意base ovewrflow的問題，先 n/=10 ;，再來if(n > 0) base*=10;** <br>
---

### 3726 Remove Zeros in Decimal Representation
> [Remove Zeros in Decimal Representation](https://leetcode.com/problems/remove-zeros-in-decimal-representation) <br>
> 跟 3697很像，差異是digit != 0 才 res += base * digit; base *= 10;<br>
---




### 3895 Count Digit Appearances
> [Count Digit Appearances](https://leetcode.com/problems/count-digit-appearances/)  <br>
> 檢查nums中每一位是否等於digit<br>
> **int temp = num;** <br>
> **while(temp > 0) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if(temp% 10 == digit) count++;** <br>
> &emsp;&emsp;&emsp;&emsp;**temp /= 10;** <br>
> **}** <br>
---



### 3908 Valid Digit Number
> [Valid Digit Number](https://leetcode.com/problems/valid-digit-number/) <br>
> 用一個bool紀錄digit是否有x，最後return digit != x && findX; <br>

---

### 3945 Digit Frequency Score
> [Digit Frequency Score](https://leetcode.com/problems/digit-frequency-score/) <br>
> 用sum把十進制每個digit相加，最後return sum<br>
---

### 3950 Exactly One Consecutive Set Bits Pair
> [Exactly One Consecutive Set Bits Pair](https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/)<br>
> 如果 (n & 3) == 3，count++，如果count > 1  return false，n >>= 1，迴圈出來，return count == 1<br>
---


### 3959 Check Good Integer
> [Check Good Integer](https://leetcode.com/problems/check-good-integer/)<br>
> 全部加起來除以k取餘數，可以一邊加，一邊取餘數<br>
>

<br><br>
---

## <a name="prime"></a>🔢 Math Prime(數學 質數)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0204 | [Count Primes](https://leetcode.com/problems/count-primes/) | 🟡 Medium | Math / Sieve | [C++](./solution/Solution_0204.cpp) | O(NloglogN) | O(N) | [Note](#0204-count-primes) |
| 2521 | [Distinct Prime Factors of Product of Array](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/) | 🟡 Medium | Math / Prime Factorization | [C++](./solution/Solution_2521.cpp) | O(N*sqrt(M)) | O(K) |[Note](#2521-distinct-prime-factors-of-product-of-array) |
| **2523** | [Closest Prime Numbers in Range](https://leetcode.com/problems/closest-prime-numbers-in-range/) | 🟡 Medium | Math / Sieve | [C++](./solution/Solution_2523.cpp) | O(Nloglog N) | O(N) | [Note](#2523-closest-prime-numbers-in-range) | 
| 2614 | [Prime In Diagonal](https://leetcode.com/problems/prime-in-diagonal/) | 🟢 Easy | Math / Trial Division | [C++](./solution/Solution_2614.cpp) | O(N * sqrt(M)) | O(1) | [Note](#2614-prime-in-diagonal) |
| 2761 | [Prime Pairs With Target Sum](https://leetcode.com/problems/prime-pairs-with-target-sum/) | 🟡 Medium | Math <br> Sieve | [C++](./solution/Solution_2761.cpp) | O(NloglogN) | O(N) | [Note](#2761-prime-pairs-with-target-sum)|
| 3591 | [Check if Any Element Has Prime Frequency](https://leetcode.com/problems/check-if-any-element-has-prime-frequency/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_3591.cpp) | O(N + Kloglog K) | O(K) | [Note](#3591-check-if-any-element-has-prime-frequency) |
| 3618 | [Split Array by Prime Indices](https://leetcode.com/problems/split-array-by-prime-indices/) | 🟢 Easy | Math / Sieve | [C++](./solution/Solution_3618.cpp) | O(N + R log log R) | O(R) | [Note](#3618-split-array-by-prime-indices) |
| 3765 | [Complete Prime Number](https://leetcode.com/problems/complete-prime-number/) | 🟢 Easy | Math / Prime Number | [C++](./solution/Solution_3765.cpp) | O(D * sqrt(N)) | O(D) | [Note](#3765-complete-prime-number) |
| 3770 | [Largest Prime from Consecutive Prime Sum](https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/) | 🟡 Medium | Math / Prefix Sum | [C++](./solution/Solution_3770.cpp) | O(R log log R) | O(R) | [Note](#3770-largest-prime-from-consecutive-prime-sum) |
| 3918 | [Sum of Primes Between Number and Its Reverse](https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/) | 🟡 Medium | Math / Sieve | [C++](./solution/Solution_3918.cpp) | O(R log log R) | O(R) | [Note](#3918-sum-of-primes-between-number-and-its-reverse) |


### 0204 Count Primes
> [Count Primes](https://leetcode.com/problems/count-primes/)<br>
> 起一組 bitset<50001> isPrime，執行Sieve of Eratosthenes演算法，一個for loop 2 ~ **(n-1)**，看prime有幾個<br>
---

### 2521 Distinct Prime Factors of Product of Array
[Distinct Prime Factors of Product of Array](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/)
> 對vector<int>& nums的每個num做質因素分解，質因素放入unordered_set<int> factors<br>
> 最後回傳 static_cast<int>(factors.size())<br>

---


### 2523 Closest Prime Numbers in Range
> [Closest Prime Numbers in Range](https://leetcode.com/problems/closest-prime-numbers-in-range/)<br>
> 先用Sieve Algorithm 算出 1 ~ right<br>
> 初始化變數 vector<int> result = {-1, -1};  int prevPrime = -1; int minDiff = INT_MAX;<br>
> for loop i = left ~ right，更新prevPrime，更新diff最小，更新result<br>

---

### 2614 Prime In Diagonal
> [Prime In Diagonal](https://leetcode.com/problems/prime-in-diagonal/)<br>
> 實作isPrime，兩邊對角線一一代入，紀錄Max Prime<br>
---


### 2761 Prime Pairs With Target Sum
> [Prime Pairs With Target Sum](https://leetcode.com/problems/prime-pairs-with-target-sum/) <br>
> 起一組 bitset<100001> isPrime，執行Sieve of Eratosthenes演算法，i 從 1 ~ n/2，i和 n - 1都是prime，則放入result vector<br>
---




### 3591 Check if Any Element Has Prime Frequency
> [Check if Any Element Has Prime Frequency](https://leetcode.com/problems/check-if-any-element-has-prime-frequency/) <br>
> 起一組 bitset<101> isPrime，執行Sieve of Eratosthenes演算法，用vector<int> count(101, 0)計算每個numt出現頻率，檢查哪個頻率prime<br>
---

### 3618 Split Array by Prime Indices
> [Split Array by Prime Indices](https://leetcode.com/problems/split-array-by-prime-indices/)<br>
> 執行Sieve of Eratosthenes演算法，travsal nums 1 ~ size() - 1，if(isPrime[i]) { sum += nums[i]; } else { sum -= nums[i]; }<br>
---

### 3765 Complete Prime Number
> [Complete Prime Number](https://leetcode.com/problems/complete-prime-number/)<br>
> **string s = to_string(num);** <br>
> **int n = s.size();** <br>
> **for(int i = 1; i <= n; i++) {** <br>
> &emsp;&emsp;&emsp;&emsp;**int prefix = stoi(s.substr(0, i));** <br>
> &emsp;&emsp;&emsp;&emsp;**if(!isPrime(prefix)) return false;** <br>
> &emsp;&emsp;&emsp;&emsp;**int suffix = stoi(s.substr(n - i,i));** <br>
> &emsp;&emsp;&emsp;&emsp;**if(!isPrime(suffix)) return false;** <br>
> **}** <br>
> **return true;** <br>

---


### 3770 Largest Prime from Consecutive Prime Sum
> [Largest Prime from Consecutive Prime Sum](https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/)<br>
> 執行Sieve of Eratosthenes演算法，算出質數vector<int> primes;和 vector<bool> isPrime;<br>
> travsal primes，把prime加到current_sum，if (current_sum > n) break;，if (isPrime[current_sum]) { ans = static_cast<int>(current_sum);}<br>
---


### 3918 Sum of Primes Between Number and Its Reverse
> [Sum of Primes Between Number and Its Reverse](https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/)<br>
> 先求n的reverse，int left = min(n, reversed);int right = max(n, reversed);<br>
> 執行Sieve of Eratosthenes演算法，left到right區間，if(isPrime[i])sum += i;<br>
---
            
<br><br>
---

## <a name="math-palindrome"></a>🔢 Math Palindrome(數學-回文)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0009 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0009.cpp) | O(logn) | O(1) | [Note](#0009-palindrome-number) |
| 0866 | [Prime Palindrome](https://leetcode.com/problems/prime-palindrome/) | 🟡 Medium | Math / Palindrome | [C++](./solution/Solution_0866.cpp) | O(sqrt(P) * 10^(L/2)) | O(1) |
| 2396 | [Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/) | 🟡 Medium | Math <br> Brainteaser | [C++](./solution/Solution_2396.cpp) | O(1) | O(1) | [Note](#2396-strictly-palindromic-number) |


### 0009. Palindrome Number
>  [Palindrome Number](https://leetcode.com/problems/palindrome-number/)<br>
> x < 0 則 return false <br>
> x == 0 則 return true <br>
> **while回圈內，邊界條件如下** <br>
> **if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && (x % 10) > 7)) return 0;** <br>
---

### 2396 Strictly Palindromic Number
> [Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/) 
> return false;

---


<br><br>
---


## <a name="Bit-manipulation"></a>📊 Bit Manipulation (位元運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0029 | [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) | 🟡 Medium | Bit Manipulation / Math | [C++](./solution/Solution_0029.cpp) | O(log²N) | O(1) |
| 0089 | [Gray Code](https://leetcode.com/problems/gray-code/) | 🟡 Medium | Bit Manipulation / Math | [C++](./solution/Solution_0089.cpp) | O(2ᴺ) | O(1) | |
| 0137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Bit-Manipulation | [C++](./solution/Solution_0137.cpp) | O(n) | O(1) | [Note](#0137-2-single-number-ii)  |
| 0190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0190.cpp) | O(1) | O(1) | [Note](#0190-reverse-bits) |
| **0371** | [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0371.cpp) | O(1) | O(1) | [Note](#0371-sum-of-two-integers)
| 0389 | [Find the Difference](https://leetcode.com/problems/find-the-difference/) | 🟢 Easy | Hash Table <br> Bit Manipulation | [C++](./solution/Solution_0389.cpp) | O(N) | O(1) | [Note](#0389-find-the-difference) |
| 0401 | [Binary Watch](https://leetcode.com/problems/binary-watch/) | 🟢 Easy | Bit Manipulation / Brute Force | [C++](./solution/Solution_401.cpp) | O(1) | O(1) ||
| 0476 | [Number Complement](https://leetcode.com/problems/number-complement) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0476.cpp) | O(log N) | O(1) | [Note](#0476-number-complement) | 
| 0762 | [Prime Number of Set Bits](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0762.cpp) | O(N log K) | O(1) | [Note](#762-prime-bits) |
| 1009 | [Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_1009.cpp) | O(log N) | O(1) | [Note](#1009-complement-of-base-10-integer)|
| **1680** | [Concatenation of Consecutive Binary Numbers](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/) | 🟡 Medium | Math / Bit Manipulation | [C++](./solution/Solution_1680.cpp) | O(N) | O(1) | |
| 1684 | [Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings) | 🟢 Easy | Array <br> Hash Table <br> Bit Manipulation | [C++](./solution/Solution_1684.cpp) | O(N * M) | O(1) | [Note](#1684-count-the-number-of-consistent-strings) |
| **1920** | [Build Array from Permutation](https://leetcode.com/problems/build-array-from-permutation/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_1920.cpp) | O(N) | O(1) | |
| 2032 | [Two Out of Three](https://leetcode.com/problems/two-out-of-three/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2032.cpp) | O(N1+N2+N3) | O(1) | [Note](#2032-two-out-of-three) |
| **2235** | [Add Two Integers](https://leetcode.com/problems/add-two-integers) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2235.cpp) | O(1) | O(1) | [Note](#2235-add-two-integers) |
| 2716 | [Minimize String Length](https://leetcode.com/problems/minimize-string-length/) | 🟢 Easy | Hash Set <br> Bit Manipulation | [C++](./solution/Solution_2716.cpp) | O(N) | O(1) | [Note](#2716-minimize-string-length) |
| 3120 | [Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3120.cpp) | O(N) | O(1) | [Note](#3120-special-chars) |
| 3151 | [Special Array I](https://leetcode.com/problems/special-array-i) | 🟢 Easy | Array <br> Bit Manipulation | [C++](./solution/Solution_3151.cpp) | O(N) | O(1) | [Note](#3151-special-array-i) |
| 3370 | [Smallest Number With All Set Bits](https://leetcode.com/problems/smallest-number-with-all-set-bits/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3370.cpp) | O(log N) | O(1) | [Note](#3370-smallest-number-with-all-set-bits) |
| 3827 | [Count Monobit Integers](https://leetcode.com/problems/count-monobit-integers/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3827.cpp) | O(1) | O(1) | [Note](#3827-count-monobit-integers) |

---

> 0029.[Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)<br>
> 此題是處理邊界的魔王題，這一題網路上掛一片，大部分偷用long long<br>
> 溢位處理有許多常見的解法，如 [meyr543](https://hackmd.io/@meyr543/rkSRWnXPK), [grandyang](https://www.cnblogs.com/grandyang/p/4741122.html),[doocs](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0260.Single%20Number%20III/Solution.cpp),[BylwiCXPt](https://hackmd.io/@Inversionpeter/BylwiCXPt)<br>
> 使用 'unsigned',`long long` 來處理 `INT_MIN` 的溢位，這在工程上屬於一種 **Workaround**<br>
---

### 0089 Gray Code
> [Gray Code](https://leetcode.com/problems/gray-code/)<br>
> 數字i的Gray code為 **i ⊕ (i >> 1)** <br>

---


### 0137-2. Single Number II
> [Single Number II](https://leetcode.com/problems/single-number-ii)<br>
> **int one = 0, two = 0;** <br>
> **for(const int& num : nums) {** <br>
> &emsp;&emsp;&emsp;&emsp;**one = one^num & ~two;** <br>
> &emsp;&emsp;&emsp;&emsp;**two = two^num & ~one;** <br>
> **}** <br>
> return one;** <br>
> 此題有三種解法，位元有限狀態機是最佳解<br>
---


### 0190 Reverse Bits
> [Reverse Bits](https://leetcode.com/problems/reverse-bits)<br>
> 記得 for(int i = 1; i <= 32; i++) <br>

---


> 0260.[Single Number III](https://leetcode.com/problems/single-number-iii) 
>  是 Bit Manipulation 經典題目，目前只有**neetcode.io**有最佳解<br>

---

### 0371 Find the Difference
> [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers) <br>
> **while(b != 0) {** <br>
> &emsp;&emsp;&emsp;&emsp;**int carry = (a  & b) << 1;** <br>
> &emsp;&emsp;&emsp;&emsp;**a = a ^ b; b = carry;** <br>
> **}** <br>
> **return a;** <br>
> 同 2235.  [Add Two Integers](https://leetcode.com/problems/add-two-integers) <br>

---

### 0389 Find the Difference
> [Find the Difference](https://leetcode.com/problems/find-the-difference/) <br>
> 起一個vector<int> seen(26, 0)紀錄s的每個lowercase char，尋訪t的每個lowercase char，如果seen[c - 'a']已經是0，return char<br>

---


### 0476 Number Complement
> [Number Complement](https://leetcode.com/problems/number-complement)<br>
> temp = num， while(temp > 0)，mask Or 1 一直左移動，最後mask ^ num<br>
> [476 Number Complement](./solution/Solution_0476.cpp)和[1009 Complement of Base 10 Integer](./solution/Solution_1009.cpp)<br>
> 本質上是相同的題目。<br>
---

### 0762 Prime Number of Set Bits
> [Prime Number of Set Bits](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/)<br>
> 對於範圍在 [1, 1e6] 的數字，其二進位長度最多不超過 20 位（因為 2^20 > 1e6) <br>
> isPrime只要判斷 if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19) <br>
> [left , right]範圍內 int bits = __builtin_popcount(i); if(isPrime(bits)) count++;<br>
---

### 1009 Complement of Base 10 Integer
> [Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer) <br>
> temp = n， while(temp > 0)，mask Or 1 一直左移動，最後mask ^ n，比476那一題多 **if(n == 0) return 1;** <br>

---

### 1684 Count the Number of Consistent Strings
> [Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings)<br>
> 先用一個int mask 紀錄哪些字元出現過(| 1 << c-'a')，檢查每個string的每個char(1 << c-'a')和msk &，為0則是沒有在字典中<br>
> 為什麼選擇 int mask 而非 bitset？
> int (或 long) 的運算直接對應 CPU 的暫存器指令，在這種極小範圍 (26 bits) 的情況下，它的運算速度幾乎是瞬間完成，且不需要引入額外的標頭檔 (<bitset>)，代碼更簡潔。<br>
---


### 2032 Two Out of Three
> [Two Out of Three](https://leetcode.com/problems/two-out-of-three/)<br>
> 起一組vector<int> counts(101, 0)，nums1 數字 counts[num] |= 1，nums2 數字 counts[num] |= 2，nums3 數字 counts[num] |= 4<br>
> 因為三組陣列都有可能有重覆值，OR 就不用考慮重覆，最後算if (popcount((unsigned int)counts[i]) >= 2) res.push_back(i);<br>

---


### 2235 Add Two Integers
> [Add Two Integers](https://leetcode.com/problems/add-two-integers) <br>
> **while(num2 != 0) {** <br>
> &emsp;&emsp;&emsp;&emsp;**unsigned int carry = (num1  & num2) << 1;** <br>
> &emsp;&emsp;&emsp;&emsp;**num1 = num1 ^ num2;** <br>
> &emsp;&emsp;&emsp;&emsp;**num2 = carry;** <br>
> **}** <br>
> **return num1; ** <br>
> 同 0371. [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers)  <br>


### 2716 Minimize String Length
> [Minimize String Length](https://leetcode.com/problems/minimize-string-length/)<br>
> 就是計算相異字元個數，用bitset<26> bits紀錄，最後回傳 bits.count()<br>
---

### 2917 Single Number
> [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array)<br>
> **for(int i = 0; i < 32; i++) {** <br>
> &emsp;&emsp;&emsp;&emsp;**int count = 0;** <br>
> &emsp;&emsp;&emsp;&emsp;**for(const int& num : nums) count += (num >> i) & 1** <br>
> &emsp;&emsp;&emsp;&emsp;**if(count >= k) res |= 1 << i;** <br>
> **}**  <br>
---

### 3120 Count the Number of Special Characters I
> [Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/)<br>
> 要記錄char大小寫都有出現的字元數
> **for(char c : word) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if(islower(c)) lower |= 1 << (c-'a');** <br>
> &emsp;&emsp;&emsp;&emsp;**if(isupper(c)) upper |= 1 << (c-'A');** <br>
> **}** <br>
> **return __builtin_popcount(lower & upper);** <br>
---

### 3151 Special Array I
> [Special Array I](https://leetcode.com/problems/special-array-i)<br>
> **邊界條件 nums.size() == 1  return true** <br>
> 相鄰兩數的lsb相同則return false<br>
> **for(int i = 0 ; i < nums.size() - 1; i++) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if((nums[i] & 1) ^ (nums[i + 1] & 1) == 0) return false;** <br>
> **}** <br>
---


### 3370 Smallest Number With All Set Bits
> [Smallest Number With All Set Bits](https://leetcode.com/problems/smallest-number-with-all-set-bits/)<br>
> int mask = ~0; while(n & mask) { mask <<= 1; } return ~mask;<br>
> [476 Number Complement](./solution/Solution_0476.cpp)和[1009 Complement of Base 10 Integer](./solution/Solution_1009.cpp)<br>
> 類似上面這兩個的題目，只是直接回傳mask。<br>
---

### 3827 Count Monobit Integers
> [Count Monobit Integers](https://leetcode.com/problems/count-monobit-integers/)<br>
> 0->1，1->2，2->2，3->3...，6->3，7->4，**等於算(n+1)的bit數目**<br>
> **return bit_width(static_cast<uint32_t>(n + 1));** <br>


<br><br>
---


## <a name="Bit-manipulation-mask"></a>📊 Bit Manipulation - Mask (位元運算 - 遮罩)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 2605 | [Form Smallest Number From Two Digit Arrays](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/) | 🟢 Easy | Bit Manipulation / Bitmask | [C++](./solution/Solution_2605.cpp) | O(N + M) | O(1) | [Note](#2605-form-smallest-number-from-two-digit-arrays) |

### 2605 Form Smallest Number From Two Digit Arrays
> [Form Smallest Number From Two Digit Arrays](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/) <br>
> **此題總共有四種作法**<br>
> [法一 int mask](./solution/Solution_2605.cpp)，Time:O(N+M)，Time:O(1)<br>
> [法二 雙迴圈暴力法](./solution/Solution_2605_1.cpp)，Time:O(N*M)，Time:O(1)<br>
> [法三 bitset](./solution/Solution_2605_2.cpp)，Time:O(N+M)，Time:O(1)<br>
> [法四 unordered_map](./solution/Solution_2605_3.cpp)，Time:O(N+M)，Time:O(M)<br>
> 因為只有0~9，兩個mask 紀錄數字出現位置，int mask1 = 0, mask2 = 0;<br>
> **for(const int& num : nums1) mask1 |= 1 << num;** <br>
> **for(const int& num : nums2) mask2 |= 1 << num;** <br>
> 如果出現相同數字，取最小的回傳，ctz是算幾個0，等於剛才紀錄的最小數
> **if(mask1 & mask2) return __builtin_ctz(mask1 & mask2);** <br>
> 如果沒有相同數字，min2 * 10 + min1 和 min1 * 10 + min2;，取小的回傳<br>
> **int min1 = __builtin_ctz(mask1);** <br>
> **int min2 = __builtin_ctz(mask2);** <br>
> **return (min1 > min2) ? min2 * 10 + min1 : min1 * 10 + min2;** <br>



<br><br>
---

## <a name="Bit-manipulation-or"></a>📊 Bit Manipulation - OR operation (位元運算 - 或運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1318** | [Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_1318.cpp) | O(1) | O(1) | [Note](#1318-minimum-flips-to-make-a-or-b-equal-to-c) |
| **2917** | [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2917.cpp) | O(N * log(max_val)) | O(1) | [Note](#2917-find-the-k-or-of-an-array) |
| 2980 | [Check if Bitwise OR Has Trailing Zeros](https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/) | 🟢 Easy | Bit Manipulation <br> Math | [C++](./solution/Solution_2980.cpp) | O(N) | O(1) | [Note](#2980-check-if-bitwise-or-has-trailing-zeros) |
| 3688 | [Bitwise OR of Even Numbers in an Array](https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3688.cpp) | O(N) | O(1) | [Note](#3688-bitwise-or-of-even-numbers-in-an-array) |

### 1318 Minimum Flips to Make a OR b Equal to c
> [Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/)<br>
> **int diff = (a | b) ^ c;** <br>
> **int flips = __builtin_popcount(diff & ~c) + __builtin_popcount(a & b & diff);** <br>

---


### 2917 Find the K-or of an Array
> [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array)<br>
> 起回圈i = 0到31 <br>
> count = 0，travsal 每個數，(num >> i) & 1加到count<br>
> 如果count >= k， res |= (1<<i)<br>
---


### 2980 Check if Bitwise OR Has Trailing Zeros
> [Check if Bitwise OR Has Trailing Zeros](https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/)<br>
> travsal nums，出現兩個even number，return true<br>

---

### 3688 Bitwise OR of Even Numbers in an Array
> [Bitwise OR of Even Numbers in an Array](https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/) <br>
> int res = 0，把所有even number OR 到res上<br>

<br><br>
---

## <a name="Bit-manipulation-and"></a>📊 Bit Manipulation - AND operation (位元運算 - 及運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0191.cpp) | O(1) | O(1) | [Note](#0191-number-of-1-bits) |
| 0201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0201.cpp) | O(logn) | O(1) | [Note](#0201-bitwise-and-of-numbers-range)|
| 0338 | [Counting Bits](https://leetcode.com/problems/counting-bits) | 🟢 Easy | DP <br> Bit Manipulation | [C++](./solution/Solution_0338.cpp) | O(n) | O(n) | [Note](#0338-counting-bits) |
| 0693 | [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0693.cpp) | O(1) | O(1) | [Note](#0693-binary-number-with-alternating-bits) |

### 0191 Number of 1 Bits
> [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits)<br>
> 使用 **Brian Kernighan's Algorithm** ，**n = n & (n - 1)**，有 build in function可以用<br>
> **(1)** C++20，std::popcount(static_cast<unsigned int>(n)) 或  **(2)** 若編譯器(GCC/Clang)支援， __builtin_popcount(n) <br>
---

### 0201 Bitwise AND of Numbers Range
> [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range)<br>
> 使用 **Brian Kernighan's Algorithm** ，**right = right & (right - 1)**， while(right > left) <br>
---

### 0338 Counting Bits
> [Counting Bits](https://leetcode.com/problems/counting-bits)<br>
> **Brian Kernighan's Algorithm** ，**n & (n - 1)，其實是去掉最右邊的1**<br>
> vector<int> count(n + 1, 0);<br>
> for(int i = 1; i <= n; i++) count[i] = count[i & (i - 1)] + 1;<br>


### 0693 Binary Number with Alternating Bits
> [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/)<br>
> n先mod 4等於t，檢查11(t & 3) == 3，檢查00(t ^ 3) == 3，符合就回傳false<br>
---

<br><br>
---

## <a name="Bit-manipulation-xor"></a>📊 Bit Manipulation - XOR operation (位元運算 - 互斥或運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0136 | [Single Number](https://leetcode.com/problems/single-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0136.cpp) | O(n) | O(1) | [Note](#0136-single-number) |
| **0260** | [Single Number III](https://leetcode.com/problems/single-number-iii) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0260.cpp) | O(n) | O(1) | [Note](#0260-single-number-iii)
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0268_2.cpp) | O(n) | O(1) | [Note](#0268-missing-number) |
| **2317** | [Maximum XOR After Operations](https://leetcode.com/problems/maximum-xor-after-operations) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_2317.cpp) | O(n) | O(1) | [Note](#2317-maximum-xor-after-operations) |
| 2425 | [Bitwise XOR of All Pairings](https://leetcode.com/problems/bitwise-xor-of-all-pairings/) | 🟡 Medium | Bit Manipulation / Math | [C++](./solution/Solution_2425.cpp) | O(N + M) | O(1) | [Note](#2425-bitwise-xor-of-all-pairings) |
| 2429 | [Minimize XOR](https://leetcode.com/problems/minimize-xor/) | 🟡 Medium | Bit Manipulation / Greedy | [C++](./solution/Solution_2429.cpp) | O(1) | O(1) | [Note](#2429-minimize-xor) |
| 3158 | [Find the XOR of Numbers Which Appear Twice](https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/) | 🟢 Easy | Bit Manipulation / Array | [C++](./solution/Solution_3158.cpp) | O(N) | O(1) | |

### 0136 Single Number
> [Single Number](https://leetcode.com/problems/single-number)<br>
> 所有num出現兩次，目標num出現一次，全部的數字XOR起來就是答案<br>

---

### 0260 Single Number III
> [Single Number III](https://leetcode.com/problems/single-number-iii) <br>
> 兩數出現1次，其他出現兩次，xor_ab等於所有數XOR的結果<br>
> 算diff_bit，為a和b比較大的數的MSB，int diff_bit = 1;  while((xor_ab & diff_bit) == 0)  diff_bit <<= 1;<br>
> 再travsal nums，如果num和diff_bit AND > 0，num XOR 到a，否則b<br>

---

### 0268 Missing Number
> [Missing Number](https://leetcode.com/problems/missing-number) <br>
> for loop 從0 ~ (size - 1) ， missing ^= (i + 1) ^ nums[i]<br>

---


### 2317 Maximum XOR After Operations
> [Maximum XOR After Operations](https://leetcode.com/problems/maximum-xor-after-operations) <br>
> 所有元素之間AND，再把所有結果XOR，等於所有元素直接OR

---

### 2425 Bitwise XOR of All Pairings
> [Bitwise XOR of All Pairings](https://leetcode.com/problems/bitwise-xor-of-all-pairings/) <br>
> xor1 = 0 ， xor2 = 0，
> 如果nums1 size是奇數，把所有nums2的element xor到 xor2<br>
> 如果nums2 size是奇數，把所有nums1的element xor到 xor1<br>
> 回傳 xor1 ^ xor2<br>
---

### 2429 Minimize XOR
> [Minimize XOR](https://leetcode.com/problems/minimize-xor/) <br>
> 要找一個和num2 set bit樹目相等，且和num2 XOR 最小的數<br>
> 先計算bits數目，int bits = __builtin_popcount(num2);<br>
> 起一個 int res，把num1 有1的先set到res，bits一邊減<br>
> 把剩下的bits由低到高set到res<br>
---


<br><br>
---


## <a name="Hamming Distance"></a>📊 Bit Manipulation - Hamming Distance (位元運算 漢明距離)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0461.cpp) | O(k) | O(1) | [Note](#0461-hamming-distance) |
| 2220 | [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2220.cpp) | O(log(max(start, goal))) | O(1) | [Note](#2220-minimum-bit-flips-to-convert-number) |
| **3226** | [Number of Bit Changes to Make Two Integers Equal](https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3226.cpp) | O(1) | O(1) | [Note](#3226-number-of-bit-changes-to-make-two-integers-equal) |
| 3750 | [Minimum Number of Flips to Reverse Binary String](https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3750.cpp) | O(log N) | O(1) | [Note](#3750-minimum-number-of-flips-to-reverse-binary-string) |

### 0461 Hamming Distance
> [Hamming Distance](https://leetcode.com/problems/hamming-distance)<br>
> x和y做互斥或成為z，取z的2進制1的個數<br>

---

### 2220 Minimum Bit Flips to Convert Number
> [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number) <br>
> x和y做互斥或成為z，取z的2進制1的個數<br>
> start和goal做互斥或成為n，取n的2進制1的個數<br>
<br><br>
---

### 3226 Number of Bit Changes to Make Two Integers Equal
> [Number of Bit Changes to Make Two Integers Equal](https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/) <br>
> **先確認k是n的binary子集合，也就是 n&k == k，如果沒有return -1**<br>
> 接下來找n和k的hamming distance(n ^ k找1的個數)，回傳結果<br>

---

### 3750 Minimum Number of Flips to Reverse Binary String
> [Minimum Number of Flips to Reverse Binary String](https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/)<br>
> 先求binary string的reverse，取n和reverse的Hamming Distance<br>

<br><br>
---


## <a name="string"></a>🔗 String (字串)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **0008** | [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi) | 🟡 Medium | String <br> Math | [C++](./solution/Solution_0008.cpp) | O(N) | O(1) | [Note](#0008-string-to-integer-atoi) |
| 0014 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 Easy | String <br> Trie | [C++](./solution/Solution_0014.cpp) | O(S) | O(1) | [Note](#0014-longest-common-prefix) |
| **0043** | [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | 🟡 Medium | Math / String | [C++](./solution/Solution_43.cpp) | O(M * N) | O(M + N) | |
| 0058 | [Length of Last Word](https://leetcode.com/problems/length-of-last-word) | 🟢 Easy | String | [C++](./solution/Solution_0058.cpp) | O(n) | O(1) | [Note](#0058-length-of-last-word) |
| **0151** | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_0151.cpp) | O(N) | O(N) |
| 0434 | [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string) | 🟢 Easy | String | [C++](./solution/Solution_0434.cpp) | O(N) | O(1) | [Note](#0434-number-of-segments-in-a-string) |
| **0648** | [Replace Words](https://leetcode.com/problems/replace-words/) | 🟡 Medium | Hash Table <br> Sorting | [C++](./solution/Solution_0648_2.cpp) | O(N * L + M * K) | O(D * L) |  |
| 0944 | [Delete Columns to Make Sorted](https://leetcode.com/problems/delete-columns-to-make-sorted/) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_0944.cpp) | O(N * M) | O(M) | [Note](#0944-delete-columns-to-make-sorted) |
| 1078 | [Occurrences After Bigram](https://leetcode.com/problems/occurrences-after-bigram/) | 🟢 Easy | String Parsing | [C++](./solution/Solution_1078.cpp) | O(N) | O(N) | [Note](#1078-occurrences-after-bigram) |
| 1108 | [Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/) | 🟢 Easy | String | [C++](./solution/Solution_1108.cpp) | O(N) | O(N) | |
| 1455 | [Check If a Word Occurs As a Prefix](https://leetcode.com/problems/check-if-word-occurs-as-a-prefix-of-any-word-in-a-sentence/) | 🟢 Easy | String / Stream | [C++](./solution/Solution_1455.cpp) | O(N) | O(W) | |
| 1528 | [Shuffle String](https://leetcode.com/problems/shuffle-string) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_1528.cpp) | O(N) | O(N) | [Note](#1528-shuffle-string) |
| 1592 | [Rearrange Spaces Between Words](https://leetcode.com/problems/rearrange-spaces-between-words/) | 🟢 Easy | String / Simulation |  [C++](./solution/Solution_1592.cpp)  | O(N) | O(N) | |
| 1758 | [Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string) | 🟢 Easy | String | [C++](./solution/Solution_1758.cpp) | O(N) | O(1) | [Note](#1758-minimum-changes-to-make-alternating-binary-string) |
| 1790 | [Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/) | 🟢 Easy | String / Simulation | [C++](./solution/Solution_1790.cpp) | O(N) | O(1) | [Note](#1790-check-if-one-string-swap-can-make-strings-equal) |
| 1910 | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/) | 🟡 Medium | Stack / String | [C++](./solution/Solution_1910.cpp) | O(N * M) | O(N) | [Note](#1910-remove-all-occurrences-of-a-substring) |
| 2042 | [Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence) | 🟢 Easy | String <br> Parsing | [C++](./solution/Solution_2042.cpp) | O(n) | O(1) | [Note](#2042-check-if-numbers-are-ascending-in-a-sentence) |
| 2114 | [Maximum Number of Words Found in Sentences](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_2114.cpp) | O(N * M) | O(1) | [Note](#2114-maximum-number-of-words-found-in-sentences) |
| 2243 | [Calculate Digit Sum of a String](https://leetcode.com/problems/calculate-digit-sum-of-a-string/) | 🟢 Easy | Simulation / String | [C++](./solution/Solution_2243.cpp) | O(N * log N) | O(N) | |
| 2255 | [Count Prefixes of a Given String](https://leetcode.com/problems/count-prefixes-of-a-given-string/) | 🟢 Easy | String / Simulation | [C++](./solution/Solution_2255.cpp) | O(N * M) | O(1) | [Note](#2255-count-prefixes-of-a-given-string) |
| 2264 | [Largest 3-Same-Digit Number in String](https://leetcode.com/problems/largest-3-same-digit-number-in-string) | 🟢 Easy | String | [C++](./solution/Solution_2264.cpp) | O(N) | O(1) | [Note](#2264-largest-3-same-digit-number-in-string) |
| **2460** | [Apply Operations to an Array](https://leetcode.com/problems/apply-operations-to-an-array) | 🟢 Easy | Array <br> Simulation | [C++](./solution/Solution_2460.cpp) | O(N) | O(1) |
| 2490 | [Circular Sentence](https://leetcode.com/problems/circular-sentence) | 🟢 Easy | String | [C++](./solution/Solution_2490.cpp) | O(N) | O(1) | [Note](#2490-circular-sentence) |
| 2828 | [Check if a String Is an Acronym of Words](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_2828.cpp) | O(n) | O(1) | [Note](#2828-check-if-a-string-is-an-acronym-of-words) |
| 2937 | [Make Three Strings Equal](https://leetcode.com/problems/make-three-strings-equal/) | 🟢 Easy | String | [C++](./solution/Solution_2937.cpp) | O(min(L1, L2, L3)) | O(1) | [Note](#2937-make-three-strings-equal) |
| 2942 | [Find Words Containing Character](https://leetcode.com/problems/find-words-containing-character/) | 🟢 Easy | String Search | [C++](./solution/Solution_2942.cpp) | O(N * L) | O(1) | [Note](#2942-find-words) |
| 3210 | [Find the Encrypted String](https://leetcode.com/problems/find-the-encrypted-string/) | 🟢 Easy | String / Cyclic Shift | [C++](./solution/Solution_3210.cpp) | O(N) | O(N) | |
| 3280 | [Convert Date to Binary](https://leetcode.com/problems/convert-date-to-binary/) | 🟢 Easy | String Manipulation / Bit Format | [C++](./solution/Solution_3280.cpp) | O(1) | O(1) | |
| 3304 | [Find the K-th Character in String Game I](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/) | 🟢 Easy | Simulation / Recursion | [C++](./solution/Solution_3304.cpp) | O(K) | O(K) | [Note](#3304-kth-char) |
| 3407 | [Substring Matching Pattern](https://leetcode.com/problems/substring-matching-pattern/) | 🟢 Easy | String / Pattern Matching | [C++](./solution/Solution_3407.cpp) | O(N + M) | O(M) ||
| 3456 | [Find Special Substring of Length K](https://leetcode.com/problems/find-special-substring-of-length-k/description/) | 🟢 Easy | String / Block-Skipping | [C++](./solution/Solution_3456.cpp)| O(N) | O(1) ||
| 3498 | [Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string) | 🟢 Easy | Math <br> String | [C++](./solution/Solution_3498.cpp) | O(n) | O(1) | [Note](#3498-reverse-degree-of-a-string) |


### 0008. String to Integer (atoi)
> [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi)<br>
> 處裡多餘空白，while(i < n && s[i] == ' ') i++;<br>
> 處裡正負號，int sign = 1;  if(s[i] == '+' || s[i] == '-' ) sign = (s[i++] == '+') ? 1 : -1;<br>
> while(i < n && isdigit(s[i])) {<br>
> int digit = s[i++] - '0';<br>
> if(res > (INT_MAX - digit) / 10) return sign == 1 ? INT_MAX : INT_MIN;<br>
> res = res * 10 + digit;<br>
} <br>
---

### 0014. Longest Common Prefix
> [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix)<br>
> 外迴圈i從0到strs[0].size()-1，內層迴圈j從 1 ~ strs.size()<br>
> 如果比較的字串比較長 strs[j].size() < i或是發現第i個char不一樣(strs[j][i] != strs[0][i]<br>
> return strs[0].substr(0, i);<br>
> 或最後  return strs[0];<br>
---

### 0058. Length of Last Word
> [Length of Last Word](https://leetcode.com/problems/length-of-last-word) <br>
> 頭尾都有可能有空白<br>
> 先把right調過尾巴的空白，指到最後一個word的最後一個char，while (right >= 0 && s[right] == ' ') {right--;}<br>
> 開始算最後一組word長度，while (right >= 0 && s[right] != ' ') { right--; length++;}<br>
---



### 0434. Number of Segments in a String
> [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string) <br>
> 第一次開頭也要算segment，char lastChar = ' ';<br>
> 上一個char是空白，這個char不是空白就count++，for(char c : s) if(c != ' ' && lastChar == ' ')  count++;<br>

---

### 0648. Replace Words
> [Replace Words](https://leetcode.com/problems/replace-words/)<br>
> 最佳解是用Trie<br>


---

### 0944. Delete Columns to Make Sorted
> [Delete Columns to Make Sorted](https://leetcode.com/problems/delete-columns-to-make-sorted/)<br>
> 外迴圈i為column(string的第幾個char) 0 ~ cols，內迴圈j為row(第幾個string) 1 ~ rows<br>
> 發現前面string第i個char比後面string第i個char大，bitset那個位置，往下一個char檢查，if(strs[j-1][i] > strs[j][i]) { bits.set(i);  break;}
> **return static_cast<int>(bits.count())** <br>

---

### 1078. Occurrences After Bigram
> [Occurrences After Bigram](https://leetcode.com/problems/occurrences-after-bigram/)<br>
> 用istringstream拆解text成為vector<string> words;<br>
> **for(int i = 0; i < words.size() - 2; i++) {** <br>
> &emsp;&emsp;&emsp;&emsp;> &emsp;&emsp;&emsp;&emsp;**if(words[i] == first && words[i + 1] == second) res.push_back(words[i + 2]);** <br>
> **}** <br>


---



### 1528. Shuffle String
> [Shuffle String](https://leetcode.com/problems/shuffle-string)<br>
> **string res(s.size(), ' ');** <br>
> **for(int i = 0 ; i < s.size(); i++) res[indices[i]] = s[i];** <br>

---

### 1758. Minimum Changes To Make Alternating Binary String
> [Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string)<br>
> **for(int i = 0 ; i < s.size(); i++) if(i % 2 == s[i]-'0') count++;** <br>
> **return min(count, static_cast<int>(s.size()) - count);** <br>

---


### 1790. Check if One String Swap Can Make Strings Equal
> [Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)<br>
> 找出限定一個character swap，兩字串能否相等<br>
> 如果兩字串長度不一樣，return false<br>
> 直接比較兩字串相同index之character，放入vector<pair<char, char>> diff;<br>
> 比較期間，如果diff大小超過2，表示無法緊用一次swap，return false<br>
> 最後產生兩種結果，一種是兩字串已經相等，一種是((diff.size() == 2) && (diff[0].first == diff[1].second) && (diff[0].second == diff[1].first));<br>
---


### 1910. Remove All Occurrences of a Substring
> [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/)<br>
> 先算part的size，int k = part.size();<br>
> 把souce string s 每個ch 慢慢加到 res<br>
> 每次加到res，如果res長度大於等於k，則比對尾巴字串，if (res.size() >= k && res.compare(res.size() - k, k, part) == 0) <br>
> res.resize，比string erase效率高<br>
---


### 2042.Check if Numbers Are Ascending in a Sentence
> [Check if Numbers Are Ascending in a Sentence](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence)<br>
> 用一個 istringstream iss(s)<br>
> **while(iss >> word) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if(isdigit(word[0])) {** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**int num = stoi(word);** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**if(num <= prev) return false;** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**prev = num;** <br>
> &emsp;&emsp;&emsp;&emsp;**}** <br>
> **}** <br>

---




### 2114. Maximum Number of Words Found in Sentences
> [Maximum Number of Words Found in Sentences](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences)<br>
> 用 434. [Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string)的方法計算每個string的segment數量<br>
> mostSize = max(mostSize, segment);<br>


---


### 2255. Count Prefixes of a Given String
> [Count Prefixes of a Given String](https://leetcode.com/problems/count-prefixes-of-a-given-string/)<br>
> **for(const string& word : words) {**
> &emsp;&emsp;&emsp;&emsp**if(s.find(word) == 0) count++;**
> **}**


---




### 2264. Largest 3-Same-Digit Number in String
> [Largest 3-Same-Digit Number in String](https://leetcode.com/problems/largest-3-same-digit-number-in-string) <br>
> 先設定maxChar = 0<br>
> 檢查連續三個字元是否相等，如果相等，maxChar = max(maxChar,num[i])<br>
> return (maxChar == 0) ? "" : string(3, maxChar);<br>
> <br>


---


### 2490. Circular Sentence
> [Circular Sentence](https://leetcode.com/problems/circular-sentence) <br>
> 先檢查第一個和最後一個char是否相等，segment 1或多同時處理，if(sentence.front() != sentence.back()) return false;<br>
> travsal string中每一個char，檢查是否是 x空格x的pattern<br>

---



### 2828. Check if a String Is an Acronym of Words
> [Check if a String Is an Acronym of Words](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words) <br>
> 如果vector<string> words size和 s size不同，return false<br>
> for loop i 從 0 ~ s.size() - 1，if(words[i][0] != s[i]) return false;<br>


---


### 2937. Make Three Strings Equal
> [Make Three Strings Equal](https://leetcode.com/problems/make-three-strings-equal/)  <br>
> 跟0014.[Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix)很像，此題三字串，0014多字串
> int minLen = min({n1, n2, n3});<br>
> for(int i = 0 ; i < minLen; i++) if((s1[i] == s2[i]) && (s1[i] == s3[i])) prefix++;<br>
> 計算前綴長度 prefix，用個別長度減去前綴長度，return (n1 + n2 + n3 - prefix - prefix - prefix);<br>


---

### 2942. Find Words Containing Character
> [Find Words Containing Character](https://leetcode.com/problems/find-words-containing-character/)  <br>
> 對 vector<string> words中每個word，找尋char x是否存在，如果有，把index i push到result vector<br>

---

### 3304. Find the K-th Character in String Game I
> [Find the K-th Character in String Game I](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/) <br>
> 要return第k個char，先算iterations，int iterations = static_cast<int>(ceil(std::log2(k)));<br>
> apend 原本string到尾巴，每個char多+1，判斷如果原本是'z'，要變成'a'<br>
> **for(int j = 0; j < n; j++) {** <br>
> &emsp;&emsp;&emsp;&emsp;**char nextCh = (s[j] == 'z') ? 'a' : s[j] + 1;** <br>
> &emsp;&emsp;&emsp;&emsp;**s.push_back(nextCh);** <br>
> **}** <br>

---



### 3498. Reverse Degree of a String
> [Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string) <br>
> travsal字串 ， degree +=  (26 - (s[i] - 'a')) * (i + 1);<br>


---



<br><br>
---

## <a name="string-substring-enumeration"></a>🔗 String - Substring Enumeration (字串 子字串列舉)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1291 | [Sequential Digits](https://leetcode.com/problems/sequential-digits/) | 🟡 Medium | Brute Force / String | [C++](./solution/Solution_1291.cpp) | O(1) | O(1) | |
| 3556 | [Sum of Largest Prime Substrings](https://leetcode.com/problems/sum-of-largest-prime-substrings/) | 🟡 Medium | Math / Brute Force | [C++](./solution/Solution_3556.cpp) | O(N²*sqrt(M)) | O(1) | [Note](#3556-sum-of-largest-prime-substrings) |
| 3713 | [Longest Balanced Substring I](https://leetcode.com/problems/longest-balanced-substring-i/) | 🟡 Medium | Brute Force / Math | [C++](./solution/Solution_3713.cpp) | O(N^2) | O(1) | [Note](#3713-longest-balanced-substring) |

### 3556 Sum of Largest Prime Substrings
> [Sum of Largest Prime Substrings](https://leetcode.com/problems/sum-of-largest-prime-substrings/) <br>
> 雙層迴圈計算列出子字串，轉成數字，for(int i = 0;i < n; i++)  for(int j = i;j < n; j++) curNum = curNum * 10 + (s[j] - '0');<br>
> 如果curNum是prime，curNum更新到前三大的數，if(isPrime(curNum)) updateMax(curNum, max1, max2, max3); <br>
---

### 3713 Longest Balanced Substring I
> [Longest Balanced Substring I](https://leetcode.com/problems/longest-balanced-substring-i/) <br>
> 對於 3713. Longest Balanced Substring I，這題通常不能直接用單一的「滑動視窗」來解，原因在於它的定義要求「所有出現過的字元頻率必須相等」。<br>
> [3090 Maximum Length Substring](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/)是Sliding window的一個例子<br>
> 為什麼滑動視窗很難用在這裡？<br>
> 典型的滑動視窗（如上一題 3090）適用於「頻率上限檢查」（例如 count <= 2），當條件不滿足時，我們可以透過移動 left 來快速縮小視窗直到條件再次滿足。<br>
> 然而，「平衡」的定義要求的是「各字元頻率相等」。如果視窗內有 'a': 2, 'b': 1，當你滑動時，這個條件極不穩定。這導致你無法單純地透過移動 left 來保證平衡，因為「平衡」是一個非常脆弱的狀態。<br>

---



<br><br>
---



## <a name="string-character-classification "></a>🔗 String - Character Classification (字串 字元識別)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0520 | [Detect Capital](https://leetcode.com/problems/detect-capital/) | 🟢 Easy | String | [C++](./solution/Solution_0520.cpp) | O(N) | O(1) | [Note](#0520-detect-capital) |
| 0709 | [To Lower Case](https://leetcode.com/problems/to-lower-case) | 🟢 Easy | String | [C++](./solution/Solution_0709.cpp) | O(N) | O(1) | [Note](#0709-to-lower-case) |
| 1704 | [Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/) | 🟢 Easy | String / Bit Manipulation | [C++](./solution/Solution_1704.cpp) | O(N) | O(1) | [Note](#1704-second-largest-digit-in-a-string) |
| 1796 | [Second Largest Digit in a String](https://leetcode.com/problems/second-largest-digit-in-a-string/) | 🟢 Easy | String <br> Hash Table | [C++](./solution/Solution_1796.cpp) | O(N) | O(1) |[Note](#1796-second-largest-digit-in-a-string) |
| 1903 | [Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/) | 🟢 Easy | String | [C++](./solution/Solution_1903.cpp) | O(N) | O(1) | [Note](#1903-largest-odd-number-in-string) |
| 1957 | [Delete Characters...](https://leetcode.com/problems/delete-characters-to-make-fancy-string/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_1957.cpp) | O(N) | O(N) | |
| 2124 | [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs) | 🟢 Easy | String | [C++](./solution/Solution_2124.cpp) | O(N) | O(1) | [Note](#2124-check-if-all-as-appears-before-all-bs) |
| 2586 | [Count the Number of Vowel Strings in Range](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range) | 🟢 Easy | Array <br> String | [C++](./solution/Solution_2586.cpp) | O(n) | O(1) |
| 2678 | [Number of Senior Citizens](https://leetcode.com/problems/number-of-senior-citizens) | 🟢 Easy | String | [C++](./solution/Solution_2678.cpp) | O(n) | O(1) | [Note](#2678-number-of-senior-citizens) |
| 2710 | [Remove Trailing Zeros From a String](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/) | 🟢 Easy | String / Two Pointers |  [C++](./solution/Solution_2710.cpp) | O(N) | O(1) | [Note](#2710-check-if-a-string-is-an-acronym-of-words) |
| 3110 | [Score of a String](https://leetcode.com/problems/score-of-a-string) | 🟢 Easy | String | [C++](./solution/Solution_3110.cpp) | O(N) | O(1) |
| 3121 | [Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/) | 🟡 Medium | String Processing | [C++](./solution/Solution_3121.cpp) | O(N) | O(1) | [Note](#3121-special-chars-ii) | [Note](#3121-count-the-number-of-special-characters-ii) | 
| 3136 | [Valid Word](https://leetcode.com/problems/valid-word/) | 🟢 Easy | String / Validation | [C++](./solution/Solution_3136.cpp) | O(N) | O(1) | [Note](#3136-valid-word) |
| 3775 | [Reverse Words With Same Vowel Count](https://leetcode.com/problems/reverse-words-with-same-vowel-count/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_3775.cpp) | O(N*L) | O(N) |
| 3813 | [Vowel-Consonant Score](https://leetcode.com/problems/vowel-consonant-score/) | 🟢 Easy | String Processing | [C++](./solution/Solution_3813.cpp) | O(N) | O(1) | |
| 3856 | [Trim Trailing Vowels](https://leetcode.com/problems/trim-trailing-vowels/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_3856.cpp) | O(N) | O(1) | [Note](#3856-trim-trailing-vowels) |
| 3931 | [Check Adjacent Digit Differences](https://leetcode.com/problems/check-adjacent-digit-differences/) | 🟢 Easy | String <br> Math | [C++](./solution/Solution_3931.cpp) | O(N) | O(1) |


### 0520. Detect Capital
> [Detect Capital](https://leetcode.com/problems/detect-capital/) <br>
> count計算uppercase個數<br>
> 全部小寫 count == 0，全部大寫 count == word.size()，第一個char大寫 count == 1 && isupper(word[0])<br>

---


### 0709. To Lower Case
> [To Lower Case](https://leetcode.com/problems/to-lower-case) <br>
> **for(char& c : s ) if(isupper(c)) c += 32;** <br>

---

### 1704. Second Largest Digit in a String
> [Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)<br>
> isVowel函數回傳是否大小寫Vowel，countVowels回傳一個string裡面有多少個Vowel<br>
> 最後檢查左半子字串和右半子字串是否相等，**return countVowels(s.substr(0, mid)) == countVowels(s.substr(mid));** <br>

---


### 1796. Second Largest Digit in a String
> [Second Largest Digit in a String](https://leetcode.com/problems/second-largest-digit-in-a-string/) <br>
> 可能有重覆的數<br>
> **if(digit > large) { second = large; large = digit;}** <br>
> **else if( **digit < large** && digit > second) { second = digit;}** <br>
                
---


### 1903. Largest Odd Number in String
> [Largest Odd Number in String](https://leetcode.com/problems/largest-odd-number-in-string/) <br>
> 一直檢查最後一個digit是否是odd<br>
> for(int i = num.size() - 1; i >= 0; i--) if(num[i] & 1) return num.substr(0, i + 1);<br>

---

### 2124. Check if All A's Appears Before All B's
> [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs)<br>
> 檢查是否存在"ba"的case，如果有，return false<br>
> **return s.find("ba") == string::npos;** <br>


---

### 2678. Number of Senior Citizens
> [Number of Senior Citizens](https://leetcode.com/problems/number-of-senior-citizens)  <br>
> Index 11和12是age <br>
> int age = 10 * (detail[11] - '0') + (detail[12] - '0');<br>
> if( age > 60) citizens++;<br>

---

### 2710. Check if a String Is an Acronym of Words
> [Remove Trailing Zeros From a String](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/)<br>
> 類似 3856[Trim Trailing Vowels](https://leetcode.com/problems/trim-trailing-vowels/) <br>
> **while (!num.empty() && num.back() == '0'){** <br>
> &emsp;&emsp;&emsp;&emsp;**num.pop_back();** <br>
> **}** <br>


---


### 3121. Count the Number of Special Characters II
> [Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/)  <br>
> 用一組vector紀錄26個大小寫char出現的位置vector<pair<int, int>> indices(26, {-1, -1});<br>
> 大寫紀錄最左邊，小寫紀錄最右邊<br>
> 最後count計算所有char，小寫index在大寫前面(小於)

---




### 3136. Valid Word
> [Valid Word](https://leetcode.com/problems/valid-word/) <br>
> 如果是數字continue， if(isdigit(c)) continue<br>
> 如果是大小寫字母，代入isVowel，計數vowel或consonant<br>
> 不是前兩種，return false<br>
> 最後 (vowel >= 1) && (consonant >= 1)<br>

---

### 3856. Trim Trailing Vowels
> [Trim Trailing Vowels](https://leetcode.com/problems/trim-trailing-vowels/) <br>
> 類似 [Remove Trailing Zeros From a String](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/)<br>
> while loop檢查 s.back()是不是Vowel，如果是，移除<br>
> **while (!s.empty() && isVowel(s.back())) {** <br>
> **&emsp;&emsp;&emsp;&emsp;s.pop_back();** <br>
> **}** <br>


---


<br><br>
---



## <a name="string-substring"></a>🔗 String - Substring (字串 子字串)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0796 | [Rotate String](https://leetcode.com/problems/rotate-string) | 🟢 Easy | String | [C++](./solution/Solution_0796.cpp) | O(N) | O(N) | [Note](#0796-rotate-string) |
| **0833** | [Find And Replace in String](https://leetcode.com/problems/find-and-replace-in-string/) | 🟡 Medium | String | [C++](./solution/Solution_833.cpp) | O(N+M*K) | O(N) |
| 1967 | [Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/) | 🟢 Easy | String / Search | [C++](./solution/Solution_1967.cpp) | O(N * M * K) | O(1) | [Note](#1967-number-of-strings-that-appear-as-substrings-in-word) |
| 3083 | [Existence of a Substring in a String and Its Reverse](https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_3083.cpp) | O(N) | O(1) |



### 0796. Rotate String
> [Rotate String](https://leetcode.com/problems/rotate-string) <br>
> **return (s + s).find(goal) != string::npos;** <br>

---

### 1967. Number of Strings That Appear as Substrings in Word
> [Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/) <br>
> 用word去find vector<string> patterns<br>

---

<br><br>
---


## <a name="string-kmp"></a>🔗 String - Knuth Morris Pratt (字串 KMP)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0028 | [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string) | 🟢 Easy | String <br> KMP | [C++](./solution/Solution_0028.cpp) | O(N * M) | O(1) |
| 0459 | [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern) | 🟢 Easy | String <br> KMP | [C++](./solution/Solution_0459.cpp) | O(n) | O(n) |

<br><br>
---

## <a name="array"></a>🍱 Array (陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0054 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | 🟡 Medium | Array / Simulation | [C++](./solution/Solution_0054.cpp) | O(M*N) | O(1) | 
| 0057 | [Insert Interval](https://leetcode.com/problems/insert-interval) | 🟡 Medium | Array <br> Interval | [C++](./solution/Solution_0057.cpp) | O(N) | O(N) |
| 0059 | [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | 🟡 Medium | Array / Simulation | [C++](./solution/Solution_0059.cpp) | O(N²) | O(1) |
| 0189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | 🟡 Medium | Array | [C++](./solution/Solution_0189.cpp) | O(n) | O(1) |
| 0717 | [1-bit and 2-bit Characters](https://leetcode.com/problems/1-bit-and-2-bit-characters/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_0717.cpp) | O(N) | O(1) | 
| 0821 | [Shortest Distance to a Character](https://leetcode.com/problems/shortest-distance-to-a-character/) | 🟢 Easy | Two-Pass Scan | [C++](./solution/Solution_0821.cpp) | O(N) | O(1) | |
| 0896 | [Monotonic Array](https://leetcode.com/problems/monotonic-array) | 🟢 Easy | Array | [C++](./solution/Solution_0896.cpp) | O(N) | O(1) |
| 1299 | [Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side) | 🟢 Easy | Array | [C++](./solution/Solution_1299.cpp) | O(N) | O(1) |
| 1304 | [Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/) | 🟢 Easy | Math / Array | [C++](./solution/Solution_1304.cpp) | O(N) | O(1) | markdown[Note](#1304-find-n-unique-integers-sum-up-to-zero) |
| 1389 | [Create Target Array in the Given Order](https://leetcode.com/problems/create-target-array-in-the-given-order/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_1389.cpp) | O(N²) | O(N) |
| 1470 | [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/) | 🟢 Easy | Array | [C++](./solution/Solution_1470.cpp) | O(N) | O(N) |
| 1550 | [Three Consecutive Odds](https://leetcode.com/problems/three-consecutive-odds/) | 🟢 Easy | Array | [C++](./solution/Solution_1550.cpp) | O(N) | O(1) | [Note](#1550-three-consecutive-odds) |
| 1662 | [Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent) | 🟢 Easy | String <br> Array | [C++](./solution/Solution_1662.cpp) | O(N+ M) | O(1) |
| 1752 | [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated) | 🟢 Easy | Array | [C++](./solution/Solution_1752.cpp) | O(N) | O(1) |
| 1800 | [Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum) | 🟢 Easy | Array | [C++](./solution/Solution_1800.cpp) | O(N) | O(1) |
| 1844 | [Replace All Digits with Characters](https://leetcode.com/problems/replace-all-digits-with-characters/) | 🟢 Easy | In-place Manipulation | [C++](./solution/Solution_1844.cpp) | O(N) | O(1) | [Note](#1844-replace-digits) |
| 1913 | [Maximum Product Difference Between Two Pairs](https://leetcode.com/problems/maximum-product-difference-between-two-pairs) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_1913.cpp) | O(N) | O(1) |
| 1929 | [Concatenation of Array](https://leetcode.com/problems/concatenation-of-array) | 🟢 Easy | Array | [C++](./solution/Solution_1929.cpp) | O(N) | O(1)* |
| 2089 | [Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/) | 🟢 Easy | Array <br> Counting | [C++](./solution/Solution_2089.cpp) | O(N) | O(1) |
| 2148 | [Count Elements With Strictly Smaller and Greater Elements](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_2148.cpp) | O(N) | O(1) |
| 3925 | [Concatenate Array With Reverse](https://example.com/problems/3925) | 🟢 Easy | Array <br> Simulation | [C++](./solution/Solution_3925.cpp) | O(N) | O(N) |
| 3969 | Valid Subarrays With Matching Sum Digits I | 🟢 Easy | Array / Brute Force | [C++](./solution/Solution_3969.cpp) | O(N^2) | O(1) | |

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

<br><br>
---

## <a name="array-continuous-counting"></a>🍱 Array - Continuous Counting (陣列 連續計數)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0485 | [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones) | 🟢 Easy | Array | [C++](./solution/Solution_0485.cpp) | O(N) | O(1) |
| 1446 | [Consecutive Characters](https://leetcode.com/problems/consecutive-characters/) | 🟢 Easy | String | [C++](./solution/Solution_1446.cpp) | O(N) | O(1) | |
| 1759 | [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/) | 🟢 Medium | Math / String | N/A | O(N) | O(1) | |

<br><br>
---

## <a name="array-continuous-counting"></a>🍱 Array - Dual Counter Switch (陣列 雙計數切換)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1869 | [Longer Contiguous Segments of Ones than Zeros](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/) | 🟢 Easy | Simulation / Linear Scan | N/A | O(N) | O(1) | |
| 2609 | [Find the Longest Balanced Substring](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/) | 🟢 Easy | Greedy / Two Counters | N/A | O(N) | O(1) | |

<br><br>
---


## <a name="array-linear-scan"></a>🍱 Array - Linear Scan (陣列 線性掃描)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0414 | [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/) | 🟢 Easy | Array | [C++](./solution/Solution_414.cpp) | O(N) | O(1) |
| 1431 | [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) | 🟢 Easy | Array | [C++](./solution/Solution_1431.cpp) | O(N) | O(1)* |
| 1848 | [Minimum Distance to the Target Element](https://leetcode.com/problems/minimum-distance-to-the-target-element/) | 🟢 Easy | Array <br> Simulation | [C++](./solution/Solution_1848.cpp) | O(N) | O(1) |
| 2057 | [Smallest Index With Equal Value](https://leetcode.com/problems/smallest-index-with-equal-value/) | 🟢 Easy | Array | [C++](./solution/Solution_2057.cpp) | O(N) | O(1) |
| 2239 | [Find Closest Number to Zero](https://leetcode.com/problems/find-closest-number-to-zero) | 🟢 Easy | Array | [C++](./solution/Solution_2239.cpp) | O(N) | O(1) |
| 2643 | [Row With Maximum Ones](https://leetcode.com/problems/row-with-maximum-ones/) | 🟢 Easy | Matrix / Linear Scan | [C++](./solution/Solution_2643.cpp) | O(M * N) | O(1) |  |
| 2733 | [Neither Minimum nor Maximum](https://leetcode.com/problems/neither-minimum-nor-maximum/) | 🟢 Easy | Math / Array | [C++](./solution/Solution_2733.cpp) | O(N) | O(1) |  |
| 3168 | [Minimum Number of Chairs](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/) | 🟢 Easy | Simulation | [C++](./solution/Solution_3168.cpp) | O(N) | O(1) | |
| 3861 | [Minimum Capacity Box](https://leetcode.com/problems/minimum-capacity-box/) | 🟢 Easy | Array / Linear Search | [C++](./solution/Solution_3861.cpp) | O(N) | O(1) | [Note](#3861-min-capacity) |

<br><br>
---

## <a name="array-difference-array"></a>🍱 Array - Difference Array (陣列 差分陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1094 | [Car Pooling](https://leetcode.com/problems/car-pooling/) | 🟡 Medium | Difference Array / Sweep Line | [C++](./solution/Solution_1094.cpp) | O(N + M) | O(M) | |
| 1109 | [Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/) | 🟡 Medium | Difference Array | [C++](./solution/Solution_1109.cpp) | O(N + K) | O(N) | |
| 1854 | [Maximum Population Year](https://leetcode.com/problems/maximum-population-year/) | 🟢 Easy | Difference Array / Sweep Line | [C++](./solution/Solution_1854.cpp) | O(N + Y) | O(Y) |  |


<br><br>
---
## <a name="array-boyer-moore"></a>🍱 Array - Boyer-Moore Voting Algorithm(陣列 多數投票演算法)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element/) | 🟢 Easy | Array <br> Voting Algorithm | [C++](./solution/Solution_0169.cpp) | O(N) | O(1) |
| 0229 | [Majority Element II](https://leetcode.com/problems/majority-element-ii/) | 🟡 Medium | Array <br> Voting Algorithm | [C++](./solution/Solution_0229.cpp) | O(N) | O(1) |

<br><br>
---

## <a name="2d-array"></a>🍱 Array - 2D Array (陣列 二維陣列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0048 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | 🟡&nbsp;Medium | Array | [C++](./solution/Solution_0048.cpp) | O(n²) | O(1) | [Note](#0048-rotate-image) |
| 0073 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes) | 🟡 Medium | Array <br> Matrix | [C++](./solution/Solution_0073.cpp) | O(M*N) | O(1) | [Note](#0073-set-matrix-zeros) |
| 0832 | [Flipping an Image](https://leetcode.com/problems/flipping-an-image/) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_0832.cpp) | O(N * M) | O(1) | |
| 0867 | [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) | 🟢 Easy | Matrix | [C++](./solution/Solution_0867.cpp) | O(M*N) | O(M*N) |[Note](#0867-tranpose-matrix) |
| 1252 | [Cells with Odd Values...](https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/) | 🟢 Easy | Array / Math | [C++](./solution/Solution_1252.cpp) | O(K + MN) | O(M + N) | |
| 1260 | [Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_1260.cpp) | O(M * N) | O(K) | [Note](#1260-shift-note) |
| **1582** | [Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/) | 🟢 Easy | Array <br> Matrix | [C++](./solution/Solution_1582.cpp) | O(m * n) | O(m + n) |
| 1886 | [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/) | 🟢 Easy | Array | [C++](./solution/Solution_1886.cpp) | O(n²) | O(1) |[Note](#1886-determine-whether-matrix-can-be-obtained-by-rotation) |
| 2022 | [Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array) | 🟢 Easy | Array <br> Matrix <br> Simulation | [C++](./solution/Solution_2022.cpp) | O(m*n) | O(1) | [Note](#2022-convert-1d-array-into-2d-array) |
| 2639 | [Find the Width of Columns of a Grid](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/) | 🟢 Easy | Array / Simulation | [C++](./solution/Solution_2639.cpp) | O(M * N * D) | O(1)* | |
| 3142 | [Check if Grid Satisfies Conditions](https://leetcode.com/problems/check-if-grid-satisfies-conditions/) | 🟢 Easy | Simulation <br> Array | [C++](./solution/Solution_3142.cpp)  | O(M * N) | O(1) | [Note](#3142-grid-note) |
| 3417 | [Zigzag Grid Traversal With Skip](https://leetcode.com/problems/zigzag-grid-traversal-with-skip/) | 🟢 Easy | Simulation | [C++](./solution/Solution_3417.cpp) | O(M * N) | O(M * N) | [Note](#3417-zigzag-note) |

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
> Size mxn，New 一個 Vector nxm<br>
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
| **1201** | [Ugly Number III](https://leetcode.com/problems/ugly-number-iii/) | 🟡 Medium | Binary Search <br> Math | [C++](./solution/Solution_1201.cpp) | O(log(2e9)) | O(1) | |
| 1351 | [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) | 🟢 Easy | Array <br> Matrix <br> Binary Search | [C++](./solution/Solution_1351.cpp) | O(R + C) | O(1) |
| **1930** | [Unique Length-3 Palindromic Subsequences](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/) | 🟡 Medium | Greedy <br> Hash | [C++](./solution/Solution_1930.cpp) | O(N) | O(1) | |
| **2195** | [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum/) | 🟡 Medium | Math / Binary Search | [C++](./solution/Solution_2195.cpp) | O(N log N) | O(1) |  |
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
| **1170** | [Compare Strings by Frequency](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/) | 🟡 Medium | Sorting / Binary Search | [C++](./solution/Solution_1170.cpp) | O(N log N + M log N) | O(N) | |
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
| 0523 | [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) | 🟡 Medium | Prefix Sum / Hash Map | [C++](./solution/Solution_0523.cpp) | O(N) | O(min(N, K)) |  |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) | 🟡 Medium | Array <br> Hash Table <br> Prefix Sum | [C++](./solution/Solution_0560.cpp) | O(N) | O(N) |
| 0724 | [Find Pivot Index](https://leetcode.com/problems/find-pivot-index) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_0724.cpp) | O(N) | O(1) |
| 0930 | [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/) | 🟡 Medium | Array <br> Prefix Sum | [C++](./solution/Solution_930.cpp) | O(N) | O(N) |
| 1480 | [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_1480.cpp) | O(N) | O(1) |
| 1588 | [Sum of All Odd Length Subarrays](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/) | 🟢 Easy | Array / Prefix Sum | [C++](./solution/Solution_1588_1.cpp) | O(N²) | O(N) | |
| 1685 | [Sum of Absolute Differences in a Sorted Array](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/) | 🟡 Medium | Array <br> Prefix Sum <br> Math | [C++](./solution/Solution_1685.cpp) | O(N) | O(N) |
| 1732 | [Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/) | 🟢 Easy | Array / Prefix Sum | N/A | O(N) | O(1) | |
| 2256 | [Minimum Average Difference](https://leetcode.com/problems/minimum-average-difference/) | 🟡 Medium | Prefix Sum / Math | [C++](./solution/Solution_2256.cpp) | O(N) | O(1) | |
| 2559 | [Count Vowel Strings in Ranges](https://leetcode.com/problems/count-vowel-strings-in-ranges) | 🟡 Medium | Array <br> Prefix Sum | [C++](./solution/Solution_2559.cpp) | O(N + Q) | O(N) |
| 2574 | [Left and Right Sum Differences](https://leetcode.com/problems/left-and-right-sum-differences/) | 🟢 Easy | Array <br> Prefix Sum | [C++](./solution/Solution_2574.cpp) | O(N) | O(N) | 
| 3432 | [Count Partitions with Even Sum Difference](https://leetcode.com/problems/count-partitions-with-even-sum-difference/) | 🟢 Easy | Prefix Sum / Math | [C++](./solution/Solution_3432.cpp) | O(N) | O(N) | [Note](#3432-partition-note) |

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
| 0680 | [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0680.cpp) | O(N) | O(1) | 
| 0917 | [Reverse Only Letters](https://leetcode.com/problems/reverse-only-letters/) | 🟢 Easy | Two Pointers / String | [C++](./solution/Solution_0917.cpp) | O(N) | O(1) |
| 0941 | [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0941.cpp) | O(n) | O(1) |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0977.cpp) | O(n) | O(n) |
| 1750 | [Minimum Length of String After Deleting Similar Ends](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_1750.cpp) | O(N) | O(1) |
| 2000 | [Reverse Prefix of Word](https://leetcode.com/problems/reverse-prefix-of-word/) | 🟢 Easy | Two Pointers / String | [C++](./solution/Solution_2000.cpp) | O(N) | O(1) |
| 2108 | [Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_2108.cpp) | O(N * L) | O(1) | [Note](#2108-find-first-palindromic-string-in-the-array) |
| 2562 | [Find the Array Concatenation Value](https://leetcode.com/problems/find-the-array-concatenation-value/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_2562.cpp) | O(N * D) | O(1) | [Note](#2562-find-the-array-concatenation-value) |
| 3794 | [Reverse String Prefix](https://leetcode.com/problems/reverse-string-prefix/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_3794.cpp) | O(N) | O(1) |
| 3884 | [First Matching Character From Both Ends](https://leetcode.com/problems/first-matching-character-from-both-ends/description/) | 🟢 Easy | Two-Pointers | [C++](./solution/Solution_3884.cpp) | O(N) | O(1) | [Note](#3884-first-match) |

> [!NOTE]
> [Opposite Direction 核心概念]<br>
> left 從頭、right 從尾，條件不符時移動較劣的那側。<br>
> 通常需要**排序**作為前提（0015、0016、0167、0977）。<br>
> 回文判斷（0125、0344、0345）：左右同時往中間收斂，不符合就提早返回。<br>


### 2108. Find First Palindromic String in the Array
> [Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/) <br>
> 實做string isPalindromic，travsal vector<string>& words，第一個Palindromic回傳<br>

<br><br>

---
### 2562. Find the Array Concatenation Value
> [Find the Array Concatenation Value](https://leetcode.com/problems/find-the-array-concatenation-value/) <br>
> 兩個index 往中間走，int left = 0; int right = nums.size() - 1;<br>
> 每次要加到sum 的數字為 nums[left] * (nums[right]的10位數)<br>
> nums[right]的10位數算法，log10效率太低，static_cast<int>(log10(nums[right])) + 1<br>
> 直接計算nums[right]右移次數，每次次數直接*10，當作nums[left]的multiplier<br>

---





### 3884. First Matching Character From Both Ends
> [First Matching Character From Both Ends](https://leetcode.com/problems/first-matching-character-from-both-ends/description/) <br>
> 兩個index 往中間走，int left = 0; int right = nums.size() - 1;<br>
> 字元相等，return left，if(s[left] == s[right]) return left;<br>
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
| 1417 | [Reformat The String](https://leetcode.com/problems/reformat-the-string/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_1417.cpp) | O(N) | O(N) | |
| 1721 | [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list) | 🟡 Medium | Linked List <br> Two Pointers | [C++](./solution/Solution_1721.cpp) | O(N) | O(1) |
| 1768 | [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_1768.cpp) | O(N+M) | O(1) |
| 2109 | [Adding Spaces to a String](https://leetcode.com/problems/adding-spaces-to-a-string) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_2109.cpp) | O(N+M) | O(N+M) |
| 2540 | [Minimum Common Value](https://leetcode.com/problems/minimum-common-value) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_2540.cpp) | O(N+M) | O(1) |
| 3132 | [Find the Integer Added to Array II](https://leetcode.com/problems/find-the-integer-added-to-array-ii/) | 🟡 Medium | Sorting / Two Pointers | [C++](./solution/Solution_3132.cpp) | O(N log N) | O(1) | |
| 3819 | [Rotate Non Negative Elements](https://leetcode.com/problems/rotate-non-negative-elements/) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_3819.cpp) | O(N) | O(N) |
| 3940 | [Limit Occurrences in Sorted Array](https://leetcode.com/problems/limit-occurrences-in-sorted-array/) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_3940.cpp) | O(N) | O(1) |


> [!NOTE]
> [Same Direction 核心概念]<br>
> 兩個指針同方向前進，各自掃描不同陣列或字串（0392、1768、2540）。<br>
> 或一個指針掃描、另一個記錄「有效位置」（0228、0844）。<br>
> 0844 從**尾端**往前同向掃描，模擬退格後比對。<br>

> [!NOTE]
> [0392 Is Subsequence](./solution/Solution_0392.cpp)<br>
> 此題如果用 Dynamic Programming LCS，Complexity 會是 O(nm)，O(nm)<br>
> 但如果用 Two Pointers 會是 O(n)，O(1)<br>

<br><br>
---

## <a name="two-pointers-partition"></a>👥 Two Pointers - Partition (分割型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0075.cpp) | O(n) | O(1) |
| 0088 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0088.cpp) | O(M + N) | O(1) |
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


## <a name="two-pointers-swap"></a>👥 Two Pointers - Swap (交換型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | 🟢 Easy | Array <br> Fast-Slow Pointers | [C++](./solution/Solution_0283.cpp) | O(n) | O(1) |
| 0905 | [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0905.cpp) | O(n) | O(1) |
| 0922 | [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0922.cpp) | O(n) | O(1) |
| 3467 | [Transform Array by Parity](https://leetcode.com/problems/transform-array-by-parity/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_3467.cpp) | O(N) | O(1) | [Note](#3467-transform-array-by-parity) |
| 3823 | [Reverse Letters Then Special Characters](leetcode.com/problems/reverse-letters-then-special-characters-in-a-string) | 🟢 Easy | Two-Pointer | [C++](./solution/Solution_3823.cpp)  | O(N) | O(1) | [Note](#3823-reverse-note) |


### 3467. Transform Array by Parity
> [Transform Array by Parity](https://leetcode.com/problems/transform-array-by-parity/) <br>
> 905[Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity)的擴展<br>
> 多了最後把元素改成0(even)和1(odd)， **for(int& num : nums) num &= 1** <br>
<br><br>


---


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
| 0049 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | 🟡 Medium | Hash Table <br> String | [C++](./solution/Solution_0049.cpp) | O(N*K) | O(N*K) | 
| 0771 | [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/) | 🟢 Easy | Hash Set <br> String | [C++](./solution/Solution_0771.cpp) | O(J + S) | O(J) |
| 0819 | [Most Common Word](https://leetcode.com/problems/most-common-word/) | 🟢 Easy | String <br> Hash Table | [C++](./solution/Solution_0819.cpp)| O(M + N) | O(M + N) | |
| 1160 | [Find Words That Can Be Formed by Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/) | 🟢 Easy | Frequency Count | [C++](./solution/Solution_1160.cpp)  | O(N) | O(1) |
| 1207 | [Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_1207.cpp) | O(N) | O(N) |
| 1394 | [Find Lucky Integer in an Array](https://leetcode.com/problems/find-lucky-integer-in-an-array) | 🟢 Easy | Array <br> Hash Table <br> Counting | [C++](./solution/Solution_1394.cpp) | O(N) | O(1) |
| 1460 | [Make Two Arrays Equal by Reversing Subarrays](https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_1460.cpp) | O(N) | O(K) |
| 1512 | [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs) | 🟢 Easy | Array <br> Hash Table <br> Math | [C++](./solution/Solution_1512.cpp) | O(N) | O(N) |
| 1647 | [Minimum Deletions...](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/) | 🟡 Medium | Greedy / Hash Set | [C++](./solution/Solution_1647.cpp) | O(N + K log K) | O(K) |  |
| 1748 | [Sum of Unique Elements](https://leetcode.com/problems/sum-of-unique-elements) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_1748.cpp) | O(N) | O(N) |
| 1941 | [Check if All Characters Have Equal Number of Occurrences](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences) | 🟢 Easy | Hash Table <br> String <br> Counting | [C++](./solution/Solution_1941.cpp) | O(n) | O(1) |
| 2001 | [Number of Pairs of Interchangeable Rectangles](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles) | 🟡 Medium | Hash Table <br> Math | [C++](./solution/Solution_2001.cpp) | O(N) | O(N) |
| 2053 | [Kth Distinct String in an Array](https://leetcode.com/problems/kth-distinct-string-in-an-array/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2053.cpp) | O(N) | O(N) |
| 2094 | [Finding 3-Digit Even Numbers](https://leetcode.com/problems/finding-3-digit-even-numbers/) | 🟢 Easy | Hash Table <br> Math | [C++](./solution/Solution_2094.cpp) | O(N) | O(1) |
| 2150 | [Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array) | 🟡 Medium | Hash Table <br> Counting | [C++](./solution/Solution_2150.cpp) | O(n) | O(n) | [Note](#2150-find-all-lonely-numbers-in-the-array) |
| 2206 | [Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs) | 🟢 Easy | Array <br> Hash Table <br> Counting | [C++](./solution/Solution_2206.cpp) | O(n) | O(1) |
| 2225 | [Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses) | 🟡 Medium | Hash Table <br> Counting <br> Sorting | [C++](./solution/Solution_2225.cpp) | O(nlogn) | O(n) |
| 2283 | [Check if Number Has Equal Digit Count and Digit Value](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/) | 🟢 Easy | Hash Map / Counting | [C++](./solution/Solution_2283.cpp) | O(N) | O(1) | [Note](#2283-digit-count) |
| 2351 | [First Letter to Appear Twice](https://leetcode.com/problems/first-letter-to-appear-twice) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2351.cpp) | O(N) | O(1) |
| 2395 | [Find Subarrays With Equal Sum](https://leetcode.com/problems/find-subarrays-with-equal-sum/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2395.cpp) | O(N) | O(N) | [Note](#2395-find-subarrays-with-equal-sum) |
| 2404 | [Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_2404.cpp) | O(n) | O(n) |
| 2451 | [Odd String Difference](https://leetcode.com/problems/odd-string-difference/) | 🟢 Easy | Hash Map / Difference Array |[C++](./solution/Solution_2451.cpp) | O(N * M) | O(N * M) | [Note](#2451-odd-note) |
| 2965 | [Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values/) | 🟢 Easy | Hashing | [C++](./solution/Solution_2965.cpp) | O(N²) | O(N²) | [Note](#2965-find-missing-and-repeated-values) |
| 3005 | [Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency) | 🟢 Easy | Hash Table <br> Counting | [C++](./solution/Solution_3005.cpp) | O(n) | O(1) |
| 3289 | [The Two Sneaky Numbers of Digitville](https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/) | 🟢 Easy | Hash Table / Bit Manipulation | [C++](./solution/Solution_3289.cpp) | O(N) | O(1) | |
| 3438 | Find Valid Pair of Adjacent Digits in String | 🟢 Easy | String / Hash Map | [C++](./solution/Solution_3438.cpp) | O(N) | O(1) | |
| 3442 | [Maximum Difference Between Even and Odd Frequency I](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/) | 🟢 Easy | String / Hash Map | [C++](./solution/Solution_3442.cpp) | O(N) | O(1) | [Note](#3442-max-diff-note) |
| 3541 | [Find Most Frequent Vowel and Consonant](https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/) | 🟢 Easy | Hash Table <br> Frequency Counting | [C++](./solution/Solution_3541.cpp) | O(N) | O(1) |
| 3663 | [Find The Least Frequent Digit](https://leetcode.com/problems/find-the-least-frequent-digit/) | 🟢 Easy | Hash Table <br> Frequency Counting | [C++](./solution/Solution_3663.cpp) | O(log N) | O(1) |
| 3843 | [First Element with Unique Frequency](https://leetcode.com/problems/first-element-with-unique-frequency/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_3843.cpp) | O(N) | O(N) | [Note](#3843-first-element-with-unique-frequency) |
| 3866 | [First Unique Even Element](https://leetcode.com/problems/first-unique-even-element/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_3866.cpp) | O(N) | O(1) | [Note](#3866-first-unique-even-element) |
| 3926 | [Count Valid Word Occurrences](https://leetcode.com/problems/count-valid-word-occurrences/) | 🟡 Medium | String <br> Hash Map | [C++](./solution/Solution_3926.cpp) | O(N + M) | O(N) | |

### 2150. Find All Lonely Numbers in the Array
> [Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array)<br>
> 用unordered map紀錄數字頻率，travsal unordered map，如果 num - 1和 num + 1都不在unordered map，且num頻率等於1，則加入result vector<br>
---

### 2283. Check if Number Has Equal Digit Count and Digit Value
> [Check if Number Has Equal Digit Count and Digit Value](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/)<br>
> 先用vector<int> appear(10);travsal每個char，紀錄'0'~'9'的出現次數<br>
> 第二次把num[i] - '0'和 appear[i] 比對
---



### 2395. Find Subarrays With Equal Sum
> [Find Subarrays With Equal Sum](https://leetcode.com/problems/find-subarrays-with-equal-sum/) <br>
> 從 index 1 開始，左右兩數的sum，unordered map存在，回傳false，不存在，則存入unordered map<br>
---

### 2965. Find Missing and Repeated Values
> [Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values/) <br>
> 起一個vector<int> counts(n * n + 1, 0);計數字出現頻率<br>
> if(counts[i] == 0) missing = i; else if(counts[i] == 2) repeat = i;<br>
> **雖然數學方法（利用數列總和公式 1+2+...+n²）可以達到 O(1) 的額外空間，但那樣做會涉及較大的數值加總，可能會有溢位風險**。 <br>

---



### 3843. First Element with Unique Frequency
> [First Element with Unique Frequency](https://leetcode.com/problems/first-element-with-unique-frequency/)<br>
> travsal nums, 用unordered_map<int, int> counts紀錄數字出現的次數<br>
> travsal counts, 用 unordered_map<int, int> countFreq;紀錄出現次數的頻率<br>
> travsal nums, if(countFreq[counts[num]] == 1) return num;<br>
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
| 0804 | [Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/) | 🟢 Easy | Hash Set | [C++](./solution/Solution_0804.cpp) | O(S) | O(S) | [Note](#0804-unique-morse-code-words) |
| 0884 | [Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0884.cpp) | O(N + M) | O(N + M) |
| 1002 | [Find Common Characters](https://leetcode.com/problems/find-common-characters) | 🟢 Easy | Array <br> Hash Table <br> String | [C++](./solution/Solution_1002.cpp) | O(N*K) | O(1) |
| 1436 | [Destination City](https://leetcode.com/problems/destination-city) | 🟢 Easy | Hash Table <br> String | [C++](./solution/Solution_1436.cpp) | O(N) | O(N) |
| 1640 | [Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/) | 🟢 Easy | Hash Map | [C++](./solution/Solution_1640.cpp) | O(N) | O(N) | [Note](#1640-check-array-formation-through-concatenation) |
| 2133 | [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers) | 🟢 Easy | Array <br> Hash Table <br> Bitset | [C++](./solution/Solution_2133.cpp) | O(n²) | O(n) |
| 2154 | [Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two) | 🟢 Easy | Array <br> Hash Table <br> Simulation | [C++](./solution/Solution_2154.cpp) | O(n) | O(n) |
| 2342 | [Max Sum of a Pair With Equal Sum of Digits](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/) | 🟡 Medium | Hash Table / Math | [C++](./solution/Solution_2342.cpp) | O(N * log M) | O(N) | |
| 2418 | [Sort the People](https://leetcode.com/problems/sort-the-people) | 🟢 Easy | Array <br> Sorting <br> Hash Table | [C++](./solution/Solution_2418.cpp) | O(NlogN) | O(N) |
| 2441 | [Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative) | 🟢 Easy | Hash Table <br> Two Pointers <br> Sorting | [C++](./solution/Solution_2441.cpp) | O(n) | O(n) |
| 3678 | [Smallest Absent Positive Greater Than Average](https://leetcode.com/problems/smallest-absent-positive-greater-than-average/) | 🟢 Easy | Array <br> Hash Set | [C++](./solution/Solution_3678.cpp) | O(N) | O(N) |
| 3838 | [Weighted Word Mapping](https://leetcode.com/problems/weighted-word-mapping/) | 🟢 Easy | Hash Mapping / Simulation | [C++](./solution/Solution_3828.cpp) | O(N * L) | O(1) | [Note](#3838-weight-note) |


> [!NOTE]
> [Two Sum](./solution/Solution_0001.cpp) 因為**尚未排序**過，所以 Complexity **O(n), O(n)**<br>
> [Two Sum II](./solution/Solution_0167.cpp) 因為**已排序**，所以 Complexity **O(n), O(1)**<br>

> [!NOTE]
> [2001 Number of Pairs of Interchangeable Rectangles](./solution/Solution_2001.cpp) 和 [1512. Number of Good Pairs](./solution/Solution_1512.cpp)<br>
> 同時用到了 Greedy Math Pattern，(1+n)/2<br>
> [2001 Number of Pairs of Interchangeable Rectangles](./solution/Solution_2001_1.cpp)同時也在考<br>
> **浮點數精度問題(Floating-point precision)-某些比例可能在運算中產生微小的誤差（例如1/3在某些計算環境下可能不完全相等）**<br>
> **導致原本應該視為相同的比例被誤判為不同。**<br>

### 0804. Unique Morse Code Words
> [Unique Morse Code Words](https://leetcode.com/problems/unique-morse-code-words/) <br>
> 用一組 vector<string> morse 定義morse code mapping<br>
> 針對words每個string，轉為morsecode，放入unordered_set<string> unique_codes;<br>
> 因為unordered_set會去重覆，最後unique_codes.size();<br>

### 1640. Check Array Formation Through Concatenation
> [Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/) <br>
> 用一組  unordered_map<int,vector<int>> map 紀錄每組vector第一個int和該組vector <br>
> 對arr 使用index i，如果arr[i]在map中找到，取出來，每個int開始比對，i往後走<br>

### 2342. Max Sum of a Pair With Equal Sum of Digits
> [Max Sum of a Pair With Equal Sum of Digits](https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/) <br>
> **int digit_sum = digitSum(num);** <br>
> **if(digit_max_map.count(digit_sum)) {** <br>
> &emsp;&emsp;&emsp;&emsp;**maximum  = std::max(maximum, digit_max_map[digit_sum] + num );** <br>
> &emsp;&emsp;&emsp;&emsp;**digit_max_map[digit_sum] = std::max(digit_max_map[digit_sum], num);** <br>
> **} else {** <br>
> &emsp;&emsp;&emsp;&emsp;**digit_max_map[digit_sum] = num;** <br>
> **}** <br>


<br><br>
---

## <a name="hash-table-set"></a>🔑 Hash Table - Set (集合 / 存在性判斷)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0217.cpp) | O(n) | O(n) |
| 0219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) | 🟢 Easy | Hash Table <br> Sliding Window | [C++](./solution/Solution_0219.cpp) | O(n) | O(min(n,k)) |
| 0349 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0349.cpp) | O(n+m) | O(n) |
| 0350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0350.cpp) | O(n+m) | O(min(n,m)) |
| 0705 | [Design HashSet](https://leetcode.com/problems/design-hashset) | 🟢 Easy | Hash Table <br> Design | [C++](./solution/Solution_0705.cpp) | O(1) | O(N) |
| 0888 | [Fair Candy Swap](https://leetcode.com/problems/fair-candy-swap/) | 🟢 Easy | Hash Set / Math | [C++](./solution/Solution_0888.cpp) | O(A + B) | O(B) | |
| 0939 | [Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/) | 🟡 Medium | Array <br> Hash Table | [C++](./solution/Solution_939.cpp) | O(N²) | O(N) |
| 1346 | [Check If N and Its Double Exist](https://leetcode.com/problems/check-if-n-and-its-double-exist) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_1346.cpp) | O(n) | O(n) |
| 1496 | [Path Crossing](https://leetcode.com/problems/path-crossing/) | 🟢 Easy | Hash Set <br> Coordinates | [C++](./solution/Solution_1496.cpp) | O(N) | O(N) |  |
| 1624 | [Largest Substring Between Two Equal Characters](https://leetcode.com/problems/largest-substring-between-two-equal-characters/) | 🟢 Easy | String / Hash Table | [C++](./solution/Solution_1624.cpp) | O(N) | O(1) |
| **1805** | [Number of Different Integers in a String](https://leetcode.com/problems/number-of-different-integers-in-a-string/) | 🟢 Easy | String / Hash Set | [C++](./solution/Solution_1805.cpp) | O(N) | O(N) |  |
| 2215 | [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2215.cpp) | O(n+m) | O(n+m) |
| 2248 | [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2248.cpp) | O(n*m) | O(n) |
| 2670 | [Find the Distinct Difference Array](https://leetcode.com/problems/find-the-distinct-difference-array/) | 🟢 Easy | Array / Hash Set | [C++](./solution/Solution_2670.cpp) | O(N) | O(N) ||
| 2784 | [Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good) | 🟢 Easy | Array <br> Hash Table <br> Sorting | [C++](./solution/Solution_2784.cpp) | O(n) | O(n) |
| 3483 | [Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/) | 🟢 Easy | Brute Force | [C++](./solution/Solution_3483.cpp) | O(N³) | O(U) |
| 3718 | [Smallest Missing Multiple of K](https://leetcode.com/problems/smallest-missing-multiple-of-k/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_3718.cpp) | O(N+M) | O(M) |
| 3731 | [Find Missing Elements](https://leetcode.com/problems/find-missing-elements/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_3731.cpp) | O(N+K) | O(K) |

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
| **0437** | [Path Sum III](https://leetcode.com/problems/path-sum-iii/) | 🟡 Medium | DFS / Prefix Sum | [C++](./solution/Solution_0437.cpp) | O(N) | O(H) | |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0543.cpp) | O(n) | O(h) |
| 0559 | [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree) | 🟢 Easy | Tree <br> DFS <br> BFS | [C++](./solution/Solution_0559.cpp) | O(N) | O(H) |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0572.cpp) | O(n*m) | O(h) |
| 0606 | [Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0606.cpp) | O(N) | O(H) |
| 0617 | [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees) | 🟢 Easy | Tree <br> DFS <br> Recursion | [C++](./solution/Solution_0617.cpp) | O(min(N, M)) | O(min(N, M)) |
| 0671 | [Second Minimum Node In a Binary Tree](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0671.cpp) | O(N) | O(H) |
| **0687** | [Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/) | 🟡 Medium | DFS <br> Tree | [C++](./solution/Solution_0687.cpp) | O(N) | O(H) | |
| 0872 | [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0872.cpp) | O(N+M) | O(N+M) |
| 0965 | [Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree) | 🟢 Easy | Tree <br> DFS | [C++](./solution/Solution_0965.cpp) | O(N) | O(H) |
| 0988 | [Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/) | 🟡 Medium | Tree <br> DFS | [C++](./solution/Solution_988.cpp) | O(N) | O(H) |
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


## <a name="trie"></a>🔗 Trie (前綴樹)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 648 | [Replace Words](https://leetcode.com/problems/replace-words/) | 🟡 Medium | Trie | [C++](./solution/Solution_0648_1.cpp) | O(N * L) | O(M * L) |  |


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
| 0524 | [Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/) | 🟡 Medium | Two Pointers / Sorting | [C++](./solution/Solution_0524.cpp) | O(D log D + D * M) | O(1) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 Medium | Array <br> Divide and Conquer <br> Sorting | [C++](./solution/Solution_0912.cpp) | O(nlogn) | O(logn) |
| 1200 | [Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/) | 🟢 Easy | Array <br> Sorting | [C++](./solution/Solution_1200.cpp) | O(NlogN) | O(N) | 
| 1356 | [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits) | 🟢 Easy | Bit Manipulation <br>  Sorting | [C++](./solution/Solution_1356.cpp) | O(NlogN) | O(1) |
| 1408 | [String Matching in an Array](https://leetcode.com/problems/string-matching-in-an-array/) | 🟢 Easy | String <br> Sorting | [C++](./solution/Solution_1408.cpp) | O(N²*K) | O(N) |
| 1481 | [Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/) | 🟡 Medium | Greedy / Sorting | [C++](./solution/Solution_1481.cpp) | O(N log N) | O(N) | [Note](#1481-least-number-of-unique-integers-after-k-removals) |
| 2164 | [Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently/) | 🟢 Easy | Sorting | [C++](./solution/Solution_2164.cpp) | O(NlogN) | O(N) | 
| 2545 | [Sort the Students by Their Kth Score](https://leetcode.com/problems/sort-the-students-by-their-kth-score/) | 🟢 Medium | Array <br> Sorting | [C++](./solution/Solution_2545.cpp) | O(NlogN) | O(1) |
| 3769 | [Sort Integers by Binary Reflection](https://leetcode.com/problems/sort-integers-by-binary-reflection/) | 🟡 Medium | Bit Manipulation <br> Sorting | [C++](./solution/Solution_3769.cpp) | O(NlogN) | O(N) |
| 3913 | [Sort Vowels by Frequency](https://leetcode.com/problems/sort-vowels-by-frequency/) | 🟡 Medium | Sorting <br> Hash | [C++](./solution/Solution_3913.cpp) | O(NlogN) | O(N) | 
| 3684 | [Maximize Sum of At Most K Distinct Elements](https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/) | 🟢 Easy | Sorting <br> Set | [C++](./solution/Solution_3684.cpp) | O(N logN) | O(N) |
| 3867 | [Sum of GCD of Formed Pairs](leetcode.com/problems/sum-of-gcd-of-formed-pairs/) | 🟡 Medium | GCD <br> Sorting | [C++](./solution/Solution_3867.cpp)  | O(NlogN) | O(N) | [Note](#3867-gcd-note) |

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


## <a name="Sorting-cycle-decomposition"></a>📊 Sorting - Cycle Decomposition(排序 循環分解)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 3551 | Minimum Swaps to Sort by Digit Sum | 🟡 Medium | Cycle Decomposition | [C++](./solution/Solution_3551.cpp) | O(N log N) | O(N) ||

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
| 0786 | [K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/) | 🟡 Medium | Priority Queue / Binary Search | [C++](./solution/Solution_0786.cpp) | O(N log N) | O(N) | |
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
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 Medium | DP | [C++](./solution/Solution_0063.cpp) | O(m*n) | O(n) | [Note](#0063-unique-paths-ii) |
| 0064 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | 🟡 Medium | DP | [C++](./solution/Solution_0064.cpp) | O(M*N) | O(1) |
| 0070 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0070.cpp) | O(n) | O(1) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 Medium | Dynamic Programming <br> Math | [C++](./solution/Solution_0096.cpp) | O(N²) | O(N) |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | 🟡 Medium | Dynamic Programming <br> Math | [C++](./solution/Solution_0264.cpp) | O(n) | O(n) |
| 0313 | [Super Ugly Number](https://leetcode.com/problems/super-ugly-number/) | 🟡 Medium | Dynamic Programming <br> Multi-pointers | [C++](./solution/Solution_0313.cpp) | O(N * K) | O(N + K) | [Note](#313-super-ugly) |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0509.cpp) | O(n) | O(1) | 
| **0926** | [Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/) | 🟡 Medium | Dynamic Programming | [C++](./solution/Solution_0926.cpp) | O(N) | O(1) | |
| 1137 | [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | 🟢 Easy | DP <br> Math | [C++](./solution/Solution_1137.cpp) | O(N) | O(1) |
| 1668 | [Maximum Repeating Substring](https://leetcode.com/problems/maximum-repeating-substring/) | 🟢 Easy | String | [C++](./solution/Solution_1668.cpp) | O(N*M²) | O(M) |

### 0063. Unique Paths II
> [Unique Paths II](https://leetcode.com/problems/unique-paths-ii)<br>
> 先取得size，int m = obstacleGrid.size(); int n = obstacleGrid[0].size();<br>
> 起一個vector紀錄，vector<long> dp(n); dp[0] = 1;<br>
> for(int i = 0; i < m;i++) {<br>
> &emsp;&emsp;&emsp;&emsp;**for(int j = 0; j < n;j++) {** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**if(obstacleGrid[i][j]) dp[j] = 0;** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**else if(j > 0) dp[j] += dp[j - 1];** <br>
> &emsp;&emsp;&emsp;&emsp;**}** <br>
> }<br>
---

### 0313. Super Ugly Number
> [Super Ugly Number](https://leetcode.com/problems/super-ugly-number/)
> [264 Ugly Number II](https://leetcode.com/problems/ugly-number-ii/)的擴展題<br>


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
| 0139 | [Word Break](https://leetcode.com/problems/word-break/) | 🟡 Medium | DP  <br> Unbounded Knapsack | [C++](./solution/Solution_0139.cpp) | O(N³) | O(N) | 

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
| 0118 | [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | 🟢 Easy | Array <br> DP | [C++](./solution/Solution_0118.cpp) | O(N²) | O(1)* |
| 0152 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | 🟡 Medium | Dynamic Programming <br> Array | [C++](./solution/Solution_0152.cpp) | O(N) | O(1) |
| 0918 | [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-subarray-sum-circular/) | 🟡 Medium | Array <br> Kadane's Algorithm | [C++](./solution/Solution_0918.cpp) | O(N) | O(1) |
| 1641 | [Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/) | 🟡 Medium | Math <br> Dynamic Programming | [C++](./solution/Solution_1641.cpp) | O(1) | O(1) |

<br><br>
---

## <a name="greedy"></a>🧩 Greedy (貪婪法)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0055 | [Jump Game](https://leetcode.com/problems/jump-game/) | 🟡 Medium | Greedy | [C++](./solution/Solution_0055.cpp) | O(N) | O(1) | [Note](#0055-jump-game) | 
| **0343** | [Integer Break](https://leetcode.com/problems/integer-break/) | 🟡 Medium | Math / Greedy | [C++](./solution/Solution_0343.cpp) | O(1) | O(1) | |
| **0397** | [Integer Replacement](https://leetcode.com/problems/integer-replacement/) | 🟡 Medium | Greedy / Bit Manipulation | O(log N) | O(1) | |
| 0435 | [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) | 🟡 Medium | Greedy <br> Interval | [C++](./solution/Solution_0435.cpp) | O(NlogN) | O(1) |
| 0409 | [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/) | 🟢 Easy | Hash Table / Greedy | [C++](./solution/Solution_0409.cpp) | O(N) | O(K) | [Note](#0409-longest-palindrome) |
| 0624 | [Maximum Distance in Arrays](https://leetcode.com/problems/maximum-distance-in-arrays) | 🟡 Medium | Array <br> Greedy | [C++](./solution/Solution_0624.cpp) | O(n) | O(1) |
| **0670** | [Maximum Swap](https://leetcode.com/problems/maximum-swap/) | 🟡 Medium | Greedy | [C++](./solution/Solution_0670.cpp) | O(N) | O(1) | |
| 0674 | [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence) | 🟢 Easy | Array <br> Greedy | [C++](./solution/Solution_0674.cpp) | O(n) | O(1) |
| 0678 | [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/) | 🟡 Medium | Greedy <br> String | [C++](./solution/Solution_0678.cpp) | O(N) | O(1) |
| **0696** | [Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/) | 🟢 Easy | String / Greedy | [C++](./solution/Solution_696.cpp) | O(N) | O(1) ||
| 0921 | [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) | 🟡 Medium | Stack / Greedy | [C++](./solution/Solution_921.cpp) | O(N) | O(1) | |
| **0945** | [Minimum Increment to Make Array Unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique/) | 🟡 Medium | Sorting <br> Greedy | [C++](./solution/Solution_0945.cpp) | O(NlogN) | O(1) | |
| 0961 | [N-Repeated Element](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/) | 🟢 Easy | Math/Greedy | [C++](./solution/Solution_0961.cpp) | O(N) | O(1) | [Note](#0961-n-repeated-element)  |
| 1323 | [Maximum 69 Number](https://leetcode.com/problems/maximum-69-number/) | 🟢 Easy | Greedy <br> Math | [C++](./solution/Solution_1323.cpp) | O(D) | O(D) |
| **1529** | [Minimum Suffix Flips](https://leetcode.com/problems/minimum-suffix-flips/) | 🟡 Medium | Greedy / State Machine | [C++](./solution/Solution_1529.cpp) | O(N) | O(1) | |
| 1576 | [Replace All ?'s](https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/) | 🟢 Easy | Greedy | [C++](./solution/Solution_1576.cpp) | O(N) | O(1) | [Note](#1576-replace-all-s) |
| 1785 | [Minimum Elements to Add to Form a Given Sum](https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/) | 🟡 Medium | Math / Greedy | [C++](./solution/Solution_1785.cpp) | O(N) | O(1) | |
| 1881 | [Maximum Value after Insertion](https://leetcode.com/problems/maximum-value-after-insertion/) | 🟡 Medium | Greedy / String | [C++](./solution/Solution_1881.cpp) | O(N) | O(1) | |
| **1936** | [Add Minimum Number of Rungs](https://leetcode.com/problems/add-minimum-number-of-rungs/) | 🟡 Medium | Greedy / Math | [C++](./solution/Solution_1936.cpp) | O(N) | O(1) | |
| 2027 | [Minimum Moves to Convert String](https://leetcode.com/problems/minimum-moves-to-convert-string/) | 🟢 Easy | Greedy | [C++](./solution/Solution_2027.cpp) | O(N) | O(1) | [Note](#2027-minimum-moves-to-convert-string) |
| 2231 | [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/) | 🟢 Easy | Greedy / Partition by Parity | [C++](./solution/Solution_2231.cpp) | O(D log D) | O(D) | [Note](#2231-largest-number-after-digit-swaps-by-parity) |
| 2259 | [Remove Digit From Number to Maximize Result](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/) | 🟢 Easy | Greedy / String | [C++](./solution/Solution_2259.cpp) | O(N) | O(N) | |
| 2578 | [Split With Minimum Sum](https://leetcode.com/problems/split-with-minimum-sum/) | 🟢 Easy | Greedy / Sorting | [C++](./solution/Solution_2578.cpp) | O(NlogN) | O(N) | [Note](#2578-split-with-minimum-sum)|
| 2815 | [Max Pair Sum in an Array](https://leetcode.com/problems/max-pair-sum-in-an-array/) | 🟢 Easy | Greedy / Hashing | [C++](./solution/Solution_2815.cpp) | O(N * D) | O(1) | [Note](#2815-max-pair-sum-in-an-array) |
| 2864 | [Maximum Odd Binary Number](https://leetcode.com/problems/maximum-odd-binary-number/) | 🟢 Easy | Greedy / String | [C++](./solution/Solution_2864.cpp) | O(N) | O(1) | |
| 3011 | [Find if Array Can Be Sorted](https://leetcode.com/problems/find-if-array-can-be-sorted/) | 🟡 Medium | Array <br> Greedy <br> Bit Manipulation | [C++](./solution/Solution_3011.cpp) | O(N) | O(1) | 
| 3216 | [Lexicographically Smallest String After a Swap](https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/) | 🟢 Easy | Greedy / String | [C++](./solution/Solution_3216.cpp) | O(N) | O(1) | [Note](#3216-lexicographically-smallest-string-after-a-swap) |
| 3536 | [Maximum Product of Two Digits](https://leetcode.com/problems/maximum-product-of-two-digits/description/) | 🟢 Easy | Math / Greedy | [C++](./solution/Solution_3536.cpp) | O(log N) | O(1) | [Note](#3536-maximum-product-of-two-digits)|
| 3798 | [Largest Even Number](https://leetcode.com/problems/largest-even-number/) | 🟢 Easy | Greedy / String | [C++](./solution/Solution_3798.cpp) | O(N) | O(1) |


### 0055. Jump Game
> [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)<br>
> 用一個maxReach更新最大能到達，maxReach = max(maxReach, i + nums[i]);<br>
> 如果 i > maxReach表示不可到達，if(i > maxReach) return false;<br>
> 如果到了結尾，可以先回傳，if(maxReach >= n - 1) return true;<br>
---


### 0409. Longest Palindrome
> [Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)<br>
> 用 unordered_map<char, int> counts;統計大小寫出現頻率<br>
> 對每個頻率，如果是偶數，直接加到res，如果是奇數，減1加到res<br>
> 如果頻率有奇數，最後res再+1<br>
---


### 0961. N-Repeated Element
> [N-Repeated Element](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)<br>
> **for (int i = 0; i < n; ++i) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if (i + 1 < n && nums[i] == nums[i + 1]) return nums[i];** <br>
> &emsp;&emsp;&emsp;&emsp;**if (i + 2 < n && nums[i] == nums[i + 2]) return nums[i];** <br>
> &emsp;&emsp;&emsp;&emsp;**if (i + 3 < n && nums[i] == nums[i + 3]) return nums[i];** <br>
> **}** <br>


---


### 1576. Replace All ?'s
> [Replace All ?'s](https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/)<br>
> 將字串中的 '?' 替換為合法字元，保證相鄰字元不重複遍歷字串，當遇到 '?' 時，從 'a', 'b', 'c' 中選出一個與左右相鄰皆不同的字元替換<br>
> **for(char c = 'a'; c <= 'c'; c++) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if(i > 0 && s[i - 1] == c) continue;** <br>
> &emsp;&emsp;&emsp;&emsp;**if(i < s.size() && s[i + 1] == c) continue;** <br>
> &emsp;&emsp;&emsp;&emsp;**s[i] = c;** <br>
> **}** <br>
---

### 2027. Minimum Moves to Convert String
> [Minimum Moves to Convert String](https://leetcode.com/problems/minimum-moves-to-convert-string/)<br>
> 起一個for loop ，遇到O，index i遞增1，遇到X，index i遞增3 且count + 1<br>
> **for(int i = 0; i < s.size();) {** <br>
> &emsp;&emsp;&emsp;&emsp;**while(i < s.size() && s[i] == 'O') i++;** <br>
> &emsp;&emsp;&emsp;&emsp;**if(i < s.size() && s[i] == 'X') {** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**i += 3;** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;** count++;** <br>
> &emsp;&emsp;&emsp;&emsp;**}** <br>
> **}** <br>
---



### 2231. Largest Number After Digit Swaps by Parity
> [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)<br>
> 用to_string把int num轉成string s<br>
> 初始化bucket vector<vector<char>> buckets(2);，travsal char，分成奇數，偶數<br>
> 把char分到bucket，for(const char& c : s) buckets[c & 1].push_back(c); <br>
> 兩組bucket直接排序，由大到小 <br>
> 擺回s，for(char& c : s)  c = buckets[c & 1][index[c & 1]++];<br>
> return stoi(s);
---

### 2578. Split With Minimum Sum
> [Split With Minimum Sum](https://leetcode.com/problems/split-with-minimum-sum/)<br>
> 用to_string把int num轉成string s，對s排序<br>
> 取穿插字元成為兩數，兩樹相加即是答案<br>
---



### 2815. Max Pair Sum in an Array
> [Max Pair Sum in an Array](https://leetcode.com/problems/max-pair-sum-in-an-array/)<br>
> 時做一個函數maxDigit回傳num的maximum digit <br>
> 起一個vector<pair<int, int>> best(10,{-1 , -1});，用來記錄每個maxDigit的max和第二max<br>
> travsal maxDigit 0~9;，如果max和第二max都在，second~=-1，相加後，如果比res大，更新到res<br>
> <br>
---

### 3216. Lexicographically Smallest String After a Swap
> [Lexicographically Smallest String After a Swap](https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/)<br>
> 前後兩個character找到相同parity且前面character比較大，做swap<br>
> **for(int i = 1; i < s.size(); i++) {** <br>
> &emsp;&emsp;&emsp;&emsp;**if((s[i-1] & 1) == (s[i] & 1) && s[i-1] > s[i]) {** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**swap(s[i], s[i-1]);** <br>
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**break;** <br>
> &emsp;&emsp;&emsp;&emsp;**}** <br>
> **}** <br>

---




### 3536. Maximum Product of Two Digits
> [Maximum Product of Two Digits](https://leetcode.com/problems/maximum-product-of-two-digits/description/) <br>
> digit decomposition時，紀錄最大和第二大，最後回傳相乘
> <br>
---




<br><br>
---

## <a name="backtracking-combination"></a>🔢 Backtracking Combination(回朔法 組合)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **0017** | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0017.cpp) | O(4^N) | O(N) | [Note](#0017-letter-combinations-of-a-phone-number) |
| 0022 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | 🟡 Medium | Backtracking / String | [C++](./solution/Solution_0022.cpp) | O(4ᴺ/√N) | O(N) |
| 0039 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0039.cpp) | O(N^(T/M)) | O(T/M) | [Note](#0039-combination-sum) |
| 0040 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | 🟡 Medium | Backtracking / Sorting | [C++](./solution/Solution_0040.cpp) | O(2ᴺ) | O(N) | [Note](#0040-combination-sum-ii) |
| 0077 | [Combinations](https://leetcode.com/problems/combinations/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0077.cpp) | O(k * C(n, k)) | O(k) |
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 Medium | Backtracking / Recursion <br> Bit Manipulation | [C++](./solution/Solution_0078.cpp) | O(N*2ᴺ) | O(N) |
| 0079 | [Word Search](https://leetcode.com/problems/word-search/) | 🟡 Medium | DFS / Backtracking | [C++](./solution/Solution_0079.cpp) | O(N*3ᴸ) | O(L) |
| 0090 | [Subsets II](https://leetcode.com/problems/subsets-ii/) | 🟡 Medium | Backtracking / Sorting | [C++](./solution/Solution_0090.cpp) | O(N*2ᴺ) | O(N) |
| 0216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0216.cpp) | O(C(9, k)) | O(k) |
| 0784 | [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0784.cpp) | O(2^N) | O(N) | [Note](#0784-letter-case-permutation) |


### 0017. Letter Combinations of a Phone Number
> [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)<br>
> vector<string> phone = {"abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};<br>
> index為digits目前走到第index個char，phone[digits[index]-'2']為digits[index]所對應到的phone string<br>
---

### 0039. Combination Sum
> [Combination Sum](https://leetcode.com/problems/combination-sum/)<br>
> 先對candidates做排序，sort(candidates.begin(), candidates.end());<br>
> 副程式combinationSum，多int start call by value，vector<vector<int>> res; vector<int> cur; call by reference<br>
> for(int i = start; i < candidates.size(); i++)內要判斷 if(candidates[i] > target) break;否則跑不出來<br>
> 因為此題允許元素重覆使用，遞迴呼叫**i不用+1**，combinationSum(candidates, target , **i**, cur, res);<br>
---

### 0040. Combination Sum II
> [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) <br>
> 先對candidates做排序，sort(candidates.begin(), candidates.end());<br>
> 副程式combinationSum2，多int start call by value，vector<vector<int>> res; vector<int> cur; call by reference<br>
> 去重覆，**if(i > start && candidates[i] == candidates[i - 1]) continue;**<br>
> 因為此題**不**允許元素重覆使用，遞迴呼叫**i需用+1**， combinationSum2(candidates, target - candidates[i], **i+1**, cur, res);<br>
---



### 0784. Letter Case Permutation
> [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) <br>
> index從開始傳進backtrack，因為只要處理大小寫，index先跳過不是大小寫，while (index < s.size() && isdigit(s[index])) index++<br>
> 終止遞迴條件， if(index == s.size()) { res.push_back(s); return;}<br>
> index目標字元轉lowercase遞迴， s[index] = tolower(s[index]); backtrack(s, index + 1, res);<br>
> index目標字元轉uppercase遞迴， s[index] = toupper(s[index]); backtrack(s, index + 1, res);<br>
---





<br><br>
---

## <a name="backtracking-permutation"></a>🔢 Backtracking Permutation(回朔法 排列)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0046 | [Permutations](https://leetcode.com/problems/permutations/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0046.cpp) | O(N*N!) | O(N) | [Note](#0046-permutations) |
| 0047 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | 🟡 Medium | Backtracking | [C++](./solution/Solution_0047.cpp) | O(N*N!) | O(N) |
| 3483 | [Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/) | 🟢 Easy | Backtracking | [C++](./solution/Solution_3483_1.cpp) | O(P(N, 3)) | O(N) | |


### 0046. Permutations
> [Permutations](https://leetcode.com/problems/permutations/)<br>
> start == size，則一組排列結果完成，for loop i，從 start 到size - 1，先swap start 和 i，start + 1 帶入遞迴，再swap start 和 i做恢復<br>
---


<br><br>
---

> [!NOTE]
一個實用的分類判斷法則<br>
遇到新題目時可以這樣快速判斷：<br>
**(1) [1,2] 和 [2,1] 算不算同一個答案？** <br>
算同一個 → Combination<br>
不算同一個 → Permutation<br>
**(2) 同一個元素能不能重複選？** <br>
不行 → 用 used[]（排列）或 start+1（組合)<br>
可以 → 排列時用 visited 但允許同層重複跳過；組合時遞迴呼叫用 start 而非 start+1<br>
**(3) 陣列本身有沒有重複數字，且要求結果不能重複？** <br>
有 → 先排序，遞迴時 if (i > start && nums[i] == nums[i-1]) continue; 做去重<br>



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
| 3090 | [Maximum Length Substring](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/) | 🟢 Easy | Sliding Window | [C++](./solution/Solution_3090.cpp) | O(N) | O(1) ||



<br><br>
---

## <a name="variable-size-sliding-window"></a>🔢Variable Size Sliding Window
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum) | 🟡 Medium | Array <br> Sliding Window <br> Binary Search | [C++](./solution/Solution_0209.cpp) | O(N) | O(1) |
| 0424 | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement) | 🟡 Medium | Sliding Window / Hash Table | [C++](./solution/Solution_0424.cpp) | O(N) | O(1) |
| 1004 | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii) | 🟡 Medium | Sliding Window | [C++](./solution/Solution_1004.cpp) | O(N) | O(1) |
| 1358 | [Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) | 🟡 Medium | Sliding Window | [C++](./solution/Solution_1358.cpp) | O(N) | O(1) |
| 2062 | [Count Vowel Substrings](https://leetcode.com/problems/count-vowel-substrings-of-a-string/) | 🟢 Easy | Sliding Window / Math | [C++](./solution/Solution_2062.cpp) | O(N) | O(1) | |

<br><br>
---

## <a name="sql"></a>🔢SQL
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0182 | [Duplicate Emails](https://leetcode.com/problems/duplicate-emails/) | 🟢 Easy | Database | [SQL](./solution/Solution_0182.sql) | O(N) | O(N) | 使用 GROUP BY 聚合相同 Email，並透過 HAVING 過濾出計數大於 1 的項目，達成簡潔的重複項篩選 |

<img src="https://github.com/smartcsie/leetcode/blob/main/images/206Reverse_Linked_List.png" width="570" height="705">


© 2026 Laurence Chang.


© 2026 Laurence Chang. 保持思考，持續進化。
