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
        unordered_map<int,string> maps;
        int n = names.size();
        for(int i = 0; i < n; i++) maps[heights[i]] =  names[i];
        sort(heights.begin(), heights.end(), greater<int>());
        vector<string> ans(n);
        for(int i = 0; i < n; i++) ans[i] = maps[heights[i]];
        return ans;
    }
};
