/**
 * 題目：867. Transpose Matrix (轉置矩陣)
 * 難度：簡單 (Easy)
 * 描述：返回矩陣 matrix 的轉置矩陣。
 * * 時間複雜度：O(M * N) - 遍歷矩陣中的每個元素。
 * 空間複雜度：O(M * N) - 建立一個新的轉置矩陣來存放結果。
 * * 優化思路：
 * 直接初始化結果矩陣 `res` 為 `n x m` 的維度，
 * 並透過雙重迴圈將 `matrix[j][i]` 賦值給 `res[i][j]`。
 */

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 優化：直接初始化 n x m 的二維向量，避免動態擴展空間
        vector<vector<int>> res(n, vector<int>(m));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 原矩陣的 [i][j] 對應轉置後的 [j][i]
                res[j][i] = matrix[i][j];
            }
        }
        
        return res;
    }
};
