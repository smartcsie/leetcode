/**
 * 題目：198. House Robber (打家劫舍)
 * 難度：中等 (Medium)
 * 描述：搶劫不能搶相鄰的房屋，求能搶到的最大金額。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 空間優化：將原本 O(N) 的 dp 陣列壓縮為兩個整數 `prev2` 和 `prev1`。
 * 2. 狀態轉移：`current = max(prev1, prev2 + nums[i])`。
 */

class Solution {
private:
    int robRange(vector<int>& nums, int start, int end) {
        int n0 = 0, n1= 0, n2 = 0;
        for(int i = start; i <= end; i++) {
            n2 = max(n1, n0 + nums[i]);
            n0 = n1;
            n1 = n2;
        }
        return n2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return robRange(nums, 0 , n - 1);
    }
};