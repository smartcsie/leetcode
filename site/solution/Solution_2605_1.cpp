class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int res = 100;
        for(const int& x : nums1) {
            for(const int& y : nums2) {
                if(x == y) {
                    res = min(res, x);
                } else {
                    res = min({res, 10 * x + y, 10 * y + x});
                }
            }
        }
        return res;
    }
};
