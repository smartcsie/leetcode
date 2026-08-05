/**
 * 題目：205. Isomorphic Strings (同構字串)
 * 難度：簡單 (Easy)
 * 描述：判斷字串 s 與 t 是否同構。
 *
 * 時間複雜度：O(N) - 其中 n 是字串長度，只需遍歷一次。
 * 空間複雜度：O(1) - 使用固定大小為 128 的陣列，儲存 ASCII 字元映射。
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s2t(128, 0);
        vector<int> t2s(128, 0);
        for(int i = 0; i < s.size(); i++) {
            if(s2t[s[i]] && s2t[s[i]] != t[i]) return false;
            if(t2s[t[i]] && t2s[t[i]] != s[i]) return false;
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};
