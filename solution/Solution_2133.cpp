/**
 * 題目：2133. Check if Every Row and Column Contains All Numbers (檢查每一行每一列是否包含所有數字)
 * 難度：簡單 (Easy)
 * 描述：給你一個 n x n 的整數矩陣 matrix。
 *      判斷該矩陣是否為一個「有效」矩陣：即每一行與每一列都包含從 1 到 n 的所有整數（含）。
 * 
 * 時間複雜度：O(n²) - 矩陣共有 n^2 個元素，必須全部檢查一遍。
 * 空間複雜度：O(n) - 每一次外層迴圈使用兩個長度為 101 的 bitset（常數空間，但與 n 相關）。
 * 
 * 解法思路：
 * 1. 核心邏輯：在一次外層迴圈中，同時檢查第 i 行與第 i 列。
 * 2. 使用 bitset<101> 來標記出現過的數字（題目限制 n 最大為 100）。
 * 3. 對於每一行 (row)：將 matrix[i][j] 的值在 bitset 中設為 1。
 * 4. 對於每一列 (col)：將 matrix[j][i] 的值（轉置索引）在 bitset 中設為 1。
 * 5. 最後檢查 bitset 中被設為 1 的位元總數 (count()) 是否剛好等於 n。
 *    若不等於 n，說明有數字重複或缺失。
 */

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++ ) {
            bitset<101> row;
            bitset<101> col;
            for(int j = 0; j < n; j++ ) {
                row.set(matrix[i][j]);
                col.set(matrix[j][i]);
            }
            if(col.count() != n || row.count() != n)
                return false;
        }
        return true;
    }
};
