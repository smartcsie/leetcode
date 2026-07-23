/**
 * 題目：1277. Count Square Submatrices with All Ones
 * 描述：給你一個 m * n 的二維矩陣，矩陣元素由 0 和 1 組成，
 *       請返回該矩陣中有多少個全由 1 組成的正方形子矩陣。
 * 
 * 解法思路：
 * 1. 動態規劃狀態定義：`matrix[i][j]` 代表以格子 `(i, j)` 作為「右下角」時，所能形成的「最大正方形邊長」。
 * 2. 狀態轉移方程式：
 *    - 若 `matrix[i][j] == 1` 且非第一行或第一列（`i > 0 && j > 0`）：
 *      `matrix[i][j] += min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]})`
 *    - 意思是：當前點能形成的正方形邊長，取決於其左方、上方、左上方三個鄰居的最小值再加 1。
 * 3. 原地修改（In-place）：直接複用輸入的矩陣儲存計算結果，省去額外開闢 DP 表格的開銷。
 * 4. 最後透過 `std::accumulate` 將矩陣中所有累積後的數值加總起來，即為全矩陣正方形的總數量。
 */

class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // 1. 動態規劃遍歷與原地更新
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] += std::min({
                        matrix[i - 1][j - 1], 
                        matrix[i - 1][j], 
                        matrix[i][j - 1]
                    });
                }
            }
        }
        
        // 2. 加總矩陣中所有的數值（每個位置的值代表以其為右下角所能貢獻的正方形個數）
        return std::accumulate(matrix.begin(), matrix.end(), 0,
            [](int subtotal, const std::vector<int>& row) {
                return subtotal + std::accumulate(row.begin(), row.end(), 0);
        });
    }
};
