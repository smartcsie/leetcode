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
        // 先計算總位數，以決定第一位的正負號
        // 也可以直接算出最高位的除數 (divisor)
        int divisor = 1;
        int temp = n;
        while (temp >= 10) {
            temp /= 10;
            divisor *= 10;
        }
        
        int sum = 0;
        int sign = 1; // 第一位預設為正
        
        // 由高位向低位逐一取出數字
        while (divisor > 0) {
            int digit = (n / divisor) % 10;
            sum += sign * digit;
            sign *= -1; // 切換正負號
            divisor /= 10;
        }
        
        return sum;
    }
};
