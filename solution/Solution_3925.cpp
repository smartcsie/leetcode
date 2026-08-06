/**
 * 題目：3925. Concatenate Array With Reverse
 * 難度：簡單 (Easy)
 * 描述：將原陣列 nums 與其反轉後的陣列進行連接。
 *
 * 時間複雜度：O(N) - 遍歷陣列兩次。
 * 空間複雜度：O(N) - 用於存放結果。
 *
 * 解法思路：
 * 1. 預配置記憶體 (reserve)：避免在 push_back 時發生多次記憶體搬移，提升效能。
 */

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2 * n);
        for(int i = 0; i < n; i++) {
            nums[i + n] = nums[n - 1- i];
        }
        return nums;
    }
};
