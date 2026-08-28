/**
 * 題目：787. Cheapest Flights Within K Stops
 * 難度：中等 (Medium)
 * 分類主題：greedy-graph
 * 描述：給定 n 個城市和一組航班 flights[i] = [from, to, price]，求從
 * src 到 dst、最多經過 k 個中轉站（也就是最多搭 k+1 趟班機）的最便宜
 * 價格，找不到就回傳 -1。
 *
 * 時間複雜度：O(K * E)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Bellman-Ford 演算法，限制鬆弛輪數來對應「最多 k+1 趟班機」這個
 * 限制，這題不能直接用標準 Dijkstra，因為 Dijkstra 沒辦法限制「最多
 * 經過幾條邊」，而 Bellman-Ford 天生就是逐輪鬆弛，剛好可以卡輪數）：
 * 1. dist[i] 代表「目前已知從 src 到城市 i 的最便宜價格」，初始化
 *    dist[src] = 0，其他是無限大。
 * 2. 進行 k+1 輪鬆弛（對應最多 k+1 趟航班）：每一輪，對每條航班
 *    (u, v, w)，如果 dist[u] 已知（不是無限大），嘗試用
 *    dist[u] + w 更新 dist[v]。
 * 3. **關鍵細節（容易寫錯的地方）**：每一輪鬆弛必須用「上一輪」的
 *    dist 值來更新，不能直接在同一個陣列上原地更新（那樣會變成沒有
 *    輪數限制的標準 Bellman-Ford，允許一輪內連續走多條邊，等於沒有
 *    限制中轉次數）。做法是每輪開始時複製一份 newDist，鬆弛時讀舊的
 *    dist、寫新的 newDist，一輪結束後才整批替換。
 * 4. k+1 輪跑完，dist[dst] 就是答案（如果還是無限大代表到不了，
 *    回傳 -1）。
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> newDist = dist;
            for (auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != INT_MAX && dist[u] + w < newDist[v]) {
                    newDist[v] = dist[u] + w;
                }
            }
            dist = newDist;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
