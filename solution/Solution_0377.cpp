/**
 * 題目：377. Combination Sum IV (組合總和 IV)
 * 難度：中等 (Medium)
 * 描述：找出 nums 中元素相加等於 target 的所有排列數（順序不同視為不同排列）。
 *
 * 時間複雜度：O(TARGET*N)
 * 空間複雜度：O(TARGET)
 *
 * 解法思路：
 * 1. 排列計數模型：外層迴圈遍歷「金額 (1 到 target)」，內層遍歷「數字」，確保了順序差異。
 * 2. 狀態定義：dp[i] 表示組成金額 i 的所有排列總數。
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(const int& num : nums) {
                if(i >= num) dp[i] += dp[i - num];
            }
        }
        return static_cast<int>(dp[target]);
    }
};
