/**
 * 題目：2133. Check if Every Row and Column Contains All Numbers
 * 難度：簡單 (Easy)
 * 描述：給定 n x n 的矩陣 matrix，若每一列與每一行都恰好包含
 *       1 到 n 的所有整數（即拉丁方陣），回傳 true，否則回傳 false。
 *
 * 分類主題：hash-table-uniqueness
 * 技巧：布林標記陣列檢查重複, 同一輪迴圈同時檢查列與行, matrix[i][j] 與 matrix[j][i] 對稱存取
 *
 * 時間複雜度：O(N²)，N 為矩陣邊長，每格恰好被讀兩次
 * 空間複雜度：O(N)
 *
 * 解法思路：標記陣列檢查重複
 * 1. 每列（行）有 n 個格子、值域是 1 ~ n，要包含所有數字，
 *    等價於「n 個值彼此不重複，且都落在 1 ~ n」。
 * 2. 用 rows[v] 記錄第 i 列是否已出現過值 v + 1，
 *    用 cols[v] 記錄第 i 行是否已出現過值 v + 1。
 * 3. 對每個 i，同一個 j 迴圈裡：
 *    - matrix[i][j] 走訪第 i 列
 *    - matrix[j][i] 走訪第 i 行
 *    所以一次迴圈就同時檢查完第 i 列與第 i 行。
 * 4. 遇到值超出 1 ~ n，或同一列（行）已出現過，直接回傳 false。
 * 5. 每處理完一個 i，兩個標記陣列要清空，才能給下一列（行）使用。
 * 6. 全部檢查完都沒問題，回傳 true。
 */
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> rows(n);  // rows[v]：目前這一列是否已出現過值 v + 1
        vector<int> cols(n);  // cols[v]：目前這一行是否已出現過值 v + 1

        for (int i = 0; i < n; i++) {
            // 換下一列 / 下一行前，先清空標記
            fill(rows.begin(), rows.end(), 0);
            fill(cols.begin(), cols.end(), 0);

            for (int j = 0; j < n; j++) {
                int rVal = matrix[i][j] - 1;  // 第 i 列第 j 個，轉成 0 起算的索引
                int cVal = matrix[j][i] - 1;  // 第 i 行第 j 個，轉成 0 起算的索引

                // 值超出 1 ~ n（題目限制下不會發生，但可避免越界存取）
                if (rVal < 0 || rVal > n - 1 || cVal < 0 || cVal > n - 1) return false;

                // 同一列或同一行已經出現過，代表重複，無法涵蓋 1 ~ n
                if (rows[rVal] || cols[cVal]) return false;

                rows[rVal] = 1;
                cols[cVal] = 1;
            }
        }
        return true;
    }
};