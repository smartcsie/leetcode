
/**
 * 解題思路：動態規劃 (Dynamic Programming)
 * 1. 狀態定義：dp[i] 代表以 nums[i] 這個數字作為「結尾」的最長遞增子序列長度。
 * 2. 初始狀態：每個數字本身都能構成一個長度為 1 的子序列，故 dp 陣列初始化全為 1。
 * 3. 狀態轉移方程：
 *    - 對於當前數字 nums[i]，我們遍歷它之前的所有數字 nums[j] (0 <= j < i)。
 *    - 如果 nums[i] > nums[j]，說明 nums[i] 可以接在以 nums[j] 結尾的遞增序列後面。
 *    - 此時長度會變成 dp[j] + 1。
 *    - 我們要取所有可能情況的最大值：dp[i] = max(dp[i], dp[j] + 1)。
 * 4. 最終結果：整個 dp 陣列中的最大值即為答案。
 * 
 * Time Complexity: O(n^2) - 雙重迴圈遍歷。
 * Space Complexity: O(n) - 需要一個長度為 n 的 dp 陣列。
 */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int lis = 1;
        for(int i = 1; i < n ;i++) {
            for(int j = 0; j < i ;j++) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            lis = max(lis, dp[i]);
        }
        return lis;
    }
};
