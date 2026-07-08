/**
 * 題目：3438. Find Valid Pair of Adjacent Digits in String
 * 難度：簡單 (Easy)
 * 描述：在字串中尋找滿足以下條件的第一個相鄰數對：
 * 1. 兩個數字不相等。
 * 2. 每個數字在字串中的出現頻率等於該數字本身。
 */

#include <string>
#include <vector>

class Solution {
public:
    std::string findValidPair(std::string s) {
        // 使用長度為 10 的陣列統計 0-9 出現頻率
        std::vector<int> count(10, 0);
        for (const char& c : s) {
            count[c - '0']++;
        }
        
        // 檢查相鄰的數位對
        for (int i = 0; i < (int)s.size() - 1; i++) {
            int d1 = s[i] - '0';
            int d2 = s[i + 1] - '0';
            
            // 條件檢查：不相等 且 頻率符合要求
            if (d1 != d2 && count[d1] == d1 && count[d2] == d2) {
                return s.substr(i, 2);
            }
        }
        
        return "";
    }
};
