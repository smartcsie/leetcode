/**
 * 題目：3417. Zigzag Grid Traversal With Skip
 * 難度：簡單 (Easy)
 * 描述：以之字形遍歷網格，且每隔一個格子跳過。
 * 
 * 解法思路：
 * 1. 條件判斷：透過 `(i % 2 == j % 2)` 的邏輯來篩選出正確的格子。
 * 2. 使用雙向佇列 (deque)：
 *    - 偶數行 (i=0, 2, ...)：由左至右加入結果。
 *    - 奇數行 (i=1, 3, ...)：由右至左加入結果。
 * 3. 處理每一行的數據，存入 deque 後根據行號奇偶性選擇 push/pop 的方向。
 */

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size();
        int n = grid[0].size(); 
        deque<int> dq;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if((i + j) % 2 == 0) 
                dq.push_back(grid[i][j]);
            }
            if(i % 2 == 1) while(!dq.empty()) {
                ans.push_back(dq.back()); 
                dq.pop_back();
            }
            else while(!dq.empty()) {
                ans.push_back(dq.front());
                dq.pop_front();
            }
        }
        return ans;
    }
};
