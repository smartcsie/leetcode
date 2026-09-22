/**
 * 題目：3370. Smallest Number With All Set Bits
 * 難度：簡單 (Easy)
 * 描述：給定一個正整數 n，找出最小的整數使得其二進位表示中所有位元都為 1，
 * 且該整數大於或等於 n。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （bit_width + 全 1 遮罩）：
 * 1. 用 bit_width 計算 n 需要幾個 bit 表示。
 * 2. 建立一個相同位數、所有 bit 都為 1 的數字。
 *    例如 n=5（101），bit_width=3，建立 111=7。
 * 3. 全 1 的數字一定 >= n，且是最小的滿足條件的數字。
 *
 * 等價寫法：(1 << bits) - 1
 */
class Solution {
public:
    int smallestNumber(int n) {
        int bits = bit_width(static_cast<unsigned int>(n));
        return (1 << bits) - 1;
    }
};