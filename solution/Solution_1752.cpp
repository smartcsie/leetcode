/**
 * 題目：1752. Check if Array Is Sorted and Rotated (檢查陣列是否經排序和旋轉)
 * 難度：簡單 (Easy)
 * 描述：檢查陣列是否可以由一個遞增陣列旋轉得到。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(1) - 不使用額外空間。
 * * 優化思路：
 * 在一個排序且旋轉的陣列中，滿足 nums[i] > nums[(i + 1) % n] 的次數，
 * 正常情況下最多只能發生一次（即旋轉點）。
 */

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i < n; i++) {
            if(nums[i] > nums[(i+1) % n]) count++;
            if(count > 1) return false;
        }
        return true;
    }
};
