/**
 * 題目：50. Pow(x, n) (計算 x 的 n 次方)
 * 難度：中等 (Medium)
 * 描述：實現 pow(x, n)，計算 x 的 n 次冪。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 設計思路：
 * 1. 將 n 視為二進位組合。
 * 2. 例如 x^13 = x^(1101_2) = x^8 * x^4 * x^1。
 * 3. 透過不斷將底數平方，並在指數位元為 1 時累乘，達成極致效能。
 */

class Solution {
    double myPow(double x, long n) {
        if(n == 0) return 1;
        if(n < 0) return 1 / myPow(x, -n);
        if(n & 1) return x * myPow(x, n - 1);
        return myPow(x * x, n /2);
    }
public:
    double myPow(double x, int n) {
        return myPow(x, static_cast<long>(n));
    }
};