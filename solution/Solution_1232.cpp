/**
 * 題目：1232. Check If It Is a Straight Line
 * 難度：簡單 (Easy)
 * 描述：給定一個陣列 coordinates，其中 coordinates[i] = [x, y] 表示座標點，
 * 請判斷這些點是否剛好在同一直線上。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 若點的數量小於等於 2（`n == 2`），任意兩點必定在同一直線上，直接回傳 true。
 * 2. 先計算前兩個點產生的向量差：`dx = x1 - x0`, `dy = y1 - y0`。
 * 3. 對於後續的每一個點 i，計算它與第一個點的向量差：`dx1 = xi - x0`, `dy1 = yi - y0`。
 * 4. 為了避免斜率計算時的分母為零（垂直線）以及浮點數精度誤差，
 * 我們將斜率相等公式 `dy / dx == dy1 / dx1` 交叉相乘轉化為整數乘法：
 * `dx1 * dy == dy1 * dx`。
 * 5. 只要有一個點不符合交叉相乘相等的條件，就回傳 false；全部符合則回傳 true。
 */

class Solution {
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates) {
        vector<vector<int>>& c = coordinates;
        if(c.size() == 2) return true;
        int dx = c[1][0] - c[0][0];
        int dy = c[1][1] - c[0][1];
        for(int i = 1; i < c.size() - 1; i++) {
            int dx1 = c[i + 1][0] - c[i][0];
            int dy1 = c[i + 1][1] - c[i][1];
            if(dx * dy1 != dy * dx1) return false;
        }
        return true;
    }
};
