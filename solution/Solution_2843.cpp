/**
 * 題目：2843. Count Symmetric Integers
 * 難度：簡單 (Easy)
 * 描述：計算 [low, high] 區間內有多少「對稱整數」。
 *       定義：位數為偶數，且將數字對半分成兩部分，兩部分數位和相等。
 * 
 * 解法思路：
 * 1. 遍歷區間內的每個整數。
 * 2. 判斷數字位數：
 *    - 2 位數：判斷 (n/10) == (n%10)
 *    - 4 位數：前兩位數和 == 後兩位數和
 * 3. 注意：位數為奇數的整數 (例如 100-999) 永遠不對稱，無需考慮。
 */

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int n = low; n <= high; n++) {
            // 處理 2 位數
            if (n >= 10 && n <= 99) {
                if ((n / 10) == (n % 10)) count++;
            } 
            // 處理 4 位數
            else if (n >= 1000 && n <= 9999) {
                int left = n / 100;
                int right = n % 100;
                // 比較左右兩部分的總和
                if ((left / 10 + left % 10) == (right / 10 + right % 10)) {
                    count++;
                }
            }
        }
        return count;
    }
};
