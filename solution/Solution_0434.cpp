/**
 * 題目：434. Number of Segments in a String (字串中的段數)
 * 難度：簡單 (Easy)
 * 描述：計算字串中連續非空白字元組成的區段數量。
 * * 時間複雜度：O(N) - 遍歷字串一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 一個區段的開始，必定滿足兩個條件：
 * 1. 當前字元不是空白。
 * 2. 當前字元是字串的第一個字元，或者它前一個字元是空白。
 */

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        char lastChar = ' ';
        for(char c : s) {
            if(c != ' ' && lastChar == ' ')  count++;
            lastChar = c;
        }
        return count ;
    }
};
