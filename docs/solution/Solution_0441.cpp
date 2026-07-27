/**
 * 題目：441. Arranging Coins (排列硬幣)
 * 難度：簡單 (Easy)
 * 描述：找出能排成完整階梯行的最大行數 k。
 * * 時間複雜度：O(1)，直接使用數學公式求根。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 數學求根：將問題轉化為二次方程式 k^2 + k - 2n = 0，利用求根公式直接得出近似值。
 * 2. 避免搜尋：移除二分搜尋的迴圈，達到常數級執行時間。
 */

class Solution {
public:
    int arrangeCoins(int n) {
        // 利用求根公式: k = (-1 + sqrt(1 + 8n)) / 2
        // 因為 k 必須是整數，所以取 floor
        // 使用 long long 防止計算過程中的溢位
        return static_cast<int>((std::sqrt(1.0 + 8.0 * (long long)n) - 1) / 2);
    }
};
