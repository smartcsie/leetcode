/**
 * 題目：53. Maximum Subarray
 * 難度：中等 (Medium)
 * 描述：找出具有最大和的連續子陣列，回傳其最大和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DP，dp[i] 代表以 i 結尾的最大子陣列和）：
 * dp[i] = max(nums[i], dp[i-1] + nums[i])，與 Kadane's Algorithm 等價但使用陣列。
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};