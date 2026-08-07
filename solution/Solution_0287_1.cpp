class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            
            // 如果該位置已經是負數，代表這個數字之前已經被訪問過，即為重複數字
            if (nums[idx] < 0) {
                return abs(nums[i]);
            }
            
            // 將對應索引的值轉為負數，作為「已訪問」的標記
            nums[idx] = -nums[idx];
        }
        return -1;
    }
};