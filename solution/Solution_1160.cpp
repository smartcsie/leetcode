/**
 * 題目：1160. Find Words That Can Be Formed by Characters
 * 難度：簡單 (Easy)
 * 描述：計算 words 中所有能被 chars 構成的單字長度總和。
 * 
 * 解法思路：
 * 1. 使用長度為 26 的陣列 `counts` 記錄 chars 中每個字母出現的次數。
 * 2. 對於每個單字 word，複製一份 `counts` (稱為 `temp`)。
 * 3. 遍歷單字中的每個字元：
 *    - 若 `temp` 對應的頻率變為負數，代表 chars 無法構成該單字，跳過。
 *    - 若成功走完單字，將該單字長度累加至結果。
 */

class Solution {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        std::vector<int> counts(26, 0);
        // 統計 chars 中每個字母的頻率
        for (const char& c : chars) {
            counts[c - 'a']++;
        }
        
        int ans = 0;
        for (const std::string& word : words) {
            std::vector<int> temp = counts;
            bool canForm = true;
            
            for (const char& c : word) {
                // 若減去後小於 0，代表該字母已耗盡
                if (--temp[c - 'a'] < 0) {
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                ans += word.size();
            }
        }
        return ans;
    }
};
