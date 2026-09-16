/**
 * 題目：1779. Find Nearest Point That Has the Same X or Y Coordinate
 * 難度：簡單 (Easy)
 * 描述：給定兩個整數 x 和 y 表示你的當前位置。另有一個二維整數陣列 points，
 * 其中 points[i] = [ai, bi] 表示第 i 個點的位置。
 * 如果一個點與你的位置共享相同的 x 座標或 y 座標，則被認為是有效點。
 * 請返回距離你最近的有效點的索引（從 0 開始）。
 * 如果有多個有效點且距離相同，返回索引最小的那個。若沒有任何有效點，返回 -1。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 初始化最小距離 distance 為 INT_MAX，最佳索引 idx 為 -1。
 * 2. 迴圈遍歷 points 陣列中的每一個點：
 * - 檢查是否為有效點（即 x == x1 || y == y1）。
 * - 若為有效點，計算其與當前位置的距離。
 * (註：標準曼哈頓距離為 abs(x - x1) + abs(y - y1)。)*
 * - 若算出的距離小於當前的最小值，則更新最小距離與對應的索引 idx。
 * 3. 迴圈結束後回傳 idx。
 */

class Solution {
public:
    int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
        iint mn = INT_MAX;
        int idx = -1;
        for(int i = 0; i < points.size(); i++) {
            if(x == points[i][0] && abs(y - points[i][1]) < mn ) {
                mn = abs(y - points[i][1]);
                idx = i;
            }
            if(y == points[i][1] &&  abs(x - points[i][0]) < mn) {
                mn = abs(x - points[i][0]);
                idx = i;
            }
        }
        return idx;
    }
};
