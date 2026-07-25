/**
 * 題目：217. Contains Duplicate
 * 描述：給你一個整數陣列 nums。如果任一值在陣列中出現至少兩次，返回 true；如果陣列中每個元素互不相同，返回 false。
 * 
 * 解法思路（排序與相鄰比較法 Sorting & Adjacent Check）：
 * 1. 排序陣列：
 *    - 使用 C++20 的 `ranges::sort(nums)` 將整數陣列由小到大排序。排序後，所有相同的元素都會相鄰排列。
 * 2. 使用 std::unique 移除相鄰重複項：
 *    - `std::unique` 會將陣列中相鄰的重複元素移動到陣列的尾端，並回傳指向第一個「被移除的重複元素」的迭代器（即新邏輯結尾）。
 * 3. 判斷是否有重複：
 *    - 如果 `std::unique` 回傳的迭代器不等於 `nums.end()`，代表陣列中確實有重複的元素被過濾掉了，返回 `true`；否則返回 `false`。
 */

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // 步驟 1：對陣列進行排序，使相同元素相鄰
        std::ranges::sort(nums);
        //步驟 2：利用 std::unique 將相鄰重複元素移到後方
        // 步驟 3：若迭代器不等於 end()，代表有重複元素
        if (unique(nums.begin(), nums.end()) != nums.end()) return true;
        return false;
    }
};
