/**
 * 註解：待補充
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)

 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0) && (static_cast<int>(pow(3, 19)) % n == 0);
    }
};