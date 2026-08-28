/**
 * 題目：2864. Maximum Odd Binary Number
 * 難度：簡單 (Easy)
 * 描述：重新排列二進位字串，使其成為最大的奇數。
 * 優化重點：
 * 1. 貪婪法則：最末位保留一個 1，其餘 1 全部移至最左側。
 * 2. 效率：僅需統計 1 的數量並重組字串，線性時間 O(N)。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros = s.size() - ones;
        int idx = 0;
        for(int i = 1; i <= ones -1; i++) s[idx++] = '1';
        for(int i = 1; i <= zeros; i++) s[idx++] = '0';
        s[s.size() - 1] = '1';
        return s;
    }
};
