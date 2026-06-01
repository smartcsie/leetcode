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
        double res = 1;
        long num = abs((double)n);
        while (num != 0) {
            if (num % 2 != 0) res *= x;
            x *= x;
            num >>= 1;
        }
        return n >= 0 ? res : 1 / res;
    }
};
