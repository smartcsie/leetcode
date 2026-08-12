/**
 * 註解：待補充
 */
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> counts(1001, 0);
        for(auto row : nums) {
            for(auto x : row) {
                counts[x]++;
            }
        }
        for( int i = 0; i <= 1000; i++) {
            if(counts[i] == n) ans.push_back(i);
        }
        return ans;
    }
};