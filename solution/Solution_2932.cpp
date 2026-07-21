/**
 * 題目：2932. Maximum Strong Pair XOR I
 * 描述：給定一個正整數陣列 nums。如果兩個數字 x 和 y 滿足 |x - y| <= min(x, y)，
 *       則稱它們為一個「強數對 (Strong Pair)」。
 *       請找出所有強數對中，按位與 XOR 運算的最大值。
 * 
 * 解法思路：
 * 1. 排序：先將 nums 進行升冪排序。排序後對於任意數字 x = nums[i] 與 y = nums[j]（其中 i <= j），
 *    因為 x 是較小者，條件 |x - y| <= min(x, y) 可以簡化成 y - x <= x（即 y <= 2x）。
 * 2. 暴力雙迴圈枚舉：利用雙重迴圈遍歷所有可能的 pair (nums[i], nums[j])。
 * 3. 條件篩選與更新：
 *    - 若滿足 nums[j] - nums[i] <= nums[i]，則計算 XOR 並更新全域最大值 xorMax。
 *    - 若不滿足（由於陣列已排序，當前 i 的後續 j 會更大），可以直接提早結束內層迴圈（Optimization）。
 */

class Solution {
public:
    int maximumStrongPairXor(std::vector<int>& nums) {
        int n = nums.size();
        int xorMax = 0;
        // 1. 排序陣列，方便後續判斷大小關係
        std::sort(nums.begin(), nums.end());
        // 2. 雙重迴圈枚舉所有數對
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i; j < n; j++) { // 可以從 i 開始或 i+1 開始
                int y = nums[j];
                
                // 強數對條件：|x - y| <= min(x, y)
                // 經過排序後 x <= y，所以等價於 y - x <= x (即 y <= 2 * x)
                if (std::abs(x - y) <= x) {
                    xorMax = std::max(xorMax, x ^ y);
                } else {
                    // 若 y 超過 2 * x，因為後面的元素更大，直接跳出內層迴圈
                    break; 
                }
            }
        }
        return xorMax;
    }
};
