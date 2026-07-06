/**
 * 題目：2942. Find Words Containing Character
 * 難度：簡單 (Easy)
 * 描述：返回所有包含指定字元 'x' 的字串索引。
 * * 優化重點：
 * 1. 查找函數：使用 string::find 尋找字元，若找到則會返回該字元首次出現的位置。
 * 2. 邊界條件：透過 string::npos 檢查字元是否不存在。
 */

#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
        std::vector<int> res;
        
        // 預留空間以減少 vector 動態調整造成的效能損耗
        res.reserve(words.size());
        
        for (int i = 0; i < words.size(); ++i) {
            // find() 返回字元位置，若沒找到則返回 string::npos
            if (words[i].find(x) != std::string::npos) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
