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
        vector<char> vowels;
        unordered_map<char, int> counts;
        unordered_map<char, int> first;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if((0x104111 >> (c - 'a')) & 1) {
                vowels.push_back(c);
                counts[c]++;
                if(!first.contains(c)) first[c] = i;
            }
        }
        sort(vowels.begin(), vowels.end(), [&](const char& c1, const char& c2) {
            if(counts[c1] != counts[c2])
                return counts[c1] > counts[c2];
            return first[c1] < first[c2];
        });
        int idx = 0;
        for(char& c : s) {
            if((0x104111 >> (c - 'a')) & 1) {
                c = vowels[idx++];
            }
        }
        return s;
    }
};
