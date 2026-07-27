/**
 * 題目：3011. Find if Array Can Be Sorted (找出陣列是否可排序)
 * 難度：中等 (Medium)
 * 描述：只有 set bits 數量相同的相鄰元素可以交換。判斷陣列是否能排序。
 * * 時間複雜度：O(N) - 每個節點僅被遍歷一次。
 * 空間複雜度：O(1) - 僅使用常數空間變數。
 * * 優化思路：
 * 1. 分組：根據 popcount 將連續數字分組。
 * 2. 檢查：相鄰兩組之間必須滿足 `prevGroupMax <= currentGroupMin`。
 */

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int preMax = 0; // 上一個分組的最大值
        int i = 0;
        int n = nums.size();

        while (i < n) {
            int currentGroupMax = nums[i];
            int currentGroupMin = nums[i];
            int bits = __builtin_popcount(nums[i]);
            
            // 找出當前 popcount 相同的所有連續數字
            while (i < n && __builtin_popcount(nums[i]) == bits) {
                currentGroupMax = std::max(currentGroupMax, nums[i]);
                currentGroupMin = std::min(currentGroupMin, nums[i]);
                i++;
            }

            // 檢查當前組的最小值是否小於上一組的最大值
            if (currentGroupMin < preMax) {
                return false;
            }

            // 更新 preMax 為當前組的最大值
            preMax = currentGroupMax;
        }

        return true;
    }
};
