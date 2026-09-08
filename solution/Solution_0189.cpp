/**
 * 題目：189. Rotate Array
 * 難度：中等 (Medium)
 * 描述：將陣列向右旋轉 k 步。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （三次 Reverse）：
 * 1. 反轉整個陣列。
 * 2. 反轉前 k 個元素。
 * 3. 反轉剩餘元素。
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
