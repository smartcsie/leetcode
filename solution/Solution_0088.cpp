/**
 * 題目：88. Merge Sorted Array (合併兩個有序陣列)
 * 難度：簡單 (Easy)
 * 描述：將 nums2 合併到 nums1 中，nums1 有足夠空間。
 * * 時間複雜度：O(m + n)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // 指向 nums1 的有效元素末端
        int j = n - 1;       // 指向 nums2 的末端
        int last = m + n - 1; // 指向 nums1 的最終空間末端

        // 從後往前合併
        while (j >= 0) {
            // 若 i < 0，代表 nums1 有效元素已全處理完，直接把 nums2 剩下的塞進去
            // 若 nums1[i] > nums2[j]，則將 nums1[i] 往後移
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[last--] = nums1[i--];
            } else {
                nums1[last--] = nums2[j--];
            }
        }
    }
};
