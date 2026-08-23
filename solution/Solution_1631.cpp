/**
 * 題目：1631. Path With Minimum Effort
 * 難度：中等 (Medium)
 * 分類主題：greedy-graph
 * 描述：給定一個高度網格 heights，從左上角走到右下角（上下左右移動），
 * 一條路徑的「代價」定義為路徑上相鄰兩格高度差的最大值（不是總和）。
 * 求代價最小的路徑，回傳這個最小代價。
 *
 * 時間複雜度：O(M*N log(M*N))
 * 空間複雜度：O(M*N)
 *
 * 解法思路：
 * （Dijkstra 的變形，這是這個 pattern 的精神所在：貪心策略內建在
 * 「優先處理目前代價最小的節點」這個 heap 機制裡）：
 * 1. 跟標準 Dijkstra 幾乎一樣，差別只在於「路徑代價的定義」：標準
 *    Dijkstra 是累加邊權重，這題是取路徑上「最大」的邊權重（高度差）。
 * 2. effort[r][c] 記錄「走到這一格，路徑上最大高度差的最小可能值」。
 * 3. 用 min-heap 存 (目前路徑代價, row, col)，每次取出代價最小的節點
 *    處理（貪心：優先確定「目前已知最容易到達」的格子）。
 * 4. 狀態轉移：從 (r,c) 走到鄰居 (nr,nc)，新的路徑代價是
 *    `max(目前路徑代價, 這一步的高度差)`——因為代價是「路上最大值」，
 *    新增一步只會維持不變或變大，不會累加。如果這個新代價比目前記錄
 *    的 effort[nr][nc] 更好，就更新並丟進 heap。
 * 5. 第一次從 heap 取出終點 (m-1, n-1) 時，這個值就是答案（Dijkstra
 *    的貪心性質保證：第一次彈出某節點時，該節點的距離已經是最終值）。
 */
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        effort[0][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        while (!pq.empty()) {
            auto [e, r, c] = pq.top(); pq.pop();
            if (r == m - 1 && c == n - 1) return e;
            if (e > effort[r][c]) continue;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int diff = abs(heights[nr][nc] - heights[r][c]);
                int newEffort = max(e, diff);
                if (newEffort < effort[nr][nc]) {
                    effort[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }
        return 0;
    }
};
