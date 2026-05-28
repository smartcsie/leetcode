/**
 * 題目：8. String to Integer (atoi)
 * 難度：中等 (Medium)
 * 描述：模擬 atoi 函式，將字串轉為整數。
 * * 時間複雜度：O(N) - N 為字串長度。
 * 空間複雜度：O(1)。
 * * 解法思路：
 * 1. 跳過前導空格。
 * 2. 處理符號 (正/負)。
 * 3. 遍歷數字並進行溢位檢查：若 `res * 10 + digit` 會超過邊界，則返回邊界值。
 */

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. 跳過前導空格
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;
        
        // 2. 處理符號
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        
        // 3. 轉換數字並處理溢位
        long res = 0; // 使用 long 方便檢查溢位，也可使用 int 直接比較
        while (i < n && isdigit(s[i])) {
            int digit = s[i++] - '0';
            
            // 溢位檢查：利用當前結果與邊界比較
            // 注意：這裡直接判斷若 res * 10 + digit > INT_MAX 即可
            res = res * 10 + digit;
            
            if (sign == 1 && res > INT_MAX) return INT_MAX;
            if (sign == -1 && (-res) < INT_MIN) return INT_MIN;
        }
        
        return (int)(res * sign);
    }
};
