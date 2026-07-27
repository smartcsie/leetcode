/**
 * 題目：1768. Merge Strings Alternately (交替合併字串)
 * 難度：簡單 (Easy)
 * 描述：交替合併 word1 和 word2，若某字串較長，則將剩餘部分接在後面。
 * * 時間複雜度：O(N + M) - N 與 M 分別為兩字串長度。
 * 空間複雜度：O(1) - 不計算回傳所需的結果字串空間。
 */

#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        // 優化：預先配置長度，避免執行過程中進行多次記憶體擴充
        res.reserve(word1.size() + word2.size());
        int i = 0, n1 = word1.size(), n2 = word2.size();
        // 遍歷直到兩者皆處理完畢
        while (i < n1 || i < n2) {
            if (i < n1) res.push_back(word1[i]);
            if (i < n2) res.push_back(word2[i]);
            i++;
        }
        
        return res;
    }
};
