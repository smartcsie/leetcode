class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> map;
        for(int num : nums1) {
            map[num]++;
        }
        for(int num : nums2) {
            if(map[num]-->0) 
                res.push_back(num);
        }
        return res;
    }
};