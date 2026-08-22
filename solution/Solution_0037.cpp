/**
 * 題目：37. Sudoku Solver
 * 難度：困難 (Hard)
 * 描述：給定一個部分填好的 9x9 數獨盤面，原地解出完整的數獨解答（保證
 * 有解且唯一）。
 *
 * 時間複雜度：O(9^M)，M 是空格數量（最壞情況，實務上剪枝後遠比這快）
 * 空間複雜度：O(1)（原地修改，遞迴深度最多 81）
 *
 * 解法思路：
 * （Constraint Satisfaction 回溯，跟 N-Queens 是同一種「棋盤約束
 * 滿足」形狀，只是規則從「不同行列對角線」換成「同行同列同九宮格
 * 不重複」）：
 * 1. isValid(row, col, c) 檢查：在這個位置放數字 c 會不會跟同一行、
 *    同一列、或同一個 3x3 九宮格裡的其他數字重複。九宮格索引用
 *    `3*(row/3)+i/3, 3*(col/3)+i%3` 這個公式定位。
 * 2. backtrack 掃描整個盤面，找到第一個空格（'.'），嘗試填入 1~9
 *    每個數字，只要合法就填入、遞迴處理剩下的空格；如果遞迴成功
 *    （回傳 true，代表後面都解出來了），直接往上回傳 true，不用
 *    再試其他數字；如果不成功，恢復這格為空（回溯），繼續試下一個
 *    數字。
 * 3. 如果 1~9 都試過還是無法讓後面的空格解出來，回傳 false，讓上一層
 *    知道「這條路走不通」，換其他數字重試。
 * 4. base case：掃描到沒有空格了（全部填滿），回傳 true，代表整個
 *    盤面都解出來了。
 */
class Solution {
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') continue;
                for (char digit = '1'; digit <= '9'; ++digit) {
                    if (isValid(board, r, c, digit)) {
                        board[r][c] = digit;
                        if (backtrack(board)) return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};
