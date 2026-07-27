## <a name="dynamic-programming"></a>🧩 Dynamic Programming (動態規劃)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 Medium | DP | [C++](./solution/Solution_0063.cpp) | O(m*n) | O(n) | [Note](#0063-unique-paths-ii) |
| 0064 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | 🟡 Medium | DP | [C++](./solution/Solution_0064.cpp) | O(M*N) | O(1) |
| 0070 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0070.cpp) | O(n) | O(1) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 Medium | Dynamic Programming <br> Math | [C++](./solution/Solution_0096.cpp) | O(N²) | O(N) |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | 🟡 Medium | Dynamic Programming <br> Math | [C++](./solution/Solution_0264.cpp) | O(n) | O(n) |
| 0313 | [Super Ugly Number](https://leetcode.com/problems/super-ugly-number/) | 🟡 Medium | Dynamic Programming <br> Multi-pointers | [C++](./solution/Solution_0313.cpp) | O(N * K) | O(N + K) | |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 Easy | Math <br> Dynamic Programming | [C++](./solution/Solution_0509.cpp) | O(n) | O(1) | 
| **0898** | [Bitwise ORs of Subarrays](https://leetcode.com/problems/bitwise-or-s-of-subarrays/) | 🟡 Medium | Bit Manipulation / Dynamic Programming | [C++](./solution/Solution_0898.cpp) | O(N * 30) | O(N * 30) ||
| **0926** | [Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/) | 🟡 Medium | Dynamic Programming | [C++](./solution/Solution_0926.cpp) | O(N) | O(1) | |
| 1137 | [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | 🟢 Easy | DP <br> Math | [C++](./solution/Solution_1137.cpp) | O(N) | O(1) |
| 1277 | [Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) | 🟡 Medium | Matrix / Dynamic Programming | [C++](./solution/Solution_1277.cpp) | O(M * N) | O(1)* |  |
| 1668 | [Maximum Repeating Substring](https://leetcode.com/problems/maximum-repeating-substring/) | 🟢 Easy | String | [C++](./solution/Solution_1668.cpp) | O(N*M²) | O(M) |
| 2707 | [Extra Characters in a String](https://leetcode.com/problems/extra-characters-in-a-string/) | 🟡 Medium | Dynamic Programming / Hash Set | [C++](./solution/Solution_2707.cpp) | O(N³ + M*L) | O(N + M * L) | |


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


