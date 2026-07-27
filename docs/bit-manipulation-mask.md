## <a name="Bit-manipulation-mask"></a>📊 Bit Manipulation - Mask (位元運算 - 遮罩)
| # | 題目 | 難度 | 標籤 | 程式碼 | 時間 | 空間 | 詳解 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0318 | [Maximum Product of Word Lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/) | 🟡 Medium | Bit Manipulation / Bitmask | [C++](./solution/Solution_318.cpp.md) | O(N * L + N^2) | O(N) |  |
| 2605 | [Form Smallest Number From Two Digit Arrays](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/) | 🟢 Easy | Bit Manipulation / Bitmask | [C++](./solution/Solution_2605.cpp.md) | O(N + M) | O(1) | [Note](#2605-form-smallest-number-from-two-digit-arrays) |



### 2605 Form Smallest Number From Two Digit Arrays
> [Form Smallest Number From Two Digit Arrays](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/) <br>
> **此題總共有四種作法**<br>
> [法一 int mask](./solution/Solution_2605.cpp.md)，Time:O(N+M)，Time:O(1)<br>
> [法二 雙迴圈暴力法](./solution/Solution_2605_1.cpp.md)，Time:O(N*M)，Time:O(1)<br>
> [法三 bitset](./solution/Solution_2605_2.cpp.md)，Time:O(N+M)，Time:O(1)<br>
> [法四 unordered_map](./solution/Solution_2605_3.cpp.md)，Time:O(N+M)，Time:O(M)<br>
> 因為只有0~9，兩個mask 紀錄數字出現位置，int mask1 = 0, mask2 = 0;<br>
> **for(const int& num : nums1) mask1 |= 1 << num;** <br>
> **for(const int& num : nums2) mask2 |= 1 << num;** <br>
> 如果出現相同數字，取最小的回傳，ctz是算幾個0，等於剛才紀錄的最小數
> **if(mask1 & mask2) return __builtin_ctz(mask1 & mask2);** <br>
> 如果沒有相同數字，min2 * 10 + min1 和 min1 * 10 + min2;，取小的回傳<br>
> **int min1 = __builtin_ctz(mask1);** <br>
> **int min2 = __builtin_ctz(mask2);** <br>
> **return (min1 > min2) ? min2 * 10 + min1 : min1 * 10 + min2;** <br>



<br><br>
---

