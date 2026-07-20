/**
 * 題目：2859. Sum of Values at Indices With K Set Bits
 * 描述：給定一個下標從 0 開始的整數陣列 nums 和一個整數 k。
 *       請返回 nums 中滿足其索引的二進位表示中恰好有 k 個設定位（即 1 的個數）的元素總和。
 * 
 * 解法思路：
 * 1. 遍歷陣列的每個索引 i（從 0 到 nums.size() - 1）。
 * 2. 使用 GCC 內建函數 __builtin_popcount(i) 計算索引 i 的二進位中有多少個 1。
 * 3. 若計數等於 k，則將該索引對應的 nums[i] 累加到總和中。
 */

class Solution {
public:
    int sumIndicesWithKSetBits(std::vector<int>& nums, int k) {
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // __builtin_popcount 用於計算整數二進位中 1 的個數
            if (static_cast<int>(__builtin_popcount(i)) == k) {
                sum += nums[i];
            }
        }
        
        return sum;
    }
};
