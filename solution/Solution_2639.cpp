/**
 * 題目：2639. Find the Width of Columns of a Grid
 * 難度：簡單 (Easy)
 * 描述：計算網格中每一欄的最大寬度。數字的寬度為其字串表示法的長度。
 * 
 * 解法思路：
 * 1. 建立一個輔助函數 `getWidth` 計算單一數字寬度：
 *    - 處理 0 的特殊情況 (寬度為 1)。
 *    - 若為負數，寬度為位數 + 1 (符號位)。
 * 2. 遍歷網格中的每一個格子，更新每一欄 (Column) 對應的最大寬度。
 * 3. 確保遍歷順序為 (row, col) 以維持最佳 Cache Locality。
 */

class Solution {
private: 
    int getWidth(int num) {
        int width = 0;
        if(num == 0) return 1;
        int val = abs(num);
        while(val > 0) {
            width++;
            val /= 10;
        }
        return num < 0 ? (width + 1) : width; 
    }
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 && n == 0) return {};

        vector<int> ans(n, 0);
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                int width = getWidth(grid[i][j]);
                ans[j] = max(ans[j], width);
            }
        }
        return ans;
    }
};
