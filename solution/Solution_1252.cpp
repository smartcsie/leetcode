/**
 * 題目：1252. Cells with Odd Values in a Matrix
 * 難度：簡單 (Easy)
 * 描述：在 m x n 矩陣中，根據給定的 indices 對行列進行增加，最後統計矩陣中值為奇數的單元格數量。
 *
 * 時間複雜度：O(K+M*N) - 差分陣列記錄行列奇偶性。
 * 空間複雜度：O(M+N) - 行列各一個陣列。
 *
 * 解法思路：
 * 1. 矩陣中位置 (i, j) 的最終值 = row[i] + col[j]。
 * 2. 位置 (i, j) 為奇數的條件是：row[i] 與 col[j] 一個為奇數，另一個為偶數。
 * 3. 使用 XOR 運算：`(row[i] % 2) ^ (col[j] % 2)` 即為當前格是否為奇數的布林值。
 */

class Solution {
public:
    int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
        vector<int> rows(m ,0);
        vector<int> cols(n ,0);
        int ans = 0;
        for(const vector<int>& v : indices) {
            rows[v[0]]++;
            cols[v[1]]++;
        }
        for(int i =0 ;i < m ;i++) {
            for(int j =0 ;j < n ;j++) {
                if((rows[i] + cols[j]) & 1) ans++;
            }
        }
        return ans;
    }
};
