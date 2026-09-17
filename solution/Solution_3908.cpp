/**
 * 題目：3908. Valid Digit Number (有效的位數數字)
 * 難度：簡單 (Easy)
 * 描述：判斷整數 n 的最高位是否不為 x，且剩餘位數中是否至少包含一個 x。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 移除浮點數運算：避免 `log10` 和 `floor` 的精度風險，改用純整數除法。
 * 2. 單次遍歷：在提取位數的同時同步記錄最高位與是否出現過 x。
 */

class Solution {
public:
    bool validDigit(int n, int x) {
        int d;
        int m = n;
        bool valid = false;
        while(m > 0) {
            d = m % 10;
            if(d == x) valid = true;
            m /= 10;
        }
        return valid && (d != x);
    }
};