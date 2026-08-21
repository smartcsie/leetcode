/**
 * 題目：375. Guess Number Higher or Lower II
 * 難度：中等 (Medium)
 * 描述：對手心裡想了一個 1 到 n 之間的數字，你每次猜一個數字 x，如果猜
 * 錯要付 x 元。求在「對手會用最壞方式選數字讓你付最多錢」的情況下，
 * 保證獲勝所需準備的最少金額（Minimax，這題同時也是 Game Theory DP
 * 的經典題）。
 *
 * 時間複雜度：O(N³)
 * 空間複雜度：O(N²)
 *
 * 解法思路：
 * （Interval DP + Minimax，dp[i][j] 代表「答案落在 [i, j] 這段範圍」時，
 * 保證獲勝所需的最少金額）：
 * 1. 狀態轉移：枚舉這一輪猜的數字 k（i <= k <= j）：如果猜錯，答案會落
 *    在 [i, k-1]（比 k 小）或 [k+1, j]（比 k 大）其中一段，因為對手會
 *    選對你最不利的那一段（付最多錢的那段），所以猜 k 這一步的成本是
 *    k + max(dp[i][k-1], dp[k+1][j])。
 * 2. dp[i][j] 取所有可能的 k 之中，成本最小的那個（這是「我」這邊要
 *    做的選擇：挑一個 k，讓「對手選最壞情況」之後的成本最小）。
 * 3. 邊界：k = i 時沒有左半段（left = 0），k = j 時沒有右半段
 *    （right = 0）。
 * 4. 按照區間長度由小到大遞推，答案是 dp[1][n]。
 * 5. 這題可以同時歸進 Interval DP（區間切割型狀態）跟 Game Theory DP
 *    （min-max 對抗邏輯）兩個分類，看你想強調哪個角度，我會建議放
 *    interval，因為狀態定義本身就是標準的區間 DP 形狀。
 */
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 1; len < n; ++len) {
            for (int i = 1; i + len <= n; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    int left = (k > i) ? dp[i][k - 1] : 0;
                    int right = (k < j) ? dp[k + 1][j] : 0;
                    int cost = k + max(left, right);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n];
    }
};
