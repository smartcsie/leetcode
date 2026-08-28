/**
 * 題目：2942. Find Words Containing Character
 * 難度：簡單 (Easy)
 * 描述：返回所有包含指定字元 'x' 的字串索引。
 * 優化重點：
 * 1. 查找函數：使用 string::find 尋找字元，若找到則會返回該字元首次出現的位置。
 * 2. 邊界條件：透過 string::npos 檢查字元是否不存在。
 *
 * 時間複雜度：O(N*L)
 * 空間複雜度：O(1)
 */

#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
        vector<int> ans;
        ans.reserve(words.size());
        for(int i = 0; i < words.size(); i++) {
            for(const char& c : words[i]) {
                if(c == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
