/**
 * 題目：59. Spiral Matrix II (螺旋矩陣 II)
 * 難度：中等 (Medium)
 * 描述：產生一個 n x n 的矩陣，依據螺旋順序填入 1 到 n^2 的數字。
 * * 時間複雜度：O(N²) - 每個格子填入一次，總計 n*n 個格子。
 * 空間複雜度：O(1) - 除了回傳的輸出矩陣外，僅使用常數空間。
 * * 優化思路：
 * 1. 方向陣列：dx, dy 陣列清晰定義了右、下、左、上的移動變化。
 * 2. 轉向判定：利用 `next` 位置是否越界或已填入（非零）來觸發 `dir` 切換。
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n , vector<int>(n, 0));
        const int dx[] = {0 , 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, dir = 0;
        for(int v = 1; v <= n * n; ++v) {
            res[x][y] = v;
            int next_x = x + dx[dir];
            int next_y = y + dy[dir];

            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || res[next_x][next_y] != 0) {
                dir = (dir + 1) % 4;
                next_x = x + dx[dir];
                next_y = y + dy[dir];
            }
            x = next_x;
            y = next_y;
        }
        return res;
    }
};
