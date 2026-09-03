/**
 * 題目：153. Find Minimum in Rotated Sorted Array
 * 難度：中等 (Medium)
 * 描述：給定一個已排序但經過旋轉的陣列，找出其中的最小值。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Binary Search，比較 mid 與 right）：
 * 1. 用 left < right 作為終止條件，迴圈結束時 left == right 即為最小值位置。
 * 2. 每次取 mid，比較 nums[mid] 和 nums[right]：
 *    - nums[mid] > nums[right]：最小值在右半段（不含 mid），left = mid + 1。
 *    - nums[mid] <= nums[right]：最小值在左半段（含 mid），right = mid。
 * 3. 為何比較 right 而非 left？
 *    因為旋轉點一定在右半段某處，nums[right] 永遠是右半段的參考基準，
 *    而 nums[left] 可能剛好是最小值，直接排除會漏掉答案。
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};
