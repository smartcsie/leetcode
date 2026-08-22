/**
 * 題目：980. Unique Paths III
 * 難度：困難 (Hard)
 * 描述：給定一個網格 grid，1 是起點、2 是終點、0 是可通行的空格、-1
 * 是障礙物。求從起點走到終點、且「每個非障礙格都要恰好走過一次」的
 * 路徑總共有幾條（上下左右移動）。
 *
 * 時間複雜度：O(4^(可走格數))
 * 空間複雜度：O(M*N)（遞迴深度）
 *
 * 解法思路：
 * （Grid 回溯，跟 1219 一樣是「DFS 探路 + 標記走過 + 回溯復原」的
 * 框架，但這題不是求最大值，而是「計數」符合條件的完整路徑數，多了
 * 一個「必須走過所有格子」的硬性限制）：
 * 1. 先掃描整個網格，找到起點座標，並統計「總共有幾格是可以走的」
 *    （walkable，包含起點、終點、空格，不含障礙物）。
 * 2. dfs(r, c, remaining) 代表「目前站在 (r,c)，還剩 remaining 格
 *    沒走過」：
 *    - 邊界/障礙檢查：出界或撞到障礙物（-1，包含走過的格子，因為走過
 *      的格子會被暫時標記成 -1），直接返回。
 *    - 如果走到終點（grid[r][c] == 2）：只有當 remaining == 0（代表
 *      所有其他格子都剛好走完）才算一條合法路徑，result++。
 * 3. 一般格子的處理：先把目前格子標記成 -1（代表「暫時視為障礙物」，
 *    防止之後走回頭路），往四個方向遞迴（remaining 傳入時要 -1），
 *    遞迴結束後要恢復原本的值（回溯），因為同一格會在「不同分支的
 *    路徑」中被重複經過，不能永久標記。
 * 4. 從起點出發，remaining 初始值是 walkable - 1（扣掉起點自己）。
 */
class Solution {
    int m, n, result;

    void dfs(vector<vector<int>>& grid, int r, int c, int remaining) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1) return;
        if (grid[r][c] == 2) {
            if (remaining == 0) result++;
            return;
        }
        int backup = grid[r][c];
        grid[r][c] = -1;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        for (int d = 0; d < 4; ++d) {
            dfs(grid, r + dr[d], c + dc[d], remaining - 1);
        }
        grid[r][c] = backup;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        result = 0;
        int startR = 0, startC = 0, walkable = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) { startR = r; startC = c; }
                if (grid[r][c] != -1) walkable++;
            }
        }
        dfs(grid, startR, startC, walkable - 1);
        return result;
    }
};
