# backtracking-combination

## 🔴 生疏（13）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | 🟡 Medium | Backtracking | [C++](../problems/0017.md) | O(4^N) | O(N) |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | 🟡 Medium | Backtracking, String | [C++](../problems/0022.md) | O(4ᴺ/√N) | O(N) |
| 39 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | 🟡 Medium | Backtracking | [C++](../problems/0039.md) | O(N^(T/M)) | O(T/M) |
| 40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | 🟡 Medium | Backtracking, Sorting | [C++](../problems/0040.md) | O(2ᴺ) | O(N) |
| 77 | [Combinations](https://leetcode.com/problems/combinations/) | 🟡 Medium | Backtracking | [C++](../problems/0077.md) | O(K*C(N,K)) | O(K) |
| 78 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 Medium | Backtracking, Recursion, Bit Manipulation | [C++](../problems/0078.md) | O(N*2ᴺ) | O(N) |
| 79 | [Word Search](https://leetcode.com/problems/word-search/) | 🟡 Medium | DFS, Backtracking | [C++](../problems/0079.md) | O(N*3ᴸ) | O(L) |
| 90 | [Subsets II](https://leetcode.com/problems/subsets-ii/) | 🟡 Medium | Backtracking, Sorting | [C++](../problems/0090.md) | O(N*2ᴺ) | O(N) |
| 131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) | 🟡 Medium | Backtracking Combination | [C++](../problems/0131.md) | O(N | O(N)（遞迴堆疊 + 目前路徑） |
| 216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | 🟡 Medium | Backtracking | [C++](../problems/0216.md) | O(C(9,K)) | O(K) |
| 638 | [Shopping Offers](https://leetcode.com/problems/shopping-offers/) | 🟡 Medium | Backtracking Combination | [C++](../problems/0638.md) | O(優惠數量^商品種類數)（最壞情況，實務上因為需求量有限 | O(商品種類數)（遞迴深度） |
| 784 | [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) | 🟡 Medium | Backtracking | [C++](../problems/0784.md) | O(2ᴺ) | O(N) |
| 1593 | [Split a String Into the Max Number of Unique Substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/) | 🟡 Medium | Backtracking Combination | [C++](../problems/1593.md) | O(N*2^(N-1)) - 在最壞情況下，字串有 n-1 個可分割的間隙，總共有 2^(n-1) 種分割組合，每次分割與子字串截取需花費 O(N) 時間。 | O(N) - 遞迴呼叫堆疊的深度最多為 n，且雜湊表 `seen` 在任一時刻最多儲存 n 個子字串。 |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（0）

目前沒有標記為練習過的解法。

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。
