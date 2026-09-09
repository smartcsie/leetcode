/**
 * 題目：516. Longest Palindromic Subsequence (最長回文子序列)
 * 難度：中等 (Medium)
 * 描述：給定字串 s，找出最長回文子序列的長度。
 *       子序列不需要連續，但相對順序必須保持。
 *
 * 時間複雜度：O(N²) - 雙層迴圈遍歷所有子字串區間。
 * 空間複雜度：O(N²) - 二維 dp 陣列。
 *
 * 解法思路：
 * 1. 狀態定義：
 *    - dp[i][j] 表示字串 s[i..j] 的最長回文子序列長度。
 *
 * 2. 初始化：
 *    - dp[i][i] = 1，單一字元本身就是長度為 1 的回文。
 *
 * 3. 轉移方程（由短區間推長區間，i 從右往左、j 從左往右）：
 *    - s[i] == s[j]：兩端字元相同，可以把兩端加入回文
 *      dp[i][j] = dp[i+1][j-1] + 2
 *    - s[i] != s[j]：兩端字元不同，捨棄其中一端取較大值
 *      dp[i][j] = max(dp[i+1][j], dp[i][j-1])
 *
 * 4. 答案：dp[0][n-1]，即整個字串的最長回文子序列長度。
 *
 * 範例：s = "bbbab"
 *    dp 最終 dp[0][4] = 4，對應子序列 "bbbb"
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n ; i++) dp[i][i] = 1;
        for(int i = n - 1; i >= 0 ; i--) {
            for(int j = i + 1; j < n ; j++) {
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
