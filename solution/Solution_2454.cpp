/**
 * 題目：2425. Bitwise XOR of All Pairings (所有配對的位元異或)
 * 難度：中等 (Medium)
 * 描述：計算 nums1 與 nums2 所有元素兩兩配對後的 XOR 之和。
 * * 時間複雜度：O(N + M)，遍歷兩個陣列各一次。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 簡化邏輯：不需要顯式寫出所有分支，直接根據長度奇偶性累加 XOR 結果。
 */

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int xor1 = 0;
        int xor2 = 0;
        if((m & 1) == 1) {
            for(const int& num : nums2) xor2 ^= num;
        }
        if((n & 1) == 1) {
            for(const int& num : nums1) xor1 ^= num;
        }
        return xor1 ^ xor2;
    }
};
