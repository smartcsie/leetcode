/**
 * 題目：2351. First Letter to Appear Twice (第一個出現兩次的字母)
 * 難度：簡單 (Easy)
 * 描述：在字串中找出第一個出現兩次的字元。
 *
 * 時間複雜度：O(N) - N 為字串長度，最壞情況掃描完整個字串。
 * 空間複雜度：O(1) - 使用長度為 26 的固定陣列，不隨輸入大小改變。
 *
 * 解法思路：
 * 由於字元僅限小寫英文字母，使用 `int[26]` 取代 `unordered_map` 可以省去雜湊運算，
 * 顯著提升執行效能並降低記憶體佔用。
 */

class Solution {
public:
    char repeatedCharacter(string s) {
        char repeatedCharacter(string s) {
        vector<int> counts(26, 0);
        for(const char& c : s) {
            counts[c - 'a']++;
            if(counts[c - 'a'] == 2) return c;
        }
        return ' ';
    }
    }
};
