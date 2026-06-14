/**
 * 題目：674. Longest Continuous Increasing Subsequence (最長連續遞增序列)
 * 難度：簡單 (Easy)
 * 描述：找出陣列中連續遞增子序列的最大長度。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(N) - 使用 DP 陣列存儲每個位置的狀態。
 * * DP 思路：
 * 1. 狀態定義：dp[i] 表示以 nums[i] 結尾的最長連續遞增子序列長度。
 * 2. 轉移方程：若 nums[i] > nums[i-1]，則 dp[i] = dp[i-1] + 1；否則 dp[i] = 1。
 * 3. 初始狀態：所有 dp[i] 初始均為 1。
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        int maxLen = 1;
        // dp[i]：以 nums[i] 結尾的最長連續遞增序列長度
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            // 如果當前數字大於前一個數字，則形成連續遞增
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            
            // 更新全局最大值
            if (dp[i] > maxLen) {
                maxLen = dp[i];
            }
        }
        
        return maxLen;
    }
};
