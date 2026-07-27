/**
 * 題目：647. Palindromic Substrings (回文子串)
 * 難度：中等 (Medium)
 * 描述：計算字串中所有回文子串的總數量。
 * * 時間複雜度：O(N^2) - 兩層迴圈遍歷所有子串。
 * 空間複雜度：O(N^2) - 使用二維 DP 陣列記錄狀態。
 * * 優化思路：
 * 1. 狀態定義：dp[i][j] 為 bool，表示 s[i...j] 是否為回文。
 * 2. 轉移方程：若 s[i] == s[j]，則當長度 <= 2 時為真，否則參考 dp[i+1][j-1]。
 * 3. 遍歷順序：i 必須從後往前，j 必須從 i 往後，確保 dp[i+1][j-1] 先被計算。
 */

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int result = 0;
        // dp[i][j] 表示 s[i...j] 是否為回文
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 遍歷順序：i 從 n-1 到 0，j 從 i 到 n-1
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    // 若長度為 1 或 2，或中間部分已是回文
                    if (j - i <= 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
