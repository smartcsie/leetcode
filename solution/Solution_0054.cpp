/**
 * 題目：54. Spiral Matrix (螺旋矩陣)
 * 難度：中等 (Medium)
 * 描述：按螺旋順序遍歷 m x n 矩陣並回傳結果。
 * * 時間複雜度：O(M * N) - 每個節點訪問一次。
 * 空間複雜度：O(1) - 原地修改矩陣作為標記，不使用額外容器。
 * * 優化思路：
 * 1. 方向陣列：封裝移動邏輯。
 * 2. 狀態標記：修改矩陣數值標記已讀，實現空間原地優化。
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        res.reserve(m * n); // 預分配空間避免動態擴容

        // 方向陣列：右, 下, 左, 上
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        
        int x = 0, y = 0, dir = 0;
        const int visited = 101; // 題目數值範圍 [-100, 100]，使用 101 作為已拜訪標記

        for (int v = 0; v < m * n; ++v) {
            res.push_back(matrix[x][y]);
            matrix[x][y] = visited; // 標記已拜訪

            // 計算預測下一步
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 判斷是否需要轉向
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] == visited) {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            
            x = nx;
            y = ny;
        }
        return res;
    }
};
