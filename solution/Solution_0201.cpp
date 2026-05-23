/**
 * 題目：201. Bitwise AND of Numbers Range (數字範圍按位與)
 * 難度：中等 (Medium)
 * 描述：給定兩個整數 left 和 right，返回範圍 [left, right] 內所有數字按位與 (AND) 的結果。
 * 
 * 時間複雜度：O(K)，其中 K 為二進位位元的數量（最多 31 次操作）。
 * 空間複雜度：O(1)。
 * 
 * 解法思路 (Brian Kernighan's Algorithm)：
 * 1. 區間內所有數進行 AND 運算，結果必定只剩下所有數共同擁有的「前綴位元」。
 * 2. 如果 `right > left`，代表在這個範圍內至少有兩個數字，這兩個數字之間一定會發生進位變化，
 *    導致最低位的 bit 變成 0。
 * 3. 透過 `right &= (right - 1)`，我們不斷清除 `right` 的最低位 1，
 *    直到 `right` 變小至小於或等於 `left`，此時剩餘的 `right` 即為所有數字的共同前綴。
 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 透過不斷清除 right 最右邊的 1，直到 right 縮小至 [left, right] 的公共前綴
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }
};
