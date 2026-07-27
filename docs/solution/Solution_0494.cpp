/**
 * 題目：494. Target Sum (目標和)
 * 難度：中等 (Medium)
 * 描述：透過在數字前加上 '+' 或 '-'，使總和等於 target。
 * * 時間複雜度：O(N * S) - N 為陣列長度，S 為目標子集和。
 * 空間複雜度：O(S) - 使用一維 DP 陣列儲存組合數量。
 * * 優化思路：
 * 1. 模型轉換：設正數和為 P，負數和絕對值為 N。
 * P - N = target, P + N = sum => 2P = sum + target => P = (sum + target) / 2。
 * 問題轉化為：在 nums 中選取元素，使總和為 P 的組合數。
 * 2. 動態規劃：dp[j] 表示湊出總和 j 的方法數。
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // 邊界條件：目標不可能達成
        if (abs(target) > sum || (sum + target) % 2 != 0) return 0;
        
        int p = (sum + target) / 2;
        
        // dp[j] 表示湊出總和為 j 的組合數
        vector<int> dp(p + 1, 0);
        dp[0] = 1; // 基礎條件：總和為 0 的方法只有一種（什麼都不選）
        
        for (int num : nums) {
            // 倒序遍歷，確保每個 num 只使用一次 (0/1 背包)
            for (int j = p; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[p];
    }
};
