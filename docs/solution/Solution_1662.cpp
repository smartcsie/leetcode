/**
 * 題目：1662. Check If Two String Arrays are Equivalent (檢查兩個字串陣列是否相等)
 * 難度：簡單 (Easy)
 * 描述：檢查兩個字串陣列連接後是否組成相同的字串。
 * * 時間複雜度：O(N + M) - N 和 M 為兩個陣列中所有字元的總數。
 * 空間複雜度：O(1) - 僅使用指標變數，不建立新的字串。
 * * 解法思路：
 * 1. 使用四個指標分別追蹤兩個陣列目前的「字串索引 (wordIdx)」與「字元索引 (charIdx)」。
 * 2. 同步遍歷兩個陣列，若在任意位置字元不匹配則回傳 false。
 * 3. 若某字串已遍歷完，則跳轉到下一個字串並將字元指標歸零。
 * 4. 最後檢查是否兩個陣列都同時到達結尾。
 */

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int wordIdx1 = 0, wordIdx2 = 0;
        int charIdx1 = 0, charIdx2 = 0;

        // 當兩者都還有字串尚未處理完時，持續比較
        while (wordIdx1 < word1.size() && wordIdx2 < word2.size()) {
            // 比較當前字元
            if (word1[wordIdx1][charIdx1] != word2[wordIdx2][charIdx2]) {
                return false;
            }
            
            // 移動字元指標
            charIdx1++;
            charIdx2++;
            
            // 若第一個陣列的當前字串已讀完，切換至下一個字串
            if (charIdx1 == word1[wordIdx1].size()) {
                wordIdx1++;
                charIdx1 = 0;
            }
            
            // 若第二個陣列的當前字串已讀完，切換至下一個字串
            if (charIdx2 == word2[wordIdx2].size()) {
                wordIdx2++;
                charIdx2 = 0;
            }
        }
        
        // 確保兩個陣列同時讀取完畢 (避免一個長度較長的情況)
        return wordIdx1 == word1.size() && wordIdx2 == word2.size();
    }
};
