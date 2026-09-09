/**
 * 題目：1143. Longest Common Subsequence (最長公共子序列)
 * 難度：中等 (Medium)
 * 描述：給定兩個字串 text1 和 text2，找出兩者的最長公共子序列長度。
 * 子序列不要求連續，但相對順序必須一致。
 * 時間複雜度：O(M*N)
 * 空間複雜度：O(M*N)
 *
 * 解法思路：
 * 二維動態規劃 (2D DP)
 * 1. 狀態定義：dp[i][j] 表示 text1[0...i-1] 與 text2[0...j-1] 的最長公共子序列長度。
 * 2. 初始化：dp 矩陣大小為 (m+1) x (n+1)，初始值全為 0。多出的一列一行代表空字串的情況。
 * 3. 狀態轉移方程：
 * - 若 text1[i-1] == text2[j-1] (當前字元相同)：
 * 代表我們找到了一個新的公共字元，dp[i][j] = dp[i-1][j-1] + 1。
 * - 若 text1[i-1] != text2[j-1] (當前字元不同)：
 * LCS 可能出現在「text1 減少一個字元」或「text2 減少一個字元」的情況中，
 * 因此取兩者較大值：dp[i][j] = max(dp[i-1][j], dp[i][j-1])。
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string& s = text1;
        string& t = text2;
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i  - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
