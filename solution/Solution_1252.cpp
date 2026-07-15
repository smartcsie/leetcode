/**
 * 題目：1252. Cells with Odd Values in a Matrix
 * 難度：簡單 (Easy)
 * 描述：在 m x n 矩陣中，根據給定的 indices 對行列進行增加，最後統計矩陣中值為奇數的單元格數量。
 * 
 * 解法思路：
 * 1. 矩陣中位置 (i, j) 的最終值 = row[i] + col[j]。
 * 2. 位置 (i, j) 為奇數的條件是：row[i] 與 col[j] 一個為奇數，另一個為偶數。
 * 3. 使用 XOR 運算：`(row[i] % 2) ^ (col[j] % 2)` 即為當前格是否為奇數的布林值。
 */

class Solution {
public:
    int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
        std::vector<int> row(m, 0);
        std::vector<int> col(n, 0);
        
        // 統計各行各列被增加的次數
        for (const auto& index : indices) {
            row[index[0]]++;
            col[index[1]]++;
        }
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // XOR 運算：當兩者奇偶性不同時，結果為 1 (奇數)
                count += (row[i] & 1) ^ (col[j] & 1);
            }
        }
        return count;
    }
};
