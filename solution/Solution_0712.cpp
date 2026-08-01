/**
 * 題目：712. Minimum ASCII Delete Sum for Two Strings (兩個字串的最小 ASCII 刪除總和)
 * 難度：中等 (Medium)
 * 描述：給定兩個字串 s1 和 s2，找到使兩個字串相等所需刪除字元的 ASCII 值最小總和。
 *       每次刪除操作可以刪除任一字串中的一個字元，回傳最小的刪除總和。
 *
 * 時間複雜度：O(M×N) - M、N 為 s1、s2 的長度，需要填滿整個 (M+1) x (N+1) 的 dp 表格。
 * 空間複雜度：O(M×N) - 使用二維陣列 dp 儲存每個子問題的最小刪除成本。
 *
 * 解法思路：
 * 1. 定義狀態 (DP State Definition)：
 *    - dp[i][j] 代表讓 s1 的前 i 個字元與 s2 的前 j 個字元變得相等，所需要的最小刪除 ASCII 總和。
 * 2. 初始化邊界條件 (Base Cases)：
 *    - 若 s2 是空字串（j=0），s1 的前 i 個字元必須全部刪除，累加其 ASCII 值。
 *    - 若 s1 是空字串（i=0），同理 s2 的前 j 個字元必須全部刪除。
 * 3. 狀態轉移 (Transition)：
 *    - 若 s1[i-1] 與 s2[j-1] 字元相同，不需刪除，直接繼承 dp[i-1][j-1]。
 *    - 若不同，取兩種選擇中較小的成本：刪除 s1 的當前字元（dp[i-1][j] + s1[i-1]），
 *      或刪除 s2 的當前字元（dp[i][j-1] + s2[j-1]）。
 * 4. 最終答案：
 *    - dp[m][n] 即為讓整個 s1 與 s2 相等所需的最小刪除 ASCII 總和。
 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        // dp[i][j] 代表 s1 前 i 個字元與 s2 前 j 個字元達到相等的最小刪除成本
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 初始化邊界條件：如果 s2 是空字串，s1 必須全部刪除
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        // 如果 s1 是空字串，s2 必須全部刪除
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        // 填表格
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]; // 字元一樣，不用刪
                } else {
                    dp[i][j] = min(
                        dp[i-1][j] + s1[i-1], // 刪除 s1 的字元
                        dp[i][j-1] + s2[j-1]  // 刪除 s2 的字元
                    );
                }
            }
        }
        return dp[m][n];
    }
};
