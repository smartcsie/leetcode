/**
 * 題目：2225. Find Players With Zero or One Losses (找出輸球次數為零或一次的玩家)
 * 難度：中等 (Medium)
 * 描述：給你一個比賽結果陣列 matches，其中 matches[i] = [winner_i, loser_i]。
 * 你需要回傳一個長度為 2 的列表：
 * 1. 第一個列表包含所有「沒有輸掉任何比賽」的玩家。
 * 2. 第二個列表包含所有「恰好輸掉一場比賽」的玩家。
 * 列表內的玩家編號必須按「升序」排列。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> loses(100001, -1);
        for(const vector<int>& v : matches) {
            if(loses[v[0]] == -1) loses[v[0]] = 0;
            if(loses[v[1]] == -1) loses[v[1]] = 1;
            else loses[v[1]]++;
        }
        vector<vector<int>> ans(2);
        for(int i = 1; i <= 100000; i++) {
            if(loses[i] == 0) ans[0].push_back(i);
            else if(loses[i] == 1) ans[1].push_back(i);
        }
        return ans;
    }
};