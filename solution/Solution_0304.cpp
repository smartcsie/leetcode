/**
 * 題目：304. Range Sum Query 2D - Immutable (二維區域和檢索)
 * 難度：中等 (Medium)
 * 描述：計算給定矩陣中，左上角 (row1, col1) 到右下角 (row2, col2) 的子矩陣總和。
 * * 時間複雜度：初始化 O(M * N)，查詢 O(1)。
 * 空間複雜度：O(M * N) - 用於儲存二維前綴和。
 * * 解法思路：
 * 建立 (M+1) x (N+1) 的前綴和陣列 prefix，其中 prefix[i][j] 表示從 (0,0) 到 (i-1, j-1) 的區域總和。
 */


class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 初始化 prefix 陣列，多加一行一列以便處理邊界 (i=0 或 j=0)
        prefix.assign(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 二維前綴和狀態轉移公式
                prefix[i + 1][j + 1] = matrix[i][j] 
                                     + prefix[i + 1][j] 
                                     + prefix[i][j + 1] 
                                     - prefix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // 利用容斥原理計算矩形總和
        // 大矩形 - 上方矩形 - 左方矩形 + 左上角重疊部分
        return prefix[row2 + 1][col2 + 1] 
             - prefix[row1][col2 + 1] 
             - prefix[row2 + 1][col1] 
             + prefix[row1][col1];
    }
};
