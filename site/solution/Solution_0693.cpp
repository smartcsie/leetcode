/**
 * 題目：693. Binary Number with Alternating Bits (交替位元二進位數)
 * 難度：簡單 (Easy)
 * 描述：判斷給定整數的二進位表示中，相鄰位元是否始終不同。
 * * 時間複雜度：O(1)，僅涉及有限次位元運算。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 簡化邏輯：利用 `(x & (x + 1)) == 0` 的特性，它能完美處理所有連續 1 的情況。
 * 2. 溢位防護：將 `n` 轉為 `long long` 以處理邊界情況 (如 `INT_MAX`)，避免 `n+1` 溢位錯誤。
 */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n ^ (n >> 1);
        return x == INT_MAX ? true : (x & (x + 1)) == 0;
    }
};
