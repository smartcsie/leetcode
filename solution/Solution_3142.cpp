/**
 * 題目：3142. Check if Grid Satisfies Conditions
 * 難度：簡單 (Easy)
 * 描述：檢查網格是否滿足：
 *       1. 同一列的所有格子相等 (grid[i][j] == grid[i+1][j])。
 *       2. 相鄰兩列的格子必須不同 (grid[i][j] != grid[i][j+1])。
 * 
 * 解法思路：
 * 1. 使用兩次雙重迴圈分別檢測垂直條件與水平條件。
 * 2. 垂直檢測：檢查 grid[i][j] 與下方 grid[i+1][j] 是否相等。
 * 3. 水平檢測：檢查 grid[i][j] 與右方 grid[i][j+1] 是否不相等。
 */

class Solution {
public:
    bool satisfiesConditions(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 垂直條件：每一列元素必須與下一列對應元素相同
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
            }
        }
        
        // 水平條件：每一列元素必須與右側元素不同
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
