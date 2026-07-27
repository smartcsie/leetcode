/**
 * 題目：1342. Number of Steps to Reduce a Number to Zero
 * 描述：給定一個非負整數 num。如果它是偶數，把它除以 2；
 *       如果它是奇數，把它減去 1。返回將它減到 0 所需的步驟數。
 * 
 * 解法思路：
 * 1. 傳統直覺是寫 while 迴圈模擬，時間複雜度為 O(log n)。
 * 2. 透過二進位視角來分析操作：
 *    - 奇數減 1：等同於將二進位中的某個 `1` 變成 `0`。因此總減法次數 = 二進位中 `1` 的總個數（Popcount）。
 *    - 偶數除以 2：等同於將二進位向右位移一位。因此總除法次數 = 二進位有效長度減 1。
 * 3. 利用 C++20 的 `<bit>` 內建函式，可以直接在 O(1) 時間內算出這兩個數值並相加。
 */

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) {
            return 0;
        }
        
        // 1. 計算二進位中 1 的個數（對應奇數減 1 的次數）
        int subtracts = std::popcount(static_cast<unsigned int>(num));
        
        // 2. 計算二進位長度減 1（對應偶數除以 2 的右移次數）
        int divides = std::bit_width(static_cast<unsigned int>(num)) - 1;
        
        // 3. 總步驟數 = 減法次數 + 除法次數
        return subtracts + divides;
    }
};
