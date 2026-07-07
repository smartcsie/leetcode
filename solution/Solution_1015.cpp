/**
 * 題目：1015. Smallest Integer Divisible by K
 * 難度：中等 (Medium)
 * 描述：找出最小的 repunit（由數字 1 組成的整數）能被 K 整除，回傳其位數；
 *       若不存在則回傳 -1。
 *
 * 核心概念：
 * - 只追蹤除以 K 的餘數，避免處理超大整數。
 * - 遞推公式：remainder = (remainder * 10 + 1) % K
 * - 若 K 為偶數或為 5 的倍數，repunit 必不可能整除，直接回傳 -1。
 * - 餘數空間大小為 K，超過 K 次迭代仍未歸零則代表無解。
 */
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        for (int length = 1, remainder = 0; length <= k; ++length) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return length;
            }
        }
        return -1;
    }
};
