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
        while (i < n && s[i] == ' ') i++;
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        int res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i++] - '0';
            if (res > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
        }
        return res * sign;
    }
};
