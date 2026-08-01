/**
 * 題目：2352. Equal Row and Column Pairs
 * 難度：待補充
 * 描述：給你一個大小為 n x n 的整數矩陣 grid，請你返回滿足「第 i 行與第 j 列完全相同」的組數 (i, j)。
 * 行與列的元素相同定義為順序與數值皆須完全一致。
 *
 * 時間複雜度：O(N^2logN) - hash map 記錄每個 row，遍歷每個 column 查詢。
 * 空間複雜度：O(N^2) - map 儲存 N 個向量。
 *
 * 解法思路：
 * （雜湊映射統計 Row Frequency Mapping）：
 * 1. 儲存所有行的出現頻率：
 * - 由於 C++ 的 `std::map` 支援將 `std::vector<int>` 作為 Key，我們可以直接用一個 `std::map<vector<int>, int>` 來統計矩陣中每一行（Row）出現的次數。
 * 2. 逐一提取並比對列：
 * - 接著，針對矩陣的每一列（Column）建構出對應的整數陣列 `col`。
 * - 利用 `counts[col]` 直接查詢這個列是否與哪幾行相同，並將對應的出現次數累加到答案 `ans` 中。
 */

class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::map<std::vector<int>, int> counts;
        int ans = 0;
        // 步驟 1：統計每一行的出現頻率
        for (const auto& row : grid) {
            counts[row]++;
        }
        // 步驟 2：建構每一列，並檢查其在 map 中出現了幾次
        for (int j = 0; j < n; j++) {
            std::vector<int> col(n, 0);
            for (int i = 0; i < n; i++) {
                col[i] = grid[i][j];
            }
            ans += counts[col];
        }
        return ans;
    }
};
