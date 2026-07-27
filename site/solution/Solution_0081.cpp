/**
 * 題目：81. Search in Rotated Sorted Array II (搜尋旋轉排序陣列 II)
 * 難度：中等 (Medium)
 * 描述：在包含重複元素的旋轉排序陣列中搜尋目標值。
 * * 時間複雜度：平均 O(log N)，最壞情況 O(N) (當大量重複元素導致無法判斷區間時)。
 * 空間複雜度：O(1) - 原地搜尋。
 * * 優化思路：
 * 當 `nums[left] == nums[mid]` 時，我們無法得知左半部或右半部哪邊是有序的。
 * 此時最安全的做法是執行 `left++`，將邊界縮小，直到能判定有序區間為止。
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return true;
            
            // 情況 1：左半區間有序
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // 情況 2：右半區間有序
            else if (nums[left] > nums[mid]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } 
            // 情況 3：無法確定哪邊有序 (遇到重複元素)
            else {
                left++;
            }
        }
        
        return false;
    }
};
