/**
 * 題目：69. Sqrt(x) (求整數平方根)
 * 難度：簡單 (Easy)
 * 描述：計算並返回 x 的算術平方根，若 x 不是完全平方數，則返回整數部分。
 * * 時間複雜度：O(log x)，每次迴圈將搜尋範圍減半。
 * 空間複雜度：O(1)，僅使用常數空間。
 * * 優化思路：
 * 1. 提前偵測：在找到完全平方根時 (mid * mid == x) 直接返回，提升極端測試案例的效率。
 * 2. 防溢位設計：使用 mid == x / mid 取代 mid * mid == x，避免大數平方溢位。
 * 3. 邊界回傳：若迴圈結束仍未找到相等值，則 right 為向下取整的平方根。
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
