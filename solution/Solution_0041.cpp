class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // 當 nums[i] 是正數、且在範圍內、且它不在正確的位置上時，進行交換
            // 使用 while 是因為交換過來的新數字可能也需要被換走
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // 最後檢查誰不在位置上
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        
        // 如果 1~n 都在位置上，那缺的就是 n+1
        return n + 1;
    }
};