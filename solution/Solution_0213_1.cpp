class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
private:
    int robLinear(const vector<int>& nums, int start, int end) {
        int length = end - start + 1;
        if (length <= 0) return 0;
        if (length == 1) return nums[start];
        vector<int> dp(length);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < length; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        return dp[length - 1];
    }
};