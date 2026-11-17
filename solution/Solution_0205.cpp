/**
 * 題目：205. Isomorphic Strings (同構字串)
 * 難度：簡單 (Easy)
 * 描述：判斷字串 s 與 t 是否同構。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        array<uint8_t, 128> s2t;
        s2t.fill(255);
        array<uint8_t, 128> t2s;
        t2s.fill(255);
        for(int i = 0 ; i < s.size(); i++) {
            char cs = s[i];
            char ct = t[i];
            if(s2t[cs] != 255 && s2t[cs] != ct) return false;
            else s2t[cs]= ct;
            if(t2s[ct] != 255 && t2s[ct] != cs) return false;
            else t2s[ct]= cs;
        }
        return true;
    }
};
