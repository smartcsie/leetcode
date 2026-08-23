/**
 * 題目：1584. Minimum Cost to Connect All Points
 * 難度：中等 (Medium)
 * 分類主題：greedy-graph
 * 描述：給定平面上一組點 points，任兩點之間的連接成本是曼哈頓距離，
 * 求把所有點連通所需的最小總成本（最小生成樹）。
 *
 * 時間複雜度：O(N²)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Prim's 演算法，MST 系列裡最經典的貪心：每一步都貪心地把「離目前
 * 已連通集合最近的點」納入，這正是「Greedy in Graph Algorithms」這個
 * pattern 名字裡「MST 裡的貪心邏輯」所指的東西）：
 * 1. minDist[i] 代表「點 i 到目前已經在生成樹裡的集合」的最短距離，
 *    inMST[i] 代表點 i 是否已經被納入生成樹。
 * 2. 初始化：任選一個點（這裡選點 0）當起點，minDist[0] = 0，其他點
 *    的 minDist 先設成無限大。
 * 3. 重複 n 次：
 *    - 從「還沒被納入」的點裡，挑 minDist 最小的那個點 u（這就是
 *      貪心的核心：優先接上目前離生成樹最近的點，能保證總成本
 *      最小）。
 *    - 把 u 納入生成樹，累加 minDist[u] 到總成本（這是連接 u 進生成
 *      樹的實際花費）。
 *    - 用 u 去更新其他還沒納入的點的 minDist：如果 u 到某個點 v 的
 *      距離比目前記錄的 minDist[v] 更短，代表「透過 u 連接 v」比
 *      「透過其他已在生成樹裡的點連接 v」更划算，更新它。
 * 4. n 個點都處理完後，totalCost 就是最小生成樹的總成本。
 * 5. 這裡用最簡單的 O(N²) 版本（適合點數不多、稠密圖的情況，题目
 *    給的 N 最多 1000，O(N²) = 10^6 完全可以接受），沒有另外用堆優化
 *    成 O(N² log N)，因為稠密圖用鄰接矩陣掃描反而更直接。
 */
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        minDist[0] = 0;
        int totalCost = 0;

        for (int iter = 0; iter < n; ++iter) {
            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (!inMST[i] && (u == -1 || minDist[i] < minDist[u])) u = i;
            }
            inMST[u] = true;
            totalCost += minDist[u];

            for (int v = 0; v < n; ++v) {
                if (inMST[v]) continue;
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (dist < minDist[v]) minDist[v] = dist;
            }
        }
        return totalCost;
    }
};
