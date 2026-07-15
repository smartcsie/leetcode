/**
 * 題目：1790. Check if One String Swap Can Make Strings Equal
 * 難度：簡單 (Easy)
 * 描述：判斷是否能透過「最多」一次交換，使 s1 等於 s2。
 * * 時間複雜度：O(N) - N 為字串長度，需遍歷字串一次。
 * 空間複雜度：O(1) - 僅儲存最多兩個不匹配的字元對，空間為常數。
 * * 解法思路：
 * 1. 若兩字串完全相同，返回 true。
 * 2. 遍歷字串，記錄所有 s1[i] != s2[i] 的位置及字元。
 * 3. 若不匹配數量大於 2，則無法透過一次交換達成，返回 false。
 * 4. 若不匹配數量剛好為 2，檢查這兩組字元是否能透過交換達到相等（即 s1[i]==s2[j] 且 s1[j]==s2[i]）。
 */

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<pair<char, char>> diff;
        if(s1.size() != s2.size()) return false;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) diff.push_back({s1[i], s2[i]});
            if(diff.size() > 2) return false;
        }
        if(diff.size() == 0)  return true;
        return ((diff.size() == 2) && 
                (diff[0].first == diff[1].second) && 
                (diff[0].second == diff[1].first));
    }
};
