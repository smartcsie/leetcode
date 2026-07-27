## <a name="Bit-manipulation-or"></a>📊 Bit Manipulation - OR operation (位元運算 - 或運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1318** | [Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/) | 🟡 Medium | Bit Manipulation | [C++](./solution/Solution_1318.cpp) | O(1) | O(1) | [Note](#1318-minimum-flips-to-make-a-or-b-equal-to-c) |
| **2917** | [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2917.cpp) | O(N * log(max_val)) | O(1) | [Note](#2917-find-the-k-or-of-an-array) |
| 2980 | [Check if Bitwise OR Has Trailing Zeros](https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/) | 🟢 Easy | Bit Manipulation <br> Math | [C++](./solution/Solution_2980.cpp) | O(N) | O(1) | [Note](#2980-check-if-bitwise-or-has-trailing-zeros) |
| **3314** | [Construct the Minimum Bitwise Array I](https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/) | 🟢 Easy | Bit Manipulation / Math | [C++](./solution/Solution_3314.cpp) | O(N) | O(N) |  |
| 3688 | [Bitwise OR of Even Numbers in an Array](https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3688.cpp) | O(N) | O(1) | [Note](#3688-bitwise-or-of-even-numbers-in-an-array) |

### 1318 Minimum Flips to Make a OR b Equal to c
> [Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/)<br>
> **int diff = (a | b) ^ c;** <br>
> **int flips = __builtin_popcount(diff & ~c) + __builtin_popcount(a & b & diff);** <br>

---


### 2917 Find the K-or of an Array
> [Find the K-or of an Array](https://leetcode.com/problems/find-the-k-or-of-an-array)<br>
> 起回圈i = 0到31 <br>
> count = 0，travsal 每個數，(num >> i) & 1加到count<br>
> 如果count >= k， res |= (1<<i)<br>
---


### 2980 Check if Bitwise OR Has Trailing Zeros
> [Check if Bitwise OR Has Trailing Zeros](https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/)<br>
> travsal nums，出現兩個even number，return true<br>

---

### 3688 Bitwise OR of Even Numbers in an Array
> [Bitwise OR of Even Numbers in an Array](https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/) <br>
> int res = 0，把所有even number OR 到res上<br>

<br><br>
---

