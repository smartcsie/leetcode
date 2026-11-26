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
        string alphas;
        string digits;
        for(const char& c : s) {
            if(islower(c)) alphas.push_back(c);
            else digits.push_back(c);
        }
        int alphaSize = alphas.size();
        int digitSize = digits.size();
        if(abs(alphaSize - digitSize) > 1) return "";
        string ans;
        for(int i = 0; i < min(alphaSize, digitSize); i++) {
            ans.push_back(alphas[i]);
            ans.push_back(digits[i]);
        }
        if(alphaSize > digitSize) ans.push_back(alphas.back());
        if(alphaSize < digitSize) ans.insert(ans.begin(), digits.back());
        return ans;
    }
};