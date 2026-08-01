/**
 * 題目：2397. Maximum Rows Covered by Columns
 * 難度：待補充
 * 描述：給你一個 m x n 的二進位矩陣 matrix 和一個整數 numSelect。
 * 你可以選擇剛好 numSelect 個不同的行（Columns）。
 * 如果某一個行（Row）中所有的 1 都在你選中的那些行（Columns）之內，則稱該行被「涵蓋」了。
 * 請你返回透過選擇 numSelect 個行，最多可以涵蓋多少行（Rows）。
 *
 * 時間複雜度：O(2^N*N) - Bitmask 枚舉所有列選法，M 為行數。
 * 空間複雜度：O(M+N) - row bitmask 陣列大小為 M。
 *
 * 解法思路：
 * （位元遮罩與窮舉 Bitmask & Brute Force）：
 * 1. 狀態壓縮（Row Masks）：
 * - 將矩陣每一行（Row）中含有 1 的位置轉換成一個整數的位元遮罩（Bitmask），存入 `row_masks` 陣列中。
 * 2. 窮舉所有欄位組合（Column Combinations）：
 * - 由於欄位總數 `n` 通常不大（通常 $n \le 15$），我們可以用一個 32 位元整數 `col_mask` 從 `0` 窮舉到 `2^n - 1` 來代表所有可能的選欄組合。
 * - 利用 GCC 內建函數 `__builtin_popcount(col_mask)` 快速篩選出剛好選了 `numSelect` 個欄位的組合。
 * 3. 檢查涵蓋狀態與計數：
 * - 對於每一個符合條件的 `col_mask`，檢查每一個 row 的遮罩是否被其完全涵蓋：`(row_masks[i] & col_mask) == row_masks[i]`。
 * - 若成立代表該 row 被涵蓋，將計數器加 1，並持續更新最大涵蓋列數 `max_covered`。
 */


class Solution {
public:
    int maximumRows(std::vector<std::vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();

        // 步驟 1：將每一行的 1 轉換成 Bitmask 儲存
        std::vector<int> row_masks(m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    row_masks[i] |= (1 << j);
                }
            }
        }
        int max_covered = 0;
        // 步驟 2：窮舉所有可能的選欄組合 (從 0 到 2^n - 1)
        for (int col_mask = 0; col_mask < (1 << n); ++col_mask) {
            // 檢查這個組合是否剛好選了 numSelect 個欄位
            if (__builtin_popcount(col_mask) == numSelect) {
                int current_covered = 0;
                
                // 步驟 3：檢查每個 row 是否被當前的 col_mask 完全涵蓋
                for (int i = 0; i < m; i++) {
                    if ((row_masks[i] & col_mask) == row_masks[i]) {
                        current_covered++;
                    }
                }
                
                // 更新最大涵蓋行數
                max_covered = std::max(max_covered, current_covered);
            }
        }
        return max_covered;
    }
};
