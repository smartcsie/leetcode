# dynamic-programming

## 🔴 生疏（28）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 63 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 Medium | DP | [C++](../problems/0063.md) | O(M*N) | O(N) |
| 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | 🟡 Medium | DP | [C++](../problems/0064.md) | O(M*N) | O(1) |
| 72 | [Edit Distance](https://leetcode.com/problems/edit-distance/) | 🟡 Medium | DP, String | [C++](../problems/0072.md) | O(N*M) | O(N*M) |
| 96 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 Medium | Dynamic Programming, Math | [C++](../problems/0096.md) | O(N²) | O(N) |
| 97 | [Interleaving String](https://leetcode.com/problems/interleaving-string/) | 🟡 Medium | Dynamic Programming, Two Strings | [C++](../problems/0097.md) | O(M * N) | O(M * N) |
| 115 | [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) | 🔴 Hard | DP, String | [C++](../problems/0115.md) | O(S*T) | O(T) |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | 🟢 Easy | Dynamic Programming | [C++](../problems/0121.md) | O(N) | O(1) |
| 198 | [House Robber](https://leetcode.com/problems/house-robber/) | 🟢 Medium | DP, Linear Optimization | [C++](../problems/0198.md) | O(N) | O(1) |
| 213 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | 🟡 Medium | DP | [C++](../problems/0213.md) | O(N) | O(1) |
| 264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | 🟡 Medium | Dynamic Programming, Math | [C++](../problems/0264.md) | O(N) | O(N) |
| 300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 Medium | Array, Dynamic Programming | [C++](../problems/0300.md) | O(N²) | O(N) |
| 313 | [Super Ugly Number](https://leetcode.com/problems/super-ugly-number/) | 🟡 Medium | Dynamic Programming, Multi-pointers | [C++](../problems/0313.md) | O(N*K) | O(N+K) |
| 337 | [House Robber III](https://leetcode.com/problems/house-robber-iii/) | 🟡 Medium | Tree, DP | [C++](../problems/0337.md) | O(N) | O(H) |
| 392 | [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | 🟢 Easy | DP, LCS | [C++](../problems/0392.md) | O(S*T) | O(S*T) |
| 509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 Easy | Math, Dynamic Programming | [C++](../problems/0509.md) | O(N) | O(1) |
| 516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) | 🟡 Medium | DP, String | [C++](../problems/0516.md) | O(N²) | O(N) |
| 583 | [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings) | 🟡 Medium | Dynamic Programming | [C++](../problems/0583.md) | O(M*N) | O(M*N) |
| 712 | [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) | 🟡 Medium | Dynamic Programming, String | [C++](../problems/0712.md) | O(M×N) | O(M×N) |
| 718 | [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) | 🟡 Medium | DP, Array | [C++](../problems/0718.md) | O(N*M) | O(M) |
| 898 | [Bitwise ORs of Subarrays](https://leetcode.com/problems/bitwise-or-s-of-subarrays/) | 🟡 Medium | Bit Manipulation, Dynamic Programming | [C++](../problems/0898.md) | O(N*30) | O(N*30) |
| 926 | [Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/) | 🟡 Medium | Dynamic Programming | [C++](../problems/0926.md) | O(N) | O(1) |
| 1035 | [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/) | 🟡 Medium | DP, LCS | [C++](../problems/1035.md) | O(N*M) | O(M) |
| 1137 | [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | 🟢 Easy | DP, Math | [C++](../problems/1137.md) | O(N) | O(1) |
| 1277 | [Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) | 🟡 Medium | Matrix, Dynamic Programming | [C++](../problems/1277.md) | O(M*N) | O(1)* |
| 1567 | [Maximum Length of Subarray With Positive Product](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/) | 🟡 Medium | Dynamic Programming | [C++](../problems/1567.md) | O(N) - 僅需對 nums 陣列進行一次從頭到尾的線性掃描，每個元素的狀態轉移皆為常數時間。 | O(1) - 僅使用常數個變數（ans, pos, neg）來動態追蹤狀態，不需額外配置記憶體。 |
| 1668 | [Maximum Repeating Substring](https://leetcode.com/problems/maximum-repeating-substring/) | 🟢 Easy | String | [C++](../problems/1668.md) | O(N*M²) | O(M) |
| 2707 | [Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/) | 🟡 Medium | Dynamic Programming, Hash Set | [C++](../problems/2707.md) | O(N³) | O(N+D) |
| 2826 | [Sorting Three Groups](https://leetcode.com/problems/sorting-three-groups/) | 🟡 Medium | Dynamic Programming, Longest Non-Decreasing Subsequence | [C++](../problems/2826.md) | O(N) | O(1) |

## 🟠 再練習（5）

| # | 題目 | 難度 | 標籤 | 解法檔案 | 時間 | 空間 |
| --- | --- | --- | --- | --- | --- | --- |
| 53 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 Medium | Dynamic Programming | [C++](../problems/0053.md) | O(N) | O(N) |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 Easy | Dynamic Programming, DP, Unbounded Knapsack (Permutation) | [C++](../problems/0070.md) | O(N) | O(1) |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 Easy | Dynamic Programming | [C++](../problems/0070.md) | O(N) | O(N) |
| 674 | [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/) | 🟢 Easy | Dynamic Programming, DP | [C++](../problems/0674.md) | O(N) | O(N) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 Medium | Dynamic Programming | [C++](../problems/1143.md) | O(M*N) | O(M*N) |

## 🟡 練習過（0）

目前沒有標記為練習過的解法。

## 🟣 易忘（0）

目前沒有標記為易忘的解法。

## 🟢 熟悉（0）

目前沒有標記為熟悉的解法。
