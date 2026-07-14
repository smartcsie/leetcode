/**
 * 題目：1417. Reformat The String
 * 難度：簡單 (Easy)
 * 描述：將字串重新排列，使數字與字母交替出現。
 * * 時間複雜度：O(N) - N 為字串長度，需遍歷字串進行分類與合併。
 * 空間複雜度：O(N) - 使用額外空間儲存數字與字母。
 * * 解法思路：
 * 1. 使用兩個容器分別儲存所有字母與數字。
 * 2. 檢查兩者數量差，若大於 1 則無法交替排列，返回空字串。
 * 3. 根據數量較多的類型決定排列順序（字母多則字母先，否則數字先）。
 */

class Solution {
public:
    string reformat(string s) {
        string alphas, digits;
        for (char c : s) {
            (isalpha(c) ? alphas : digits).push_back(c);
        }
        
        int m = alphas.size(), n = digits.size();
        if (abs(m - n) > 1) return "";
        
        if (m < n) swap(alphas, digits);
        
        string ans;
        for (int i = 0; i < alphas.size(); i++) {
            ans.push_back(alphas[i]);
            if (i < digits.size()) ans.push_back(digits[i]);
        }
        return ans;
    }
};
