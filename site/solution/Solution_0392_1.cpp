/**
 * 題目：392. Is Subsequence (判斷子序列)
 * 難度：簡單 (Easy)
 * 描述：判斷 s 是否為 t 的子序列。
 * * 時間複雜度：O(S * T) - S 為 s 長度，T 為 t 長度。
 * 空間複雜度：O(T) - 使用滾動陣列優化空間，從 O(S*T) 壓縮至 O(T)。
 * * 優化思路：
 * 1. 模型轉換：判斷 LCS(s, t) 是否等於 s.length()。
 * 2. 空間壓縮：只保留當前行與上一行的狀態。
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        
        // 基礎邊界情況
        if (sLen == 0) return true;
        if (tLen == 0) return false;
        
        // dp[j] 代表 s[0...i-1] 與 t[0...j-1] 的 LCS 長度
        vector<int> dp(tLen + 1, 0);
        
        for (int i = 1; i <= sLen; ++i) {
            int pre = 0; // 用於儲存 dp[i-1][j-1] 的值
            for (int j = 1; j <= tLen; ++j) {
                int temp = dp[j]; // 儲存更新前的 dp[j]，即 dp[i-1][j]
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = temp; // 更新 pre 為下一輪的 dp[i-1][j-1]
            }
        }
        
        return dp[tLen] == sLen;
    }
};
