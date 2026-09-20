/**
 * 題目：3775. Reverse Words With Same Vowel Count (依母音數量翻轉單字)
 * 難度：簡單 (Easy)
 * 描述：計算第一個單字的母音數量，隨後若其他單字母音數相同，則將該單字反轉。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string w;
        int vowels = -1;
        string ans;
        while(iss >> w) {
            int count = 0;
            for(const char& c : w) if((0x104111 >> (c - 'a')) & 1) count++;
            if(vowels == -1) vowels = count;
            else if(count == vowels) reverse(w.begin(), w.end());
            ans += w;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
