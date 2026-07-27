class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set set2(nums2.begin(), nums2.end());
        int common_min = INT_MAX;
        for(const int& num : nums1) {
            if(set2.count(num)) common_min = min(common_min, num);
        }
        if(common_min != INT_MAX) return common_min;
        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.end());
        return min1 > min2 ? min2 * 10 + min1 : min1 * 10 + min2;
    }
};
