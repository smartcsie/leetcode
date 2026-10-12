/**
 * 題目：2485. Find the Pivot Integer (找出中樞整數)
 * 難度：簡單 (Easy)
 * 描述：找到一個整數 x，滿足 1...x 之和等於 x...n 之和。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 數學推導：由 Sum(1, x) = Sum(x, n) 推導得 x^2 = Sum(1, n)。
 * 2. 驗證：僅需檢查 Sum(1, n) 是否為完全平方數，x 即為其平方根。
 */

#include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        int sum = (1 + n) * n / 2;
        int x = sqrt(sum);
        return (x * x == sum) ? x : -1;
    }
};
