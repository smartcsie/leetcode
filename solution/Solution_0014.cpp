/**
 * 題目：14. Longest Common Prefix (最長共同前綴)
 * 難度：簡單 (Easy)
 * 描述：編寫一個函式來查找字串陣列中的最長共同前綴。如果不存在共同前綴，返回空字串 ""。
 *
 * 時間複雜度：O(S)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 垂直掃描法：
 * - 以第一個字串 strs[0] 為基準，逐一檢查它的第 i 個字元。
 * - 內部迴圈遍歷其餘所有字串 strs[j]。
 * 2. 停止條件：
 * - 當 i 等於某個字串的長度時 (i == strs[j].size())，說明該字串已到盡頭。
 * - 當某個字串的第 i 個字元與 strs[0][i] 不同時。
 * 3. 一旦觸發停止條件，直接利用 substr 截取 0 到 i-1 的部分並回傳。
 */

if(strs.empty()) return "";
        for(int chIdx = 0; chIdx < strs[0].size(); chIdx++) {
            for(int sIdx = 1; sIdx < strs.size(); sIdx++) {
                if(strs[0][chIdx] != strs[sIdx][chIdx] || chIdx == strs[sIdx].size()) return strs[0].substr(0, chIdx);
            }
        }
        return strs[0];