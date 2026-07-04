/**
 * 題目：3726. Remove Zeros in Decimal Representation
 * 難度：簡單 (Easy)
 * 描述：移除整數中所有的 0，並將剩餘數字組成新整數。
 * * 優化重點：
 * 1. 效率提升：直接使用數學累加，避免字串轉換帶來的開銷。
 * 2. 邊界檢查：使用 long long 確保運算過程中位數擴增不會溢位。
 */

class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0;
        long long base = 1;
        while(n > 0) {
            int digit = n % 10;
            if(digit) {
                res += base * digit;
                base *= 10;
            }
            n /= 10;
        }
        return res;
    }
};
