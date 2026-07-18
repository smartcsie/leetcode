/**
 * 題目：1935. Maximum Number of Words You Can Type
 * 描述：計算在給定壞掉鍵盤的情況下，有多少個完整的單字可以被完全輸入。
 * 
 * 解法思路：
 * 1. 使用 istringstream 將 text 切分成多個單字。
 * 2. 針對每個單字進行檢查，若單字中包含任何一個 brokenLetters，則該單字無法輸入。
 * 3. 統計未被標記為「損壞」的單字數量。
 */

class Solution {
public:
    int canBeTypedWords(std::string text, std::string brokenLetters) {
        std::istringstream ss(text);
        std::string word;
        int count = 0;
        
        while (ss >> word) {
            bool broken = false;
            // 檢查單字中是否包含任何一個壞掉的字母
            for (const char& c : brokenLetters) {
                if (word.find(c) != std::string::npos) {
                    broken = true;
                    break;
                }
            }
            if (!broken) count++;
        }
        
        return count;
    }
};
