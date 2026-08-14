class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;
        while(fast < n) {
            while(fast < n && nums[fast] == 0) fast++;
            if(fast < n) swap(nums[slow++], nums[fast++]);
        }
    }
};