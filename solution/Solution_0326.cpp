/**
 * 題目：326. Power of Three
 * 難度：簡單 (Easy)
 * 描述：判斷一個整數是否為 3 的冪次方。
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)

 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0) && (static_cast<int>(pow(3, 19)) % n == 0);
    }
};