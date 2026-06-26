/**
 * 題目：3775. Reverse Words With Same Vowel Count (依母音數量翻轉單字)
 * 難度：簡單 (Easy)
 * 描述：計算第一個單字的母音數量，隨後若其他單字母音數相同，則將該單字反轉。
 * * 時間複雜度：O(N)，N 為字串總長度。
 * 空間複雜度：O(N)，用於存放結果字串。
 */

class Solution {
private:
    int countVowels(const std::string& s) {
        int count = 0;
        const std::string_view vowels = "aeiou";
        for (char c : s) {
            if (vowels.find(c) != std::string_view::npos) {
                count++;
            }
        }
        return count;
    }
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        ss >> word;
        int vowels = countVowels(word);
        string res = word;
        while(ss >> word) {
            res += " ";
            if(countVowels(word) == vowels) {
                reverse(word.begin(), word.end());
            }
            res += word;
        }
        return res;
    }
};
