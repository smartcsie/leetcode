/**
 * 題目：931. Minimum Falling Path Sum
 * 難度：中等 (Medium)
 * 描述：給定一個 n x n 的矩陣 matrix，從第一列任一位置開始往下走，每一步
 * 只能移動到正下方、左下方、或右下方，求走到最後一列的最小路徑和。
 *
 * 時間複雜度：O(N²)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （逐列 DP，dp[j] 代表「走到目前這一列第 j 欄」的最小路徑和）：
 * 1. dp 初始化為矩陣第一列（第一列每個位置本身就是起點，路徑和就是自己）。
 * 2. 狀態轉移（從第 2 列往下推到最後一列）：走到 (i, j) 的最小路徑和，
 *    要看上一列「正上方 (i-1,j)」「左上方 (i-1,j-1)」「右上方 (i-1,j+1)」
 *    三個位置的 dp 值中最小的，再加上 matrix[i][j] 自己。
 * 3. 邊界處理：j = 0 時沒有左上方，j = n-1 時沒有右上方，用 j > 0 /
 *    j < n-1 判斷即可。
 * 4. 走完所有列之後，答案是最後一列 dp 陣列裡的最小值（因為終點可以是
 *    最後一列任意位置）。
 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];
        for (int i = 1; i < n; ++i) {
            vector<int> next(n);
            for (int j = 0; j < n; ++j) {
                int best = dp[j];
                if (j > 0) best = min(best, dp[j - 1]);
                if (j < n - 1) best = min(best, dp[j + 1]);
                next[j] = matrix[i][j] + best;
            }
            dp = next;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
