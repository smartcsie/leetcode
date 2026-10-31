/**
 * 題目：678. Valid Parenthesis String (有效的括號字串)
 * 難度：中等 (Medium)
 * 描述：檢查包含 '(', ')', '*' 的字串是否有效，'*' 可代表空、'(', 或 ')'。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 區間追蹤：維護 `low` (最少需要匹配的左括號數) 與 `high` (最多能匹配的左括號數)。
 * 2. 邊界檢查：若 `high < 0`，代表右括號過多，立即返回 false。
 * 3. 負值修正：`low` 不能小於 0，因為左括號數量不可能為負。
 */

class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        for(char& c : s) {
            mn += (c == '(') ? 1 : -1; 
            mx += (c == ')') ? -1 : 1; 
            if(mx < 0) return false;
            mn = max(mn, 0);
        }
        return mn == 0;
    }
};