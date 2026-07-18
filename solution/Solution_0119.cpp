/**
 * 題目：119. Pascal's Triangle II
 * 描述：回傳帕斯卡三角形的第 rowIndex 行。
 * 
 * 解法思路 (組合數公式)：
 * 1. 帕斯卡三角形第 n 行的第 k 個數即為組合數 C(n, k)。
 * 2. C(n, k) = n! / (k! * (n-k)!)。
 * 3. 為了計算效率與避免溢位，使用遞迴乘法公式：
 *    C(n, i) = C(n, i-1) * (n - i + 1) / i。
 */

class Solution {
private:
    // 計算組合數 C(n, k)
    int combination(int n, int k) {
        if (k == 0 || k == n) return 1;
        // 利用對稱性 C(n, k) = C(n, n-k) 減少運算次數
        if (k > n / 2) k = n - k;
        long res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
        }
        return static_cast<int>(res);
    }
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> ans(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            ans[i] = combination(rowIndex, i);
        }
        return ans;
    }
};
