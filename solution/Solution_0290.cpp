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
        array<string, 26> c2w{};
        unordered_map<string, int> w2c;
        int pIdx = 0;
        for(int sIdx = 0, start = 0; sIdx <= s.size(); sIdx++) {
            if(sIdx == s.size() || s[sIdx] == ' ') {
                if (pIdx == pattern.size()) return false;
                int cIdx = pattern[pIdx++] - 'a';
                string word = s.substr(start, sIdx - start);
                if(!c2w[cIdx].empty() && c2w[cIdx] != word) return false;
                if(w2c.contains(word) && w2c[word] != cIdx) return false;
                c2w[cIdx] = word;
                w2c[word] = cIdx;
                start = sIdx + 1;
            }
        }
        return pIdx == pattern.size();
    }
};