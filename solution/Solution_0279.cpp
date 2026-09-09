/**
 * 題目：279. Perfect Squares (完全平方數)
 * 難度：中等 (Medium)
 * 描述：找出湊出數字 n 所需的最少完全平方數個數。
 *
 * 時間複雜度：O(N*√N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 模型轉換：這是一個完全背包的變體，硬幣面額為 {1, 4, 9, 16, ...}。
 * 2. 狀態定義：dp[i] 表示組成數字 i 所需的最少平方數數量。
 * 3. 轉移方程：dp[i] = min(dp[i], dp[i - j * j] + 1)。
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return static_cast<int>(dp[n]);
    }
};
