/**
 * 題目：804. Unique Morse Code Words
 * 難度：簡單 (Easy)
 * 描述：將每個單字轉換為摩斯密碼，計算有多少種唯一的密碼組合。
 * * 優化重點：
 * 1. 使用 `std::string::reserve` 預分配摩斯密碼轉換後的空間，避免動態擴充。
 * 2. 使用 `std::vector<string_view>` 或直接存取陣列，提升轉換效率。
 */

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static const vector<string> morse = { 
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        };
        unordered_set<string> unique_codes;
        unique_codes.reserve(words.size());
        for(const string& word : words) {
            string str;
            for(char c : word) str += morse[c - 'a'];
            unique_codes.insert(str);
        }
        return unique_codes.size();
    }
};
