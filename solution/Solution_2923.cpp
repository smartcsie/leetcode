/**
 * 題目：2923. Find Champion I
 * 難度：待補充
 * 描述：在一個錦標賽圖中，找出勝場數為 N-1 的隊伍（即冠軍）。
 *
 * 時間複雜度：O(N^2) - 遍歷矩陣，找沒有任何行可以打敗它的行。
 * 空間複雜度：O(1) - 僅使用常數空間。
 *
 * 解法思路：
 * 1. 題目保證 grid[i][j] = 1 代表 i 贏過 j。
 * 2. 冠軍隊伍必須擊敗其他所有隊伍，因此其勝場數（該列的總和）必須等於 N-1。
 * 3. 透過 std::accumulate 計算每一列的勝場數即可。
 */

class Solution {
public:
    int findChampion(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        for(int i =0 ; i < n; i++) {
            int wins = count(grid[i].begin(), grid[i].end(), 1);
            if(wins == (n - 1)) {
                return i;
            }
        }
        return -1;
    }
};
