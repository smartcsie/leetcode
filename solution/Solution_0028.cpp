/**
 * 題目：28. Find the Index of the First Occurrence in a String (找出字串中第一個匹配項的索引)
 * 難度：簡單 (Easy)
 * 描述：在 haystack 中找出 needle 出現的第一個位置，若無則回傳 -1。
 * * 時間複雜度：O(N * M) - 其中 N 為 haystack 長度，M 為 needle 長度。
 * 空間複雜度：O(1)。
 * * 解法思路：
 * 1. 若 needle 長度大於 haystack，直接返回 -1。
 * 2. 遍歷 haystack 直到剩下的字元數小於 needle 長度為止。
 * 3. 針對每個起點 `i`，檢查後續 `needle.size()` 個字元是否完全匹配。
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hSize = haystack.size();
        int nSize = needle.size();
        
        // 邊界檢查
        if (nSize == 0) return 0;
        if (hSize < nSize) return -1;
        
        // 遍歷所有可能的起始位置
        for (int i = 0; i <= hSize - nSize; ++i) {
            int j = 0;
            // 檢查匹配
            while (j < nSize && haystack[i + j] == needle[j]) {
                j++;
            }
            // 若完全匹配，返回當前起始索引
            if (j == nSize) return i;
        }
        
        return -1;
    }
};
