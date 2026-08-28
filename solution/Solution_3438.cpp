/**
 * 題目：3438. Find Valid Pair of Adjacent Digits in String
 * 難度：簡單 (Easy)
 * 描述：在字串中尋找滿足以下條件的第一個相鄰數對：
 * 1. 兩個數字不相等。
 * 2. 每個數字在字串中的出現頻率等於該數字本身。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

#include <string>
#include <vector>

class Solution {
public:
    std::string findValidPair(std::string s) {
        vector<int> counts(10, 0);
        string ans;
        for(const char& c : s) counts[c - '0']++;
        for(int i = 0; i < s.size() - 1; i++) {
            int c1 = s[i] - '0';
            int c2 = s[i + 1] - '0';
            if(c1 != c2 && c1 == counts[c1] && c2 == counts[c2]) {
                ans.push_back(c1 + '0');
                ans.push_back(c2 + '0');
                return ans;
            }
        }
        return "";
    }
};
