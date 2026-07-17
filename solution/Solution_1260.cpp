/**
 * 題目：1260. Shift 2D Grid
 * 難度：簡單 (Easy)
 * 描述：將一個 m x n 的網格循環右移 k 次。
 * 
 * 解法思路：
 * 1. 網格共有 N = m * n 個元素。
 * 2. 實際位移量為 k % N，避免不必要的重複循環。
 * 3. 處理「右移」問題的技巧：
 *    - 先暫存最後 k 個元素（即將被移到最前面的部分）。
 *    - 將其餘元素向後平移 k 個位置。
 *    - 將暫存的元素填入空出來的前 k 個位置。
 * 4. 使用一維轉二維公式：row = idx / colCount, col = idx % colCount。
 */

class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        int n = r * c;
        k %= n; // 減少重複循環
        
        if (k == 0) return grid;
        
        // 1. 暫存最後 k 個元素 (將移到最前面的部分)
        std::vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            int idx = i + (n - k);
            temp[i] = grid[idx / c][idx % c];
        }
        
        // 2. 其餘元素整體向後平移 k 個位置
        for (int i = n - k - 1; i >= 0; i--) {
            grid[(i + k) / c][(i + k) % c] = grid[i / c][i % c];
        }
        
        // 3. 將暫存元素放入網格開頭
        for (int i = 0; i < k; i++) {
            grid[i / c][i % c] = temp[i];
        }
        
        return grid;
    }
};
