/**
 * 題目：1957. Delete Characters to Make Fancy String
 * 難度：簡單 (Easy)
 * 描述：刪除字元以確保字串中不存在三個連續相同的字元。
 * * 時間複雜度：O(N) - N 為字串長度，我們只需遍歷一次字串。
 * 空間複雜度：O(N) - 用於儲存結果字串。
 * * 解法思路：
 * 1. 建立一個結果字串 t，用於構建目標字串。
 * 2. 遍歷原始字串 s 中的每一個字元。
 * 3. 檢查 t 的最後兩個字元：若 `t[n-1] == c` 且 `t[n-2] == c`，則跳過當前字元 c。
 * 4. 否則，將字元 c 加入 t 中。
 */

class Solution {
public:
    string makeFancyString(string s) {
        string t;
        for(const char& c : s) {
            int n = t.size();
            if( n < 2 || t[n - 1] != c ||  t[n - 2] != c) {
                 t.push_back(c);
            }
        }
        return t;
    }
};
