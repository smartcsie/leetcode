/**
 * 題目：2529. Maximum Count of Positive Integer and Negative Integer
 * 難度：簡單 (Easy)
 * 描述：在已排序陣列中，計算正整數個數與負整數個數的最大值。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用 std::lower_bound 尋找邊界。
 * 2. `lower_bound(..., 0)` 找到第一個非負數的位置，該位置前的所有元素均為負數。
 * 3. `lower_bound(..., 1)` 找到第一個正數的位置，該位置後的所有元素均為正數。
 */

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // 1. 負數個數 = 第一個大於或等於 0 的位置索引
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        // 2. 正數個數 = 結尾減去第一個大於 0 的位置
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(neg, pos);
    }
};
