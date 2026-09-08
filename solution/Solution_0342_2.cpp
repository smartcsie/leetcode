/**
 * 題目：342. Power of Four
 * 難度：簡單 (Easy)
 * 描述：判斷一個整數是否為 4 的冪次方。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （位元運算）：
 * 4 的冪次方必須是 2 的冪次方（只有一個 1 bit），且 n-1 必須能被 3 整除。
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && __builtin_popcount(n) == 1 && (n - 1) % 3 == 0;
    }
};