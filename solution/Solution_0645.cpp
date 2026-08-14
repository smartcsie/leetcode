/**
 * 題目：645. Set Mismatch (錯誤的集合)
 * 難度：簡單 (Easy)
 * 描述：在 1 到 n 的陣列中找出重複的數字以及缺失的數字。
 *
 * 時間複雜度：O(N) - 兩次線性掃描。
 * 空間複雜度：O(1) - 原地操作陣列。
 *
 * 解法思路：
 * 1. 遍歷陣列：將數值 `abs(val)` 對應的索引位置乘以 `-1`。
 * 2. 若發現該索引位置的值已經是負數，說明 `abs(val)` 重複出現了。
 * 3. 再次遍歷陣列：找出值仍為正數的索引，該索引+1 即為缺失值。
 */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0) nums[idx] = -nums[idx];
            else ans[0] = idx + 1;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) ans[1] = i + 1;
        }
        return ans;
    }
};
