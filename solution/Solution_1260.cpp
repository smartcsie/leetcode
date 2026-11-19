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