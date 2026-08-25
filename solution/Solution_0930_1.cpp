class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0 ; i < n ;i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int ans = 0;
        for(int i = 0 ; i < n ;i++) {
            for(int j = i ; j < n ;j++) {
                if(prefix[j + 1] - prefix[i] == goal) ans++;
            }
        }
        return ans;
    }
};