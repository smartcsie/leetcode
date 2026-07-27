/**
 * 題目：2042. Check if Numbers Are Ascending in a Sentence (檢查句子中的數字是否遞增)
 * 難度：簡單 (Easy)
 * 描述：檢查句子中的數字是否嚴格遞增（不包含空格）。
 * 
 * 時間複雜度：O(n) - 遍歷字串一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * 
 * 解法思路：
 * 1. 使用 `stringstream` 或直接遍歷字串來解析數字。
 * 2. 維護一個 `prev` 變數記錄前一個遇到的數字，初始設為 -1。
 * 3. 每次解析到新數字時，判斷是否大於 `prev`。
 */

class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            // 檢查字串是否為數字 (檢查第一個字元即可判斷)
            if (isdigit(word[0])) {
                int curr = stoi(word);
                
                // 檢查是否嚴格遞增
                if (curr <= prev) {
                    return false;
                }
                prev = curr;
            }
        }
        
        return true;
    }
};
