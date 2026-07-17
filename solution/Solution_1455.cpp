/**
 * 題目：1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
 * 難度：簡單 (Easy)
 * 描述：檢查 searchWord 是否為 sentence 中某個單字的前綴，返回第一個符合的單字索引 (1-indexed)。
 * 
 * 解法思路：
 * 1. 使用 `istringstream` 將句子依照空白分割成一個個單字。
 * 2. 遍歷每個單字，並使用 `word.find(searchWord) == 0` 來判斷 `searchWord` 是否出現於單字的開頭位置 (即索引 0)。
 * 3. 維護一個 `index` 計數器從 1 開始，一旦符合條件立即回傳。
 */

class Solution {
public:
    int isPrefixOfWord(std::string sentence, std::string searchWord) {
        std::istringstream ss(sentence);
        std::string word;
        int index = 1;
        
        while (ss >> word) {
            // find 回傳 0 代表字串以 searchWord 開頭
            if (word.find(searchWord) == 0) {
                return index;
            }
            index++;
        }
        
        return -1;
    }
};
