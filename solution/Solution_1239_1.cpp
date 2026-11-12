/**
 * 題目：2397. Maximum Rows Covered by Columns
 * 難度：Medium
 * 描述：給定 m x n 的 0/1 矩陣 matrix 與整數 numSelect。
 *       從中選出恰好 numSelect 欄，若某一列所有為 1 的格子所在的欄都被選中，
 *       該列就算「被覆蓋」（全為 0 的列一定被覆蓋）。
 *       回傳最多能覆蓋多少列。
 *
 * 分類主題：backtracking-combination
 * 技巧：每一列轉成欄遮罩, (r & chosen) == r 判斷列是否被覆蓋, DFS 選恰好 k 欄, i + left <= n 剪枝
 *
 * 時間複雜度：O(C(n, k) * m)，k 為 numSelect，每種選法要檢查 m 列
 * 空間複雜度：O(m + n)，rows 陣列與遞迴深度
 *
 * 解法思路：DFS 列舉欄的組合
 * 1. 每一列轉成一個遮罩 rows[i]：第 j 位為 1 代表該列在第 j 欄有 1。
 * 2. 一列被覆蓋，當且僅當它所有的 1 都落在已選的欄裡，
 *    也就是 (rows[i] & chosen) == rows[i]。
 *    全為 0 的列 rows[i] = 0，永遠成立，符合題意。
 * 3. 用 DFS 從 n 欄中挑恰好 numSelect 欄：
 *    - left：還要再選幾欄；start：只能從第 start 欄之後挑，避免同一組合重複；
 *      chosen：目前已選欄的遮罩。
 *    - left 變成 0 時選夠了，掃過所有列統計被覆蓋的列數並回傳。
 * 4. 剪枝 i + left <= n：選了第 i 欄之後，後面剩下的欄數必須還能湊滿 left - 1 欄，
 *    不夠的話這個分支不可能選滿，不用走。
 * 5. 與 1239 的差別：這題沒有「選了會衝突」的限制，任何欄都能選，
 *    改成用 left 控制「恰好選幾個」。
 */
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m, 0);  // rows[i]：第 i 列的 1 所在的欄遮罩
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j]) rows[i] |= 1 << j;
        return dfs(rows, n, numSelect, 0, 0);
    }

private:
    // left：還要再選幾欄；start：只能從第 start 欄之後挑；chosen：已選欄的遮罩
    int dfs(const vector<int>& rows, int n, int left, int start, int chosen) {
        if (left == 0) {
            int covered = 0;
            for (int r : rows)
                if ((r & chosen) == r) covered++;  // 這列的 1 全部都在已選欄裡
            return covered;
        }

        int best = 0;
        // i + left <= n：選了第 i 欄後，後面剩下的欄數仍足夠湊滿 left - 1 欄
        for (int i = start; i + left <= n; i++)
            best = max(best, dfs(rows, n, left - 1, i + 1, chosen | (1 << i)));
        return best;
    }
};