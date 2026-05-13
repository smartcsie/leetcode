# LeetCode 演算法精鍊筆記 (C++)

![LeetCode Stats](https://leetcard.jacoblin.cool/smartcsie?theme=nord) <!-- 註：將 laurence 換成你的 LeetCode ID -->

本倉庫用於記錄我的 LeetCode 解題過程、思路分析以及演算法優化心得。作為一名專注於 ADAS 模擬與感知系統的工程師，我習慣從系統效能與內存管理的角度出發，尋找最優解。

---

--

## 🚀 快速導覽

[#Bit-manipulation](#Bit-manipulation) | [#Array](#array) | [#Hash-Table](#hash-table) | [#Math](#math) | [#Binary-Search](#binary-search) | [#Stack](#stack) <br>
[#Tree](#tree) | [#Two-Pointers](#two-pointers) | [#Linked-List](#linked-list) | [#String](#string) <br>
[#Dynamic Programming](#dynamic-programming)

---

## <a name="Bit-manipulation"></a>📊 Bit Manipulation (位元運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0136 | [Single Number](https://leetcode.com/problems/single-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0136.cpp) | O(n) | O(1) | XOR 運算特性 |
| 0137 | [Single Number II](https://leetcode.com/problems/single-number-ii) | 🟡 Medium | Bit-Manipulation | [C++](./solution/Solution_0137.cpp) | O(n) | O(1) | 位元計數法 |
| 0190 | [Reverse Bits](https://leetcode.com/problems/reverse-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0190.cpp) | O(1) | O(1) | 32 位元固定遍歷 |
| 0191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0191.cpp) | O(1) | O(1) | n & (n-1) 優化 |
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0268_2.cpp) | O(n) | O(1) | XOR 或數學求和 |

---

## <a name="math"></a>🔢 Math (數學)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0007 | [Reverse Integer](https://leetcode.com/problems/reverse-integer/) | 🟡 Medium | Math | [C++](./solution/Solution_0007.cpp) | O(log n) | O(1) | 注意數值溢位 |
| 0009 | [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0009.cpp) | O(log n) | O(1) | 負數直接回傳 false |
| 0041 | [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | 🔴 Hard | Math | [C++](./solution/Solution_0041.cpp) | O(n) | O(1) | 原地哈希 (In-place Hash) |
| 0066 | [Plus One](https://leetcode.com/problems/plus-one/) | 🟢 Easy | Math | [C++](./solution/Solution_0066.cpp) | O(n) | O(1) | 考慮進位與長度增加 |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two/) | 🟢 Easy | Math | [C++](./solution/Solution_0231.cpp) | O(1) | O(1) | n > 0 && (n & (n-1)) == 0 |
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number/) | 🟢 Easy | Math | [C++](./solution/Solution_0268.cpp) | O(n) | O(1) | 高斯求和公式 |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three/) | 🟢 Easy | Math | [C++](./solution/Solution_0326.cpp) | O(log3 n) | O(1) | 遞迴或迭代處理 |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four/) | 🟢 Easy | Math | [C++](./solution/Solution_0342.cpp) | O(1) | O(1) | 位元遮罩判斷 |

---

## <a name="binary-search"></a>🔍 Binary Search (二分查找)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0004 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) | 🔴 Hard | Binary Search | [C++](./solution/Solution_0004.cpp) | O(log(m+n)) | O(1) | 分割線劃分法 |
| 0035 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0035.cpp) | O(log n) | O(1) | 標準左邊界二分 |
| 0069 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0069.cpp) | O(log n) | O(1) | 二分查找平方根 |
| 0153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0153.cpp) | O(log n) | O(1) | 旋轉數組最小值 |
| 0278 | [First Bad Version](https://leetcode.com/problems/first-bad-version/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0278.cpp) | O(log n) | O(1) | 最小化呼叫 API 次數 |
| 0367 | [Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0367.cpp) | O(log n) | O(1) | 防止中間平方溢位 |
| 0374 | [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0374.cpp) | O(log n) | O(1) | 猜數字邊界逼近 |
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search/) | 🟢 Easy | Binary Search | [C++](./solution/Solution_0704.cpp) | O(log n) | O(1) | 二分查找模板題 |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 Medium | Binary Search | [C++](./solution/Solution_0852.cpp) | O(log n) | O(1) | 尋找局部極大值 |

---

