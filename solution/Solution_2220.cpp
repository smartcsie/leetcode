/**
 * 題目：2220. Minimum Bit Flips to Convert Number (轉換數字的最少位元翻轉次數)
 * 難度：簡單 (Easy)
 * 描述：計算將 `start` 轉換為 `goal` 所需的最少位元翻轉次數。
 * 
 * 時間複雜度：O(log N) - N 為兩個數字的最大值，迴圈執行次數等於二進位位元數。
 * 空間複雜度：O(1) - 僅使用整數變數。
 * 
 * 解法思路 (XOR + Hamming Weight)：
 * 1. XOR (^) 運算：若兩個位元相同則為 0，不同則為 1。
 *    因此，`start ^ goal` 的結果中，所有為 1 的位元即為需要翻轉的地方。
 * 2. 統計 1 的個數：
 *    - 方法一：你使用的 `while` 迴圈搭配位移運算 (>> 1)。
 *    - 方法二 (進階)：使用內建函數 `__builtin_popcount(xorVal)`，執行效率極高。
 */

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int xorVal = start ^ goal;
        while(xorVal > 0) {
            xorVal &= (xorVal - 1);
            count ++;
        }
        return count;
    }
};
