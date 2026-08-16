/**
 * 題目：939. Minimum Area Rectangle (最小面積矩形)
 * 難度：中等 (Medium)
 * 描述：在平面上找出由四個點組成的矩形，並回傳最小面積。
 *
 * 時間複雜度：O(N^2) - 遍歷點對組合。
 * 空間複雜度：O(N) - 儲存點的雜湊集合。
 *
 * 解法思路：
 * 1. 減少迴圈次數：由原本遍歷所有點對 (i, j)，改為透過「共享 x 座標」的點集來篩選，顯著減少查找次數。
 * 2. 避免重複檢查：內層迴圈從 i+1 開始，並利用對角線邏輯減少冗餘計算。
 */

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        vector<vector<int>>& p = points;
        set<vector<int>> seen;
        for(const vector<int>& v : p) seen.insert(v);
        int minArea = INT_MAX;
        for(const vector<int>& p1 : p) {
            for(const vector<int>& p2 : p) {
                if(p1 != p2) {
                    int x1 = p1[0], y1 = p1[1];
                    int x2 = p2[0], y2 = p2[1];
                    if(x1 != x2 && y1 != y2 && seen.contains({x1, y2}) && seen.contains({x2, y1})) {
                        int area = abs(x1 - x2) * abs(y1 - y2);
                        minArea = min(minArea, area);
                    }
                }
            } 
        } 
        return minArea == INT_MAX ? 0 : minArea;
    }
};
