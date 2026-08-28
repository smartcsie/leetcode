/**
 * 題目：1800. Maximum Ascending Subarray Sum (最大遞增子陣列和)
 * 難度：簡單 (Easy)
 * 描述：給定一個陣列，找出其中所有連續「遞增」子陣列元素和的最大值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 初始化 `sum` 為第一個元素，`curSum` 為第一個元素。
 * 2. 從索引 1 開始遍歷陣列：
 * - 若發現不再遞增 (`nums[i-1] >= nums[i]`)，將 `curSum` 重置為 0。
 * - 將當前元素加入 `curSum`。
 * - 更新歷史最大和 `sum = max(sum, curSum)`。
 */

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i - 1]) sum = 0;
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
