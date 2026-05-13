/**
 * 解題思路：基於 LCS (Longest Common Subsequence) 的轉換
 * 1. 核心觀察：要使兩個字串相等，最後剩下的部分一定是兩者的「公共子序列」。
 * 2. 為了使刪除次數最少，剩下的公共子序列必須「最長」，也就是 LCS。
 * 3. 邏輯公式：
 *    - 令 LCS 為兩字串的最長公共子序列長度。
 *    - word1 需要刪除的字元數 = word1.length() - LCS
 *    - word2 需要刪除的字元數 = word2.length() - LCS
 *    - 總刪除次數 = word1.length() + word2.length() - 2 * LCS
 * 
 * Time Complexity: O(m * n) - 需要填滿 m x n 的 DP 表格。
 * Space Complexity: O(m * n) - 二維 DP 陣列空間。
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp( m+1, vector<int>( n+1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m + n - 2*dp[m][n];
    }
};
