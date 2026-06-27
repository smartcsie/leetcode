/**
 * 題目：50. Pow(x, n) (計算 x 的 n 次方)
 * 難度：中等 (Medium)
 * 描述：實現 pow(x, n)，計算 x 的 n 次冪。
 * * 時間複雜度：O(log N) - 指數每次減半。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 將 n 視為二進位組合。例如 x^13 = x^(1101_2) = x^8 * x^4 * x^1。
 * 透過不斷將底數平方，並在指數位元為 1 時累乘，達成極致效能。
 */

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MIN) return myPow(x * x, n / 2); // 單獨處理
        if (n < 0) return 1 / myPow(x, -n);
        if (n % 2 == 1) return x * myPow(x, n - 1);
        return myPow(x * x, n / 2);
    }
};
