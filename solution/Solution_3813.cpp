/**
 * 題目：3813. Vowel-Consonant Score
 * 難度：簡單 (Easy)
 * 描述：統計母音與子音數量，計算 vowelCount / conCount (整數除法)。
 * 優化重點：
 * 1. 查找優化：使用 string_view 進行快速匹配，避免額外的記憶體配置。
 * 2. 防禦性程式設計：處理分母為零的情況，避免除以零錯誤。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int vowelConsonantScore(std::string s) {
        int vowels = 0;
        int consonant = 0;
        for(const char& c : s) {
            if(isalpha(c)) {
                if((0x104111 >> (c - 'a')) & 1) vowels++;
                else consonant++;
            }
        }
        return consonant == 0 ? 0 : vowels / consonant;
    }
};
