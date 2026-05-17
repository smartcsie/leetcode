/**
 * 題目：36. Valid Sudoku (有效的數獨)
 * 難度：中等 (Medium)
 * 描述：判斷一個 9x9 的數獨板是否有效。只需要根據已填入的數字檢查行列與九宮格即可。
 * 
 * 時間複雜度：O(1) - 雖然是 O(81)，但因為棋盤大小固定為 9x9。
 * 空間複雜度：O(1) - 使用了固定大小的 bitset 陣列。
 * 
 * 解法思路：
 * 1. 使用三個 bitset 陣列：
 *    - rows[9]: 記錄每一橫列中數字 1-9 的出現情況。
 *    - cols[9]: 記錄每一直欄中數字 1-9 的出現情況。
 *    - boxes[9]: 記錄九個 3x3 小方格中數字 1-9 的出現情況。
 * 2. 遍歷棋盤中的每一個格子：
 *    - 如果格子是 '.'，跳過。
 *    - 計算該格屬於哪一個 3x3 小方格，公式為：boxIndex = (r / 3) * 3 + (c / 3)。
 * 3. 檢查數字是否已在該列、該欄或該方格出現過：
 *    - 若 bitset 的第 num 位已經是 1，代表重複，回傳 false。
 *    - 若否，則將該位設為 1 (set)。
 */


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<10> rows[9];
        bitset<10> cols[9];
        bitset<10> boxs[9];
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.') continue;

                int num = board[r][c] - '0';

                int b = (r/3)*3 + c/3;
                if(rows[r].test(num) || cols[c].test(num) || boxs[b].test(num)) return false;

                rows[r].set(num);
                cols[c].set(num);
                boxs[b].set(num);
            }
        }
        return true;
    }
};
