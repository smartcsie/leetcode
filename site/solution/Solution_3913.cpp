/**
 * 題目：Sort Vowels by Frequency (依照頻率排序母音)
 * 難度：中等 (Medium)
 * 描述：根據母音在字串中出現的頻率進行排序（高頻優先，同頻率維持原序）。
 * * 時間複雜度：O(N log N) - 母音排序開銷。
 * 空間複雜度：O(N) - 儲存母音清單的空間。
 */

class Solution {
private:
    // 優化：支援大小寫母音判斷
    bool isVowel(char c) {
        c = std::tolower(static_cast<unsigned char>(c));
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        unordered_map<char, int> counts;
        vector<char> vowels; // 維持原順序的母音清單
        for (char c : s) {
            if (isVowel(c)) {
                counts[c]++;
                vowels.push_back(c);
            }
        }
        // 使用 stable_sort 排序：頻率高者在前
        // 若頻率相同，stable_sort 會自動保留 vowels 中的原始相對順序
        std::stable_sort(vowels.begin(), vowels.end(), [&](char a, char b) {
            return counts[a] > counts[b]; 
        });
        // 將排序後的母音填回原字串
        int idx = 0;
        for (char& c : s) {
            if (isVowel(c)) {
                c = vowels[idx++];
            }
        }
        return s;
    }
};
