/**
 * 題目：1930. Unique Length-3 Palindromic Subsequences
 * 難度：中等 (Medium)
 * 描述：計算字串中長度為 3 的相異回文子序列數量。
 * * 優化重點：
 * 1. 預處理：紀錄每個字元第一次與最後一次出現的位置。
 * 2. 夾心結構：回文結構為 "XYX"，只需固定兩端 X，並統計中間 Y 的種類數。
 */

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        // 預處理：紀錄每個字元出現的所有索引 (實際上只需首尾即可)
        std::vector<std::vector<int>> d(26);
        for (int i = 0; i < s.size(); i++) {
            d[s[i] - 'a'].push_back(i);
        }
        
        int res = 0;
        // 針對每一個可能的兩端字元 'a'~'z'
        for (int i = 0; i < 26; i++) {
            if (d[i].size() > 1) {
                int first = d[i].front();
                int last = d[i].back();
                
                // 檢查每一個中間字元 'a'~'z' 是否存在於 (first, last) 區間內
                for (int cc = 0; cc < 26; cc++) {
                    // 使用 upper_bound 查找是否存在索引落在 (first, last) 之間
                    auto it = std::upper_bound(d[cc].begin(), d[cc].end(), first);
                    if (it != d[cc].end() && *it < last) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
