/**
 * 題目：1436. Destination City (旅行終點站)
 * 難度：簡單 (Easy)
 * 描述：給你一系列路徑，找出唯一的終點城市（該城市沒有往外走的路線）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> startCitys;
        for(vector<string>& p : paths) {
            startCitys.insert(p[0]);
        }
        for(vector<string>& p : paths) {
            if(!startCitys.contains(p[1])) return p[1];
        }
        return "";
    }
};
