/**
 * 題目：2441. Largest Positive Integer That Exists With Its Negative (與對應負數同時存在的最大正整數)
 * 難度：簡單 (Easy)
 * 描述：找出陣列中最大的正整數 k，使得 k 與 -k 同時存在於陣列中。
 * 
 * 時間複雜度：O(n log n) - 主要耗時在於排序。
 * 空間複雜度：O(1) - 僅使用常數個變數（不計排序內部使用的棧空間）。
 * 
 * 解法思路：
 * 1. 先對陣列進行升序排序，這樣負數會集中在左側，正數集中在右側。
 * 2. 使用雙指標：左指標 left 從最小值開始，右指標 right 從最大值開始。
 * 3. 比較 -nums[left] 與 nums[right] 的大小：
 *    - 若相等：找到符合條件的最大正整數，直接回傳。
 *    - 若 -nums[left] 較大：說明左側負數的絕對值太大，left 往右移尋找較小的負數。
 *    - 若 nums[right] 較大：說明右側正數太大，沒有對應的負數，right 往左移尋找較小的正數。
 */

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() -1;
        while(left < right) {
            if(-nums[left] == nums[right] ) return nums[right];
            else if (-nums[left] > nums[right] ) left++;
            else right--;
        }
        return res;
    }
};
