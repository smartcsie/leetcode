/**
 * 題目：215. Kth Largest Element in an Array (陣列中的第 K 個最大元素)
 * 難度：中等 (Medium)
 * 描述：在無序陣列中找到第 K 大的元素。
 *
 * 時間複雜度：O(N) 平均情況。
 * 空間複雜度：O(1) 原地操作。
 *
 * 解法思路：
 * 使用 std::nth_element，它能在保證平均 O(N) 的時間複雜度下，將第 K 大的元素
 * 放置在正確位置，而不需要對整個陣列進行完全排序。
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto it = nums.end() - k;
        nth_element(nums.begin(), it, nums.end());
        return *it;
    }
};
