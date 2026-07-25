/**
 * 題目：217. Contains Duplicate
 * 描述：給你一個整數陣列 nums。如果任一值在陣列中出現至少兩次，返回 true；如果陣列中每個元素互不相同，返回 false。
 * 
 * 解法思路（排序與相鄰掃描法 Sorting & Adjacent Scan）：
 * 1. 排序陣列：
 *    - 使用 C++20 的 `ranges::sort(nums)` 將整數陣列由小到大排序。排序完成後，任何相同的數字都會緊鄰排列在一起。
 * 2. 線性掃描檢查：
 *    - 從索引 1 開始迴圈遍歷整個陣列，檢查當前元素 `nums[i]` 是否等於它前一個元素 `nums[i - 1]`。
 *    - 一旦發現有相鄰元素相等，即代表存在重複，直接返回 `true`。
 * 3. 預設返回：
 *    - 若迴圈結束都沒有找到相等的相鄰元素，代表所有元素皆互不相同，返回 `false`。
 */

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // 步驟 1：對陣列進行排序，使相同元素聚集成相鄰對
        std::ranges::sort(nums);
        
        // 步驟 2：掃描相鄰元素，若有相同則代表重複
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        
        return false;
    }
};
