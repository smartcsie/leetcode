/**
 * 題目：1759. Count Number of Homogenous Substrings
 * 難度：中等 (Medium)
 * 描述：計算同構子字串的總數（字串中所有字元皆相同的子字串）。
 * 
 * 解法思路：
 * 1. 同構子字串意味著子字串中的字元必須完全相同。
 * 2. 如果一段連續相同的字元長度為 `k`，該區塊能貢獻的同構子字串數量為：
 *    - 長度 1：k 個
 *    - 長度 2：k-1 個
 *    - ... 長度 k：1 個
 *    - 總和即為等差數列公式：k * (k + 1) / 2
 * 3. 遍歷字串，當遇到不同字元或結尾時，累加該區塊的貢獻值。
 */

class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        long ans = 0; 
        long count = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (i < s.size() && s[i] == s[i - 1]) {
                count++;
            } else {
                ans = (ans + count * (count + 1) / 2) % MOD;
                count = 1;
            }
        }
        return ans;
    }
};
