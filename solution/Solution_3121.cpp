/**
 * 題目：3121. Count the Number of Special Characters II
 * 難度：中等 (Medium)
 * 描述：計算滿足以下條件的字母個數：小寫字母至少出現一次，且所有小寫出現位置皆在所有大寫之前。
 * * 優化重點：
 * 1. 紀錄狀態：使用一個大小為 26 的 pair 陣列，儲存 `{大寫第一次出現索引, 小寫最後一次出現索引}`。
 * 2. 條件判斷：
 * - 大寫必須存在 (first != -1)
 * - 小寫必須存在 (second != -1)
 * - 必須滿足：最後一個小寫位置 < 第一個大寫位置。
 */

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        // pair.first 存大寫第一次出現的索引，pair.second 存小寫最後一次出現的索引
        std::vector<std::pair<int, int>> indices(26, {-1, -1});
        
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (std::isupper(c)) {
                // 若大寫尚未紀錄，則記錄其第一次出現位置
                if (indices[c - 'A'].first == -1) {
                    indices[c - 'A'].first = i;
                }
            } else if (std::islower(c)) {
                // 持續更新小寫最後一次出現的位置
                indices[c - 'a'].second = i;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            // 條件：大小寫皆存在，且小寫最後一次位置 < 大寫第一次位置
            if (indices[i].first != -1 && indices[i].second != -1 &&
                indices[i].second < indices[i].first) {
                count++;
            }
        }

        return count;
    }
};