## <a name="hash-table"></a>🔑 Hash Table (哈希表)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0001.cpp) | O(n) | O(n) | 邊遍歷邊查找補數 |
| 0217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0217.cpp) | O(n) | O(n) | unordered_set 去重 |
| 0219 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii) | 🟢 Easy | Hash Table / Sliding Window | [C++](./solution/Solution_0219.cpp) | O(n) | O(min(n,k)) | 固定窗口哈希 |
| 0242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | 🟢 Easy | Hash Table / String | [C++](./solution/Solution_0242.cpp) | O(n) | O(1) | 26 位頻率陣列 |
| 0349 | [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0349.cpp) | O(n+m) | O(n) | 集合求交集 |
| 0350 | [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_0350.cpp) | O(n+m) | O(min(n,m)) | 哈希計數器 |
| 0387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) | 🟢 Easy | Hash Table / String | [C++](./solution/Solution_0387.cpp) | O(n) | O(1) | 兩次遍歷法 |
| 0454 | [4Sum II](https://leetcode.com/problems/4sum-ii) | 🟡 Medium | Hash Table | [C++](./solution/Solution_0454.cpp) | O(n²) | O(n²) | 拆分兩兩求和 |
| 2215 | [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2215.cpp) | O(n+m) | O(n+m) | 雙 Set 差集運算 |
| 2248 | [Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/) | 🟢 Easy | Hash Table | [C++](./solution/Solution_2248.cpp) | O(n*m) | O(n) | 多數組計數過濾 |

---

## <a name="string"></a>🔗 String (字串)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0459 | [Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern) | 🟢 Easy | String / KMP | [C++](./solution/Solution_0459.cpp) | O(n) | O(n) | S+S 技巧或 KMP |

---

## <a name="array"></a>📊 Array (數組)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0048 | [Rotate Image](https://leetcode.com/problems/rotate-image/) | 🟡 Medium | Array | [C++](./solution/Solution_0048.cpp) | O(n²) | O(1) | 轉置 + 左右翻轉 |
| 0189 | [Rotate Array](https://leetcode.com/problems/rotate-array/) | 🟡 Medium | Array | [C++](./solution/Solution_0189.cpp) | O(n) | O(1) | 三步翻轉法 |
| 0442 | [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array) | 🟡 Medium | Array | [C++](./solution/Solution_0442.cpp) | O(n) | O(1) | 符號標記法 |
| 0448 | [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array) | 🟢 Easy | Array | [C++](./solution/Solution_0448.cpp) | O(n) | O(1) | 索引映射標記 |
| 1886 | [Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/) | 🟢 Easy | Array | [C++](./solution/Solution_1886.cpp) | O(n²) | O(1) | 模擬 4 次 90 度旋轉 |

---

## <a name="two-pointers"></a>👥 Two Pointers (雙指針)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0026 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0026.cpp) | O(n) | O(1) | 快慢指標去重 |
| 0027 | [Remove Element](https://leetcode.com/problems/remove-element/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0027.cpp) | O(n) | O(1) | 快慢指標覆蓋 |
| 0080 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | 🟡 Medium | Two Pointers | [C++](./solution/Solution_0080.cpp) | O(n) | O(1) | 容許重複兩次指標控制 |
| 0167 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) | 🟢 Medium | Two Pointers | [C++](./solution/Solution_0167.cpp) | O(n) | O(1) | 左右指標向中間逼近 |
| 0283 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0283.cpp) | O(n) | O(1) | 快慢指標交換元素 |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0344.cpp) | O(n) | O(1) | 左右交換 |
| 0392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0392.cpp) | O(n) | O(1) | 匹配貪婪法指標 |
| 0540 | [Minimum Common Value](https://leetcode.com/problems/minimum-common-value/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0540.cpp) | O(n+m) | O(1) | 雙陣列同步指標 |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array) | 🟢 Easy | Array / Two Pointers | [C++](./solution/Solution_0977.cpp) | O(n) | O(n) | 兩端向中間填入 |

---

## <a name="linked-list"></a>🔗 Linked List (鏈表)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0021 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | 🟢 Easy | Linked List | [C++](./solution/Solution_0021.cpp) | O(n+m) | O(1) | 虛擬頭節點法 |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 Easy | Linked List | [C++](./solution/Solution_0141.cpp) | O(n) | O(1) | 快慢指標 (龜兔賽跑) |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | 🟢 Easy | Linked List | [C++](./solution/Solution_0206.cpp) | O(n) | O(1) | 迭代三指針法 |

---

## <a name="stack"></a>🔗 Stack (堆疊)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 Easy | Stack | [C++](./solution/Solution_0020.cpp) | O(n) | O(n) | 括號匹配壓棧 |

---

## <a name="tree"></a>🌳 Tree (樹結構)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | 🟡 Medium | Tree | [C++](./solution/Solution_0098.cpp) | O(n) | O(h) | 中序遍歷遞增或遞迴範圍 |
| 0100 | [Same Tree](https://leetcode.com/problems/same-tree/) | 🟢 Easy | Tree | [C++](./solution/Solution_0100.cpp) | O(n) | O(h) | 遞迴結構比較 |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | 🟡 Medium | Tree, BFS | [C++](./solution/Solution_0102.cpp) | O(n) | O(w) | Queue 層序遍歷 |
| 0104 | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | 🟢 Easy | Tree, DFS | [C++](./solution/Solution_0104.cpp) | O(n) | O(h) | 後序遍歷高度 |
| 0110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | 🟢 Easy | Tree, DFS | [C++](./solution/Solution_0110.cpp) | O(n) | O(h) | 自底向上遞迴判斷高度差 |
| 0111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) | 🟢 Easy | Tree / BFS / DFS | [C++](./solution/Solution_0111.cpp) | O(n) | O(h) | 找第一個葉子節點 |
| 0112 | [Path Sum](https://leetcode.com/problems/path-sum/) | 🟢 Easy | Tree | [C++](./solution/Solution_0112.cpp) | O(n) | O(h) | 遞迴減去節點值 |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0144.cpp) | O(n) | O(h) | 根-左-右 |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0145.cpp) | O(n) | O(h) | 左-右-根 |
| 0199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | 🟡 Medium | Tree, BFS | [C++](./solution/Solution_0199.cpp) | O(n) | O(w) | 取每層最後一個節點 |
| 0226 | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | 🟢 Easy | Tree | [C++](./solution/Solution_0226.cpp) | O(n) | O(h) | 遞迴交換左右子樹 |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | 🟢 Easy | Tree, DFS | [C++](./solution/Solution_0543.cpp) | O(n) | O(h) | 左右高度和的最大值 |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 Easy | Tree / DFS | [C++](./solution/Solution_0572.cpp) | O(n*m) | O(h) | 對每個節點做 SameTree |
| 0589 | [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0589.cpp) | O(n) | O(h) | 多叉樹前序遍歷 |
| 0590 | [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/) | 🟢 Easy | Tree | [C++](./solution/Solution_0590.cpp) | O(n) | O(h) | 多叉樹後序遍歷 |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/) | 🟡 Medium | Tree, BFS | [C++](./solution/Solution_0662.cpp) | O(n) | O(w) | 給節點編號防溢位 |
| 1609 | [Even Odd Tree](https://leetcode.com/problems/even-odd-tree/) | 🟡 Medium | Tree, BFS | [C++](./solution/Solution_1609.cpp) | O(n) | O(w) | 層序遍歷判斷數值規律 |

---

## <a name="dynamic-programming"></a>📊 Dynamic Programming (動態規劃)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 備註 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 Medium | Array / DP | [C++](./solution/Solution_0053.cpp) | O(n) | O(1) | Kadane's Algorithm |
| 0070 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 Easy | Math / DP | [C++](./solution/Solution_0070.cpp) | O(n) | O(1) | 斐波那契優化 |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Array / DP | [C++](./solution/Solution_0300.cpp) | O(n log n) | O(n) | Binary Search + Greedy 最佳 |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 Easy | Math / DP | [C++](./solution/Solution_0509.cpp) | O(n) | O(1) | 滾動變數迭代優化 |
| 0583 | [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) | 🟡 Medium | DP | [C++](./solution/Solution_0583.cpp) | O(m*n) | O(m*n) | 總長減去兩倍 LCS |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 Medium | DP | [C++](./solution/Solution_1143.cpp) | O(m*n) | O(m*n) | 二維填表法 |

---

© 2026 Laurence Chang.


<details>
<summary>下拉是選單</summary>
- 項目 1<br>
- 項目 2
</details>

---

## 🤖 Resource
- **<span style="color:red">[youngyangyang04](https://github.com/youngyangyang04/leetcode-master)</span>**
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
---
## 🤖 電子書
- [Cracking the Coding Interview 6th 中文](https://github.com/F8F-1BearCat/CtCI-6th-Edition-CN/tree/master)


## 🤖 面試考題
- [Google](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Google)
- [Nvidia](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Nvidia)
- [Amazon](https://github.com/liquidslr/interview-company-wise-problems/tree/main/Amazon)

© 2026 Laurence Chang. 保持思考，持續進化。
