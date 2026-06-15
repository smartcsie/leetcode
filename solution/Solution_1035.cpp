/**
 * 題目：1035. Uncrossed Lines (不相交的線)
 * 難度：中等 (Medium)
 * 描述：在兩個陣列中繪製不相交的連線，求最多能畫幾條。
 * * 時間複雜度：O(N * M) - N, M 分別為 nums1 與 nums2 的長度。
 * 空間複雜度：O(M) - 使用一維滾動陣列優化空間。
 * * 優化思路：
 * 1. 模型轉換：本題即為最長公共子序列 (LCS) 問題。
 * 2. 空間優化：dp[i][j] 只依賴於上一行的 dp[i-1][j-1] 和 dp[i-1][j]。
 * 透過臨時變數 `pre` 儲存左上角的值，即可使用一維陣列更新。
 */

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // dp[j] 代表 nums1 前 i 個元素與 nums2 前 j 個元素的最長公共子序列長度
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= m; ++i) {
            int pre = 0; // 用於儲存上一輪的 dp[i-1][j-1]
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; // 儲存更新前的 dp[j]，即當前行的上一行狀態
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = temp; // 更新 pre 為下一輪的左上角值
            }
        }
        
        return dp[n];
    }
};
