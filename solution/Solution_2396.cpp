/**
 * 題目：2396. Strictly Palindromic Number (嚴格回文數字)
 * 難度：中等 (Medium)
 * 描述：判斷整數 n 在所有 2 到 n-2 進位制下是否皆為回文。
 * * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 * * 設計思路：
 * 數學證明：
 * 對於任何 n >= 4，在 (n-2) 進位制下，n 表示為 "12"。
 * 因為 n = 1 * (n-2) + 2。
 * "12" 不是回文，因此對於所有題目給定範圍內的 n，結果永遠為 false。
 */

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        // 根據數學推導，對於題目範圍內的 n (4 <= n <= 10^5)，
        // n 在 (n-2) 進位制下的表示法為 "12"，恆不為回文。
        return false;
    }
};
