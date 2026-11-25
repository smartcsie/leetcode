/*
 * 題目：1025. Divisor Game
 * 難度：Easy
 * 描述：Alice 與 Bob 輪流玩遊戲，Alice 先手。黑板上有整數 n，輪到的人選一個 x，滿足 0 < x < n 且 n % x == 0，然後把 n 換成 n - x。無法行動的人輸。兩人都採最佳策略，回傳 Alice 是否會贏。
 * 分類主題：dp-game-theory
 * 技巧：必勝必敗狀態 DP, 取補集 (對手必敗則我必勝), 找到必勝走法即 break
 * 時間複雜度：O(n^2)
 * 空間複雜度：O(n)
 * 解法思路：
 *   1. dp[i] 表示輪到自己、黑板上是 i 時，自己能不能贏
 *   2. dp[1] = false：沒有合法的 x，直接輸
 *   3. 轉移：只要存在一個 x 使 i % x == 0 且 dp[i - x] 為 false（對手拿到 i - x 會輸），dp[i] 就為 true
 *   4. 由小到大填表，答案是 dp[n]
 *   5. 數學規律：偶數必勝（選 1 讓對手拿奇數），奇數必敗（奇數的因數都是奇數，只能讓對手拿到偶數），所以也可以直接回傳 n % 2 == 0，時間降為 O(1)
 */
class Solution {
public:
    bool divisorGame(int n) {
        // dp[i]：輪到自己、數字為 i 時，自己能不能贏（預設都先當作會輸，dp[1] 本來就是 false）
        vector<bool> dp(n + 1, false);
        for (int i = 2; i <= n; i++)
            for (int x = 1; x < i; x++)
                // x 是 i 的因數，且拿走 x 之後對手面對 i - x 會輸 → 自己這一步必勝
                if (i % x == 0 && !dp[i - x]) { dp[i] = true; break; }
        return dp[n];
    }
};