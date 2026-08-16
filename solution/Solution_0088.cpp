/**
 * 題目：88. Merge Sorted Array (合併兩個有序陣列)
 * 難度：簡單 (Easy)
 * 描述：將 nums2 合併到 nums1 中，nums1 有足夠空間。
 *
 * 時間複雜度：O(M+N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(i >= 0 ) nums1[k--] = nums1[i--];
        while(j >= 0) nums1[k--] = nums2[j--];
    }
};
