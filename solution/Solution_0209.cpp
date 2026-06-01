/**
 * 題目：209. Minimum Size Subarray Sum (長度最小的子陣列)
 * 難度：中等 (Medium)
 * 描述：在陣列中找出總和大於等於 target 的最小長度子陣列。
 * * 時間複雜度：O(N) - 每個元素最多被 right 指標訪問一次，被 left 指標訪問一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 使用滑動視窗 (right 為右擴張，left 為左收縮)。
 * 2. 累加 sum，一旦 sum >= target，嘗試更新最小長度並向右移動 left 縮小視窗。
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_length = INT_MAX;
        int current_sum = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            
            // 當前視窗滿足條件，嘗試縮小視窗以找到最小值
            while (current_sum >= target) {
                min_length = min(min_length, right - left + 1);
                
                // 收縮左側邊界，直到不滿足條件為止
                current_sum -= nums[left++];
            }
        }
        
        return (min_length == INT_MAX) ? 0 : min_length;
    }
};
