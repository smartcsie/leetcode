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
| **2195** | [Append K Integers With Minimal Sum](https://leetcode.com/problems/append-k-integers-with-minimal-sum/) | 🟡 Medium | Math / Binary Search | [C++](./solution/Solution_2195.cpp) | O(NlogN) | O(1) |  |
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

