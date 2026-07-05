/**
 * 題目：63. Unique Paths II
 * 難度：中等 (Medium)
 * 描述：在有障礙物的網格中，求從左上角走到右下角的總路徑數。
 * * 優化重點：
 * 1. 空間優化：將二維 DP 陣列壓縮為一維 `dp[n]`。
 * 2. 邊界與障礙處理：若起點或終點為障礙物，直接返回 0。
 * 3. 類型防護：使用 `long long` 防止路徑數值過大導致的溢位。
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<long> dp(n);
        dp[0] = 1;
        for(int i = 0; i < m;i++) {
            for(int j = 0; j < n;j++) {
                if(obstacleGrid[i][j]) dp[j] = 0;
                else if(j > 0) dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
