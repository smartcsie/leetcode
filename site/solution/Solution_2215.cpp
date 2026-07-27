class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        res[0].reserve(set1.size());
        res[1].reserve(set2.size());
        for(const auto& num : set1) {
            if(!set2.erase(num)) {
                res[0].push_back(num);
            }
        }
        for(const auto& num : set2) {
            res[1].push_back(num);
            
        }
        return res;
    }
};