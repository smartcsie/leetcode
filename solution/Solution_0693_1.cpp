/**
 * 題目：693. Binary Number with Alternating Bits
 * 難度：簡單 (Easy)
 * 描述：判斷一個正整數的二進位表示中，相鄰位元是否交替出現 0 和 1。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （逐位檢查）：
 * 每次比較最低位和次低位是否相同，相同則不是交替，不同則右移繼續檢查。
 */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n > 1) {
            if ((n & 1) == ((n >> 1) & 1)) return false;
            n >>= 1;
        }
        return true;
    }
};