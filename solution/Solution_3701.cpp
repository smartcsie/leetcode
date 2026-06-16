/**
 * 題目：3701. Compute Alternating Sum (計算交替和)
 * 難度：簡單 (Easy)
 * 描述：計算陣列的交替和：nums[0] - nums[1] + nums[2] - nums[3] + ...
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 簡化邏輯：移除特殊條件判斷，利用迴圈的統一性處理所有長度。
 * 2. 位元運算：使用 (i & 1) 代替 (i % 2) 進行奇偶判斷，效能更佳。
 */

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // 位元運算 (i & 1) 等同於 (i % 2 != 0)
            if (i & 1) {
                sum -= nums[i];
            } else {
                sum += nums[i];
            }
        }
        return sum;
    }
};
