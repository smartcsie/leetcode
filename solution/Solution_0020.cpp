/**
 * 題目：20. Valid Parentheses (有效的括號)
 * 難度：簡單 (Easy)
 * 描述：給定一個只包括 '('，')'，'{'，'}'，'['，']' 的字串 s ，判斷字串是否有效。
 *      有效字串需滿足：左括號必須用相同類型的右括號閉合，且必須以正確的順序閉合。
 * 
 * 時間複雜度：O(n) - 遍歷一次字串。
 * 空間複雜度：O(n) - 最壞情況下（全是左括號）需要將所有字元放入 Stack。
 * 
 * 解法思路：
 * 1. 利用 Stack (堆疊) 「後進先出」的特性。
 * 2. 遍歷字串：
 *    - 遇到左括號：將對應的「右括號」壓入 Stack。
 *    - 遇到右括號：
 *      a. 檢查 Stack 是否為空（代表沒有左括號可配對，回傳 false）。
 *      b. 檢查 Stack 頂端元素是否與當前右括號相同（不符則回傳 false）。
 *      c. 匹配成功，彈出 Stack 頂端元素。
 * 3. 最後檢查 Stack 是否為空（若不為空，代表有左括號未閉合）。
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // 技巧：遇到左括號時，直接把預期要看到的「右括號」塞進去
            // 這樣後續比對時只需要判斷是否相等，邏輯更乾淨
            if (c == '(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else if (c == '{') {
                st.push('}');
            } 
            // 如果是右括號：
            // 1. st.empty() 代表右括號比左括號多
            // 2. st.top() != c 代表括號類型不匹配（例如先開 [ 卻先閉 ) ）
            else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        // 如果全部匹配完，Stack 應該要是空的
        return st.empty();
    }
};
