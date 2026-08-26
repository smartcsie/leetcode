class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> indices(n);
        for(int i = 0; i < n; i++) indices[i] = i;
        sort(indices.begin(), indices.end(), [&](const int& a, const int& b){
            return heights[a] > heights[b];
        });
        vector<string>ans;
        ans.reserve(n);
        for(const int& idx : indices) {
            ans.push_back(names[idx]);
        }
        return ans;
    }
};