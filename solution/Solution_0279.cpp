/**
 * 題目：279. Perfect Squares (完全平方數)
 * 難度：中等 (Medium)
 * 描述：找出湊出數字 n 所需的最少完全平方數個數。
 * * 時間複雜度：O(N * √N) - 外層遍歷 N，內層遍歷 √N 個平方數。
 * 空間複雜度：O(N) - 使用一維 DP 陣列。
 * * 優化思路：
 * 1. 模型轉換：這是一個完全背包的變體，硬幣面額為 {1, 4, 9, 16, ...}。
 * 2. 狀態定義：dp[i] 表示組成數字 i 所需的最少平方數數量。
 * 3. 轉移方程：dp[i] = min(dp[i], dp[i - j * j] + 1)。
 */

class Solution {
public:
    int numSquares(int n) {
        // 使用 n + 1 作為無窮大初始值，避免 INT_MAX 相加溢位
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        
        // 遍歷所有金額 (數字)
        for (int i = 1; i <= n; i++) {
            // 遍歷所有可能的物品 (完全平方數 j*j)
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        return dp[n];
    }
};
