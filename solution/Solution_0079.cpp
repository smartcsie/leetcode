/**
 * 題目：79. Word Search (單字搜尋)
 * 難度：中等 (Medium)
 * 描述：在二維矩陣中搜尋是否存在由相鄰字母組成的指定單字。
 * * 時間複雜度：O(N * 3^L) - N 為格子數，L 為單字長度。每個格子最多 3 個分支（扣除來路）。
 * 空間複雜度：O(L) - 遞迴堆疊深度為單字長度 L。
 * * 優化思路：
 * 1. 原地標記：利用修改 board[r][c] 為 '#' 實現空間 O(1) 的訪問紀錄。
 * 2. 引用傳遞：使用 const string& 減少字串拷貝。
 */

class Solution {
private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int idx) {
        // 成功條件：已匹配到最後一個字元
        if (idx == word.size() - 1) return board[r][c] == word[idx];

        // 匹配成功後嘗試向四個方向擴展
        if (board[r][c] == word[idx]) {
            char temp = board[r][c];
            board[r][c] = '#'; // 標記已拜訪

            // 四個方向
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                    if (dfs(board, word, nr, nc, idx + 1)) return true;
                }
            }
            
            board[r][c] = temp; // 回溯：還原狀態
        }
        
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
