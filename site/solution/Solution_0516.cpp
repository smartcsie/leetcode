/**
 * 題目：516. Longest Palindromic Subsequence (最長回文子序列)
 * 難度：中等 (Medium)
 * 描述：在字串中找出最長回文子序列的長度。
 * * 時間複雜度：O(N^2)
 * 空間複雜度：O(N) - 使用一維滾動陣列優化。
 * * 優化思路：
 * 1. 狀態定義：dp[j] 表示從索引 i 到 j 的最長回文子序列長度。
 * 2. 轉移方程：
 * - s[i] == s[j]: dp[j] = prev_dp[j-1] + 2
 * - s[i] != s[j]: dp[j] = max(dp[j], dp[j-1])
 * 3. 滾動陣列：使用 `pre` 變數保存 `dp[i+1][j-1]` 的狀態。
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp[j] 儲存當前行（或上一行）的狀態
        vector<int> dp(n, 0);
        
        // i 從後往前遍歷，保證 dp[i+1] 狀態已就緒
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1; // 單一字元長度為 1
            int pre = 0; // 用於儲存 dp[i+1][j-1]
            
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j]; // 儲存更新前的 dp[j]，即下一輪的 dp[i+1][j]
                if (s[i] == s[j]) {
                    dp[j] = pre + 2;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = temp; // 更新 pre 為下一輪的 dp[i+1][j]
            }
        }
        
        return dp[n - 1];
    }
};
