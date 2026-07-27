/**
 * 題目：1582. Special Positions in a Binary Matrix (二進位矩陣中的特殊位置)
 * 難度：簡單 (Easy)
 * 描述：計算矩陣中所有符合 rowSum == 1 且 colSum == 1 的位置 (i, j)。
 * * 時間複雜度：O(m * n)，遍歷矩陣兩次。
 * 空間複雜度：O(m + n)，儲存每一行與每一列的計數。
 * * 優化思路：
 * 1. 減少冗餘判斷：在第二階段遍歷時，先檢查 rows[i] 是否為 1，如果不為 1 則直接跳過該行，減少內部迴圈的條件判斷。
 */

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<int> rowSum(m, 0);
        std::vector<int> colSum(n, 0);

        // 第一次遍歷：統計行與列總和
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }

        int count = 0;
        // 第二次遍歷：尋找特殊位置
        for(int i = 0; i < m; i++) {
            // 如果這一行總和不為 1，直接跳過 (效能優化)
            if (rowSum[i] != 1) continue;
            
            for(int j = 0; j < n; j++) {
                // 若符合特殊條件則計數
                if (mat[i][j] == 1 && colSum[j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
