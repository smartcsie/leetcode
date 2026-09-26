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
        unordered_map<int, int> losses;
        vector<vector<int>> ans(2);
        for(const vector<int>& v : matches) {
            if(!losses.contains(v[0])) losses[v[0]] = 0;
            losses[v[1]]++;
        }
        for(const auto [team, lose] : losses) {
            if(lose == 0) ans[0].push_back(team);
            if(lose == 1) ans[1].push_back(team);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};