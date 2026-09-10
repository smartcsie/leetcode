/**
 * 題目：416. Partition Equal Subset Sum
 * 難度：中等 (Medium)
 * 描述：判斷是否能將陣列分成兩個子集，使兩子集的和相等。
 *
 * 時間複雜度：O(N*S)
 * 空間複雜度：O(S)
 *
 * 解法思路：
 * （0/1 背包，轉換為子集和問題）：
 * 1. 若總和為奇數，無法平分，直接回傳 false。
 * 2. 問題轉換：能否從 nums 中選出一些數，使其和恰好等於 sum/2（target）。
 * 3. dp[j] 代表能否從已處理的數字中湊出 j。
 * 4. 狀態轉移：
 *    - 不選 num：dp[j] 維持原值
 *    - 選 num：dp[j] = dp[j - num]
 *    - 取 OR：dp[j] = dp[j] || dp[j - num]
 * 5. 內層從大到小，確保每個 num 只使用一次（0/1 背包）。
 * 6. dp[0] = true 為基底，代表不選任何數湊出 0 是可行的。
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (const int& num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};