/**
 * 題目：3925. Concatenate Array With Reverse
 * 難度：簡單 (Easy)
 * 描述：將原陣列 nums 與其反轉後的陣列進行連接。
 * * 時間複雜度：O(N) - 遍歷陣列兩次。
 * 空間複雜度：O(N) - 用於存放結果。
 * * 優化思路：
 * 1. 預配置記憶體 (reserve)：避免在 push_back 時發生多次記憶體搬移，提升效能。
 */

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        
        // 優化：預先配置兩倍的空間，避免擴容開銷
        nums.reserve(n * 2);
        
        // 從後往前取出元素並加入到陣列末端
        for (int i = n - 1; i >= 0; i--) {
            nums.push_back(nums[i]);
        }
        
        return nums;
    }
};
