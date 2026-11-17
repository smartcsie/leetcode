/**
 * 題目：1160. Find Words That Can Be Formed by Characters
 * 難度：簡單 (Easy)
 * 描述：計算 words 中所有能被 chars 構成的單字長度總和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用長度為 26 的陣列 `counts` 記錄 chars 中每個字母出現的次數。
 * 2. 對於每個單字 word，複製一份 `counts` (稱為 `temp`)。
 * 3. 遍歷單字中的每個字元：
 * - 若 `temp` 對應的頻率變為負數，代表 chars 無法構成該單字，跳過。
 * - 若成功走完單字，將該單字長度累加至結果。
 */

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        array<uint8_t, 26> countChars{};
        for(char c : chars) countChars[c - 'a']++;
        int ans= 0;
        for(const string& w : words) {
            array<uint8_t, 26> counts = countChars;
            bool form = true;
            for(char c : w) {
                if(counts[c - 'a'] == 0) {
                    form = false;
                    break;
                } else {
                    counts[c - 'a']--;
                }
            }
            if(form) ans += w.size();
        }
        return ans;
    }
};