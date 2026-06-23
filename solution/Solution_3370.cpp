/**
 * 題目：3370. Smallest Number With All Set Bits (具有所有位元為 1 的最小數字)
 * 難度：簡單 (Easy)
 * 描述：回傳一個大於或等於 n 的最小整數，其二進位表示皆為 1。
 * * 時間複雜度：O(log N)，即 n 的位元數。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 邏輯簡化：利用 `(1 << bit_count) - 1` 的性質，這比逐位元位移更具可讀性。
 */

class Solution {
public:
    int smallestNumber(int n) {
        int bits = 0;
        while(n > 0) {
            bits++;
            n >>= 1;
        }
        return (1 << bits) - 1;
    }
};
