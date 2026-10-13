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
        int digits = 0;
        for (const char& c : s) isdigit(c) digits++;
        int alphas = s.size() - digits;
        if (abs(alphas - digits) > 1) return "";
        bool digitMore = (digits > alphas);
        string ans(s.size(), ' ');
        int evenIdx = 0, oddIdx = 1;
        for (const char& c : s) {
            if (digitMore == isdigit(c)) {
                ans[evenIdx] = c;
                evenIdx += 2;
            } else {
                ans[oddIdx] = c;
                oddIdx += 2;
            }
        }
        return ans;
    }
};