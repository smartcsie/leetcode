/**
 * 註解：待補充
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)

 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555) != 0;
    }
};