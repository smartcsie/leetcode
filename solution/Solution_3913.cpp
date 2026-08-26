/**
 * 題目：Sort Vowels by Frequency (依照頻率排序母音)
 * 難度：中等 (Medium)
 * 描述：根據母音在字串中出現的頻率進行排序（高頻優先，同頻率維持原序）。
 *
 * 時間複雜度：O(NlogN) - 母音排序開銷。
 * 空間複雜度：O(N) - 儲存母音清單的空間。
 */

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> freq(128, 0);
        vector<int> first(128, -1);
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if((0x104111 >> (c - 'a')) & 1) {
                freq[c]++;
                if(first[c] == -1) first[c] = i;
            }
        }
        sort(vowels.begin(), vowels.end(), [&](const char& c1, const char& c2){
            return freq[c1] != freq[c2] ? freq[c1] > freq[c2] : first[c1] < first[c2];
        });
        vector<char> sortedVowels;
        for(const char& c : vowels) {
            for(int i =1; i <= freq[c]; i++ ) sortedVowels.push_back(c);
        }
        int idx = 0;
        for(char& c : s) {
            if((0x104111 >> (c - 'a')) & 1) {
                c = sortedVowels[idx++];
            }
        }
        return s;
    }
};