/**
 * 題目：2319. Check if Matrix Is X-Matrix
 * 描述：給你一個大小為 n x n 的二維整數陣列 grid，代表一個方陣。
 *       若該矩陣滿足以下條件，則稱其為 X-Matrix：
 *       1. 所有在對角線上的元素（主對角線與副對角線）都不為 0。
 *       2. 所有不在對角線上的元素都必須為 0。
 *       若為 X-Matrix 返回 true，否則返回 false。
 * 
 * 解法思路：
 * 1. 幾何座標條件：
 *    - 主對角線（Main Diagonal）：從左上到右下，滿足 `i == j`。
 *    - 副對角線（Anti-Diagonal）：從右上到左下，滿足 `i + j == n - 1`。
 * 2. 雙重迴圈遍歷：
 *    - 若當前格子 `(i, j)` 屬於對角線（即 `i == j || i + j == n - 1`），則檢查其數值是否為 0，若為 0 則不合規，返回 false。
 *    - 若當前格子不属于對角線，則檢查其數值是否不為 0，若不為 0 則不合規，返回 false。
 * 3. 若完整遍歷後未發現違規格子，則返回 true。
 */

class Solution {
public:
    bool checkXMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 判斷是否位於對角線上
                if (i == j || i + j == n - 1) {
                    // 對角線元素不可為 0
                    if (grid[i][j] == 0) return false;
                } else {
                    // 非對角線元素必須為 0
                    if (grid[i][j] != 0) return false;
                }
            }
        }
        
        return true;
    }
};
