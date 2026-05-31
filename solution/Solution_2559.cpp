/**
 * 題目：2559. Count Vowel Strings in Ranges (統計範圍內的母音字串數)
 * 難度：中等 (Medium)
 * 描述：計算在給定查詢區間 [L, R] 內，首尾皆為母音的單字個數。
 * * 時間複雜度：O(N + Q) - N 為單字數，Q 為查詢數。
 * 空間複雜度：O(N) - 用於儲存前綴和陣列。
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // 判斷是否為母音的 Helper 函數，現代編譯器會自動 Inline
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int n = words.size();
        // prefix[i] 代表前 i 個單字中符合條件的個數
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            bool valid = isVowel(words[i].front()) && isVowel(words[i].back());
            prefix[i + 1] = prefix[i] + (valid ? 1 : 0);
        }

        vector<int> res;
        res.reserve(queries.size()); // 優化：預分配空間
        
        // 區間查詢公式：sum[L, R] = prefix[R + 1] - prefix[L]
        for (const auto& q : queries) {
            res.push_back(prefix[q[1] + 1] - prefix[q[0]]);
        }
        
        return res;
    }
};
