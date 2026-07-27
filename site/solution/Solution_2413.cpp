/**
 * 題目：2413. Smallest Even Multiple (最小偶倍數)
 * 難度：簡單 (Easy)
 * 描述：回傳 n 與 2 的最小公倍數。
 * * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 * * 優化思路：
 * 1. 簡潔性：維持 O(1) 的數學運算，直接回傳結果。
 */

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n % 2) == 0 ? n : (n << 1);
    }
};
