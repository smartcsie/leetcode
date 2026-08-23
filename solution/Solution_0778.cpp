/**
 * 題目：778. Swim in Rising Water
 * 難度：困難 (Hard)
 * 分類主題：greedy-graph
 * 描述：給定一個高度網格 grid，第 t 個時刻，水位淹到高度 t，只能走
 * 高度 <= 目前水位的格子。從左上角走到右下角，求最早能到達的時刻。
 *
 * 時間複雜度：O(N² log N)
 * 空間複雜度：O(N²)
 *
 * 解法思路：
 * （跟 1631 是同一種 Dijkstra 變形，「路徑代價」換成「路上經過的最大
 * 格子高度」，本質上是同一個模板）：
 * 1. best[r][c] 記錄「走到這一格，路徑上經過的最大高度」的最小可能
 *    值，也就是「最早能到達這一格的時刻」。
 * 2. 用 min-heap 存 (目前路徑上的最大高度, row, col)，優先處理數值
 *    最小的節點。
 * 3. 狀態轉移：從 (r,c) 走到鄰居 (nr,nc)，新的時刻是
 *    `max(目前的時刻, grid[nr][nc])`——因為要等水位淹到這麼高才能
 *    站上去，如果 grid[nr][nc] 比目前水位低，時刻不會提前（水位不會
 *    倒退），所以取 max。
 * 4. 第一次從 heap 取出終點時，回傳這個值，就是最早能抵達的時刻。
 */
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> best(n, vector<int>(n, INT_MAX));
        best[0][0] = grid[0][0];
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (r == n - 1 && c == n - 1) return t;
            if (t > best[r][c]) continue;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                int newTime = max(t, grid[nr][nc]);
                if (newTime < best[nr][nc]) {
                    best[nr][nc] = newTime;
                    pq.push({newTime, nr, nc});
                }
            }
        }
        return -1;
    }
};
