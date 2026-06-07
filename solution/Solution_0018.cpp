/**
 * 題目：18. 4Sum (四數之和)
 * 難度：中等 (Medium)
 * 描述：在陣列中找出所有四元組 [nums[a], nums[b], nums[c], nums[d]]，使得總和為 target。
 * * 時間複雜度：O(N^3) - 外層兩層迴圈加上內層雙指標。
 * 空間複雜度：O(1) - 不含結果儲存空間。
 * * 優化思路：
 * 1. 排序：方便使用雙指標及跳過重複值。
 * 2. 剪枝 (Pruning)：當前最小值大於目標時、最大值小於目標時，直接跳過迴圈，大幅提升效能。
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // 去重
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++; right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
