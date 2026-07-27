/**
 * 題目：3216. Lexicographically Smallest String After a Swap
 * 難度：簡單 (Easy)
 * 描述：在只能進行一次交換的前提下，交換相鄰且奇偶性相同的字元，使字串字典序最小。
 * * 時間複雜度：O(N) - N 為字串長度，至多掃描一次字串。
 * 空間複雜度：O(1) - 原地修改字串。
 * * 解法思路：
 * 1. 為了讓字典序最小，我們希望盡早將較小的字元移動到較前面的位置。
 * 2. 遍歷字串，檢查相鄰的兩個字元 s[i-1] 與 s[i]。
 * 3. 條件：
 *    - s[i-1] 與 s[i] 的奇偶性必須相同 (即 `s[i-1] % 2 == s[i] % 2`)。
 *    - s[i-1] > s[i] (即前一個字元比後一個大，交換後可變小)。
 * 4. 一旦找到第一個符合條件的 pair，執行 swap 並立即 break 結束任務。
 */


class Solution {
public:
    std::string getSmallestString(std::string s) {
        for (int i = 1; i < s.size(); i++) {
            // 檢查奇偶性是否相同：利用位元運算，(s[i-1] & 1) 等同於檢查最後一位是否為 1
            if ((s[i-1] & 1) == (s[i] & 1) && s[i-1] > s[i]) {
                std::swap(s[i], s[i-1]);
                break; // 題目要求僅能交換一次
            }
        }
        return s;
    }
};
