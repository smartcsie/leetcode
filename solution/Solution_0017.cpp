/**
 * 題目：17. Letter Combinations of a Phone Number
 * 難度：中等 (Medium)
 * 描述：找出電話號碼所有可能的字母組合。
 * * 優化重點：
 * 1. 預判邊界：若輸入 digits 為空，直接返回空陣列。
 * 2. 減少記憶體配置：使用 `reserve` 預先配置結果陣列空間，避免多次 reallocation。
 * 3. 簡化映射表：直接使用字串常數，減少 vector<char> 的嵌套與空間佔用。
 */

class Solution {
private:
    void backtrack(const vector<vector<char>>& letters, int depth, 
                   string& current, vector<string>& results) {
        if (depth == letters.size()) {
            results.push_back(current);
            return;
        }
        for (char c : letters[depth]) {
            current.push_back(c);
            backtrack(letters, depth + 1, current, results);
            current.pop_back(); 
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> map = {
                        {'a', 'b', 'c'}, {'d', 'e', 'f'},
                        {'g', 'h', 'i'}, {'j', 'k', 'l'},
                        {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                        {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
        };
        vector<vector<char>> letters;
        for(char c : digits) {
            letters.push_back(map[c-'2']);
        }
        std::vector<std::string> results;
        std::string current;
        backtrack(letters, 0, current, results);
        return results;
    }
};
