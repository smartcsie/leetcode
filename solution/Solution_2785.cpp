/**
 * 題目：2785. Sort Vowels in a String (重排字串中的元音)
 * 難度：中等 (Medium)
 * 描述：將字串中的所有元音依據 ASCII 值排序，非元音位置保持不動。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 查找表：使用靜態 bool 陣列判斷元音，取代字串搜尋。
 * 2. 計數排序：直接統計元音 ASCII 頻率，免去顯式排序。
 */

class Solution {
public:
    string sortVowels(string s) {
        vector<int> counts(128,0);
        for(const char& c : s) {
            if((0x104111 >> ((c | 32) - 'a')) & 1) counts[c]++;
        }
        int idx = 0;
        for(char& c : s) {
            if((0x104111 >> ((c | 32) - 'a')) & 1) {
                while(idx < 128 && !counts[idx]) idx++;
                c = idx;
                counts[idx]--;
            }
        }
        return s;
    }
};