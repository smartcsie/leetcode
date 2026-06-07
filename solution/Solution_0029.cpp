/**
 * 題目：29. Divide Two Integers (兩數相除)
 * 難度：中等 (Medium)
 * 描述：在不使用乘法、除法與取模運算子的情況下實現除法。
 * * 時間複雜度：O(log^2 N) - 每次倍增除數進行減法，總操作次數為對數級別。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 處理特殊邊界：INT_MIN / -1 會導致溢位 (超出 INT_MAX)。
 * 2. 轉換域：使用負數運算 (範圍比正數大 1)，完美解決 INT_MIN 轉為正數時的溢位。
 * 3. 倍增法：利用位元左移實現除數的快速倍增，模擬二分法除法。
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 邊界條件：INT_MIN 除以 -1 會發生溢位，直接返回 INT_MAX
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        // 全部轉為負數計算，避免 INT_MIN 轉正數發生溢位 (因為負數域範圍較廣)
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        int dvd = (dividend > 0) ? -dividend : dividend;
        int dvs = (divisor > 0) ? -divisor : divisor;
        
        int res = 0;
        while (dvd <= dvs) {
            int tmpDvs = dvs;
            int count = 1;
            
            // 安全倍增：檢查 tmpDvs 是否小於 INT_MIN / 2，避免左移發生下溢位
            // 在負數域，tmpDvs << 1 等於 tmpDvs * 2
            while (tmpDvs >= (INT_MIN >> 1) && dvd <= (tmpDvs << 1)) {
                tmpDvs <<= 1;
                count <<= 1;
            }
            
            res += count;
            dvd -= tmpDvs;
        }
        
        return isNegative ? -res : res;
    }
};
