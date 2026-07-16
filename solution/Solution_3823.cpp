/**
 * 題目：3823. Reverse Letters Then Special Characters
 * 描述：將字串中的英文字母與特殊字元分別反轉，同時保持各自類型的相對位置。
 * 
 * 解法思路：
 * 1. 雙指標分段處理：
 *    - 第一輪：使用雙指標，若兩端皆為字母，則進行交換，達成字母類型的反轉。
 *    - 第二輪：使用同樣邏輯處理剩餘的特殊字元。
 * 2. 這種方法能有效維持 O(1) 的額外空間複雜度。
 */

class Solution {
public:
    std::string reverseByType(std::string s) {
        int n = s.size();
        
        // 階段一：反轉字母 (lowercase letters)
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !islower(s[left])) left++;
            while (left < right && !islower(s[right])) right--;
            if (left < right) {
                std::swap(s[left++], s[right--]);
            }
        }

        // 階段二：反轉非字母的特殊字元
        left = 0, right = n - 1;
        while (left < right) {
            while (left < right && islower(s[left])) left++;
            while (left < right && islower(s[right])) right--;
            if (left < right) {
                std::swap(s[left++], s[right--]);
            }
        }
        
        return s;
    }
};
