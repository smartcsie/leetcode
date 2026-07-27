/**
 * 題目：3813. Vowel-Consonant Score
 * 難度：簡單 (Easy)
 * 描述：統計母音與子音數量，計算 vowelCount / conCount (整數除法)。
 * * 優化重點：
 * 1. 查找優化：使用 string_view 進行快速匹配，避免額外的記憶體配置。
 * 2. 防禦性程式設計：處理分母為零的情況，避免除以零錯誤。
 * 時間複雜度：O(N) - 單次遍歷，母音得 (n-i) 分，子音得 (i+1) 分。
 * 空間複雜度：O(1) - 僅使用常數空間。

 */

class Solution {
private:
    bool isVowel(char c) {
        // 使用 string_view 提升查找常數時間效率
        static constexpr std::string_view vowels = "aeiouAEIOU";
        return vowels.find(c) != std::string_view::npos;
    }

public:
    int vowelConsonantScore(std::string s) {
        int vowelCount = 0;
        int conCount = 0;
        
        for (char c : s) {
            // 確保只處理英文字母
            if (std::isalpha(c)) {
                if (isVowel(c)) {
                    vowelCount++;
                } else {
                    conCount++;
                }
            }
        }
        
        // 檢查分母以防止 Runtime Error (除以零)
        return (conCount == 0) ? 0 : (vowelCount / conCount);
    }
};
