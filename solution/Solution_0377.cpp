/**
 * 題目：377. Combination Sum IV (組合總和 IV)
 * 難度：中等 (Medium)
 * 描述：找出 nums 中元素相加等於 target 的所有排列數（順序不同視為不同排列）。
 * * 時間複雜度：O(target * N) - N 為 nums 長度。
 * 空間複雜度：O(target) - 使用一維 DP 陣列存儲排列數。
 * * 優化思路：
 * 1. 排列計數模型：外層迴圈遍歷「金額 (1 到 target)」，內層遍歷「數字」，確保了順序差異。
 * 2. 狀態定義：dp[i] 表示組成金額 i 的所有排列總數。
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 使用 unsigned int 防止累加過程中的潛在溢位
        vector<unsigned int> dp(target + 1, 0);
        
        // 基礎情況：組成金額 0 的方法只有一種（不選數字）
        dp[0] = 1;
        
        // 外層遍歷金額，內層遍歷 nums，這樣會計算出所有順序的可能性
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                // 如果目前金額足以放下該數字
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return static_cast<int>(dp[target]);
    }
};
