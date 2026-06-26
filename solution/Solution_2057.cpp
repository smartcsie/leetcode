/**
 * 題目：2057. Smallest Index With Equal Value (值等於索引餘數的最小索引)
 * 難度：簡單 (Easy)
 * 描述：回傳第一個滿足 nums[i] == i % 10 的索引，若無則回傳 -1。
 * * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

#include <vector>

class Solution {
public:
    int smallestEqual(const std::vector<int>& nums) {
        // 使用 size_t 避免在大陣列時可能出現的索引溢位問題
        for (size_t i = 0; i < nums.size(); ++i) {
            // 直接進行模運算判斷
            if (static_cast<int>(nums[i]) == (i % 10)) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
};
