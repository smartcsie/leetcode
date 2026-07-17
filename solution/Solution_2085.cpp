/**
 * 題目：2085. Count Common Words With One Occurrence
 * 描述：計算在 words1 與 words2 中，皆「恰好出現一次」的單字數量。
 * 
 * 解法思路 (位元遮罩法)：
 * 1. 使用 unordered_map<string, int> 記錄單字狀態：
 *    - IN_W1 (1): 單字在 words1 出現過。
 *    - IN_W2 (2): 單字在 words2 出現過。
 *    - DUPLICATED (4): 單字在同一個陣列內重複出現 (或跨陣列累加後出現多次)。
 * 2. 遍歷兩個陣列，若單字再次出現，則使用 OR 運算將該單字的標記設為 DUPLICATED。
 * 3. 最後只需檢查 map 中滿足 mask == (IN_W1 | IN_W2) (即值為 3) 的單字個數。
 */

class Solution {
public:
    int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        // 使用位元來標記狀態
        constexpr int IN_W1 = 1, IN_W2 = 2, DUPLICATED = 4;
        std::unordered_map<std::string, int> map;
        
        // 處理 words1
        for (const std::string& word : words1) {
            if (!(map[word] & IN_W1)) map[word] |= IN_W1;
            else map[word] |= DUPLICATED;
        }
        
        // 處理 words2
        for (const std::string& word : words2) {
            if (!(map[word] & IN_W2)) map[word] |= IN_W2;
            else map[word] |= DUPLICATED;
        }
        
        int ans = 0;
        // 檢查最終狀態：必須剛好只在 w1 出現過一次，且剛好只在 w2 出現過一次
        for (const auto& [s, mask] : map) {
            if (mask == (IN_W1 | IN_W2)) ans++;
        }
        
        return ans;
    }
};
