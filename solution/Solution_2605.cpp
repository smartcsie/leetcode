/**
 * 題目：2605. Form Smallest Number From Two Digit Arrays
 * 難度：簡單 (Easy)
 * 描述：從 nums1 與 nums2 中組成最小整數，使其至少一位數字同時存在於兩陣列中。
 *
 * 核心概念：
 * - 利用 Bitmask 將「數字 0~9 是否存在」壓縮為整數的位元表示。
 * - 若存在共同數字，答案為共同數字中的最小值（單一位數）。
 * - 若無共同數字，答案為兩陣列各自最小值組成的兩位數（較小者置於十位）。
 * - 利用 __builtin_ctz 快速取得最低有效位元（即最小的數字）。
 */
class Solution {
public:
    int minNumber(vector& nums1, vector& nums2) {
        int mask1 = 0, mask2 = 0;
        for(const int& num : nums1) mask1 |= 1 << num;
        for(const int& num : nums2) mask2 |= 1 << num;
        if(mask1 & mask2) return __builtin_ctz(mask1 & mask2);
        int min1 = __builtin_ctz(mask1);
        int min2 = __builtin_ctz(mask2);
        return (min1 > min2) ? min2 * 10 + min1 : min1 * 10 + min2;
    }
};
