/**
 * 題目：1318. Minimum Flips to Make a OR b Equal to c (使 a OR b 等於 c 的最小翻轉次數)
 * 難度：中等 (Medium)
 * 描述：計算翻轉 a 或 b 的位元，使 (a | b) == c 的最少次數。
 * * 時間複雜度：O(1)，整數固定為 32 位元。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 邏輯拆解：利用 XOR 與 AND 直接定位需要翻轉的位元。
 */

class Solution {
public:
    int minFlips(int a, int b, int c) {
        // (a | b) ^ c：找出 a|b 與 c 不同步的位元
        int diff = (a | b) ^ c;
        
        // 情況 1：c 的某位為 0，但 a 或 b 該位為 1 -> 需要翻轉該位的所有 1 (1 或 2 次)
        // (a & b) & diff：當 a, b 皆為 1 時，diff 位元會被記錄，需翻轉兩次
        int flips = __builtin_popcount(diff & ~c) + __builtin_popcount(a & b & diff);
        
        return flips;
    }
};
