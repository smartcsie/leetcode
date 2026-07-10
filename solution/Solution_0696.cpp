/**
 * 題目：696. Count Binary Substrings
 * 難度：簡單 (Easy)
 * 描述：計算所有出現 0 和 1 次數相等且連續的子字串。
 * * 優化重點：
 * 1. 空間 O(1)：直接在遍歷時累計並計算，無需額外陣列空間。
 * 2. 邏輯簡潔：利用相鄰分組的長度限制，將問題轉化為 min(prev, curr) 的累加。
 */

#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countBinarySubstrings(std::string s) {
        int ans = 0;
        int prev = 0, curr = 0;
        
        for (int i = 0; i < s.size(); i++) {
            curr++;
            // 當發現字元改變，或者到達最後一個字元時計算
            if (i + 1 == s.size() || s[i] != s[i + 1]) {
                ans += std::min(prev, curr);
                prev = curr;
                curr = 0;
            }
        }
        return ans;
    }
};
