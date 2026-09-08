/**
 * 題目：198. House Robber
 * 難度：中等 (Medium)
 * 描述：不能搶相鄰房子的情況下，求能搶到的最大金額。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DP，dp[i] 代表搶到第 i 間房子時的最大金額）：
 * dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])，使用 dp 陣列版本。
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = nums[0];
        for(int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];

    }
};