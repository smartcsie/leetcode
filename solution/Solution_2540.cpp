/**
 * 題目：2540. Minimum Common Value (最小共同值)
 * 難度：簡單 (Easy)
 * 描述：在兩個已排序的陣列中，找出最小的共同整數。
 * * 時間複雜度：O(N + M) - N 和 M 為兩個陣列的長度。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 使用雙指針 i 與 j 分別遍歷兩個陣列。
 * 2. 由於陣列已排序，比較當前指針指向的值：
 * - 若相等即為答案（第一個找到的必為最小）。
 * - 若 nums1[i] < nums2[j]，則 i++ 移動較小值指針。
 * - 反之則 j++。
 */

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // 使用 size_t 與陣列的 size() 型別一致，避免編譯器潛在警告
        size_t i = 0, j = 0;
        const size_t n1 = nums1.size();
        const size_t n2 = nums2.size();
        
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return -1;
    }
};
