/**
 * 題目：1219. Path with Maximum Gold
 * 難度：中等 (Medium)
 * 描述：給定一個網格 grid，0 代表空格、正整數代表這格有多少金子。從
 * 任一格有金子的位置出發，上下左右移動（不能走到 0 的格子、也不能
 * 走出邊界、每格金子最多拿一次），求最多能拿到多少金子。
 *
 * 時間複雜度：O(4^(有金子的格數)
 * 回頭路」大幅縮小）
 * 空間複雜度：O(M × N)
 *
 * 解法思路：
 * （Grid 回溯，DFS 探路 + 原地標記走過 + 回溯復原，是這題跟其他
 * 「挑組合」型回溯不同的地方——這裡的狀態是「目前站在哪個座標」，
 * 而不是「選了哪些候選項目」）：
 * 1. dfs(r, c) 代表「從座標 (r,c) 出發，能拿到的最多金子」，先做邊界
 *    檢查：出界或這格是 0（沒金子或已經拿過），回傳 0。
 * 2. 拿走目前這格的金子（gold = grid[r][c]），並「原地標記」為 0，
 *    代表已經走過、不能再走回來（因為題目要求每格最多拿一次）。
 * 3. 往上下左右四個方向遞迴探索，取四個方向裡能拿到的最多金子 best。
 * 4. 回溯的關鍵：遞迴完之後要把 grid[r][c] 復原成原本的金子數
 *    （grid[r][c] = gold），因為同一個起點可能被「其他起點出發的路徑」
 *    重複經過，如果不復原，會誤判成「這格已經被永久拿走」。
 * 5. 外層對每個有金子的格子都當作起點跑一次 dfs，取全域最大值。
 */
class Solution {
    int m, n;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return 0;
        int gold = grid[r][c];
        grid[r][c] = 0;
        int best = 0;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        for (int d = 0; d < 4; ++d) {
            best = max(best, dfs(grid, r + dr[d], c + dc[d]));
        }
        grid[r][c] = gold;
        return gold + best;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int ans = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 0) {
                    ans = max(ans, dfs(grid, r, c));
                }
            }
        }
        return ans;
    }
};
