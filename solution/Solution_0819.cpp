/**
 * 題目：819. Most Common Word
 * 難度：簡單 (Easy)
 * 描述：找出段落中未被禁用的最常用單詞。
 *
 * 時間複雜度：O(M+N)
 * 空間複雜度：O(M+N)
 */

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string s = paragraph;
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return ispunct(c) ? ' ' : tolower(c);
        });
        unordered_set bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> counts;
        istringstream iss(s);
        string w;
        while(iss >> w) {
            if(!bannedSet.contains(w)) counts[w]++;
        }
        int mx = 0;
        string ans;
        for(const auto& [w, count] : counts) {
            if(count > mx) {
                mx = count;
                ans = w;
            }
        }
        return ans;
    }
};