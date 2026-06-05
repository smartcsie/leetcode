/**
 * 題目：744. Find Smallest Letter Greater Than Target (尋找比目標字母大的最小字母)
 * 難度：簡單 (Easy)
 * 描述：在有序字元陣列中找第一個大於 target 的字元，若無則回傳陣列第一個字元。
 * * 時間複雜度：O(log N) - 二分搜尋法。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 當 `left` 越過最後一個元素時，代表沒有比 target 更大的元素，
 * 此時利用 `left % size` 即可環繞回陣列開頭。
 */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        size_t left = 0;
        size_t right = letters.size(); // 設定右邊界為 size，讓區間為左閉右開 [left, right)
        
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // 若 left == letters.size()，表示所有元素皆小於或等於 target，
        // 根據題目需求返回第一個元素。使用模運算優雅處理此情況。
        return letters[left % letters.size()];
    }
};
