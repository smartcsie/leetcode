/**
 * 題目：3838. Weighted Word Mapping
 * 描述：根據每個字母對應的權重，計算單字總權重，並將其映射為特定字母。
 * 
 * 解法思路：
 * 1. 遍歷每個單字：對於單字中的每個字母，查詢 `weights` 陣列並累加數值。
 * 2. 映射邏輯：使用模運算 (sum % 26) 取得相對位置，並反向映射回字母 'a'-'z'。
 *    計算公式：`(26 - (sum % 26) - 1) + 'a'`
 * 3. 將計算出的字元串接至結果字串中。
 */

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(const string& word : words) {
            int sum = 0;
            for(const char& c : word) {
                sum += weights[c - 'a'];
            }
            char appendc = (26 - (sum % 26) - 1)+ 'a';
            ans.push_back(appendc);
        }
        return ans;
    }
};
