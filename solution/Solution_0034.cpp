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
        // 使用 lower_bound 分別定位起點與區間的開端
        auto it_l = lower_bound(nums.begin(), nums.end(), target);
        auto it_r = lower_bound(nums.begin(), nums.end(), target + 1);
        
        // 檢查是否存在：如果 it_l 指向陣列結尾，或者指向的值不是 target
        if (it_l == nums.end() || *it_l != target) {
            return {-1, -1};
        }
        
        // it_r 指向的是第一個大於 target 的元素，所以 r - 1 即為終點
        return {static_cast<int>(it_l - nums.begin()), static_cast<int>(it_r - nums.begin() - 1)};
    }
};
