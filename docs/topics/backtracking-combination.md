# backtracking-combination

## 🔴 生疏（15）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 17 | [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | 🟡 Medium | Backtracking | [C++](../problems/0017.md) | O(4^N) | O(N) |
| 22 | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | 🟡 Medium | Backtracking, String | [C++](../problems/0022.md) | O(4ᴺ/√N) | O(N) |
| 39 | [Combination Sum](https://leetcode.com/problems/combination-sum/) | 🟡 Medium | Backtracking | [C++](../problems/0039.md) | O(N^(T/M)) | O(T/M) |
| 40 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) | 🟡 Medium | Backtracking, Sorting | [C++](../problems/0040.md) | O(2ᴺ) | O(N) |
| 77 | [Combinations](https://leetcode.com/problems/combinations/) | 🟡 Medium | Backtracking | [C++](../problems/0077.md) | O(K\*C(N,K)) | O(K) |
| 78 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 Medium | Backtracking Combination, Backtracking, Recursion | [C++](../problems/0078.md) | O(N\*2ᴺ) | O(N) |
| 90 | [Subsets II](https://leetcode.com/problems/subsets-ii/) | 🟡 Medium | Backtracking, Sorting | [C++](../problems/0090.md) | O(N\*2ᴺ) | O(N) |
| 131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) | 🟡 Medium | Backtracking Combination | [C++](../problems/0131.md) | O(N × 2^N)（最壞情況，回溯窮舉所有切割方式） | O(N)（遞迴堆疊 + 目前路徑） |
| 216 | [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/) | 🟡 Medium | Backtracking | [C++](../problems/0216.md) | O(C(9,K)) | O(K) |
| 638 | [Shopping Offers](https://leetcode.com/problems/shopping-offers/) | 🟡 Medium | Backtracking Combination | [C++](../problems/0638.md) | O(∏(needs[i]+1) × 優惠數量)，最壞情況約 O(11^N × K) | O(∏(needs[i]+1))（記憶化表的大小） |
| 784 | [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/) | 🟡 Medium | Backtracking | [C++](../problems/0784.md) | O(2ᴺ) | O(N) |
| 1255 | [Maximum Score Words Formed by Letters](https://leetcode.com/problems/maximum-score-words-formed-by-letters/) | 🔴 Hard | Backtracking Combination | [C++](../problems/1255.md) | O(2^N)，N 是單字數量（最多 14 個，2^14 可接受） | O(26)（字母預算陣列 + 遞迴深度） |
| 1415 | [The k-th Lexicographical String of All Happy Strings of Length n](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/) | 🟡 Medium | Backtracking Combination | [C++](../problems/1415.md) | O(3 × 2^(N-1))（最壞情況窮舉所有快樂字串，但因為題目 | O(N)（遞迴深度 + 目前路徑） |
| 1593 | [Split a String Into the Max Number of Unique Substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/) | 🟡 Medium | Backtracking Combination | [C++](../problems/1593.md) | O(N\*2^(N-1)) - 在最壞情況下，字串有 n-1 個可分割的間隙，總共有 2^(n-1) 種分割組合，每次分割與子字串截取需花費 O(N) 時間。 | O(N) - 遞迴呼叫堆疊的深度最多為 n，且雜湊表 `seen` 在任一時刻最多儲存 n 個子字串。 |
| 2044 | [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) | 🟡 Medium | Backtracking Combination | [C++](../problems/2044.md) | O(2^N) | O(N) |

## 🟠 再練習（0）

目前沒有標記為再練習的解法。

## 🟡 練習過（0）

目前沒有標記為練習過的解法。

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。
