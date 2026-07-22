/**
 * 題目：2956. Find Common Elements Between Two Arrays
 * 描述：給定兩個整數陣列 nums1 和 nums2，計算：
 *       - answer1：nums1 中有多少個索引 i，其元素 nums1[i] 存在於 nums2 中。
 *       - answer2：nums2 中有多少個索引 i，其元素 nums2[i] 存在於 nums1 中。
 *       返回包含 [answer1, answer2] 的結果陣列。
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
        std::vector<int> ans(2, 0);
        
        // 宣告 bitset 來記錄數值是否存在（支援 0 到 100 的範圍）
        std::bitset<101> bits1;
        std::bitset<101> bits2;
        
        // 1. 紀錄各陣列擁有的數值
        for (const int& num : nums1) {
            bits1.set(num);
        }
        for (const int& num : nums2) {
            bits2.set(num);
        }
        
        // 2. 計算 nums1 中有多少元素存在於 nums2
        for (const int& num : nums1) {
            if (bits2.test(num)) {
                ans[0]++;
            }
        }
        
        // 3. 計算 nums2 中有多少元素存在於 nums1
        for (const int& num : nums2) {
            if (bits1.test(num)) {
                ans[1]++;
            }
        }
        
        return ans;
    }
};
