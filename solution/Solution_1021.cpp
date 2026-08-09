/**
 * 題目：1021. Remove Outermost Parentheses
 * 難度：待補充
 * 描述：移除有效括號字串中，每個原語括號組的最外層括號。
 *
 * 時間複雜度：O(N) - 計數器追蹤括號深度，不需 stack。
 * 空間複雜度：O(1) - 僅使用一個計數變數。
 *
 * 解法思路：
 * 1. 使用 count 變數紀錄當前括號的嵌套深度。
 * 2. 遍歷字串：
 * - 對於左括號 '('：若 count > 0，說明當前左括號不是外層，將其加入 ans，接著 count++。
 * - 對於右括號 ')'：先 count--，若 count > 0，說明當前右括號不是外層，將其加入 ans。
 */

class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        string ans;
        int count = 0;
        for(const char& c : s) {
            if(c == '(') {
                if(count >= 1) ans.push_back(c);
                count++;
            } else {
                count--;
                if(count >= 1) ans.push_back(c);
            }
        }
        return ans;
    }
