/**
 * 題目：2894. Divisible and Non-divisible Sums Difference
 * 描述：給定兩個正整數 n 和 m。定義：
 *       - num1：範圍 [1, n] 內所有不能被 m 整除的整數之和。
 *       - num2：範圍 [1, n] 內所有能被 m 整除的整數之和。
 *       請返回 num1 - num2 的結果。
 * 
 * 解法思路：
 * 1. 設總和為 total_sum = [1, n] 的所有數字和，公式為 n * (n + 1) / 2。
 * 2. 設能被 m 整除的個數為 k = n / m，這些數字為 m, 2m, 3m, ..., km。
 *    其總和 divisible_sum = m * (1 + 2 + ... + k) = m * k * (k + 1) / 2。
 * 3. 題目要求的 num1 是「不能被 m 整除的總和」，即 `total_sum - divisible_sum`。
 * 4. 題目要求計算 `num1 - num2`：
 *    num1 - num2 = (total_sum - divisible_sum) - divisible_sum
 *                = total_sum - 2 * divisible_sum。
 */

class Solution {
public:
    int differenceOfSums(int n, int m) {
        // 1. 計算 [1, n] 的等差級數總和
        int total_sum = (1 + n) * n / 2;
        
        // 2. 計算小於等於 n 且能被 m 整除的個數 k
        int k = n / m;
        
        // 3. 計算所有能被 m 整除的數字總和 (num2)
        int divisible_sum = m * (k + 1) * k / 2;
        
        // 4. 代入公式：num1 - num2 = (total_sum - divisible_sum) - divisible_sum
        return total_sum - 2 * divisible_sum;
    }
};
