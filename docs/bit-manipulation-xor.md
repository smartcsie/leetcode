## <a name="Bit-manipulation-xor"></a>📊 Bit Manipulation - XOR operation (位元運算 - 互斥或運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0136 | [Single Number](https://leetcode.com/problems/single-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0136.cpp.md) | O(n) | O(1) | [Note](#0136-single-number) |
| **0260** | [Single Number III](https://leetcode.com/problems/single-number-iii) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_0260.cpp.md) | O(n) | O(1) | [Note](#0260-single-number-iii)
| 0268 | [Missing Number](https://leetcode.com/problems/missing-number) | 🟢 Easy | Bit-Manipulation | [C++](./solution/Solution_0268_2.cpp.md) | O(n) | O(1) | [Note](#0268-missing-number) |
| **0477** | [Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/) | 🟡 Medium | Math / Bit Manipulation / Array | [C++](./solution/Solution_477.cpp.md) | O(31 * N) | O(1) | |
| 1486 | [XOR Operation in an Array](https://leetcode.com/problems/xor-operation-in-an-array/) | 🟢 Easy | Simulation / Bit Manipulation | [C++](./solution/Solution_1486.cpp.md) | O(N) | O(1) |  |
| 1720 | [Decode XORed Array](https://leetcode.com/problems/decode-xored-array/) | 🟢 Easy | Bit Manipulation / Simulation | [C++](./solution/Solution_1720.cpp.md)| O(N) | O(N) | |
| 1863 | [Sum of All Subset XOR Totals](https://leetcode.com/problems/sum-of-all-subset-xor-totals/) | 🟢 Easy | Bit Manipulation / Math / Combinatorics | [C++](./solution/Solution_1863.cpp.md)  | O(N) | O(1) |  |
| **2317** | [Maximum XOR After Operations](https://leetcode.com/problems/maximum-xor-after-operations) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_2317.cpp.md) | O(n) | O(1) | [Note](#2317-maximum-xor-after-operations) |
| 2425 | [Bitwise XOR of All Pairings](https://leetcode.com/problems/bitwise-xor-of-all-pairings/) | 🟡 Medium | Bit Manipulation / Math | [C++](./solution/Solution_2425.cpp.md) | O(N + M) | O(1) | [Note](#2425-bitwise-xor-of-all-pairings) |
| 2429 | [Minimize XOR](https://leetcode.com/problems/minimize-xor/) | 🟡 Medium | Bit Manipulation / Greedy | [C++](./solution/Solution_2429.cpp.md) | O(1) | O(1) | [Note](#2429-minimize-xor) |
| 2433 | [Find The Original Array of Prefix Xor](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/) | 🟡 Medium | Bit Manipulation / Prefix XOR Inverse | [C++](./solution/Solution_2433.cpp.md) | O(N) | O(N) | |
| 2683 | [Neighboring Bitwise XOR](https://leetcode.com/problems/neighboring-bitwise-xor/) | 🟡 Medium | Bit Manipulation / Math | [C++](./solution/Solution_2683.cpp.md)  | O(N) | O(1) |  |
| 3158 | [Find the XOR of Numbers Which Appear Twice](https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/) | 🟢 Easy | Bit Manipulation / Array | [C++](./solution/Solution_3158.cpp.md) | O(N) | O(1) | |
| 3513 | [Number of Unique XOR Triplets I](https://leetcode.com/problems/number-of-unique-xor-triplets-i/) | 🟡 Medium | Math / Bit Manipulation / Brainteaser | [C++](./solution/Solution_3513.cpp.md) | O(log N) | O(1) ||
| 3702 | [Longest Subsequence With Non-Zero Bitwise XOR](https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/) | 🟡 Medium | Bit Manipulation / Greedy | [C++](./solution/Solution_3702.cpp.md) | O(N) | O(1) | [Note](#3702-longest-subsequence-with-non-zero-bitwise-xor) |

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


### 3702 Longest Subsequence With Non-Zero Bitwise XOR
> [Longest Subsequence With Non-Zero Bitwise XOR](https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/) <br>
> 三種case<br>
> case 1 : nums 全為 0，return 0<br>
> case 2 : nums 全部 xor 的結果不為 0，return nums.size()<br>
> case 3 : nums 全部 xor 的結果為 0，拿掉一個元素即可，return nums.size() - 1<br>
---



<br><br>
---

