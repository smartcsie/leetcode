/**
 * 題目：486. Predict the Winner
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列 nums，兩個玩家輪流從陣列的任一端（頭或尾）
 * 拿走一個數字，加進自己的分數。兩人都用最佳策略遊玩，求先手玩家的
 * 分數是否 >= 後手玩家（先手玩家是否至少不會輸）。
 *
 * 時間複雜度：O(N²)
 * 空間複雜度：O(N²)
 *
 * 解法思路：
 * （Interval DP + Minimax，這題是這整個 pattern 的原型題）：
 * 1. dp[i][j] 不是直接記錄「誰的分數是多少」，而是記錄一個更聰明的量：
 *    「在 nums[i..j] 這段範圍裡，先手玩家能拿到的分數 - 後手玩家能
 *    拿到的分數」的最大值（分數差，而不是絕對分數）。這樣定義的好處是
 *    不用額外追蹤「現在輪到誰」，因為每個子問題裡「先手」永遠是指
 *    「目前正在選這個區間的那個人」。
 * 2. base case：dp[i][i] = nums[i]（只剩一個數字，直接拿走，分數差
 *    就是這個數字本身）。
 * 3. 狀態轉移：目前的玩家可以選擇拿左端 nums[i] 或右端 nums[j]：
 *    - 拿左端：自己得到 nums[i]，剩下 [i+1, j] 交給對手，對手在這個
 *      子區間裡的「分數差」是 dp[i+1][j]，但角色互換了（對手在子區間
 *      裡變成「先手」），所以對「我」來說變成扣分：
 *      nums[i] - dp[i+1][j]。
 *    - 拿右端：同理，nums[j] - dp[i][j-1]。
 *    - 兩個玩家都採最佳策略，所以取兩種選擇中「對自己最有利」（分數差
 *      最大）的那個：dp[i][j] = max(拿左端, 拿右端)。
 * 4. 答案：dp[0][n-1] >= 0 代表先手玩家的分數不會輸給後手玩家。
 * 5. 這個「分數差」的建模技巧是 Game Theory DP 的核心套路，877、1406
 *    都是用同樣的想法。
 */
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
