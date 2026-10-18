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

class Solution {
public:
    string findValidPair(string s) {
        array<int, 10> counts;
        for(const char& c : s) counts[c - '0']++;
        for(int i = 0 ; i < s.size() - 1; i++) {
            int k1 = s[i] - '0';
            int k2 = s[i + 1] - '0';
            if(k1 != k2 && k1 == counts[k1] && k2 == counts[k2]) {
                return s.substr(i, 2);
            } 
        }
        return "";
    }
};