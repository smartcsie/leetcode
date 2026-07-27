/**
 * 題目：1903. Largest Odd Number in String (字串中的最大奇數)
 * 難度：簡單 (Easy)
 * 描述：在字串 num 中找出作為子字串的最大奇數。
 * * 時間複雜度：O(N) - N 為字串長度，最壞情況遍歷整字串。
 * 空間複雜度：O(1) - 除了回傳字串外，不額外佔用空間。
 * * 優化思路：
 * 1. 奇數判斷：利用位元運算 `(c - '0') % 2 != 0` 或 `c & 1`。
 * 2. 效率：直接使用 substr 回傳結果，避免不必要的記憶體搬移。
 */

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--) {
            if(num[i] & 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
