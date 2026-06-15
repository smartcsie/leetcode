/**
 * 題目：115. Distinct Subsequences (不同的子序列)
 * 難度：困難 (Hard)
 * 描述：計算字串 s 中有多少種不同的子序列與字串 t 相等。
 * * 時間複雜度：O(S * T) - S, T 分別為字串 s 和 t 的長度。
 * 空間複雜度：O(T) - 使用一維滾動陣列優化。
 * * 優化思路：
 * 1. 狀態定義：dp[j] 表示 t 的前 j 個字元在 s 的前 i 個字元中出現的次數。
 * 2. 轉移方程：若 s[i-1] == t[j-1]，dp[j] = dp[j] (不選) + dp[j-1] (選)；否則 dp[j] 不變。
 * 3. 倒序遍歷：這是關鍵，確保我們使用的狀態是上一輪 (i-1) 的結果。
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        // dp[j] 表示 t 的前 j 個字元在目前已遍歷的 s 子串中出現的次數
        vector<uint64_t> dp(n + 1, 0);
        
        // 基礎狀態：空字串 t 是任何字串 s 的子序列，且只有一種方法（全刪除）
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            // 必須倒序遍歷，以確保 dp[j-1] 是 i-1 時的狀態
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // 若 s[i-1] != t[j-1]，dp[j] 保持不變，代表不使用當前 s[i-1]
            }
        }
        
        return static_cast<int>(dp[n]);
    }
};
