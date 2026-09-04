class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int ans = 1;
        while(n > 0) {
            ans <<= 1;
            n >>= 1;
        }
        return ans;
    }
};