/**
 * 題目：3136. Valid Word (有效的單字)
 * 難度：簡單 (Easy)
 * 描述：檢查單字是否滿足長度限制、僅含字母數字、並至少含一個母音與一個輔音。
 * * 時間複雜度：O(N)，N 為字串長度。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 分層判斷：先判斷非法字元，再統計母音與輔音。
 * 2. 查表法優化：`isVowel` 函式使用靜態字串視圖提高效率。
 */


class Solution {
private:
    bool isVowel(char c) {
        string_view str = "AEIOUaeiou";
        return str.find(c) != string_view::npos;
    }
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int vowel = 0;
        int consonant = 0;
        for(char c : word) {
            if(isdigit(c)) {
                continue;
            } else if(isalpha(c)) {
                if(isVowel(c)) vowel++;
                else consonant++;
            } else {
                return false;
            }
        }
        return (vowel >= 1) && (consonant >= 1);
    }
};
