/**
 * 題目：392. Is Subsequence (判斷子序列)
 * 難度：簡單 (Easy)
 * 描述：判斷 s 是否為 t 的子序列。
 *
 * 時間複雜度：O(S*T)
 * 空間複雜度：O(T)
 *
 * 解法思路：
 * 1. 模型轉換：判斷 LCS(s, t) 是否等於 s.length()。
 * 2. 空間壓縮：只保留當前行與上一行的狀態。
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        // dp[i][j] = s 前 i 個字元是否為 t 前 j 個字元的子序列
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // 空字串是任何字串的子序列
        for (int j = 0; j <= n; j++) dp[0][j] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];  // 字元匹配，往前推
                else dp[i][j] = dp[i][j-1];    // 不匹配，跳過 t[j-1]
            }
        }
        return dp[m][n];
    }
};
