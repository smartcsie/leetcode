/**
 * 題目：1436. Destination City (旅行終點站)
 * 難度：簡單 (Easy)
 * 描述：給你一系列路徑，找出唯一的終點城市（該城市沒有往外走的路線）。
 * * 時間複雜度：O(N) - 兩次線性掃描路徑。
 * 空間複雜度：O(N) - 儲存所有出發城市。
 */

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> starts;
        for(const auto& path : paths) {
            starts.insert(path[0]);
        }
        for(const auto& path : paths) {
            if(starts.find(path[1]) == starts.end())
                return path[1];
        }
        return "";

    }
};
