/**
 * 題目：409. Longest Palindrome
 * 難度：簡單 (Easy)
 * 描述：使用給定字串中的字元組成的最長回文長度。
 * * 優化重點：
 * 1. 使用 `std::vector<int>` (大小為 128) 代替 `unordered_map`，減少雜湊計算開銷，效能更佳。
 * 2. 邏輯簡化：累加所有字元計數的 `count / 2 * 2` 部分。
 */

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1) return 1;
        unordered_map<char, int> counts;
        bool countOne = false;
        for(const char a : s) {
            counts[a]++;
        }
        int res = 0;
        for(const auto& [num,count] : counts) {
            if(count & 1) {
                countOne = true;
                res += (count - 1);
            } else {
                 res += count;
            }
        }
        return countOne ? res + 1 : res;
    }
};
