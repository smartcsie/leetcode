/**
 * 題目：1347. Minimum Number of Steps to Make Two Strings Anagram
 * 描述：給你兩個長度相同的字串 s 和 t。在一步操作中，你可以選擇 t 中的任一字元，並把它換成其他任意字元。
 *       請返回使 t 成為 s 的安格拉姆（Anagram）所需的最小操作步數。
 * 
 * 解法思路：
 * 1. 宣告兩個大小為 26 的計數陣列 `countS` 與 `countT`，分別統計字串 s 和 t 中每個小寫字母的出現次數。
 * 2. 同步走訪兩個字串，將對應字元的計數器加 1。
 * 3. 遍歷 26 個字母的頻率：
 *    - 如果 `t` 中的某個字母數量大於 `s` 中的數量（`countT[i] > countS[i]`），
 *      代表這個字母在 `t` 中過剩，我們必須將這些多出來的字母替換掉。
 *    - 將過剩的數量差（`countT[i] - countS[i]`）累加到答案 `ans` 中。
 * 4. 迴圈結束後返回 `ans`。
 */

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::vector<int> countS(26, 0);
        std::vector<int> countT(26, 0);
        
        // 1. 統計兩字串中各字元的頻率
        for (size_t i = 0; i < s.size(); ++i) {
            countS[s[i] - 'a']++;
            countT[t[i] - 'a']++;
        }
        
        int ans = 0;
        
        // 2. 計算 t 中比 s 多出來的字元數總和
        for (int i = 0; i < 26; ++i) {
            if (countT[i] > countS[i]) {
                ans += (countT[i] - countS[i]);
            }
        }
        
        return ans;
    }
};
