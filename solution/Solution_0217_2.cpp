class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ranges::sort(nums);
        if(unique(nums.begin(), nums.end()) != nums.end()) return true;
        return false;
    }
};