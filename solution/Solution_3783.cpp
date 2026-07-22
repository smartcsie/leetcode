/**
 * 題目：Mirror Distance of an Integer
 * 描述：給定一個整數 n，求其原本數值與其「反轉數字（Mirror）」之間的絕對距離。
 *       例如 n = 123，其反轉後為 321，距離即為 abs(123 - 321) = 198。
 * 
 * 解法思路：
 * 1. 使用一個變數 reverse 來儲存反轉後的數字，初始為 0。
 * 2. 使用一個暫存變數 temp 保留原數字 n 的值，進行 while 迴圈剝離每一位數：
 *    - 每次透過 temp % 10 取得最低位數。
 *    - 將 reverse 乘以 10 並加上該位數，逐步組合出反轉後的數字。
 *    - 將 temp 除以 10 進入下一位。
 * 3. 迴圈結束後，計算 abs(n - reverse) 並回傳結果。
 */

class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0;
        int temp = n;
        
        // 數學反轉數字的標準寫法
        while (temp > 0) {
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }
        
        // 回傳原數字與反轉數字的絕對差值
        return std::abs(n - reverse);
    }
};
