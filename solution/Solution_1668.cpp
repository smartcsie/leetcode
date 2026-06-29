/**
 * 題目：1668. Maximum Repeating Substring (最大重複子字串)
 * 難度：簡單 (Easy)
 * 描述：計算 word 在 sequence 中連續重複出現的最大次數。
 * * 時間複雜度：O(N * M)，N 為 sequence 長度，M 為 word 長度。
 * 空間複雜度：O(N)。
 * * 優化思路：
 * 1. 使用 string_view 避免 substr 產生的字串拷貝，提升效能。
 * 2. 簡潔化狀態更新。
 */

#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

class Solution {
public:
    int maxRepeating(std::string sequence, std::string word) {
        int n = sequence.length();
        int m = word.length();
        if (m > n) return 0;

        std::vector<int> dp(n + 1, 0);
        int max_rep = 0;
        
        // 使用 string_view 進行無拷貝比較
        std::string_view seq_view(sequence);

        for (int i = m; i <= n; ++i) {
            // 比對當前位置的子字串是否等於 word
            if (seq_view.substr(i - m, m) == word) {
                // 如果等於，則當前重複次數為前一段 dp[i-m] + 1
                dp[i] = dp[i - m] + 1;
                max_rep = std::max(max_rep, dp[i]);
            }
        }
        
        return max_rep;
    }
};
