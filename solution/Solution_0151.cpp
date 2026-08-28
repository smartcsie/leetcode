/**
 * 題目：151. Reverse Words in a String (反轉字串中的單字)
 * 難度：中等 (Medium)
 * 描述：將字串反轉順序，需移除多餘空格。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用 stringstream 自動過濾多餘空格並提取單字。
 * 2. 使用 vector 儲存單字後，利用反向迭代器 (reverse_iterator) 拼接，減少迴圈中手動檢查空格的邏輯。
 */

#include <sstream>
#include <vector>
#include <string>

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        string ans;
        vector<string> words;
        while(iss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        for(const string word : words) {
            ans += word;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};
