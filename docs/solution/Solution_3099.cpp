/**
 * 題目：3099. Harshad Number (哈沙德數)
 * 難度：簡單 (Easy)
 * 描述：計算整數 x 的各位數之和，若 x 能被該和整除，回傳該和，否則回傳 -1。
 * * 時間複雜度：O(log10(x)) - 取決於數字 x 的位數。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 變數保護：使用 const 確保輸入值不被意外修改。
 * 2. 邊界檢查：雖然題目限制 x >= 1，但良好的代碼應考慮輸入為 0 或負數的可能性。
 */

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        // 根據題目限制，x >= 1，因此不需處理除以 0 的錯誤
        int sum = 0;
        int temp = x;
        // 拆解位數並加總
        while (temp > 0) {
            sum += (temp % 10);
            temp /= 10;
        }
        // 檢查是否為 Harshad 數
        return (x % sum == 0) ? sum : -1;
    }
};
