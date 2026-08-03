/**
 * 註解：待補充
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> counts1(1001, 0);
        vector<int> counts2(1002, 0);
        for(const int& num : nums1) {
            counts1[num] = 1;
        }
        for(const int& num : nums2) {
            counts2[num] = 1;
        }
        vector<int> ans;
        for(int i = 0; i <= 1000; i++) {
            if(counts1[i] && counts2[i]) ans.push_back(i);
        }
        return ans;
    }
};