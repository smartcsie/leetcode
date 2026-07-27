/**
 * 題目：2418. Sort the People (按身高排序人員)
 * 難度：簡單 (Easy)
 * 描述：根據身高從高到低排序姓名。
 * * 時間複雜度：O(N log N) - 主要開銷在排序。
 * 空間複雜度：O(N) - 儲存配對資料。
 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // 優化點：預先保留空間，避免 hash map 在插入過程中進行多次 rehash
        unordered_map<int, string> map;
        map.reserve(names.size()); 
        
        for(int i = 0; i < names.size(); i++) {
            map[heights[i]] = names[i];
        }
        
        // 排序高度
        sort(heights.begin(), heights.end(), greater<int>());
        
        // 提取結果
        vector<string> res;
        res.reserve(names.size());
        for(int height : heights) {
            res.push_back(map[height]);
        }
        return res;
    }
};
