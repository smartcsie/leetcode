class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int absN = abs(nums[i]);
            int index = absN - 1;
            // 關鍵修正：確保索引在 [0, n-1] 範圍內
            if (index >= 0 && index < n) {
                if (nums[index] < 0) {
                    ans.push_back(absN);
                } else {
                    nums[index] *= -1;
                }
            }
        }
        
        return ans;
    }
};
