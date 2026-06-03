/**
 * 題目：504. Base 7 (七進位轉換)
 * 難度：簡單 (Easy)
 * 描述：將給定的整數轉換為七進位字串。
 * * 時間複雜度：O(log7 N) - 每次除以 7，對數級別的時間複雜度。
 * 空間複雜度：O(1) - 僅使用常數額外空間儲存結果字串。
 * * 優化思路：
 * 1. 處理 0 的特殊情況。
 * 2. 使用 long long 處理絕對值，防止 INT_MIN 轉正數時發生溢位。
 * 3. 採用 `res = to_string(n % 7) + res` 的方式正確拼接位數。
 */

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        string res = "";
        bool is_negative = num < 0;
        
        // 使用 long long 防止 abs(INT_MIN) 溢位
        long long n = abs((long long)num);
        
        while (n > 0) {
            res = to_string(n % 7) + res;
            n /= 7;
        }
        
        return is_negative ? "-" + res : res;
    }
};
