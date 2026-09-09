/**
 * 題目：322. Coin Change (零錢兌換)
 * 難度：中等 (Medium)
 * 描述：找出組成目標金額 amount 所需的最少硬幣數量。
 *
 * 時間複雜度：O(A*N)
 * 空間複雜度：O(A)
 *
 * 解法思路：
 * 1. 狀態定義：dp[i] 表示組成金額 i 所需的最少硬幣數。
 * 2. 轉移方程：dp[i] = min(dp[i], dp[i - coin] + 1)。
 * 3. 邊界處理：初始化為 amount + 1 (大於所有可能的硬幣數)，若最後仍大於 amount 則無解。
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int& n = amount;
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(const int& coin : coins) {
                if(i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[n] > n ? -1 : dp[n];
    }
};
