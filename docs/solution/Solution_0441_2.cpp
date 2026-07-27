/**
 * 題目：441. Arranging Coins (排列硬幣)
 * 難度：簡單 (Easy)
 * 描述：計算能排滿的完整行數。
 * * 時間複雜度：O(log N)
 * 空間複雜度：O(1)
 * * 優化思路：
 * 1. 使用 long long 防止乘法溢位。
 * 2. 嚴格二分查找：利用性質單調性尋找滿足條件的最大 k。
 */

class Solution {
public:
    int arrangeCoins(int n) {
        // 使用 long long 防止 mid * (mid + 1) 溢位
        // 搜尋範圍上限為 n，因為 n 最小為 1
        long long left = 1, right = n;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long coinsNeeded = mid * (mid + 1) / 2;
            
            if (coinsNeeded == n) {
                return static_cast<int>(mid);
            } else if (coinsNeeded < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // 當找不到剛好相等的解時，right 會停在滿足條件的最大值位置
        return static_cast<int>(right);
    }
};
