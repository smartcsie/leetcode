class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 1;
        while(fast < n) {
            while(fast < n && nums[slow] == nums[fast]) fast++;
            if(fast < n) swap(nums[++slow], nums[fast++]);
        }
        return slow + 1;
    }
};