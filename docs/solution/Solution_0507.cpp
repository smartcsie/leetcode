/**
 * 題目：507. Perfect Number (完美數)
 * 難度：簡單 (Easy)
 * 描述：判斷一個正整數是否為完美數（等於其所有真因數之和）。
 * * 時間複雜度：O(√N) - 只需要迴圈執行到 √N。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 邊界處理：完美數定義是大於 1 的正整數。
 * 2. 成對因數：因數皆成對存在（例如 6 的因數 2 與 3），迴圈僅需執行到 √N。
 * 3. 完全平方數：若 i * i == num，則只應加一次該因數。
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        // 根據定義，完美數必須大於 1
        if (num <= 1) return false;

        int sum = 1; // 1 永遠是真因數
        
        // 遍歷到根號即可，減少運算量
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sum += i;
                // 如果兩個因數不相等（即非完全平方數），則加上另一對因數
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }

        return sum == num;
    }
};
