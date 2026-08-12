class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(const string& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            groups[s].push_back(str);
        }
        vector<vector<string>> res;
        res.reserve(groups.size());
        for(const auto& [key, vec] : groups) {
            res.push_back(vec);
        }
        return res;
    }
};