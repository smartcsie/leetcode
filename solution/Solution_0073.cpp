/**
 * 題目：73. Set Matrix Zeroes (矩陣置零)
 * 難度：中等 (Medium)
 * 描述：若矩陣中某元素為 0，則將該行與該列的所有元素設為 0。
 * * 時間複雜度：O(M * N) - 遍歷矩陣。
 * 空間複雜度：O(1) - 原地修改。
 * * 設計思路：
 * 1. 使用第一行與第一列來記錄各行各列是否需要被置零。
 * 2. 使用兩個布林變數 `rowZero` 與 `colZero` 記錄第一行與第一列本身是否含 0。
 * 3. 根據標記原地更新矩陣。
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;

        // 1. 檢查第一行與第一列是否有 0
        for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) col0 = true;
        for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) row0 = true;

        // 2. 利用第一行與第一列標記其他位置的狀態
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 3. 根據標記更新內部矩陣
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 4. 最後更新第一行與第一列
        if (col0) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        if (row0) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
    }
};
