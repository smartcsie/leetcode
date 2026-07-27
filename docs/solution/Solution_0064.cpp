/**
 * 題目：64. Minimum Path Sum (最小路徑和)
 * 難度：中等 (Medium)
 * 描述：在 m x n 網格中，找出從左上角到右下角路徑數字總和最小的路徑。
 * * 時間複雜度：O(M * N) - 遍歷整個矩陣一次。
 * 空間複雜度：O(1) - 原地修改 grid 陣列，不使用額外空間。
 * * 優化思路：
 * 1. 原地 DP：每個 grid[i][j] 更新為「到達當前格子的最小路徑和」。
 * 2. 狀態轉移：
 * - 若位於第一行：只能由左側過來 (grid[i][j] += grid[i][j-1])
 * - 若位於第一列：只能由上方過來 (grid[i][j] += grid[i-1][j])
 * - 其他：取上方與左方較小者 (grid[i][j] += min(up, left))
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 & j == 0) continue;
                if(i == 0) grid[i][j] += grid[i][j - 1];
                else if(j == 0) grid[i][j] += grid[ i - 1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
