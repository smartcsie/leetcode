/**
 * 題目：688. Knight Probability in Chessboard
 * 難度：中等 (Medium)
 * 描述：給定一個 n x n 的棋盤，騎士從 (row, column) 出發，總共走 k 步，
 * 每一步都從 8 種騎士走法中「隨機」選一種（就算會走出棋盤也照走，
 * 走出去就代表出局），求 k 步後騎士仍然停留在棋盤上的機率。
 *
 * 時間複雜度：O(K * N²)
 * 空間複雜度：O(N²)
 *
 * 解法思路：
 * （Probability DP，dp[r][c] 代表「目前這一步，騎士停在 (r,c) 的
 * 機率」，跟其他 DP 的差別是這裡傳遞的是機率值，不是計數或最優值）：
 * 1. 初始化：dp[row][column] = 1.0（一開始 100% 在起點），其他位置
 *    機率都是 0。
 * 2. 狀態轉移，走一步：對目前有機率的每個位置 (r,c)，把它的機率平均
 *    分給 8 個可能的騎士走法（每個方向機率 1/8），如果走到的新位置
 *    在棋盤內，就把這部分機率累加到新位置上；如果走出棋盤，這部分
 *    機率就直接消失（代表出局，不會再回來）。
 * 3. 重複這個轉移 k 次（模擬 k 步）。
 * 4. 走完 k 步後，答案是棋盤上所有位置的機率總和（因為每一步都可能
 *    出局，走出去的機率就不會再被算進棋盤內的總和裡，剩下的總和自然
 *    就是「還在棋盤上」的機率）。
 */
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> dirs = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1.0;
        for (int step = 0; step < k; ++step) {
            vector<vector<double>> next(n, vector<double>(n, 0));
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[r][c] == 0) continue;
                    for (auto& d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            next[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
            dp = next;
        }
        double ans = 0;
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                ans += dp[r][c];
        return ans;
    }
};
