/**
 * 題目：290. Word Pattern (單詞規律)
 * 難度：簡單 (Easy)
 * 描述：判斷字串 s 是否符合 pattern 的規律（雙射關係）。
 * * 時間複雜度：O(N + M) - N 為 pattern 長度，M 為 s 長度。
 * 空間複雜度：O(N + M) - 雜湊表儲存映射關係。
 * * 解法思路：
 * 使用雙向雜湊表維護 "字符到單詞" 與 "單詞到字符" 的雙向映射，確保雙射 (Bijection)。
 */


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        int charIdx = 0;
        stringstream ss(s);
        string word;

        while(ss >> word) {
            char ch = pattern[charIdx];

            if(charToWord.contains(ch) && charToWord[ch] != word) return false;
            if(wordToChar.contains(word) && wordToChar[word] != ch) return false;

            charToWord[ch] = word;
            wordToChar[word] = ch;

            charIdx++;
        }
        return charIdx == pattern.size();
    }
};
