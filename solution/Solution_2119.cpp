/**
 * 題目：2119. A Number After a Double Reversal (反轉兩次後的數字)
 * 難度：簡單 (Easy)
 * 描述：判斷一個數字反轉兩次後，是否與原數字相等。
 * * 時間複雜度：O(1) - 僅進行一次模數運算。
 * 空間複雜度：O(1) - 無額外空間開銷。
 * * 優化思路：
 * 1. 數學性質：一個數字反轉兩次後與原數相等，當且僅當原數字不以 0 結尾（或原數字為 0）。
 */

class Solution {
public:
    bool isSameAfterReversals(int num) {
        // 如果 num 為 0，反轉後仍為 0，回傳 true。
        // 如果 num 不為 0 且末尾有 0 (num % 10 == 0)，反轉後會丟失該 0，故不相等，回傳 false。
        // 若 num 不為 0 且末尾非 0，反轉兩次後必定相等，回傳 true。
        return num == 0 || num % 10 != 0;
    }
};
