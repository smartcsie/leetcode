/**
 * 題目：645. Set Mismatch (錯誤的集合)
 * 難度：簡單 (Easy)
 * 描述：在 1 到 n 的陣列中找出重複的數字以及缺失的數字。
 * * 時間複雜度：O(N) - 兩次線性掃描。
 * 空間複雜度：O(1) - 原地操作陣列。
 * * 解法思路：
 * 1. 遍歷陣列：將數值 `abs(val)` 對應的索引位置乘以 `-1`。
 * 2. 若發現該索引位置的值已經是負數，說明 `abs(val)` 重複出現了。
 * 3. 再次遍歷陣列：找出值仍為正數的索引，該索引+1 即為缺失值。
 */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1, miss = -1;
        
        // 標記出現過的數字
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                dup = abs(num);
            } else {
                nums[idx] *= -1;
            }
        }
        
        // 找出未被標記的數字 (即缺失值)
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                miss = i + 1;
                break; // 找到後即可跳出，提高效能
            }
        }
        
        return {dup, miss};
    }
};
