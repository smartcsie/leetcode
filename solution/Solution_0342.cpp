/**
 * 題目：342. Power of Four
 * 難度：簡單 (Easy)
 * 描述：判斷一個整數是否為 4 的冪次方。
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)

 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555) != 0;
    }
};