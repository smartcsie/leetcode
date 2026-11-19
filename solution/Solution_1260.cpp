/*
 * 題目：1260. Shift 2D Grid
 * 難度：Easy
 * 描述：給定 m × n 的二維矩陣 grid 與整數 k，執行 k 次「位移」：每個元素往右移一格，列尾元素換到下一列列首，整個矩陣最後一個元素換到 grid[0][0]。回傳位移 k 次後的矩陣。
 * 分類主題：2d-array
 * 技巧：二維攤平成一維索引, 取餘數化簡 k, 暫存備份, 由後往前搬移原地覆蓋
 * 時間複雜度：O(m × n)
 * 空間複雜度：O(k)，k 已取餘數，最壞 O(m × n)（不含輸出）
 * 解法思路：
 *   1. 把矩陣按列攤平：格子 (x, y) 對應一維索引 x × c + y，反過來 x = i / c、y = i % c
 *   2. 位移 n = m × n 次等於沒動，所以先 k %= n，避免 k 大於總格數造成索引為負
 *   3. 位移 k 次等於「每個元素往後移 k 格」，最後 k 個元素繞到最前面
 *   4. 先把最後 k 個元素存進 backup
 *   5. 由後往前搬：位置 i 取自位置 i - k（來源比目的小，且尚未被覆蓋，所以不會讀到被改過的值）
 *   6. 最後把 backup 依序填回最前面 k 格
 */
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();       // 列數
        int c = grid[0].size();    // 欄數
        int n = r * c;             // 總格數（攤平後的一維長度）
        k %= n;                    // 位移 n 次等於沒動；也避免 k > n 時索引變負

        // 暫存「會被擠到最前面」的最後 k 個元素
        // 一維索引 idx 對應格子 grid[idx / c][idx % c]
        vector<int> backup(k);
        for(int i = 0; i < k; i++) {
            backup[i] = grid[(n - k + i) / c][(n - k + i) % c];
        }

        // 由後往前搬：位置 i 的新值 = 原本位置 i - k 的值
        // 從後往前寫，來源 i - k 一定還沒被覆蓋，所以可以原地進行
        for(int i = n - 1; i >= k; i--) {
            grid[i / c][i % c] = grid[(i - k) / c][(i - k) % c];
        }

        // 把暫存的最後 k 個元素放回最前面 k 格
        for(int i = 0; i < k; i++) {
            grid[i / c][i % c] = backup[i];
        }

        return grid;
    }
};