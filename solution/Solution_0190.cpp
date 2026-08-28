/**
 * 題目：待補充
 * 難度：待補充
 * 描述：待補充
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 位元遍歷與拼湊
 * 1. 初始化結果 res = 0。
 * 2. 由於輸入是固定的 32 位元無符號整數，我們循環 32 次。
 * 3. 在每一次循環中：
 * - 將 res 向左移動一位 (res << 1)，為新的位元騰出空間。
 * - 取出 n 的最後一位 (n & 1)，並加到 res 的最低位。
 * - 將 n 向右移動一位 (n >> 1)，處理下一個位元。
 * 4. 循環結束後，res 即為反轉後的結果。
 */

class Solution {
public:
    int reverseBits(int n) {
        int reverse = 0 ;
        for(int i = 1; i <= 32; i++) {
            reverse = (reverse << 1) | (n & 1);
            n >>= 1;
        }
        return reverse;
    }
};
