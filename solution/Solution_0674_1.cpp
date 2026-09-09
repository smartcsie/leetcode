/**
 * 題目：674. Longest Continuous Increasing Subsequence (最長連續遞增序列)
 * 難度：簡單 (Easy)
 * 描述：找出陣列中連續遞增子序列的最大長度。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        int lcis = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            lcis = max(lcis, dp[i]);
        } 
        return lcis;
    }
};
