/**
 * 題目：322. Coin Change (零錢兌換)
 * 難度：中等 (Medium)
 * 描述：找出組成目標金額 amount 所需的最少硬幣數量。
 * * 時間複雜度：O(A * N) - A 為金額，N 為硬幣面額數量。
 * 空間複雜度：O(A) - 使用一維 DP 陣列存儲最小數量。
 * * 優化思路：
 * 1. 狀態定義：dp[i] 表示組成金額 i 所需的最少硬幣數。
 * 2. 轉移方程：dp[i] = min(dp[i], dp[i - coin] + 1)。
 * 3. 邊界處理：初始化為 amount + 1 (大於所有可能的硬幣數)，若最後仍大於 amount 則無解。
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 使用 amount + 1 作為無窮大初始值
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        // 外層遍歷金額，內層遍歷硬幣 (此處順序對結果無影響)
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
