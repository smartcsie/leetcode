/**
 * 題目：939. Minimum Area Rectangle (最小面積矩形)
 * 難度：中等 (Medium)
 * 描述：在平面上找出由四個點組成的矩形，並回傳最小面積。
 * * 時間複雜度：O(N^2) - 遍歷點對組合。
 * 空間複雜度：O(N) - 儲存點的雜湊集合。
 * * 優化思路：
 * 1. 減少迴圈次數：由原本遍歷所有點對 (i, j)，改為透過「共享 x 座標」的點集來篩選，顯著減少查找次數。
 * 2. 避免重複檢查：內層迴圈從 i+1 開始，並利用對角線邏輯減少冗餘計算。
 */

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> seen;
        for(const auto& point : points) {
            seen.insert(point[0] * 40001 + point[1]);
        }
        int minArea = INT_MAX;
        for(int i = 0; i < points.size() - 1; i++) {
            for(int j = 0; j < points.size(); j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0] , y2 = points[j][1];
                if(x1 != x2 && y1 != y2) {
                    if(seen.contains(x1 * 40001 + y2) &&
                        seen.contains(x2 * 40001 + y1) ) {
                        int area = abs(x1 - x2) * abs(y1 - y2);
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        return (minArea == INT_MAX) ? 0 : minArea;
    }
};
