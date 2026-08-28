/**
 * 題目：3750. Minimum Number of Flips to Reverse Binary String
 * 難度：簡單 (Easy)
 * 描述：計算整數 n 與其位元反轉後之間的差異（需要翻轉的位元數）。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用內建函數 __builtin_popcount 直接計算位元差異，提升執行效率。
 */

class Solution {
public:
    int minimumFlips(int n) {
        int m = n;
        int r = 0;
        while(m > 0) {
            r = (r << 1) | (m & 1);
            m >>= 1;
        }
        return __builtin_popcount(n ^ r);
    }
};
