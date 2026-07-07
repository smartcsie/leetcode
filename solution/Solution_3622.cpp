/**
 * 題目：3622. Check Divisibility by Digit Sum and Product
 * 難度：簡單 (Easy)
 * 描述：計算數字 n 的數位之和與數位之積，判斷 n 是否能被兩者之和整除。
 * * 優化重點：
 * 1. 數位拆解：透過 % 10 和 / 10 循環處理每個數位。
 * 2. 邊界檢查：特別處理 n 為 0 或含有 0 位元的情況，以避免除以零錯誤。
 */

class Solution {
public:
    bool checkDivisibility(int n) {
        if (n <= 0) return false;
        long long product = 1;
        int sum = 0;
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            product *= digit;
            sum += digit;
            temp /= 10;
        }
        return (n % (product + sum)) == 0;
    }
};
