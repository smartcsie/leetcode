/**
 * 題目：698. Partition to K Equal Sum Subsets
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列 nums 和一個整數 k，判斷能不能把 nums 分成 k
 * 個非空子集合，讓每個子集合的元素總和都相等。
 *
 * 時間複雜度：O(2^N * N)
 * 空間複雜度：O(2^N)
 *
 * 解法思路：
 * （Bitmask DP，dp[mask] 記錄「用了 mask 這些數字」時，目前正在填的
 * 那個子集合，累積到多少（對 target 取餘數表示））：
 * 1. 先算總和 sum，如果 sum % k != 0，不可能平分，直接 false；
 *    target = sum / k 是每個子集合要湊到的目標值。
 * 2. dp[mask] 代表：用掉 mask 這些數字之後，「目前正在填的子集合」裡
 *    已經累積的和（對 target 取模）。取模的巧思：如果累積和剛好等於
 *    target，代表這個子集合湊滿了、可以開始填下一個子集合，這時候
 *    「目前子集合的累積和」重新歸零，用 % target 剛好自然表達這件事，
 *    不用額外判斷「換到下一個子集合」的邏輯。
 * 3. dp[0] = 0（還沒用任何數字，目前子集合累積和是 0）。狀態轉移：
 *    對每個已知可達的 mask，嘗試加入一個還沒用過的數字 i，只要加進去
 *    不超過 target，就能推出新狀態 dp[newMask]。
 * 4. 答案：dp[全部數字都用完的 mask] == 0，代表最後一個子集合也剛好
 *    湊滿 target（餘數是 0），k 個子集合全部達標。
 */
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        for (int x : nums) if (x > target) return false;

        int n = nums.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) continue;
                if (dp[mask] + nums[i] > target) continue;
                int newMask = mask | (1 << i);
                if (dp[newMask] == -1) {
                    dp[newMask] = (dp[mask] + nums[i]) % target;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};
