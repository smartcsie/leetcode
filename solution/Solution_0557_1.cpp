/**
 * 題目：557. Reverse Words in a String III
 * 難度：簡單 (Easy)
 * 描述：反轉字串中每個單字的字元順序，保持單字間的相對位置。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （找邊界後反轉）：
 * 遍歷字串，遇到空格或結尾時對 [start, i) 區間做 reverse。
 */
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        for(int i = 0; i <= n; i++) {
            if(i == n || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};