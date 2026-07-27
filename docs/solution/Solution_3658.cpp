/**
 * 題目：3658. GCD of Odd and Even Sums
 * 難度：簡單 (Easy)
 * 描述：求前 n 個偶數之和與前 n 個奇數之和的最大公因數。
 * * 時間複雜度：O(log N) - 主要取決於 gcd 的計算效率。
 * 空間複雜度：O(1)
 * * 解法思路：
 * 1. 前 n 個偶數：2, 4, ..., 2n。總和為 n(n + 1) = n^2 + n。
 * 2. 前 n 個奇數：1, 3, ..., 2n-1。總和為 n^2。
 * 3. 使用 std::gcd 計算 gcd(n^2 + n, n^2)。
 * 4. 根據歐幾里得性質：gcd(a, b) = gcd(a - b, b)
 *    gcd(n^2 + n, n^2) = gcd(n, n^2) = n。
 */

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
