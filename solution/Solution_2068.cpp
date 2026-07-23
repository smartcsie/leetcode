/**
 * 題目：2068. Check Whether Two Strings are Almost Equivalent
 * 描述：如果兩個字串 word1 和 word2 中，從 'a' 到 'z' 的每一個英文字母
 *       在兩者中出現次數的絕對差值都小於或等於 3，則稱這兩個字串幾乎等價。
 *       若兩者幾乎等價請返回 true，否則返回 false。
 * 
 * 解法思路：
 * 1. 宣告一個大小為 26 的計數陣列 `counts`，初始值全為 0。
 * 2. 同步走訪兩個字串：
 *    - 對於 `word1` 出現的字元，對應的 `counts` 位置執行 `++`。
 *    - 對於 `word2` 出現的字元，對應的 `counts` 位置執行 `--`。
 *    - 這樣做可以讓相同字母的頻率在同一個陣列中互相抵銷，代表兩者數量的淨差值。
 * 3. 走訪完成後，檢查 26 個字母的計數絕對值（`std::abs`）：
 *    - 只要有任何一個字母的差值大於 3，立即回傳 `false`。
 * 4. 若全數檢查完畢皆小於或等於 3，則回傳 `true`。
 */

class Solution {
public:
    bool checkAlmostEquivalent(std::string word1, std::string word2) {
        std::vector<int> counts(26, 0);
        // 同步累加與累減字元頻率
        for (size_t i = 0; i < word1.size(); ++i) {
            counts[word1[i] - 'a']++;
            counts[word2[i] - 'a']--;
        }
        // 檢查每個字母的頻率絕對差是否超過 3
        for (int i = 0; i < 26; ++i) {
            if (std::abs(counts[i]) > 3) {
                return false;
            }
        }
        return true;
    }
};
