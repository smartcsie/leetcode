/**
 * 題目：633. Sum of Square Numbers
 * 難度：中等 (Medium)
 * 描述：給定一個非負整數 c，判斷是否存在兩個整數 a、b，使得 a² + b² = c。
 *
 * 時間複雜度：O(√c)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Two Pointers，對撞雙指針）：
 * 1. left 從 0 開始，right 從 sqrt(c) 開始，向中間收斂。
 * 2. 計算 sum = left² + right²：
 *    - sum == c：找到答案，return true。
 *    - sum < c：需要更大的值，left++。
 *    - sum > c：需要更小的值，right--。
 * 3. left > right 時仍未找到，return false。
 *
 * 注意：
 * 使用 unsigned int 避免 left² + right² 溢位，
 * 因為 right 最大約 46340，right² 約 2*10^9，接近 INT_MAX。
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned int left = 0, right = sqrt(c);
        while (left <= right) {
            unsigned int sum = left * left + right * right;
            if (sum == c) return true;
            if (sum < c) left++;
            else         right--;
        }
        return false;
    }
};
