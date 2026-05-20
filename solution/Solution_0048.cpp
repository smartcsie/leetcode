/**
 * 題目：48. Rotate Image (旋轉圖像)
 * 難度：中等 (Medium)
 * 描述：給定一個 n x n 的二維矩陣 matrix 表示一個圖像。
 *      請將圖像順時針旋轉 90 度。你必須在「原地」修改，不要使用另一個矩陣。
 * 
 * 時間複雜度：O(n²) - 需要遍歷矩陣中的所有元素。
 * 空間複雜度：O(1) - 僅在原地交換元素，不使用額外空間。
 * 
 * 解法思路：
 * 順時針旋轉 90 度可以拆解為兩步操作：
 * 1. 轉置矩陣 (Transpose)：
 *    將矩陣沿著主對角線 (左上到右下) 翻轉，即交換 matrix[i][j] 與 matrix[j][i]。
 *    此時：原本的行變成了列。
 * 2. 左右翻轉 (Reverse Each Row)：
 *    將矩陣的每一行進行左右對調。
 *    此時：原本在左側的元素移到了右側，完成了順時針 90 度的變換。
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 1. 轉置矩陣 (Transpose)
        // 注意：j 從 i 開始，只處理對角線的一側，否則換過去又換回來等於沒換
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 2. 每一行進行左右翻轉 (Reverse each row)
        for (int i = 0; i < n; ++i) {
            // 使用 std::reverse 直接翻轉整行
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
