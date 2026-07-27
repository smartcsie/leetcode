/**
 * 題目：74. Search a 2D Matrix (搜尋二維矩陣)
 * 難度：中等 (Medium)
 * 描述：在有序的二維矩陣中尋找 target 是否存在。
 * * 時間複雜度：O(log(M * N)) - 透過將 2D 視為 1D 進行二分搜尋。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 矩陣的每一行遞增，且下一行首元素大於上一行尾元素，因此整個矩陣可視為一個長度為 M * N 的有序數組。
 * 使用 index 進行二分搜尋，透過 `mid / n` 獲取行索引，`mid % n` 獲取列索引。
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 邊界檢查：確保矩陣非空
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left = 0;
        int right = m * n - 1;
        
        // 標準二分搜尋
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // 座標映射：將 1D index 轉換回 2D matrix[row][col]
            int val = matrix[mid / n][mid % n];
            
            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
