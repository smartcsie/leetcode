/**
 * 題目：1572. Matrix Diagonal Sum (矩陣對角線總和)
 * 難度：簡單 (Easy)
 * 描述：計算方陣兩條對角線的元素之和。若元素屬於兩條對角線交集，只計算一次。
 * * 時間複雜度：O(N) - 僅遍歷矩陣的一行 (或 N 個元素)。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 方陣大小為 N*N，兩條對角線分別為：
 * 1. 主對角線：(i, i)
 * 2. 次對角線：(i, N - 1 - i)
 * 當 i == N - 1 - i 時，即為中心點，僅需累加一次。
 */

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int total = 0;
        
        for (int i = 0; i < n; ++i) {
            // 加入主對角線元素
            total += mat[i][i];
            
            // 加入次對角線元素，但排除主對角線已計算過的中心點
            // i != n - 1 - i 確保了不會重複累加中間元素
            if (i != n - 1 - i) {
                total += mat[i][n - 1 - i];
            }
        }
        
        return total;
    }
};
