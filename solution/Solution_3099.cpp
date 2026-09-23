/**
 * 題目：3099. Harshad Number (哈沙德數)
 * 難度：簡單 (Easy)
 * 描述：計算整數 x 的各位數之和，若 x 能被該和整除，回傳該和，否則回傳 -1。
 *
 * 時間複雜度：O(log10(X)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 變數保護：使用 const 確保輸入值不被意外修改。
 * 2. 邊界檢查：雖然題目限制 x >= 1，但良好的代碼應考慮輸入為 0 或負數的可能性。
 */

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int digitSum = 0;
        int t = x;
        while(t > 0) {
            digitSum += t % 10;
            t/= 10;
        }
        return x % digitSum == 0 ? digitSum : -1;
    }
};
