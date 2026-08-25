class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(const char& c : s) {
            if( (0x104111 >> (c | 32) - 'a') & 1) vowels.push_back(c);
        }
        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for(char& c : s) {
            if( (0x104111 >> (c | 32) - 'a') & 1) c = vowels[idx++];
        }
        return s;
    }
};