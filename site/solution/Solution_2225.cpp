/**
 * 題目：2225. Find Players With Zero or One Losses (找出輸球次數為零或一次的玩家)
 * 難度：中等 (Medium)
 * 描述：給你一個比賽結果陣列 matches，其中 matches[i] = [winner_i, loser_i]。
 *      你需要回傳一個長度為 2 的列表：
 *      1. 第一個列表包含所有「沒有輸掉任何比賽」的玩家。
 *      2. 第二個列表包含所有「恰好輸掉一場比賽」的玩家。
 *      列表內的玩家編號必須按「升序」排列。
 * 
 * 時間複雜度：O(n log n) - 遍歷比賽需要 O(n)，但最後對玩家清單進行排序需要 O(n log n)。
 * 空間複雜度：O(n) - 使用 unordered_map 儲存所有參加過比賽玩家的輸球紀錄。
 */

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> counts;
        vector<vector<int>> res(2);

        for(const auto& match : matches) {
            if(! counts.contains(match[0]))
                counts[match[0]] = 0;
            counts[match[1]]++;
        }

        for(const auto& [num, count] : counts) {
            if( count == 0 )
                res[0].push_back(num);
            else if( count == 1 )
                res[1].push_back(num);
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};
