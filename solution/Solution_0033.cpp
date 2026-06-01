/**
 * 題目：33. Search in Rotated Sorted Array (在旋轉排序陣列中搜尋)
 * 難度：中等 (Medium)
 * 描述：在一個原本有序但經過旋轉的陣列中，以 O(log N) 時間找出目標值的索引。
 * * 時間複雜度：O(log N) - 二分搜尋法。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 將陣列分為左右兩段，總有一段是有序的。檢查 target 是否落在該有序段內，即可決定下一步搜尋的方向。
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            
            // 判斷左半部是否為有序區間
            if (nums[mid] >= nums[left]) {
                // target 是否落在有序的左半部
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } 
            // 若左半部無序，則右半部必然有序
            else {
                // target 是否落在有序的右半部
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        
        return (nums[left] == target) ? left : -1;
    }
};
