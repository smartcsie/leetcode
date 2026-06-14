/**
 * 題目：198. House Robber (打家劫舍)
 * 難度：中等 (Medium)
 * 描述：搶劫不能搶相鄰的房屋，求能搶到的最大金額。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(1) - 僅使用兩個變數記錄狀態。
 * * 優化思路：
 * 1. 空間優化：將原本 O(N) 的 dp 陣列壓縮為兩個整數 `prev2` 和 `prev1`。
 * 2. 狀態轉移：`current = max(prev1, prev2 + nums[i])`。
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // prev2 代表 dp[i-2], prev1 代表 dp[i-1]
        int prev2 = 0;
        int prev1 = nums[0];
        
        for (int i = 1; i < n; i++) {
            // dp[i] = max(dp[i-1], dp[i-2] + nums[i])
            int current = max(prev1, prev2 + nums[i]);
            
            // 更新狀態準備下一輪
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};
