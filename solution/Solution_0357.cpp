/**
 * 題目：357. Count Numbers with Unique Digits
 * 難度：中等 (Medium)
 * 描述：計算範圍 [0, 10^n] 內各位數字不重複的整數個數。
 * * 時間複雜度：O(min(N, 10))。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 基礎情況 n=0 時結果為 1 (即 {0})。
 * 2. 累加各個位數的排列組合數：
 * - 1 位數：10 種 (0-9)
 * - 2 位數：9 * 9
 * - 3 位數：9 * 9 * 8 ...
 */

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(n, 10);
        int total = 1;
        int current = 9;
        for (int i = 1; i <= n; i++) {
            total += current;
            current *= (10 - i);
        }
        return total;
    }
};
