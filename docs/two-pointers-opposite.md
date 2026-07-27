## <a name="two-pointers-opposite"></a>👥 Two Pointers - Opposite Direction (對撞型)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | 🟡 Medium | Array <br> Two Pointers <br> Greedy | [C++](./solution/Solution_0011.cpp.md) | O(n) | O(1) |
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0015.cpp.md) | O(n²) | O(logn) |
| 0016 | [3Sum Closest](https://leetcode.com/problems/3sum-closest) | 🟡 Medium | Array <br> Two Pointers <br> Sorting | [C++](./solution/Solution_0016.cpp.md) | O(n²) | O(1) |
| 0018 | [4Sum](https://leetcode.com/problems/4sum/) | 🟡 Medium | Two Pointers / Sorting | [C++](./solution/Solution_0018.cpp.md) | O(N³) | O(1) |
| 0125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0125.cpp.md) | O(n) | O(1) |
| 0167 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted) | 🟡 Medium | Array <br> Two Pointers | [C++](./solution/Solution_0167.cpp.md) | O(n) | O(1) |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0344.cpp.md) | O(n) | O(1) |
| 0345 | [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string) | 🟢 Easy | String <br> Two Pointers | [C++](./solution/Solution_0345.cpp.md) | O(N) | O(1) |
| 0680 | [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_0680.cpp.md) | O(N) | O(1) | 
| 0917 | [Reverse Only Letters](https://leetcode.com/problems/reverse-only-letters/) | 🟢 Easy | Two Pointers / String | [C++](./solution/Solution_0917.cpp.md) | O(N) | O(1) |
| 0941 | [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0941.cpp.md) | O(n) | O(1) |
| 0942 | [DI String Match](https://leetcode.com/problems/di-string-match/) | 🟢 Easy | Greedy / Two Pointers |[C++](./solution/Solution_0942.cpp.md) | O(N) | O(N) | |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array) | 🟢 Easy | Array <br> Two Pointers | [C++](./solution/Solution_0977.cpp.md) | O(n) | O(n) |
| 1750 | [Minimum Length of String After Deleting Similar Ends](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends) | 🟡 Medium | String <br> Two Pointers | [C++](./solution/Solution_1750.cpp.md) | O(N) | O(1) |
| 1877 | [Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/) | 🟡 Medium | Array / Two Pointers / Greedy / Sorting | [C++](./solution/Solution_1877.cpp.md) | O(N log N) | O(1)* ||
| 2000 | [Reverse Prefix of Word](https://leetcode.com/problems/reverse-prefix-of-word/) | 🟢 Easy | Two Pointers / String | [C++](./solution/Solution_2000.cpp.md) | O(N) | O(1) |
| 2108 | [Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_2108.cpp.md) | O(N * L) | O(1) | [Note](#2108-find-first-palindromic-string-in-the-array) |
| 2562 | [Find the Array Concatenation Value](https://leetcode.com/problems/find-the-array-concatenation-value/) | 🟢 Easy | Two Pointers | [C++](./solution/Solution_2562.cpp.md) | O(N * D) | O(1) | [Note](#2562-find-the-array-concatenation-value) |
| 3794 | [Reverse String Prefix](https://leetcode.com/problems/reverse-string-prefix/) | 🟢 Easy | String / Two Pointers | [C++](./solution/Solution_3794.cpp.md) | O(N) | O(1) |
| 3884 | [First Matching Character From Both Ends](https://leetcode.com/problems/first-matching-character-from-both-ends/description/) | 🟢 Easy | Two-Pointers | [C++](./solution/Solution_3884.cpp.md) | O(N) | O(1) | |

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

