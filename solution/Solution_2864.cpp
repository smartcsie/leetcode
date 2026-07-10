/**
 * 題目：2864. Maximum Odd Binary Number
 * 難度：簡單 (Easy)
 * 描述：重新排列二進位字串，使其成為最大的奇數。
 * * 優化重點：
 * 1. 貪婪法則：最末位保留一個 1，其餘 1 全部移至最左側。
 * 2. 效率：僅需統計 1 的數量並重組字串，線性時間 O(N)。
 */

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // 1. 使用標準函式庫統計，乾淨且高效
        int ones = std::count(s.begin(), s.end(), '1');
        // 2. 原地修改字串（保留你的空間效率優勢）
        s.assign(s.size(), '0'); // 將全字串重置為 '0'
        s[s.size() - 1] = '1';   // 末位設定為 '1'
        // 3. 填入剩餘的 '1'
        if (ones > 0) {
            std::fill(s.begin(), s.begin() + ones - 1, '1');
        }
        return s;
    }
};
