/**
 * 題目：3750. Minimum Number of Flips to Reverse Binary String
 * 難度：簡單 (Easy)
 * 描述：計算整數 n 與其位元反轉後之間的差異（需要翻轉的位元數）。
 * * 時間複雜度：O(log N)，處理位數。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 使用內建函數 __builtin_popcount 直接計算位元差異，提升執行效率。
 */

class Solution {
public:
    int minimumFlips(int n) {
        int reverse = 0;
        int m = n;
        while(m > 0) {
            reverse = (reverse << 1) | (m & 1);
            m >>= 1;
        }
        int x = reverse ^ n;
        int count = 0;
        while(x > 0) {
            x = x & (x- 1);
            count++;
        }
        return count;
    }
};
