/**
 * 題目：待補充
 * 難度：待補充
 * 描述：待補充
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 雙指標法 (Two Pointers)
 * 1. 使用兩個指標：i 指向字串 s (子序列)，j 指向字串 t (主字串)。
 * 2. 遍歷主字串 t：
 * - 當 s[i] == t[j] 時，代表在 t 中找到了 s 的當前字元，將 i 向後移一位。
 * - 不論是否匹配，j 每次都要向後移一位，繼續在 t 中尋找下一個字元。
 * 3. 判斷結果：
 * - 如果 i 最終移動到了 s 的末尾 (i == s.length())，代表 s 的所有字元都在 t 中按順序出現了。
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int idx = 0;
        for(const char& c : t) {
            if(c == s[idx]) idx++;
            if(idx == s.size()) return true;
        }
        return false;
    }
};
