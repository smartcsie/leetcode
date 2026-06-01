/**
 * 題目：215. Kth Largest Element in an Array (陣列中的第 K 個最大元素)
 * 難度：中等 (Medium)
 * 描述：在無序陣列中找到第 K 大的元素。
 * * 時間複雜度：O(N) 平均情況。
 * 空間複雜度：O(1) 原地操作。
 * * 優化思路：
 * 使用 std::nth_element，它能在保證平均 O(N) 的時間複雜度下，將第 K 大的元素
 * 放置在正確位置，而不需要對整個陣列進行完全排序。
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nth_element 會將第 k 小的元素放到 nums.begin() + (n - k) 的位置
        // 我們要的是第 k 大，也就是排序後的倒數第 k 個，即索引 size - k
        auto target_iter = nums.begin() + nums.size() - k;
        std::nth_element(nums.begin(), target_iter, nums.end());
        return *target_iter;
    }
};
