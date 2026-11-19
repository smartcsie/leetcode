/*
 * 題目：1260. Shift 2D Grid
 * 難度：Easy
 * 描述：給定 m × n 的二維矩陣 grid 與整數 k，執行 k 次「位移」：每個元素往右移一格，列尾元素換到下一列列首，整個矩陣最後一個元素換到 grid[0][0]。回傳位移 k 次後的矩陣。
 * 分類主題：2d-array
 * 技巧：二維攤平成一維索引, 取模環狀位移, 直接計算目的位置
 * 時間複雜度：O(m × n)
 * 空間複雜度：O(m × n)（回傳用的新矩陣 ans；不含輸出則為 O(1)）
 * 解法思路：
 *   1. 把矩陣按列攤平：格子 (i, j) 對應一維索引 i × c + j，反過來 x = idx / c、y = idx % c
 *   2. 位移 k 次等於每個元素的一維索引往後 k 格，超出尾端就繞回頭，所以新索引 = (舊索引 + k) % n
 *   3. 位移 n 次等於沒動，先 k %= n 讓 k 落在 [0, n)（保險，取模本身也能處理，但可避免溢位疑慮）
 *   4. 逐格計算目的位置，直接寫入新矩陣 ans，不需要備份與搬移順序的顧慮
 */
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();       // 列數
        int c = grid[0].size();    // 欄數
        int n = r * c;             // 總格數（攤平後的一維長度）
        k %= n;                    // 位移 n 次等於沒動，k 縮到 [0, n)

        vector<vector<int>> ans(r, vector<int>(c));  // 結果矩陣
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                // (i, j) 的一維索引是 i × c + j，位移 k 格後繞回，得到目的索引
                int idx = (i * c + j + k) % n;
                // 目的索引還原成二維座標，把原值放進去
                ans[idx / c][idx % c] = grid[i][j];
            }
        }
        return ans;
    }
};