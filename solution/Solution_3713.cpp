/**
 * 題目：3713. Longest Balanced Substring I
 * 難度：中等 (Medium)
 * 描述：找出最長子字串，其中所有出現過的字元出現次數必須相同。
 * * 優化重點：
 * 1. 數學簡化：透過 (長度 == 出現種類 * 最大頻率) 瞬間判斷平衡。
 * 2. 空間效率：僅使用長度 26 的陣列記錄頻率。
 */

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> count(26, 0);
            int char_types = 0;
            int max_count = 0;
            for(int j = i; j < n; j++) {
                int c = s[j] - 'a';
                count[c]++;
                if(count[c] == 1) char_types++;
                max_count = max(max_count, count[c]);
                if((j - i + 1) == max_count * char_types) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
