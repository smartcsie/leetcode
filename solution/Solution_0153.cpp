/**
 * 演算法：在旋轉排序陣列中尋找最小值 (Find Minimum in Rotated Sorted Array)
 * 時間複雜度：O(log N)，透過二分搜尋每次縮小一半的搜尋範圍。
 * 空間複雜度：O(1)，僅使用常數空間。
 * * 邏輯說明：
 * 1. 比較 nums[mid] 與 nums[right]：
 * - 若 nums[mid] > nums[right]：代表旋轉點在 mid 的右側，
 * 因此最小值必然位於 [mid + 1, right] 之間。
 * - 若 nums[mid] <= nums[right]：代表 mid 可能就是最小值，
 * 或是最小值位於 [left, mid] 之間，因此將 right 縮小至 mid。
 * 2. 迴圈終止條件 left == right 時，該位置即為陣列中的最小值。
 * * 注意：此解法假設陣列中無重複元素；若有重複元素，需額外處理 nums[mid] == nums[right] 的情況。
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) / 2);
            
            if (nums[mid] > nums[right]) {
                // mid 在左半邊較大的區塊，最小值一定在 mid 右邊
                left = mid + 1;
            } else {
                // mid 在右半邊較小的區塊，最小值可能是 mid 或在 mid 左邊
                right = mid;
            }
        }
        return nums[left];
    }
};
