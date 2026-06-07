/**
 * 題目：151. Reverse Words in a String (反轉字串中的單字)
 * 難度：中等 (Medium)
 * 描述：將字串反轉順序，需移除多餘空格。
 * * 時間複雜度：O(N) - 遍歷字串進行拆解與拼接。
 * 空間複雜度：O(N) - 用於儲存單字陣列。
 * * 優化思路：
 * 1. 使用 stringstream 自動過濾多餘空格並提取單字。
 * 2. 使用 vector 儲存單字後，利用反向迭代器 (reverse_iterator) 拼接，減少迴圈中手動檢查空格的邏輯。
 */

#include <sstream>
#include <vector>
#include <string>

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        
        // 1. 自動處理連續空格並提取單字
        while (ss >> word) {
            words.push_back(word);
        }
        
        // 2. 使用反向迭代器進行拼接
        string res;
        for (auto it = words.rbegin(); it != words.rend(); ++it) {
            res += *it;
            // 若不是最後一個單字（即不是反向迭代器的最後一個），則補上空格
            if (it != words.rend() - 1) {
                res += " ";
            }
        }
        
        return res;
    }
};
