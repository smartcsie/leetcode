/**
 * 題目：718. Maximum Length of Repeated Subarray (最長重複子陣列)
 * 難度：中等 (Medium)
 * 描述：找出兩個陣列中最長連續公共子陣列的長度。
 *
 * 時間複雜度：O(N*M) - 需遍歷兩個陣列的所有組合。
 * 空間複雜度：O(M) - 使用一維滾動陣列儲存狀態。
 *
 * 解法思路：
 * 1. 狀態定義：dp[j] 表示以 nums1[i-1] 和 nums2[j-1] 結尾的最長公共子陣列長度。
 * 2. 空間壓縮：由於 dp[i][j] 只依賴 dp[i-1][j-1]，我們可以省去一維，透過倒序遍歷更新。
 */

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp (nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ans = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
