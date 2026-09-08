/**
 * 題目：342. Power of Four
 * 難度：簡單 (Easy)
 * 描述：判斷一個整數是否為 4 的冪次方。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （迴圈除以 4）：
 * 反覆除以 4，最後若等於 1 則是 4 的冪次方。
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        while(n % 4 == 0) n /= 4;
        return n == 1;
    }
};