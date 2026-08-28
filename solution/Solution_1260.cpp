/**
 * 題目：1260. Shift 2D Grid
 * 難度：簡單 (Easy)
 * 描述：將一個 m x n 的網格循環右移 k 次。
 *
 * 時間複雜度：O(M*N)
 * 空間複雜度：O(K)
 *
 * 解法思路：
 * 1. 網格共有 N = m * n 個元素。
 * 2. 實際位移量為 k % N，避免不必要的重複循環。
 * 3. 處理「右移」問題的技巧：
 * - 先暫存最後 k 個元素（即將被移到最前面的部分）。
 * - 將其餘元素向後平移 k 個位置。
 * - 將暫存的元素填入空出來的前 k 個位置。
 * 4. 使用一維轉二維公式：row = idx / colCount, col = idx % colCount。
 */

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows * cols;    
        k %= n;
        vector<int> temp(k);
        for(int i = 0; i < k; i++) {
            int j = i + n - k;
            temp[i] = grid[j / cols][j % cols];
        }
        for(int i = n - k - 1; i >= 0; i--) {
            int j = i + k;
            grid[j / cols][j % cols] = grid[i / cols][i % cols];
        }
        for(int i = 0; i < k; i++) {
            grid[i / cols][i % cols] = temp[i];
        }
        return grid;
    }
};
