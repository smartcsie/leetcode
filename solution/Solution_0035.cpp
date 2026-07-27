/**
 * 題目：35. Search Insert Position (搜尋插入位置)
 * 難度：簡單 (Easy)
 * 描述：在排序陣列中尋找目標值，若不存在，回傳若插入該值後應維持有序的位置。
 * * 時間複雜度：O(log N) - 標準二分搜尋。
 * 空間複雜度：O(1) - 使用常數空間。
 * * 設計思路：
 * 利用 C++ 標準函式庫 `std::lower_bound`。
 * 該函數會找出陣列中第一個「大於或等於」target 的元素位置。
 * - 若目標存在：回傳該目標的位置。
 * - 若目標不存在：回傳目標應插入的位置。
 * 兩者結果皆符合題目要求。
 */

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        // lower_bound 會回傳第一個「大於或等於」target 的元素的迭代器
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        
        // 將迭代器轉為索引 (index)
        return static_cast<int>(it - nums.begin());
    }
};
