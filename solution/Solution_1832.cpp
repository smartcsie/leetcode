/**
 * 題目：1832. Check if the Sentence Is Pangram
 * 描述：全字母句（Pangram）指包含英語字母表中所有 26 個字母至少一次的句子。
 *       給你一個僅由小寫英文字母組成的字串 sentence，如果它是全字母句，請返回 true；否則返回 false。
 * 
 * 解法思路：
 * 1. 宣告一個大小為 26 的 `std::bitset<26>`，用來記錄 26 個小寫英文字母的出現狀態。
 * 2. 走訪字串中的每一個字元 `c`，透過 `c - 'a'` 計算其對應的索引位置，並用 `.set()` 將其設為 1。
 * 3. 走訪結束後，透過 `.count()` 檢查被設為 1 的位元總數是否剛好等於 26。
 * 4. 若等於 26 則代表 26 個字母全數到齊，回傳 true；否則回傳 false。
 */

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        std::bitset<26> pangram;   
        // 將出現過的字元對應 bit 設為 1
        for (const char& c : sentence) {
            pangram.set(c - 'a');
        }
        // 檢查是否 26 個位元全滿
        return pangram.count() == 26;
    }
};
