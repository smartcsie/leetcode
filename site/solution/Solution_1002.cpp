/**
 * 題目：1002. Find Common Characters (查找共用字元)
 * 難度：簡單 (Easy)
 * 
 * 時間複雜度：O(N * K) - N 為單字數量，K 為單字平均長度。
 * 空間複雜度：O(1) - 只需要常數空間 (26 個字母的計數陣列)。
 * 
 * 修正點：
 * 1. 內層迴圈的 i++ 改為 j++。
 * 2. 初始化 count 陣列為一個合理的較大值（或是用第一個單字初始化）。
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // 使用 101 因為題目給定單字長度上限為 100
        vector<int> min_freq(26, 101); 
        
        for (const string& word : words) {
            vector<int> curr_freq(26, 0);
            for (char c : word) {
                curr_freq[c - 'a']++;
            }
            
            // 更新每個字母在所有單字中出現的「最小頻率」
            for (int i = 0; i < 26; i++) {
                min_freq[i] = min(min_freq[i], curr_freq[i]);
            }
        }
        
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            // 這裡修正了原先的 i++ 錯誤，改為 j++
            for (int j = 0; j < min_freq[i]; j++) {
                // string(1, char) 會創建一個長度為 1 的字串
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};
