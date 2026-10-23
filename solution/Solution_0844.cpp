/**
 * 題目：844. Backspace String Compare (退格字串比較)
 * 難度：簡單 (Easy)
 * 描述：比較兩個包含 '#' 的字串處理後是否相等。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int count1 = 0, count2 = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (s[i] == '#' || count1 > 0)) s[i--] == '#' ? ++count1 : --count1;
            while (j >= 0 && (t[j] == '#' || count2 > 0)) t[j--] == '#' ? ++count2 : --count2;
            if (i < 0 || j < 0) return i == j;
            if (s[i--] != t[j--]) return false;
        }
        return i == j;
    }
};