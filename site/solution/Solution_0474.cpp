/**
 * 題目：474. Ones and Zeroes (一和零)
 * 難度：中等 (Medium)
 * 描述：在最多 m 個 0 和 n 個 1 的限制下，能組成的最大字串子集數量。
 * * 時間複雜度：O(L * m * n)，其中 L 為字串陣列總字元數，m, n 為限制條件。
 * 空間複雜度：O(m * n)，透過滾動陣列將空間壓縮至二維。
 * * 優化思路：
 * 1. 狀態定義：dp[i][j] 表示在消耗 i 個 0 和 j 個 1 的情況下，最多可組成幾個字串。
 * 2. 倒序遍歷：這是 0/1 背包的關鍵，確保每個字串只能在當前決策中被使用一次。
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 使用二維 DP 表存儲狀態
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string& s : strs) {
            // 統計當前字串的成本 (消耗的 0 與 1)
            int count0 = 0, count1 = 0;
            for (char c : s) {
                if (c == '0') count0++;
                else count1++;
            }
            // 倒序更新 DP 表，避免物品被重複選取
            for (int i = m; i >= count0; --i) {
                for (int j = n; j >= count1; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
