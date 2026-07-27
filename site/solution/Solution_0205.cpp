/**
 * 題目：205. Isomorphic Strings (同構字串)
 * 難度：簡單 (Easy)
 * 描述：判斷字串 s 與 t 是否同構。
 * 
 * 時間複雜度：O(n) - 其中 n 是字串長度，只需遍歷一次。
 * 空間複雜度：O(1) - 使用固定大小為 128 的陣列，儲存 ASCII 字元映射。
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        char s_to_t[128] = {0};
        char t_to_s[128] = {0};
        for(int i = 0; i < n; i++) {
            if(s_to_t[s[i]] !=0  && s_to_t[s[i]]!= t[i]) return false;
            if(t_to_s[t[i]] !=0  && t_to_s[t[i]]!= s[i]) return false;
            s_to_t[s[i]] = t[i];
            t_to_s[t[i]] = s[i];
        }  
        return true;
    }
};
