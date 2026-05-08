class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool appear[1001];
        vector<int> res;
        memset(appear, false, sizeof(appear));
        for(int num : nums1) {
            appear[num] = true;
        }
        for(int num : nums2) {
            if(appear[num]) {
                res.push_back(num);
                appear[num] = false;
            }
        }
        return res;

    }
};