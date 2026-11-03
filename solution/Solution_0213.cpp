/**
 * 題目：213. House Robber II (打家劫舍 II)
 * 難度：中等 (Medium)
 * 描述：房屋排成圓圈，相鄰房屋不可同時搶劫。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 拆分問題：圓形問題轉化為兩個直線問題。
 * - case 1: 搶劫 0 到 n-2 號房 (排除最後一間)
 * - case 2: 搶劫 1 到 n-1 號房 (排除第一間)
 * 2. 狀態壓縮：利用 prev1 和 prev2 兩個變數實作 DP，節省空間。
 */

class Solution {
    int robRange(vector<int>& nums, int start, int end) {
        int n0 = 0, n1 = 0, n2 = 0;
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
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};