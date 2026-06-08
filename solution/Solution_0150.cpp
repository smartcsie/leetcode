/**
 * 題目：150. Evaluate Reverse Polish Notation (逆波蘭表示法求值)
 * 難度：中等 (Medium)
 * 描述：根據逆波蘭表示法，求表達式的值。
 * * 時間複雜度：O(N) - 每個 token 僅被處理一次。
 * 空間複雜度：O(N) - 堆疊最壞情況儲存所有運算元。
 * * 優化思路：
 * 1. 使用 `stack<int>` 暫存數值。
 * 2. 判斷運算子時，優先將邏輯單一化，直接依運算子處理。
 * 3. 優化：將 `tokens` 的遍歷改為 reference 引用以避免拷貝，提升執行效率。
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 如果只有一個 token，直接轉型回傳，無需堆疊
        if (tokens.size() == 1) return stoi(tokens[0]);
        
        stack<int> st;
        for (const string& s : tokens) {
            // 判斷是否為運算子 (注意負數開頭的數字字串長度大於1，避免誤判)
            if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                
                switch (s[0]) {
                    case '+': st.push(num1 + num2); break;
                    case '-': st.push(num1 - num2); break;
                    case '*': st.push(num1 * num2); break;
                    case '/': st.push(num1 / num2); break;
                }
            } else {
                // 數字則轉為 int 入棧
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
