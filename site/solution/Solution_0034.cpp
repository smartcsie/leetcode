/**
 * 題目：34. Find First and Last Position of Element in Sorted Array (在排序陣列中尋找元素的起點與終點)
 * 難度：中等 (Medium)
 * 描述：在遞增陣列中尋找 target 的開始索引與結束索引。
 * * 時間複雜度：O(log N) - 兩次二分搜尋。
 * 空間複雜度：O(1) - 未使用額外空間。
 * * 設計思路：
 * 1. 使用 `lower_bound` 找出第一個 >= target 的位置 (即起點)。
 * 2. 使用 `lower_bound` 找出第一個 >= target + 1 的位置 (即終點的下一個位置)。
 * 3. 透過比較兩個位置是否相同，判定 target 是否存在。
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        if(lower == nums.end() || *lower != target) return { -1, -1};
        auto upper = upper_bound(lower, nums.end(), target);
        return {static_cast<int>(lower - nums.begin()), static_cast<int>(upper - nums.begin() - 1)};
    }
};
