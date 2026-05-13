/**
 * 解題思路：二維動態規劃 (2D DP)
 * 1. 狀態定義：dp[i][j] 表示 text1[0...i-1] 與 text2[0...j-1] 的最長公共子序列長度。
 * 2. 初始化：dp 矩陣大小為 (m+1) x (n+1)，初始值全為 0。多出的一列一行代表空字串的情況。
 * 3. 狀態轉移方程：
 *    - 若 text1[i-1] == text2[j-1] (當前字元相同)：
 *      代表我們找到了一個新的公共字元，dp[i][j] = dp[i-1][j-1] + 1。
 *    - 若 text1[i-1] != text2[j-1] (當前字元不同)：
 *      LCS 可能出現在「text1 減少一個字元」或「text2 減少一個字元」的情況中，
 *      因此取兩者較大值：dp[i][j] = max(dp[i-1][j], dp[i][j-1])。
 * 
 * Time Complexity: O(M * N) - M, N 分別為兩字串長度，需填滿整個 DP 表格。
 * Space Complexity: O(M * N) - 用於存儲二維 dp 陣列。
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1 ;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
