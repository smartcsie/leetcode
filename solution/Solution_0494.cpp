/**
 * 題目：494. Target Sum (目標和)
 * 難度：中等 (Medium)
 * 描述：透過在數字前加上 '+' 或 '-'，使總和等於 target。
 *
 * 時間複雜度：O(N*S)
 * 空間複雜度：O(S)
 *
 * 解法思路：
 * 1. 模型轉換：設正數和為 P，負數和絕對值為 N。
 * P - N = target, P + N = sum => 2P = sum + target => P = (sum + target) / 2。
 * 問題轉化為：在 nums 中選取元素，使總和為 P 的組合數。
 * 2. 動態規劃：dp[j] 表示湊出總和 j 的方法數。
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = (sum + target) / 2;
        if(abs(sum) > target || n != 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(const int& num : nums) {
            for(int i = n ; i>= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[n];
    }
};
