/**
 * 題目：2605. Form Smallest Number From Two Digit Arrays
 * 難度：簡單 (Easy)
 * 描述：從兩個陣列各取一個數字，組成最小的兩位數或一位數。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （bitset 版）：
 * 用 bitset<10> 記錄兩陣列出現的數字，AND 找公共最小值，無公共值則取各自最小組合。
 */
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        bitset<10> bits1;
        bitset<10> bits2;
        for(const int& num: nums1) bits1.set(num);
        for(const int& num: nums2) bits2.set(num);
        bitset<10> bits3 = bits1 & bits2;
        if(bits3.count()) {
            return static_cast<int>(bits3._Find_first());
        }
        int min1 = static_cast<int>(bits1._Find_first());
        int min2 = static_cast<int>(bits2._Find_first());
        return min1 > min2 ? min2 * 10 + min1 : min1 * 10 + min2;

    }
};