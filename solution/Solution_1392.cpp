/**
 * 題目：1392. Longest Happy Prefix
 * 難度：困難 (Hard)
 * 分類主題：greedy-selection-constraints
 * 描述：「快樂前綴」是既是字串的前綴、也是字串的後綴，且不等於整個
 * 字串本身。求 s 的最長快樂前綴（找不到就回傳空字串）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （這題就是 KMP 字串匹配演算法裡的「失敗函式（failure function）」
 * 本體，不是新算法，是直接應用）：
 * 1. 失敗函式 fail[i] 的定義本來就是「s[0..i] 這段字串，最長的
 *    『既是前綴、又是後綴』的長度」——這正好完全等於題目要求的
 *    「快樂前綴」定義（只是失敗函式是對每個前綴都算一次，題目只要
 *    整個字串的答案）。
 * 2. 標準 KMP 失敗函式建構：用 len 追蹤「目前比對到的前綴長度」，
 *    對每個位置 i，如果 s[i] 不等於 s[len]（前綴的下一個字元），就
 *    透過 fail[len-1] 回退到更短的前綴繼續嘗試（這是 KMP 的核心
 *    技巧，避免暴力回退到 0 重新比對）；如果相等，len 前進一格。
 * 3. fail[i] 記錄目前這個長度 len。
 * 4. 答案就是 fail[n-1]（整個字串的失敗函式值），對應的子字串就是
 *    最長快樂前綴；如果 fail[n-1] 是 0，代表沒有任何前綴同時是
 *    後綴，回傳空字串。
 */
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> fail(n, 0);
        int len = 0;
        for (int i = 1; i < n; ++i) {
            while (len > 0 && s[i] != s[len]) len = fail[len - 1];
            if (s[i] == s[len]) len++;
            fail[i] = len;
        }
        return s.substr(0, fail[n - 1]);
    }
};
