/**
 * 題目：2185. Counting Words With a Given Prefix
 * 描述：統計 words 陣列中有多少個字串以 pref 為前綴。
 * 
 * 解法思路：
 * 1. 遍歷 words 陣列中的每一個字串。
 * 2. 使用 string::find() 檢查 pref 是否出現在索引 0 的位置。
 * 3. 若符合條件，計數器 +1。
 */

class Solution {
public:
    int prefixCount(std::vector<std::string>& words, std::string pref) {
        int count = 0;
        for (const std::string& word : words) {
            // find 回傳 0 代表字串以 pref 開頭
            if (word.find(pref) == 0) {
                count++;
            }
        }
        return count;
    }
};
