/**
 * 題目：3345. Smallest Divisible Digit Product I
 * 難度：簡單 (Easy)
 * 描述：找出大於等於 n 的最小整數，使其所有數位的乘積可以被 t 整除。
 *
 * 核心概念：
 * - 從 n 開始逐一枚舉候選數。
 * - 對每個候選數拆解各數位並計算乘積。
 * - 檢查乘積是否為 t 的倍數，符合條件即回傳。
 */
class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; ; i++) {
            int temp = i;
            int product = 1;
            while(temp > 0) {
                product *= temp % 10;
                temp /= 10;
            }
            if(product % t == 0) return i;
        }
        return -1;
    }
};
