## <a name="Bit-manipulation-and"></a>📊 Bit Manipulation - AND operation (位元運算 - 及運算)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0191 | [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits) | 🟢 Easy | Bit-Manipulation | [C++](./solution-pages/Solution_0191.md) | O(1) | O(1) | [Note](#0191-number-of-1-bits) |
| 0201 | [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range) | 🟡 Medium | Bit Manipulation | [C++](./solution-pages/Solution_0201.md) | O(logn) | O(1) | [Note](#0201-bitwise-and-of-numbers-range)|
| 0338 | [Counting Bits](https://leetcode.com/problems/counting-bits) | 🟢 Easy | DP <br> Bit Manipulation | [C++](./solution-pages/Solution_0338.md) | O(n) | O(n) | [Note](#0338-counting-bits) |
| 0693 | [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/) | 🟢 Easy | Bit Manipulation | [C++](./solution-pages/Solution_0693.md) | O(1) | O(1) | [Note](#0693-binary-number-with-alternating-bits) |
| 2275 | [Largest Combination With Bitwise AND Greater Than Zero](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/) | 🟡 Medium | Bit Manipulation / Greedy | [C++](./solution-pages/Solution_2275.md) | O(32 * N) | O(1) ||
| 2309 | [Greatest English Letter in Upper and Lower Case](https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/) | 🟢 Easy | Hash Table / String / Bit Manipulation | [C++](./solution-pages/Solution_2309.md) | O(N) | O(1) | |
| 2419 | [Longest Subarray With Maximum Bitwise AND](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/) | 🟡 Medium | Bit Manipulation / Greedy / Array | [C++](./solution-pages/Solution_2419.md) | O(N) | O(1) | |


### 0191 Number of 1 Bits
> [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits)<br>
> 使用 **Brian Kernighan's Algorithm** ，**n = n & (n - 1)**，有 build in function可以用<br>
> **(1)** C++20，std::popcount(static_cast<unsigned int>(n)) 或  **(2)** 若編譯器(GCC/Clang)支援， __builtin_popcount(n) <br>
---

### 0201 Bitwise AND of Numbers Range
> [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range)<br>
> 使用 **Brian Kernighan's Algorithm** ，**right = right & (right - 1)**， while(right > left) <br>
---

### 0338 Counting Bits
> [Counting Bits](https://leetcode.com/problems/counting-bits)<br>
> **Brian Kernighan's Algorithm** ，**n & (n - 1)，其實是去掉最右邊的1**<br>
> vector<int> count(n + 1, 0);<br>
> for(int i = 1; i <= n; i++) count[i] = count[i & (i - 1)] + 1;<br>


### 0693 Binary Number with Alternating Bits
> [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/)<br>
> n先mod 4等於t，檢查11(t & 3) == 3，檢查00(t ^ 3) == 3，符合就回傳false<br>
---

<br><br>
---

