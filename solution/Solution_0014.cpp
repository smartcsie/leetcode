/**
 * 題目：14. Longest Common Prefix (最長共同前綴)
 * 難度：簡單 (Easy)
 * 描述：編寫一個函式來查找字串陣列中的最長共同前綴。如果不存在共同前綴，返回空字串 ""。
 * 
 * 時間複雜度：O(S) - S 是所有字串中字元的總數。最壞情況下，我們會比較所有字元。
 * 空間複雜度：O(1) - 除了存儲結果外，只使用了常數個變數（不計 substr 產生的字串空間）。
 * 
 * 解法思路：
 * 1. 垂直掃描法：
 *    - 以第一個字串 strs[0] 為基準，逐一檢查它的第 i 個字元。
 *    - 內部迴圈遍歷其餘所有字串 strs[j]。
 * 2. 停止條件：
 *    - 當 i 等於某個字串的長度時 (i == strs[j].size())，說明該字串已到盡頭。
 *    - 當某個字串的第 i 個字元與 strs[0][i] 不同時。
 * 3. 一旦觸發停止條件，直接利用 substr 截取 0 到 i-1 的部分並回傳。
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // 以第一個字串為基準進行垂直掃描
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            
            // 檢查其餘字串的第 i 個位置
            for (int j = 1; j < strs.size(); j++) {
                // 修正：當 i 達到當前字串長度，或字元不匹配時
                if (i == strs[j].size() || strs[j][i] != c) {
                    // substr(起始索引, 長度) 
                    // 此時符合的前綴長度正好是 i (索引 0 到 i-1)
                    return strs[0].substr(0, i);
                }
            }
        }

        // 如果全部跑完都沒觸發 return，說明 strs[0] 本身就是最長前綴
        return strs[0];
    }
};
