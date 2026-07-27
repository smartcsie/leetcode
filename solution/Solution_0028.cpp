/**
 * 題目：28. Find the Index of the First Occurrence in a String (找出字串中第一個匹配項的索引)
 * 難度：中等 (Medium)
 * 描述：在 haystack 中尋找 needle 第一次出現的位置。
 * * 時間複雜度：O(N + M)，N 為 haystack 長度，M 為 needle 長度。
 * 空間複雜度：O(M)，用於存放 next 陣列。
 */

#include <vector>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;

        // 建立 LPS (Longest Prefix Suffix) 陣列
        // next[i] 代表 needle[0...i] 最長相同前後綴的長度
        std::vector<int> next(m, 0);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) 
                j = next[j - 1];
            if (needle[i] == needle[j]) 
                j++;
            next[i] = j;
        }

        // 進行匹配
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) 
                j = next[j - 1];
            if (haystack[i] == needle[j]) 
                j++;
            if (j == m) 
                return i - m + 1;
        }
        
        return -1;
    }
};
