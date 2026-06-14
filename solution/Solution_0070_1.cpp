/**
 * 題目：70. Climbing Stairs (爬樓梯)
 * 難度：簡單 (Easy)
 * 描述：每次可以爬 1 或 2 個階梯，求到達 n 階的所有路徑總數。
 * * 時間複雜度：O(N) - 遍歷 1 到 n。
 * 空間複雜度：O(N) - 使用一維 DP 陣列。
 * * 優化思路：
 * 1. 排列計數：此題視順序為不同，故採用「外層金額(階梯)、內層物品(跳法)」的結構。
 * 2. 狀態定義：dp[i] 表示到達 i 階的方法數。
 * 3. 轉移方程：dp[i] = dp[i-1] + dp[i-2]。
 */

class Solution {
public:
    int climbStairs(int n) {
        // 使用 long long 防止溢位（雖然 n=45 內 int 足夠）
        vector<long long> dp(n + 1, 0);
        
        // 基礎情況：爬到第 0 階有一種方法（原地不動）
        dp[0] = 1;
        
        // 外層遍歷「目標階數」，內層遍歷「跳法」(1 或 2)
        // 這正是排列計數 (Combination Sum IV) 的邏輯
        for (int i = 1; i <= n; ++i) {
            // 跳 1 階
            if (i >= 1) dp[i] += dp[i - 1];
            // 跳 2 階
            if (i >= 2) dp[i] += dp[i - 2];
        }
        
        return static_cast<int>(dp[n]);
    }
};
