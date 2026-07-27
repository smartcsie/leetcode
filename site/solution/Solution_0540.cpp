/**
 * 題目：540. Single Element in a Sorted Array (有序陣列中的單一元素)
 * 難度：中等 (Medium)
 * 描述：在一個已排序的陣列中，除了一個元素外，其他元素均出現兩次，找出該元素。
 * * 時間複雜度：O(log N) - 二分搜尋法。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 利用陣列已排序特性：在單一元素出現前，成對的元素滿足 (even, odd) 下標關係。
 * 2. 透過二分搜尋判斷中間元素的奇偶特性，縮小搜尋範圍。
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid ^ 1] == nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
