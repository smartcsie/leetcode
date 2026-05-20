/**
 * 題目：35. Search Insert Position (搜尋插入位置)
 * 難度：簡單 (Easy)
 * 描述：給定一個排序陣列和一個目標值，在陣列中找到目標值並返回索引。
 *      如果目標值不存在於陣列中，返回它將會被按順序插入的位置。
 *      必須設計時間複雜度為 O(log n) 的演算法。
 * 
 * 時間複雜度：O(log n) - 使用二分搜尋法。
 * 空間複雜度：O(1) - 僅使用常數額外空間。
 * 
 * 解法思路：
 * 1. 設定左右邊界 left = 0, right = n - 1。
 * 2. 進入迴圈，計算中間索引 mid。
 * 3. 比較 nums[mid] 與 target：
 *    - 如果相等，直接返回 mid。
 *    - 如果 nums[mid] < target，目標在右半邊，更新 left = mid + 1。
 *    - 如果 nums[mid] > target，目標在左半邊，更新 right = mid - 1。
 * 4. 關鍵：如果迴圈結束仍未找到，left 指向的位置即為插入點。
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            // 使用 (right - left) / 2 避免 (left + right) 的整數溢位風險
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // 當迴圈結束時，left 剛好是第一個大於 target 的元素下標
        // 也就是 target 應該被插入的位置
        return left;
    }
};
