/**
 * 題目：162. Find Peak Element (尋找峰值元素)
 * 難度：中等 (Medium)
 * 描述：峰值元素是指其值大於左右相鄰元素的元素。給定一個陣列，找出其中一個峰值。
 * * 時間複雜度：O(log N) - 二分搜尋，每次排除一半範圍。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 比較 `mid` 與 `mid + 1` 的值。如果 `nums[mid] < nums[mid + 1]`，
 * 說明右側一定存在一個峰值；反之，左側一定存在。
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        // 使用 left < right 的循環，當 left 與 right 重合時即為峰頂
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 如果當前處於遞增坡道，則峰頂在右側
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // 如果當前處於遞減坡道或位於頂部，則峰頂在左側（包含當前 m）
            else {
                right = mid;
            }
        }
        return left; // 或回傳 left，因為 left == right
    }
};
