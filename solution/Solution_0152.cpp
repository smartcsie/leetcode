/**
 * 題目：152. Maximum Product Subarray (乘積最大子陣列)
 * 難度：中等 (Medium)
 * 描述：找出乘積最大的連續子陣列。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 由於負數的存在，乘積可能會在極大值與極小值之間跳躍。
 * 我們維護兩個變數：
 * 1. `max_prod`: 以當前位置結尾的最大乘積。
 * 2. `min_prod`: 以當前位置結尾的最小乘積。
 * 轉移方程：
 * new_max = max({nums[i], max_prod * nums[i], min_prod * nums[i]})
 * new_min = min({nums[i], max_prod * nums[i], min_prod * nums[i]})
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = nums[0];
        int mx = nums[0];
        int mn = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int pre_mx = x < 0 ? mn : mx;
            int pre_mn = x < 0 ? mx : mn;
            mx = max(x, x * pre_mx);
            mn = min(x, x * pre_mn);
            ans = max(ans, mx);
        }
        return ans;
    }
};
