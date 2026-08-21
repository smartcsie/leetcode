/**
 * 題目：221. Maximal Square
 * 難度：中等 (Medium)
 * 描述：給定一個只由 '0' 和 '1' 組成的二維矩陣 matrix，找出只包含 '1' 的
 * 最大正方形區域，回傳它的面積。
 *
 * 時間複雜度：O(M*N)
 * 空間複雜度：O(M*N)
 *
 * 解法思路：
 * （二維 Grid DP，dp[i][j] 代表「以 matrix[i-1][j-1] 為右下角」能組成的
 * 最大正方形邊長）：
 * 1. dp 陣列開 (m+1) x (n+1)，多一圈用來當邊界（避免 i-1、j-1 判斷越界），
 *    dp[i][j] 對應原矩陣的 matrix[i-1][j-1]。
 * 2. 狀態轉移：如果 matrix[i-1][j-1] 是 '1'，這個位置能組成的最大正方形
 *    邊長，取決於它「上方」「左方」「左上方」三個位置能組成的最大正方形
 *    邊長中最小的那個，再 +1（因為要同時满足三個方向都夠長，正方形才不
 *    會缺角，取三者最小值是這題的關鍵）：
 *    dp[i][j] = min(上, 左, 左上) + 1。
 *    如果是 '0'，dp[i][j] = 0（這個位置不可能是任何正方形的右下角）。
 * 3. 過程中同步記錄看過的最大邊長 best。
 * 4. 答案是 best * best（面積 = 邊長平方）。
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int best = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    best = max(best, dp[i][j]);
                }
            }
        }
        return best * best;
    }
};
