/**
 * 題目：65. Valid Number
 * 描述：判斷一個字串是否為有效的數字（包括整數、小數、科學記號）。
 * 
 * 解法思路：
 * 1. 使用三個布林值 (flags) 來記錄狀態：`seenDigit` (是否見過數字)、`seenDot` (是否見過小數點)、`seenExponent` (是否見過科學記號)。
 * 2. 遍歷字串，根據當前字元分類處理：
 *    - 數字：標記已見過數字。
 *    - 正負號：只能在字串最開頭或緊接在 'e'/'E' 後面。
 *    - 小數點：前面不可有小數點或科學記號。
 *    - 'e'/'E'：前面不可有科學記號，且必須已經見過數字，重置 `seenDigit` 以檢查後面是否有數字。
 * 3. 最後必須確保至少見過一次數字 (`seenDigit`) 才是有效數字。
 */

class Solution {
public:
    bool isNumber(std::string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (std::isdigit(ch)) {
                seenDigit = true;
            } 
            else if (ch == '+' || ch == '-') {
                // 正負號只能出現在最開頭，或在 'e'/'E' 之後
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (ch == '.') {
                // 小數點不能重複出現，且不能出現在指數符號後
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else if (ch == 'e' || ch == 'E') {
                // 指數符號不能重複出現，且前面必須有數字
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // 重置，因為 'e' 後面必須緊接整數
            } 
            else {
                // 包含非數字、非符號等無效字元
                return false;
            }
        }
        
        // 字串有效的前提：最後必須結尾於有效的數字位
        return seenDigit;
    }
};
