class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int idx = nums[i] - 1;
            if (nums[i] != nums[idx]) {
                swap(nums[i], nums[idx]); 
            } else {
                if (nums[i] == i + 1)  i++;
                else return nums[i];
            }
        }
        return -1;
    }
};