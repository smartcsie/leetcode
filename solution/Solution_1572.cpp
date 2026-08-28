/**
 * 題目：1572. Matrix Diagonal Sum (矩陣對角線總和)
 * 難度：簡單 (Easy)
 * 描述：計算方陣兩條對角線的元素之和。若元素屬於兩條對角線交集，只計算一次。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 方陣大小為 N*N，兩條對角線分別為：
 * 1. 主對角線：(i, i)
 * 2. 次對角線：(i, N - 1 - i)
 * 當 i == N - 1 - i 時，即為中心點，僅需累加一次。
 */

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i < n; i ++) {
            sum += mat[i][i];
            if(i != (n - 1 - i)) {
                sum += mat[i][ n - 1 -i];
             }
        }
        return sum;
    }
};
