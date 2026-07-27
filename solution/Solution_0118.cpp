/**
 * 題目：118. Pascal's Triangle (巴斯卡三角形)
 * 難度：簡單 (Easy)
 * 描述：給定 numRows，產生巴斯卡三角形的前 numRows 列。
 * * 時間複雜度：O(N^2) - 共有 N(N+1)/2 個元素需要計算。
 * 空間複雜度：O(1) - 不計算回傳結果所需的空間。
 * * 優化思路：
 * 1. 預分配 `res` 的大小 (`res.reserve(numRows)`)，避免在迴圈中多次觸發記憶體重分配。
 * 2. 每一列首尾固定為 1，中間元素由 `res[i-1][j-1] + res[i-1][j]` 計算而得。
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.reserve(numRows); // 優化：預分配外層容器空間
        
        for (int i = 0; i < numRows; i++) {
            // 初始化該列，所有位置預設為 1 (處理首尾)
            vector<int> row(i + 1, 1);
            
            // 計算中間的值
            for (int j = 1; j < i; j++) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            
            res.push_back(std::move(row)); // 使用 move 語義減少記憶體拷貝
        }
        return res;
    }
};
