## <a name="prime"></a>🔢 Math Prime(數學 質數)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0204 | [Count Primes](https://leetcode.com/problems/count-primes/) | 🟡 Medium | Math / Sieve | [C++](./solution/Solution_0204.cpp) | O(NloglogN) | O(N) | [Note](#0204-count-primes) |
| 2521 | [Distinct Prime Factors of Product of Array](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/) | 🟡 Medium | Math / Prime Factorization | [C++](./solution/Solution_2521.cpp) | O(N*sqrt(M)) | O(K) |[Note](#2521-distinct-prime-factors-of-product-of-array) |
| **2523** | [Closest Prime Numbers in Range](https://leetcode.com/problems/closest-prime-numbers-in-range/) | 🟡 Medium | Math / Sieve | [C++](./solution/Solution_2523.cpp) | O(Nloglog N) | O(N) | [Note](#2523-closest-prime-numbers-in-range) | 
| 2614 | [Prime In Diagonal](https://leetcode.com/problems/prime-in-diagonal/) | 🟢 Easy | Math / Trial Division | [C++](./solution/Solution_2614.cpp) | O(N * sqrt(M)) | O(1) | [Note](#2614-prime-in-diagonal) |
| 2761 | [Prime Pairs With Target Sum](https://leetcode.com/problems/prime-pairs-with-target-sum/) | 🟡 Medium | Math <br> Sieve | [C++](./solution/Solution_2761.cpp) | O(NloglogN) | O(N) | [Note](#2761-prime-pairs-with-target-sum)|
| 3591 | [Check if Any Element Has Prime Frequency](https://leetcode.com/problems/check-if-any-element-has-prime-frequency/) | 🟢 Easy | Array <br> Hash Table | [C++](./solution/Solution_3591.cpp) | O(N + Kloglog K) | O(K) | [Note](#3591-check-if-any-element-has-prime-frequency) |
| 3618 | [Split Array by Prime Indices](https://leetcode.com/problems/split-array-by-prime-indices/) | 🟢 Easy | Math / Sieve | [C++](./solution/Solution_3618.cpp) | O(N + RloglogR) | O(R) | [Note](#3618-split-array-by-prime-indices) |
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

