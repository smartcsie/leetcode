class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2 * n);
        for(auto left = nums.begin(), right = nums.end() - 1; left < nums.begin() + n; left++, right--) {
            *right = *left;
        }
        return nums;
    }
};