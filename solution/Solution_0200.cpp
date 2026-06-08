/**
 * 題目：200. Number of Islands (島嶼數量)
 * 難度：中等 (Medium)
 * 描述：計算二維網格中島嶼 ('1') 的數量。
 * * 時間複雜度：O(M × N) - 每個格子最多被存取兩次。
 * 空間複雜度：O(1) - 不使用額外 visited 陣列，直接修改原輸入網格 (忽略遞迴堆疊空間)。
 * * 優化思路：
 * 1. 原地修改：將造訪過的 '1' 改為 '0'，省去維護額外的 boolean 矩陣空間。
 * 2. 邊界檢查：在呼叫 DFS 前先檢查，減少遞迴調用的函數開銷。
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
                
    
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 | y >= grid[0].size() || grid[x][y] == '0') return;
        grid[x][y] = '0';
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
};
