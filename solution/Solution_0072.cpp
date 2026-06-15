/**
 * 題目：72. Edit Distance (編輯距離)
 * 難度：困難 (Hard)
 * 描述：計算將 word1 轉換為 word2 的最少操作次數（插入、刪除、替換）。
 * * 時間複雜度：O(N * M) - N, M 分別為兩字串長度。
 * 空間複雜度：O(M) - 透過滾動陣列將空間壓縮至一維。
 * * 優化思路：
 * 1. 狀態定義：dp[j] 表示 word1 前 i 個字元轉換為 word2 前 j 個字元的最小操作數。
 * 2. 轉移方程：
 * - 相等：dp[j] = prev_diag (即 dp[i-1][j-1])
 * - 不等：dp[j] = min(插入, 刪除, 替換) + 1
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[j] 表示 word1 的某個前綴轉換為 word2 前 j 個字元的最少操作數
        vector<int> dp(n + 1);
        
        // 初始化：word1 為空時，轉換為 word2 需要 j 次插入操作
        for (int j = 0; j <= n; ++j) dp[j] = j;
        
        for (int i = 1; i <= m; ++i) {
            int pre = dp[0]; // 儲存 dp[i-1][j-1]
            dp[0] = i;       // 更新 dp[i][0]
            
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; // 儲存 dp[i-1][j]
                
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = pre; // 字元相等，無須操作
                } else {
                    // min(替換, 刪除, 插入) + 1
                    // pre: dp[i-1][j-1], dp[j]: dp[i-1][j], dp[j-1]: dp[i][j-1]
                    dp[j] = min({pre, dp[j], dp[j - 1]}) + 1;
                }
                pre = temp; // 準備下一輪的對角線值
            }
        }
        
        return dp[n];
    }
};
