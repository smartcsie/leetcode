/**
 * 題目：1582. Special Positions in a Binary Matrix (二進位矩陣中的特殊位置)
 * 難度：簡單 (Easy)
 * 描述：計算矩陣中所有符合 rowSum == 1 且 colSum == 1 的位置 (i, j)。
 *
 * 時間複雜度：O(M*N)
 * 空間複雜度：O(M+N)
 *
 * 解法思路：
 * 1. 減少冗餘判斷：在第二階段遍歷時，先檢查 rows[i] 是否為 1，如果不為 1 則直接跳過該行，減少內部迴圈的條件判斷。
 */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }   
        }
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] && rows[i] == 1 && cols[j] == 1) {
                    count++;
                }
            }   
        }
        return count;
    }
};