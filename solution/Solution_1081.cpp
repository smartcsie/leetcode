/**
 * 題目：1081. Smallest Subsequence of Distinct Characters
 * 描述：回傳字典序最小的子序列，要求包含所有字元且每個字元僅出現一次。
 * 
 * 解法思路 (單調棧)：
 * 1. 預處理：紀錄每個字元最後出現的位置 (lastIndex)。
 * 2. 遍歷字串：
 *    - 若字元已在 ans 中，則跳過。
 *    - 若當前字元比 ans 尾端的字元小，且尾端的字元在後面還會出現，則將其彈出 (pop)。
 *    - 將當前字元加入 ans。
 */

class Solution {
public:
    std::string smallestSubsequence(std::string s) {
        std::vector<int> last(26, 0);
        std::vector<bool> visit(26, false);
        std::string ans;
        // 紀錄每個字元最後出現的位置
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            // 若該字元已經在結果中，則跳過
            if (visit[c - 'a']) continue;
            // 嘗試維持單調遞增，若當前字元更小，且舊字元之後還能補回來，就彈出舊字元
            while (!ans.empty() && c < ans.back() && i < last[ans.back() - 'a']) {
                visit[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            visit[c - 'a'] = true;
        }
        return ans;
    }
};
