/**
 * 題目：290. Word Pattern (單詞規律)
 * 難度：簡單 (Easy)
 * 描述：判斷字串 s 是否符合 pattern 的規律（雙射關係）。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(N+M)
 *
 * 解法思路：
 * 使用雙向雜湊表維護 "字符到單詞" 與 "單詞到字符" 的雙向映射，確保雙射 (Bijection)。
 */


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        unordered_map<int, string> c2w;
        unordered_map<string, int> w2c;
        string w;
        int idx = 0;
        while(iss >> w) {
            if(idx >= pattern.size()) return false;
            char c = pattern[idx];
            if(c2w.contains(c) && c2w[c] != w) return false;
            else c2w[c] = w;
            if(w2c.contains(w) && w2c[w] != c) return false;
            else w2c[w] = c;
            idx++;
        }
        return idx == pattern.size();
    }
};
