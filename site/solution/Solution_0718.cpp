/**
 * 題目：718. Maximum Length of Repeated Subarray (最長重複子陣列)
 * 難度：中等 (Medium)
 * 描述：找出兩個陣列中最長連續公共子陣列的長度。
 * * 時間複雜度：O(N * M) - 需遍歷兩個陣列的所有組合。
 * 空間複雜度：O(M) - 使用一維滾動陣列儲存狀態。
 * * 優化思路：
 * 1. 狀態定義：dp[j] 表示以 nums1[i-1] 和 nums2[j-1] 結尾的最長公共子陣列長度。
 * 2. 空間壓縮：由於 dp[i][j] 只依賴 dp[i-1][j-1]，我們可以省去一維，透過倒序遍歷更新。
 */

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // dp[j] 表示 nums1 前 i 個元素與 nums2 前 j 個元素的最長公共子陣列長度
        vector<int> dp(m + 1, 0);
        int result = 0;
        
        for (int i = 1; i <= n; ++i) {
            // 倒序遍歷，確保在更新 dp[j] 時使用的是上一輪的 dp[j-1]
            for (int j = m; j >= 1; --j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    // 若不相等，公共子陣列在此處中斷，長度歸零
                    dp[j] = 0;
                }
                result = max(result, dp[j]);
            }
        }
        
        return result;
    }
};
