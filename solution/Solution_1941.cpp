
/**
 * 題目：1941. Check if All Characters Have Equal Number of Occurrences (檢查所有字元出現次數是否相等)
 * 難度：簡單 (Easy)
 * 描述：給你一個字串 s，如果 s 中所有出現過的字元，其出現次數都相同，則回傳 true；否則回傳 false。
 * 
 * 時間複雜度：O(n) - 其中 n 是字串 s 的長度。需要遍歷一次字串進行統計。
 * 空間複雜度：O(1) - 使用了固定大小為 26 的陣列（對應英文字母 a-z），不隨輸入長度增加。
 * 
 * 解法思路：
 * 1. 建立一個長度為 26 的整數陣列 count，用來儲存每個小寫字母出現的頻率。
 * 2. 遍歷字串 s，將每個字元對應的索引（c - 'a'）加 1。
 * 3. 取得字串中第一個字元出現的次數作為基準頻率 (freq)。
 * 4. 遍歷 count 陣列，對於任何出現次數大於 0 的字母，檢查其頻率是否等於 freq。
 * 5. 若發現不相等的頻率，則立即回傳 false；若全部檢查完畢皆符合，則回傳 true。
 */

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int count[26] = {0};
        for(char c : s) {
            count[c-'a']++;
        }
        int freq =   count[s[0]-'a'];
        for(int i = 0; i < 26 ; i++ ) {
            if(count[i] > 0 &&　count[i] != freq) {
                return false;
            }
        }
        return true;

    }
};
