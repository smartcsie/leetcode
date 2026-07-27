class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> res;
        map<int, int> count;
        for(const auto& group : nums) {
            for(int num : group) {
                count[num]++;
            }
        }
        int n = nums.size();
        for (const auto& [num, freq] : count) {
            if (freq == n) {
                res.push_back(num);
            }
        }
        return res;
    }
};