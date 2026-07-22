/**
 * 題目：1614. Maximum Nesting Depth of the Parentheses
 * 描述：給定一個有效括號字串 s，請返回該字串的巢狀深度（即最大的括號巢狀層級）。
 * 
 * 解法思路：
 * 1. 巢狀深度的本質就是「當前未閉合的左括號數量」。
 * 2. 我們宣告兩個變數：`count` 紀錄當前深度，`maxCount` 紀錄曾經達到的最大深度。
 * 3. 走訪字串中的每一個字元 c：
 *    - 如果遇到 '('：代表進入更深一層，`count++`，並更新 `maxCount = max(maxCount, count)`。
 *    - 如果遇到 ')'：代表離開一層，`count--`。
 * 4. 走訪完畢後，`maxCount` 即為所求的最大深度。
 */

class Solution {
public:
    int maxDepth(std::string s) {
        int count = 0;
        int maxCount = 0;
        
        for (const char c : s) {
            if (c == '(') {
                count++;
                maxCount = std::max(maxCount, count);
            } else if (c == ')') {
                count--;
            }
        }
        
        return maxCount;
    }
};
