/**
 * 題目：213. House Robber II (打家劫舍 II)
 * 難度：中等 (Medium)
 * 描述：房屋排成圓圈，相鄰房屋不可同時搶劫。
 * * 時間複雜度：O(N) - 進行兩次線性掃描。
 * 空間複雜度：O(1) - 使用滾動變數更新狀態。
 * * 優化思路：
 * 1. 拆分問題：圓形問題轉化為兩個直線問題。
 * - case 1: 搶劫 0 到 n-2 號房 (排除最後一間)
 * - case 2: 搶劫 1 到 n-1 號房 (排除第一間)
 * 2. 狀態壓縮：利用 prev1 和 prev2 兩個變數實作 DP，節省空間。
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // 邊界條件處理
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // 分別計算兩種互斥情況取最大值
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

private:
    // 標準線性打家劫舍算法
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0; // i-2 的最大收益
        int prev1 = 0; // i-1 的最大收益
        
        for (int i = start; i <= end; ++i) {
            // 當前最大收益 = max(不搶當前房(prev1), 搶當前房+前兩間最大收益(prev2 + nums[i]))
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
