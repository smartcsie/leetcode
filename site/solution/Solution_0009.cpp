/**
 * 題目：9. Palindrome Number (回文數)
 * 難度：簡單 (Easy)
 * 描述：給你一個整數 x ，如果 x 是一個回文整數，返回 true ；否則，返回 false 。
 *      回文數是指正序（從左向右）和倒序（從右向左）讀都是一樣的整數。
 * 
 * 時間複雜度：O(log n) - 每次除以 10，執行次數為數字位數的一半。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * 
 * 解法思路 (反轉一半數字)：
 * 1. 排除顯然不是回文的情況：
 *    - 負數絕對不是回文（因為有負號）。
 *    - 最後一位是 0 但本身不是 0 的數（因為第一位不可能是 0）。
 * 2. 反轉數字的後半部分：
 *    - 透過 `x % 10` 取得末位，累加到 `revertedNumber`。
 *    - 當 `x <= revertedNumber` 時，代表已經處理了一半以上的位數。
 * 3. 比較：
 *    - 偶數位數：`x == revertedNumber`。
 *    - 奇數位數：`x == revertedNumber / 10` (忽略中間那位數)。
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int reverse = 0;
        int y = x;
        while(y > 0) {
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && (x % 10) > 7)) return 0;
            reverse = reverse * 10 + (y % 10);
            y /= 10;
        }
        return x == reverse;
    }
};
