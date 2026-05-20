/**
 * 題目：7. Reverse Integer (整數反轉)
 * 難度：中等 (Medium)
 * 描述：給你一個 32 位元的有號整數 x ，返回將 x 中的數字部分反轉後的結果。
 *      如果反轉後整數超過 32 位元的有號整數範圍 [−2^31, 2^31 − 1]，就返回 0。
 * 
 * 時間複雜度：O(log n) - 數字的位數約為 log10(n)。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * 
 * 解法思路：
 * 1. 透過 `x % 10` 取得最後一位數，並透過 `x / 10` 移除最後一位。
 * 2. 將結果不斷累加：`res = res * 10 + digit`。
 * 3. 溢位判定（關鍵）：
 *    在執行 `res * 10` 之前，檢查：
 *    - 如果 res > INT_MAX/10，乘以 10 必溢位。
 *    - 如果 res < INT_MIN/10，乘以 10 必溢位。
 *    (註：由於輸入的 x 本身是在 int 範圍內，反轉後若位數相同，其最後一位 digit
 *    不可能讓剛好等於 INT_MAX/10 的 res 發生溢位，故只需檢查到 /10 即可。)
 */

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // 檢查正向溢位
            // 如果 res 已經大於 214748364，乘以 10 至少是 2147483640
            if (res > INT_MAX / 10) return 0;
            // 檢查負向溢位
            if (res < INT_MIN / 10) return 0;

            res = res * 10 + pop;
        }
        return res;
    }
};
