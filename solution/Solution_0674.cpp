
/**
 * 題目：674. Longest Continuous Increasing Subsequence (最長連續遞增序列)
 * 難度：簡單 (Easy)
 * 描述：給定一個未排序的整數陣列，找出最長且「連續」遞增的子序列的長度。
 * 
 * 時間複雜度：O(n) - 只需要遍歷陣列一次。
 * 空間複雜度：O(1) - 只需要常數空間來儲存當前長度與最大長度。
 * 
 * 解法思路：
 * 1. 使用一個計數器 count 記錄當前連續遞增的長度。
 * 2. 遍歷陣列，如果當前元素大於前一個元素 (nums[i] > nums[i-1])，則 count + 1。
 * 3. 如果不再遞增，則將 count 重置為 1。
 * 4. 每次更新過程中使用 res 紀錄出現過的最大 count。
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        int lcis = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) dp[i] = dp[i-1] + 1;
            lcis = max(lcis, dp[i]);
        }
        return lcis;
    }
};
