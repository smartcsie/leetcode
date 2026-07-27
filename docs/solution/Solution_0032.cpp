/**
 * 題目：32. Longest Valid Parentheses (最長有效括號)
 * 難度：困難 (Hard)
 * 描述：找出字串中最長有效括號子串的長度。
 * 
 * 時間複雜度：O(n) - 遍歷字串一次。
 * 空間複雜度：O(n) - 堆疊中最多存儲 n 個索引。
 * 
 * 解法思路：
 * 1. 使用一個 stack 紀錄索引。
 * 2. 初始化堆疊放入 -1，這是為了處理第一個合法的括號組。
 *    例如：若 index 0 和 1 匹配，長度 = 1 - (-1) = 2。
 * 3. 遇到 '('：將索引壓入堆疊。
 * 4. 遇到 ')'：先彈出一個（代表消耗掉一個左括號）。
 *    - 彈出後如果堆疊為空，代表這個 ')' 是多餘的，將其索引壓入作為新的「邊界基準」。
 *    - 若不為空，長度即為 (當前索引 - 棧頂索引)。
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> st;
        // 放入 -1 作為基準，這能簡化邊界情況的計算
        st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // 將 '(' 的索引入棧
                st.push(i);
            } else {
                // 遇到 ')'，彈出對應的 '(' 索引
                st.pop();
                if (st.empty()) {
                    // 若堆疊為空，代表這是多餘的右括號，將其索引作為新的起始基準
                    st.push(i);
                } else {
                    // 計算當前長度：當前索引 i 減去棧頂的基準索引
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};
