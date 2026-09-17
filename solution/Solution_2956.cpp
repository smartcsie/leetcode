/**
 * 題目：2956. Find Common Elements Between Two Arrays
 * 難度：簡單 (Easy)
 * 描述：給定兩個整數陣列 nums1 和 nums2，計算：
 * - answer1：nums1 中有多少個索引 i，其元素 nums1[i] 存在於 nums2 中。
 * - answer2：nums2 中有多少個索引 i，其元素 nums2[i] 存在於 nums1 中。
 * 返回包含 [answer1, answer2] 的結果陣列。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 觀察到題目的數值範圍通常較小（本題測資中元素值介於 1 到 100 之間）。
 * 2. 宣告兩個 `std::bitset<101>` 分別代表 nums1 與 nums2 中出現過的數字。
 * 3. 走訪 nums1 與 nums2，將出現的數值利用 `bits.set(num)` 點亮對應的 bit。
 * 4. 再次走訪 nums1，檢查每個數字是否存在於 bits2 中（`bits2.test(num)`），若存在則 ans[0]++。
 * 5. 同理，走訪 nums2，檢查每個數字是否存在於 bits1 中，若存在則 ans[1]++。
 * 6. 返回結果向量 ans。
 */

class Solution {
public:
    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        bitset<101> seen1, seen2;
        vector<int> count(2, 0);
        for(const int& x : nums1) seen1.set(x);
        for(const int& x : nums2) seen2.set(x);
        for(const int& x : nums1) if(seen2.test(x)) count[0]++;
        for(const int& x : nums2) if(seen1.test(x)) count[1]++;
        return count;
    }
};
