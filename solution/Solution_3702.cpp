/**
 * 題目：3702. Longest Subsequence With Non-Zero Bitwise XOR
 * 描述：給定一個整數陣列 nums，找出一個最長的子序列 (Subsequence)，
 *       使得該子序列所有元素的按位與 XOR 總和不為 0。回傳該子序列的最大長度。
 * 
 * 解法思路：
 * 1. 檢查極端情況：如果整個陣列的所有元素全部都是 0，那麼無論選取哪個子序列，
 *    XOR 總和永遠是 0，此時無解，回傳 0。
 * 2. 計算全體 XOR 總和 (mask)：
 *    - 如果 mask != 0，代表整條陣列原本的 XOR 總和就不為 0，
 *      因此我們可以直接選取「全部元素」，長度即為 nums.size()。
 *    - 如果 mask == 0，代表整條陣列的 XOR 總和為 0。這時我們只需要隨便拔掉一個元素（例如任何一個非 0 元素或陣列中其中一個數），
 *      就能破壞平衡，讓剩餘的 XOR 總和變成非 0。此時最大長度為 nums.size() - 1。
 */

class Solution {
private:
    bool isAllZero(const std::vector<int>& nums) {
        return std::all_of(nums.begin(), nums.end(), [](int x) { return x == 0; });
    }

public:
    int longestSubsequence(std::vector<int>& nums) {
        // 1. 若全數為 0，無法組成非零 XOR 的子序列，回傳 0
        if (isAllZero(nums)) {
            return 0;
        }
        
        int mask = 0;
        for (int num : nums) {
            mask ^= num;
        }
        
        // 2. 若全體 XOR 不為 0，直接拿全部；若為 0，拿掉一個元素即可
        return (mask != 0) ? nums.size() : nums.size() - 1;
    }
};
