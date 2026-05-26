/**
 * 題目：1800. Maximum Ascending Subarray Sum (最大遞增子陣列和)
 * 難度：簡單 (Easy)
 * 描述：給定一個陣列，找出其中所有連續「遞增」子陣列元素和的最大值。
 * * 時間複雜度：O(N) - 僅需遍歷陣列一次。
 * 空間複雜度：O(1) - 使用常數空間維護計數變數。
 * * 解法思路：
 * 1. 初始化 `sum` 為第一個元素，`curSum` 為第一個元素。
 * 2. 從索引 1 開始遍歷陣列：
 * - 若發現不再遞增 (`nums[i-1] >= nums[i]`)，將 `curSum` 重置為 0。
 * - 將當前元素加入 `curSum`。
 * - 更新歷史最大和 `sum = max(sum, curSum)`。
 */

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // 若陣列為空，雖題目限制至少有1個，但仍可進行安全檢查
        if (nums.empty()) return 0;
        
        int sum = nums[0];
        int curSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // 若當前元素不大於前一個，遞增序列中斷，重置當前和
            if (nums[i] <= nums[i-1]) {
                curSum = 0;
            }
            
            // 累加當前元素
            curSum += nums[i];
            
            // 更新歷史最大值
            sum = max(sum, curSum);
        }
        
        return sum;
    }
};
