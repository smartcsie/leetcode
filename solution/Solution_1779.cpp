/**
 * 題目：1779. Find Nearest Point That Has the Same X or Y Coordinate
 * 描述：給定兩個整數 x 和 y 表示你的當前位置。另有一個二維整數陣列 points，
 *       其中 points[i] = [ai, bi] 表示第 i 個點的位置。
 *       如果一個點與你的位置共享相同的 x 座標或 y 座標，則被認為是有效點。
 *       請返回距離你最近的有效點的索引（從 0 開始）。
 *       如果有多個有效點且距離相同，返回索引最小的那個。若沒有任何有效點，返回 -1。
 * 
 * 解法思路：
 * 1. 初始化最小距離 distance 為 INT_MAX，最佳索引 idx 為 -1。
 * 2. 迴圈遍歷 points 陣列中的每一個點：
 *    - 檢查是否為有效點（即 x == x1 || y == y1）。
 *    - 若為有效點，計算其與當前位置的距離。
 *      *(註：標準曼哈頓距離為 abs(x - x1) + abs(y - y1)。)*
 *    - 若算出的距離小於當前的最小值，則更新最小距離與對應的索引 idx。
 * 3. 迴圈結束後回傳 idx。
 */

class Solution {
public:
    int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
        int distance = INT_MAX;
        int idx = -1;
        
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            // 條件：shares the same x-coordinate or the same y-coordinate
            if (x == x1 || y == y1) {
                // 計算曼哈頓距離：|x - x1| + |y - y1|
                // （注意：原程式碼中使用的是平方，雖然對比大小無影響，但標準曼哈頓距離為一次方和）
                int dist = std::abs(x - x1) + std::abs(y - y1);
                
                // 如果距離更小，更新記錄（題目要求多個時取索引最小，所以嚴格小於 `<` 可以自然保留較小的 i）
                if (dist < distance) {
                    distance = dist;
                    idx = i;
                }
            }
        }
        
        return idx;
    }
};
