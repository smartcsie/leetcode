/**
 * 題目：2544. Alternating Digit Sum (交替數位和)
 * 難度：簡單 (Easy)
 * 描述：計算數字中各位數的交替和（第一位為正，第二位為負，以此類推）。
 * * 時間複雜度：O(log N)，即數字的位數。
 * 空間複雜度：O(1)，僅使用常數額外空間。
 * * 優化思路：
 * 1. 無字串轉換：直接進行數學運算，消除了動態記憶體配置 (malloc/free)。
 * 2. 算術提取：透過取餘與除法直接取得每一位數字。
 */

class Solution {
public:
    int alternateDigitSum(int n) {
        int digit = 0;
        int temp = n;
        while(temp > 0) {
            digit++;
            temp /= 10;
        }
        int sign = (digit % 2 == 0) ? -1 : 1;
        int sum = 0;
        
        while(n > 0) {
            sum += sign * (n % 10);
            n /= 10;
            sign *= -1;
        }
        return sum;
    }
};
