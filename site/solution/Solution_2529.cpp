/**
 * 題目：2529. Maximum Count of Positive Integer and Negative Integer
 * 難度：簡單 (Easy)
 * 描述：在已排序陣列中，計算正整數個數與負整數個數的最大值。
 * * 時間複雜度：O(log N) - 兩次二分搜尋。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 使用 std::lower_bound 尋找邊界。
 * 2. `lower_bound(..., 0)` 找到第一個非負數的位置，該位置前的所有元素均為負數。
 * 3. `lower_bound(..., 1)` 找到第一個正數的位置，該位置後的所有元素均為正數。
 */

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // pos_start: 第一個大於等於 0 的位置
        auto pos_start = lower_bound(nums.begin(), nums.end(), 0);
        // neg_count: 負數個數 (即 pos_start 之前的所有元素)
        int neg_count = distance(nums.begin(), pos_start);
        
        // pos_end: 第一個大於等於 1 的位置 (即正數的起點)
        auto pos_end = lower_bound(pos_start, nums.end(), 1);
        // pos_count: 正數個數 (即從 pos_end 到結尾的所有元素)
        int pos_count = distance(pos_end, nums.end());
        
        return max(neg_count, pos_count);
    }
};
