/**
 * 題目：1039. Minimum Score Triangulation of Polygon
 * 難度：中等 (Medium)
 * 描述：給定一個凸多邊形，頂點依序標上數值 values[i]，把它切割成
 * n-2 個三角形（三角剖分），每個三角形的分數是三個頂點數值的乘積，
 * 求所有三角形分數總和的最小值。
 *
 * 時間複雜度：O(N³)
 * 空間複雜度：O(N²)
 *
 * 解法思路：
 * （Interval DP，dp[i][j] 代表「頂點 i 到 j 這段多邊形」的最小三角剖分
 * 分數）：
 * 1. dp[i][j] 只在 j - i >= 2 時才有意義（至少要 3 個頂點才能圍出一個
 *    三角形），j - i < 2 的情況分數是 0。
 * 2. 狀態轉移：枚舉頂點 i 和 j 之間，跟它們組成三角形的第三個頂點 k
 *    （i < k < j）：這樣會把多邊形切成三塊——「i 到 k」「k 到 j」兩段
 *    子多邊形，加上 (i, k, j) 這個三角形本身：
 *    dp[i][j] = min over k of dp[i][k] + dp[k][j] + values[i]*values[j]*values[k]。
 * 3. 按照區間長度由小到大遞推，確保算 dp[i][j] 時，所有更短的子區間
 *    都已經算好。
 * 4. 答案是 dp[0][n-1]，代表整個多邊形的最小三角剖分分數。
 */
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int cost = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[0][n - 1];
    }
};
