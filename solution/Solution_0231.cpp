/**
 * 題目：231. Power of Two
 * 難度：簡單 (Easy)
 * 描述：判斷一個整數是否為 2 的冪次方。
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)

 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};