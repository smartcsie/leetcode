/**
 * 題目：2310. Sum of Numbers With Units Digit K
 * 難度：中等 (Medium)
 * 描述：找出最少個數的加數（個位皆為 k），使得其總和等於 num。
 * 優化重點：
 * 1. 數學枚舉：因為個位數是循環的 (10)，所以只需要檢查 1 到 10 個加數的情況即可。
 * 2. 邊界處理：num 為 0 時回傳 0；若枚舉後無解則回傳 -1。
 *
 * 時間複雜度：O(10)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0)
            return 0;
        for (int i = 1; i <= 10 && i * k <= num; ++i)
            if (i * k % 10 == num % 10)
                return i;
        return -1;
    }
};
