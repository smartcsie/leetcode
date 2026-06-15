/**
 * 解題思路：雙指標法 (Two Pointers)
 * 1. 使用兩個指標：i 指向字串 s (子序列)，j 指向字串 t (主字串)。
 * 2. 遍歷主字串 t：
 *    - 當 s[i] == t[j] 時，代表在 t 中找到了 s 的當前字元，將 i 向後移一位。
 *    - 不論是否匹配，j 每次都要向後移一位，繼續在 t 中尋找下一個字元。
 * 3. 判斷結果：
 *    - 如果 i 最終移動到了 s 的末尾 (i == s.length())，代表 s 的所有字元都在 t 中按順序出現了。
 * 
 * Time Complexity: O(n) - 其中 n 是主字串 t 的長度，最壞情況下需遍歷 t 一次。
 * Space Complexity: O(1) - 僅使用兩個整數指標。
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int i = 0;
        for(const char& c : t) {
            if(s[i] == c) {
                i++;
            }
            if(i == s.size()) return true;
        }
        return false;
    }
};
