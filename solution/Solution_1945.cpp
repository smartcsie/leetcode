/**
 * 題目：1945. Sum of Digits of String After Convert
 * 難度：簡單 (Easy)
 * 描述：將字串轉為字母序數字 (a=1, b=2...)，並進行 k 次「數字位數和」轉換。
 *
 * 時間複雜度：O(N+K*log(SUM)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 轉換階段：將每個字元轉為對應數字 (1-26)，並直接將這些數字的「位數相加」計入初始總和。
 * 2. 迭代階段：根據題目要求執行 k-1 次位數總和轉換 (digitSum)。
 */

class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(const char& c : s) {
            int num = c - 'a' + 1;
            if(num >= 10) sum += (num / 10) + num %10;
            else sum += num;
        }
        k--;
        while(k > 0) {
            int n = sum;
            sum = 0;
            while(n > 0) {
                sum += n % 10;
                n /= 10;
            }
            k--;
        }
        return sum;
    }
};