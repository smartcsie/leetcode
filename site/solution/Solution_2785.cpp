/**
 * 題目：2785. Sort Vowels in a String (重排字串中的元音)
 * 難度：中等 (Medium)
 * 描述：將字串中的所有元音依據 ASCII 值排序，非元音位置保持不動。
 * * 時間複雜度：O(N) - 遍歷兩次字串。
 * 空間複雜度：O(1) - 使用固定大小的陣列與查找表。
 * * 優化思路：
 * 1. 查找表：使用靜態 bool 陣列判斷元音，取代字串搜尋。
 * 2. 計數排序：直接統計元音 ASCII 頻率，免去顯式排序。
 */

class Solution {
private:
    string vowels = "AEIOUaeiou";
    bool isVowel(char c) {
        return vowels.find(c) != string::npos;
    }

public:
    string sortVowels(string s) {
        int count[128] = {0};
        for(const char& c : s) {
            if(isVowel(c)) {
                count[c]++;
            }
        }

        int v_idx = 0;
        for(char& c : s) {
            if(isVowel(c)) {
                while(count[vowels[v_idx]] == 0) v_idx++;
                c = vowels[v_idx];
                count[c]--;
            }
        }
        return s;
    }
};
