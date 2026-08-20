/**
 * 題目：1312. Minimum Insertion Steps to Make a String Palindrome
 * 難度：困難 (Hard)
 * 描述：給定一個字串 s，每次操作可以在任意位置插入一個字元，
 * 求最少需要插入幾個字元才能讓 s 變成回文字串。
 *
 * 時間複雜度：O(N²)
 * 空間複雜度：O(N²)
 *
 * 解法思路：
 * （LCS 變體，求 s 和其反轉字串的最長公共子序列）：
 * 1. 將 s 反轉得到 st，求 LCS(s, st)。
 * 2. LCS 的部分已經是回文，不需要插入。
 * 3. 剩餘的字元（n - LCS 長度）就是需要插入的最少次數。
 * 4. 狀態轉移：
 *    - 若 s[i-1] == st[j-1]：dp[i][j] = 1 + dp[i-1][j-1]
 *    - 否則：dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 * 5. 答案為 n - dp[n][n]。
 */
class Solution {
public:
    int minInsertions(string s) {
        string st = s;
        int n = s.size();
        reverse(st.begin(), st.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == st[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n - dp[n][n];
    }
};
