## <a name="math-factor-enumeration"></a>🔢 Math - Factor Enumeration(數學 因式分解)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **0507** | [Perfect Number](https://leetcode.com/problems/perfect-number/) | 🟢 Easy | Math | [C++](./solution-pages/Solution_0507.md) | O(√N) | O(1) | [Note](#0507-perfect-number) |
| **1492** | [The kth Factor of n](https://leetcode.com/problems/the-kth-factor-of-n/) | 🟡 Medium | Math | [C++](./solution-pages/Solution_1492.md) | O(√N) | O(1) |  [Note](#1492-the-kth-factor-of-n)|
| 2169 | [Count Operations to Obtain Zero](https://leetcode.com/problems/count-operations-to-obtain-zero/) | 🟢 Easy | Euclidean Algorithm / Simulation | [C++](./solution-pages/Solution_2169.md)  | O(log(min(num1, num2))) | O(1) ||
| **2507** | [Smallest Value After Replacing With Sum of Prime Factors](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/) | 🟡 Medium | Math / Prime Factorization | [C++](./solution-pages/Solution_2507.md) | O(log N * sqrt(N)) | O(1) ||
| 2427 | [Number of Common Factors](https://leetcode.com/problems/number-of-common-factors/) | 🟢 Easy | Math / Number Theory / GCD | [C++](./solution-pages/Solution_2427.md) | O(min(A, B)) | O(1) | |

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


