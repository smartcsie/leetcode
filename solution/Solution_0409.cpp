/**
 * 題目：409. Longest Palindrome
 * 難度：簡單 (Easy)
 * 描述：使用給定字串中的字元組成的最長回文長度。
 * 優化重點：
 * 1. 使用 `array<int, 128>` (大小為 128) 代替 `unordered_map`，減少雜湊計算開銷，效能更佳。
 * 2. 邏輯簡化：累加所有字元計數的 `count / 2 * 2` 部分。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(K)
 */

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1) return 1;
        array<int, 128> counts = {};
        for(const char& c : s) counts[c]++;
        int longest = 0;
        bool odd = false;
        for(int i = 0; i < 128; i++) {
            if(counts[i] == 0) continue;
            if(counts[i] & 1) {
                longest += (counts[i] - 1);
                odd = true;
            } else {
                longest += counts[i];
            }
        }
        return odd ? longest + 1 : longest;
    }
};