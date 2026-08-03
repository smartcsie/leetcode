class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueSet(nums.begin(), nums.end());
        return nums.size() != uniqueSet.size();
    }
};