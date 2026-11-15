/**
 * 題目：867. Transpose Matrix (轉置矩陣)
 * 難度：簡單 (Easy)
 * 描述：返回矩陣 matrix 的轉置矩陣。
 *
 * 時間複雜度：O(M*N)
 * 空間複雜度：O(M*N)
 *
 * 解法思路：
 * 直接初始化結果矩陣 `res` 為 `n x m` 的維度，
 * 並透過雙重迴圈將 `matrix[j][i]` 賦值給 `res[i][j]`。
 */

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows, 0));
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                ans[c][r] = matrix[r][c];
            }
        }
        return ans;
    }
};