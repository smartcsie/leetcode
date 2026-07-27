/**
 * 題目：62. Unique Paths (不同路徑)
 * 難度：中等 (Medium)
 * 描述：在 m x n 的網格中，計算從左上角到右下角的總路徑數。
 * * 時間複雜度：O(min(m, n)) - 取決於組合數計算中 k 的大小。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 組合數學：總步數為 (m-1) + (n-1)，從中選取 m-1 步向下走。
 * 2. 避免溢位：在計算 C(n, k) 時，先乘再除，並利用對稱性縮小 k。
 */

class Solution {
private:
    long C(int n, int k) {
        if(k == 0 || k == n) return 1;
        long res = 1;
        if (k > n / 2) k = n - k;
        for(int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }
public:
    int uniquePaths(int m, int n) {
        return static_cast<int>(C(m + n - 2, m - 1));
    }
};
