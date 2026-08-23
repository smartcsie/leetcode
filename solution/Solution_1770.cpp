/**
 * 題目：1770. Maximum Score From Performing Multiplication Operations
 * 難度：困難 (Hard)
 * 分類主題：greedy-selection-constraints
 * 描述：給定陣列 nums 和 multipliers，總共要做 m 次操作（m 是
 * multipliers 長度），第 i 次操作可以選 nums 目前剩下的最左邊或最
 * 右邊的元素，乘上 multipliers[i] 加進總分，並把選中的元素移除。
 * 求最大總分。
 *
 * 時間複雜度：O(M²)
 * 空間複雜度：O(M²)
 *
 * 解法思路：
 * （這題雖然清單分類在 Selection With Constraints，實際是區間型 DP，
 * 關鍵洞察是「狀態可以只用一個維度表示」）：
 * 1. 直覺上狀態要記錄「目前 nums 剩下的左右邊界」，但因為每次操作
 *    一定會讓 nums 少一個元素，做完第 i 次操作後，如果左邊總共取了
 *    left 個，右邊就一定取了 i - left 個——這代表**只要知道目前做了
 *    幾次操作 i、以及左邊取了幾個 left，就能唯一推算出右邊界**
 *    （right = n - 1 - (i - left)），不需要真的記錄兩個邊界。
 * 2. dp[i][left] 代表「第 i 次操作前，左邊已取 left 個」時，從這裡
 *    開始能拿到的最大總分。
 * 3. 狀態轉移：第 i 次操作，選最左邊（nums[left]）或最右邊
 *    （nums[right]），取兩者較大：
 *    dp[i][left] = max(multipliers[i]*nums[left] + dp[i+1][left+1],
 *                       multipliers[i]*nums[right] + dp[i+1][left])
 * 4. 從 i = m-1 往回推到 i = 0（後面的操作結果要先算出來），答案是
 *    dp[0][0]（一開始還沒做任何操作，左邊取了 0 個）。
 */
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for (int i = m - 1; i >= 0; --i) {
            for (int left = i; left >= 0; --left) {
                int right = n - 1 - (i - left);
                int takeLeft = multipliers[i] * nums[left] + dp[i + 1][left + 1];
                int takeRight = multipliers[i] * nums[right] + dp[i + 1][left];
                dp[i][left] = max(takeLeft, takeRight);
            }
        }
        return dp[0][0];
    }
};
