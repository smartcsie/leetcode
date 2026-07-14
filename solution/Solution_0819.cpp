/**
 * 題目：819. Most Common Word
 * 難度：簡單 (Easy)
 * 描述：找出段落中未被禁用的最常用單詞。
 */

class Solution {
public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
        // 1. 將所有非字母字元轉為空白，並統一小寫
        std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(), [](unsigned char c) {
            return std::isalpha(c) ? std::tolower(c) : ' ';
        });
        
        // 2. 將禁用詞放入 Hash Set 以提升查詢速度
        std::unordered_set<std::string> bannedSet(banned.begin(), banned.end());
        std::unordered_map<std::string, int> counts;
        
        // 3. 利用 stringstream 切割單詞
        std::istringstream ss(paragraph);
        std::string word;
        std::string maxStr;
        int maxCount = 0;
        
        while (ss >> word) {
            if (!bannedSet.count(word)) {
                counts[word]++;
                // 在統計當下更新最大值，省去最後再一次遍歷 map
                if (counts[word] > maxCount) {
                    maxCount = counts[word];
                    maxStr = word;
                }
            }
        }
        
        return maxStr;
    }
};
