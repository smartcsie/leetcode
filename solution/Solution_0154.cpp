/**
 * 題目：154. Find Minimum in Rotated Sorted Array II (搜尋旋轉排序陣列中的最小值 II)
 * 難度：困難 (Hard)
 * 描述：在包含重複元素的旋轉排序陣列中找出最小值。
 * * 時間複雜度：平均 O(log N)，最壞情況 O(N) (當大量重複元素出現時)。
 * 空間複雜度：O(1) - 原地搜尋。
 * * 設計思路：
 * 1. 若 `nums[mid] < nums[right]`：最小值必在左半區間（含 mid）。
 * 2. 若 `nums[mid] > nums[right]`：最小值必在右半區間（不含 mid）。
 * 3. 若 `nums[mid] == nums[right]`：無法判斷，將 `right--` 以避開一個潛在的重複值，確保最小值仍在區間內。
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[right]) {
                // 最小值在左側 (包含 mid)
                right = mid;
            } else if (nums[mid] > nums[right]) {
                // 最小值在右側 (不包含 mid)
                left = mid + 1;
            } else {
                // 當 nums[mid] == nums[right] 時，無法確認區間，
                // 只能安全地縮小右邊界
                right--;
            }
        }
        
        // 迴圈結束時 left == right，即為最小值
        return nums[left];
    }
};
