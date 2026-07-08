/**
 * 題目：1281. Subtract the Product and Sum of Digits of an Integer
 * 難度：簡單 (Easy)
 * 描述：回傳數位之積與數位之和的差。
 * * 優化重點：
 * 1. 單次遍歷：利用 while 迴圈一次處理所有位數，無需額外儲存空間。
 * 2. 數位拆解：`n % 10` 取得個位數，`n /= 10` 去除個位數。
 */

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        return product - sum;
    }
};
