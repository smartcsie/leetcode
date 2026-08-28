/**
 * 題目：1002. Find Common Characters (查找共用字元)
 * 難度：簡單 (Easy)
 * 描述：待補充
 *
 * 時間複雜度：O(N*K)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> minFreq(26, INT_MAX);
        for(const string& s : words) {
            vector<int> freq(26, 0);
            for(const char& c : s) freq[c - 'a']++;
            for(int i = 0; i < 26; i++) minFreq[i] = min(minFreq[i], freq[i]);
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            while(minFreq[i]--)   ans.push_back(string(1, i + 'a'));
        }
        return ans;
    }
};
