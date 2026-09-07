/**
 * 題目：1417. Reformat The String
 * 難度：簡單 (Easy)
 * 描述：將字串重新排列，使數字與字母交替出現。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用兩個容器分別儲存所有字母與數字。
 * 2. 檢查兩者數量差，若大於 1 則無法交替排列，返回空字串。
 * 3. 根據數量較多的類型決定排列順序（字母多則字母先，否則數字先）。
 */

class Solution {
public:
    string reformat(string s) {
        vector<char> digits;
        vector<char> alphas;
        for(const char& c : s) {
            if(isdigit(c)) digits.push_back(c);
            else alphas.push_back(c);
        }
        string ans;
        ans.reserve(s.size());
        if(abs(static_cast<int>(digits.size()) - static_cast<int>(alphas.size())) > 1) return "";
        if(digits.size() > alphas.size()) swap(digits, alphas);
        for(int i = 0, j= 0;  i < alphas.size() || j < digits.size(); i++, j++) {
            if(i < alphas.size()) ans.push_back(alphas[i]);
            if(j < digits.size()) ans.push_back(digits[j]);
        }
        return ans;
    }
};