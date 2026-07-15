class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int ones = 0;
        for(const int& num : nums) {
            ones = (num & 1) ? ones + 1 : 0;
            max_ones = max(max_ones, ones);
        }
        return max_ones;
    }
};
