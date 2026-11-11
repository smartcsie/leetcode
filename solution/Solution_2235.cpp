/**
 * 題目：2235. Add Two Integers (兩整數之和)
 * 難度：簡單 (Easy)
 * 描述：計算兩個整數 num1 和 num2 的和。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. XOR (^): 運算結果相當於「不考慮進位的加法」。(0+0=0, 0+1=1, 1+0=1, 1+1=0)
 * 2. AND (&) + 左移 (<< 1): 運算結果為「進位值」。只有兩個位元都為 1 時才會產生進位，
 * 且進位會傳遞到高一位，因此需要左移。
 * 3. 迴圈執行：將「不進位和」與「進位值」重複進行加法，直到進位為 0 為止。
 */
class Solution {
public:
    int sum(int num1, int num2) {
        while(num2) {
            int carry = static_cast<unsigned int>((num1 & num2) << 1);
            num1 ^= num2;
            num2 = carry;
        }
        return num1;
    }
};
