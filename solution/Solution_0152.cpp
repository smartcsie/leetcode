/**
 * 題目：152. Maximum Product Subarray (乘積最大子陣列)
 * 難度：中等 (Medium)
 * 描述：找出乘積最大的連續子陣列。
 * * 時間複雜度：O(N) - 線性掃描。
 * 空間複雜度：O(1) - 僅儲存狀態變數。
 * * 優化思路：
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
        if (nums.empty()) return 0;
        
        int max_prod = nums[0];
        int min_prod = nums[0];
        int ans = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            int prev_max = max_prod;
            int prev_min = min_prod;
            
            // 使用 std::max/min 的 initializer_list 版本比較三個值
            max_prod = max({nums[i], prev_max * nums[i], prev_min * nums[i]});
            min_prod = min({nums[i], prev_max * nums[i], prev_min * nums[i]});
            
            ans = max(ans, max_prod);
        }
        
        return ans;
    }
};
