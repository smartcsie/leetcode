/**
 * 題目：507. Perfect Number (完美數)
 * 難度：簡單 (Easy)
 * 描述：判斷一個正整數是否為完美數（等於其所有真因數之和）。
 *
 * 時間複雜度：O(√N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 邊界處理：完美數定義是大於 1 的正整數。
 * 2. 成對因數：因數皆成對存在（例如 6 的因數 2 與 3），迴圈僅需執行到 √N。
 * 3. 完全平方數：若 i * i == num，則只應加一次該因數。
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;
        int sum = 1;
        for(int i = 2; i * i <= num; i++) {
            if(!(num % i)) {
                sum += i;
                if(i * i != num) sum += num / i;
            }
        }
        return sum == num;
    }
};