## <a name="Hamming Distance"></a>📊 Bit Manipulation - Hamming Distance (位元運算 漢明距離)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0461 | [Hamming Distance](https://leetcode.com/problems/hamming-distance) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_0461.cpp) | O(k) | O(1) | [Note](#0461-hamming-distance) |
| 2220 | [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_2220.cpp) | O(log(max(start, goal))) | O(1) | [Note](#2220-minimum-bit-flips-to-convert-number) |
| **3226** | [Number of Bit Changes to Make Two Integers Equal](https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3226.cpp) | O(1) | O(1) | [Note](#3226-number-of-bit-changes-to-make-two-integers-equal) |
| 3750 | [Minimum Number of Flips to Reverse Binary String](https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/) | 🟢 Easy | Bit Manipulation | [C++](./solution/Solution_3750.cpp) | O(log N) | O(1) | [Note](#3750-minimum-number-of-flips-to-reverse-binary-string) |

### 0461 Hamming Distance
> [Hamming Distance](https://leetcode.com/problems/hamming-distance)<br>
> x和y做互斥或成為z，取z的2進制1的個數<br>

---

### 2220 Minimum Bit Flips to Convert Number
> [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number) <br>
> x和y做互斥或成為z，取z的2進制1的個數<br>
> start和goal做互斥或成為n，取n的2進制1的個數<br>
<br><br>
---

### 3226 Number of Bit Changes to Make Two Integers Equal
> [Number of Bit Changes to Make Two Integers Equal](https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/) <br>
> **先確認k是n的binary子集合，也就是 n&k == k，如果沒有return -1**<br>
> 接下來找n和k的hamming distance(n ^ k找1的個數)，回傳結果<br>

---

### 3750 Minimum Number of Flips to Reverse Binary String
> [Minimum Number of Flips to Reverse Binary String](https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/)<br>
> 先求binary string的reverse，取n和reverse的Hamming Distance<br>

<br><br>
---


