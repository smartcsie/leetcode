class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> sets;
        for(const int& x : nums) {
            if(!sets.insert(x).second)  return x;
        }
        return -1;
    }
};