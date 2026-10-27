/**
 * 題目：Sort Vowels by Frequency (依照頻率排序母音)
 * 難度：中等 (Medium)
 * 描述：根據母音在字串中出現的頻率進行排序（高頻優先，同頻率維持原序）。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    string sortVowels(string s) {
        array<int ,128> counts = {};
        array<int ,128> first;
        first.fill(-1);
        for(int i = 0; i < s.size(); i++) {
            if((0x104111 >> (s[i] - 'a')) & 1) {
                if(first[s[i]] == -1) first[s[i]] = i;
                counts[s[i]]++;

            }
        }
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        sort(vowels.begin(), vowels.end(), [&](char c1, char c2) {
            if(counts[c1] != counts[c2]) return counts[c1] > counts[c2];
            return first[c1] < first[c2];
        });
        int idx = 0;
        for(char& c : s) {
            if((0x104111 >> (c - 'a')) & 1) {
                while(counts[vowels[idx]]  == 0) idx++;
                char vowel = vowels[idx];
                c = vowel;
                counts[vowel]--;
            }
        }
        return s;
    }
};