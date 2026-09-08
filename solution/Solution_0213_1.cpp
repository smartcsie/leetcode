/**
 * 題目：213. House Robber II
 * 難度：中等 (Medium)
 * 描述：房子排成環狀，不能搶相鄰房子，求能搶到的最大金額。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （拆成兩個線性 House Robber）：
 * 環狀問題拆成「搶第 0 到 n-2 間」和「搶第 1 到 n-1 間」兩個子問題取最大值。
 */
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