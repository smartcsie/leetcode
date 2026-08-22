/**
 * 題目：1406. Stone Game III
 * 難度：困難 (Hard)
 * 描述：給定一列石堆 stoneValue，兩個玩家輪流從陣列「最前面」拿 1、2
 * 或 3 堆（不是任一端，只能從頭開始拿），兩人都用最佳策略遊玩，求
 * Alice 贏、Bob 贏、還是平手。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （一維版本的 Minimax DP，因為只能從前面拿，不像 486/877 是雙端夾擊，
 * 狀態只需要一個維度）：
 * 1. dp[i] 代表「從索引 i 開始到結尾」這段範圍裡，目前玩家（先手）能
 *    拿到的分數 - 對手能拿到的分數，最大值是多少。跟 486 一樣是
 *    「分數差」的建模。
 * 2. 狀態轉移：目前玩家可以選擇拿 1、2、或 3 堆（k = 1, 2, 3，且不能
 *    超出陣列範圍）：
 *    dp[i] = max over k of (sum(stoneValue[i..i+k-1]) - dp[i+k])
 *    拿走這 k 堆的總和，扣掉「對手在剩下範圍裡的分數差」（角色互換，
 *    對手變成新子問題的先手）。
 * 3. base case：dp[n] = 0（沒有石頭可拿，分數差是 0）。
 * 4. 從後往前遞推，答案是 dp[0]：
 *    - dp[0] > 0：Alice（先手）獲勝
 *    - dp[0] < 0：Bob（後手）獲勝
 *    - dp[0] == 0：平手
 */
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int best = INT_MIN;
            int sum = 0;
            for (int k = 0; k < 3 && i + k < n; ++k) {
                sum += stoneValue[i + k];
                best = max(best, sum - dp[i + k + 1]);
            }
            dp[i] = best;
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};
