/**
 * 題目：1021. Remove Outermost Parentheses
 * 描述：移除有效括號字串中，每個原語括號組的最外層括號。
 * 
 * 解法思路：
 * 1. 使用 count 變數紀錄當前括號的嵌套深度。
 * 2. 遍歷字串：
 *    - 對於左括號 '('：若 count > 0，說明當前左括號不是外層，將其加入 ans，接著 count++。
 *    - 對於右括號 ')'：先 count--，若 count > 0，說明當前右括號不是外層，將其加入 ans。
 */

class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string ans;
        int count = 0;
        
        for (const char c : s) {
            if (c == '(') {
                // 若 count > 0，代表此 '(' 被包在其他括號內
                if (count > 0) ans.push_back(c);
                count++;
            } else { // c == ')'
                count--;
                // 若 count > 0，代表此 ')' 對應的左括號不是外層
                if (count > 0) ans.push_back(c);
            }
        }
  
        return ans;
    }
