/**
 * 題目：Trim Trailing Vowels
 * 難度：簡單 (Easy)
 * 描述：移除字串末尾所有的母音（a, e, i, o, u，包含大小寫）。
 * 優化重點：
 * 1. O(N) 時間：僅需遍歷末端母音部分。
 * 2. 位元運算：利用 2130466 進行母音識別。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    string trimTrailingVowels(string s) {
        while(!s.empty() && (0x104111 >> (s.back() - 'a')) & 1) s.pop_back();
        return s;
    }
};
