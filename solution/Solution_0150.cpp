/**
 * 題目：150. Evaluate Reverse Polish Notation (逆波蘭表示法求值)
 * 難度：中等 (Medium)
 * 描述：根據逆波蘭表示法，求表達式的值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用 `stack<int>` 暫存數值。
 * 2. 判斷運算子時，優先將邏輯單一化，直接依運算子處理。
 * 3. 優化：將 `tokens` 的遍歷改為 reference 引用以避免拷貝，提升執行效率。
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string s : tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                if(s == "+") st.push(x + y);
                else if(s == "-") st.push(x - y);
                else if(s == "*") st.push(x * y);
                else if(s == "/") st.push(x / y);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};
