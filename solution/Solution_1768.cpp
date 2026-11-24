/**
 * 題目：1768. Merge Strings Alternately (交替合併字串)
 * 難度：簡單 (Easy)
 * 描述：交替合併 word1 和 word2，若某字串較長，則將剩餘部分接在後面。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans(word1.size() + word2.size(), ' ');
        auto it1 = word1.begin();
        auto it2 = word2.begin();
        auto it3 = ans.begin();
        while(it3 != ans.end()) {
            if(it1 != word1.end()) *it3++ = *it1++;
            if(it2 != word2.end()) *it3++ = *it2++;
        }
        return ans;
    }
};