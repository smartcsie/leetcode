/**
 * 題目：2169. Count Operations to Obtain Zero
 * 描述：給定兩個非負整數 num1 和 num2。如果 num1 >= num2，
 *       則用 num1 減去 num2；否則用 num2 減去 num1。
 *       重複此操作直到其中一個數字變為 0，返回所需的總操作次數。
 * 
 * 解法思路：
 * 1. 模擬減法的過程其實就是輾轉相除法（Euclidean Algorithm）的變形。
 * 2. 如果用單純的減法（while 迴圈每次減一次），當數字很大時會超時。
 * 3. 因此改用「除法與取餘數」優化：
 *    - 若 num1 >= num2，總共可以連續減去 (num1 / num2) 次，
 *      且操作後的新 num1 為 (num1 % num2)。
 *    - 反之亦然。
 * 4. 重複直到其中一個數字變成 0 為止，累加總次數。
 */

class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        
        // 當兩者皆不為 0 時持續迴圈
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                // 連續減法的次數等於 num1 / num2，剩餘的值為 num1 % num2
                count += num1 / num2;
                num1 %= num2;
            } else {
                // 同理，若 num2 較大
                count += num2 / num1;
                num2 %= num1;
            }
        }
        
        return count;
    }
};
