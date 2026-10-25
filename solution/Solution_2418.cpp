/**
 * 題目：2418. Sort the People (按身高排序人員)
 * 難度：簡單 (Easy)
 * 描述：根據身高從高到低排序姓名。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> heightToName;
        for(int i = 0; i < names.size(); i++) heightToName.push_back({heights[i], names[i]});
        sort(heightToName.begin(), heightToName.end(), greater<>());
        vector<string> ans(names.size());
        for(int i = 0; i < names.size(); i++) ans[i] = heightToName[i].second;
        return ans;
    }
};
