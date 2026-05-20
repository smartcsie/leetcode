/**
 * 題目：4. Median of Two Sorted Arrays (兩個有序陣列的中位數)
 * 難度：困難 (Hard)
 * 描述：給定兩個大小分別為 m 和 n 的正序陣列 nums1 和 nums2。
 *      請找出並返回這兩個正序陣列的「中位數」。
 * 
 * 時間複雜度：O(log(min(m, n))) - 僅對較短的陣列進行二分搜尋。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * 
 * 解法思路：
 * 1. 為了優化效率，確保 nums1 是較短的陣列。
 * 2. 在 nums1 中透過二分搜尋找到一個切分點 i，則 nums2 的切分點 j 會隨之固定：
 *    j = (m + n + 1) / 2 - i
 * 3. 切分點必須滿足：
 *    nums1[i-1] <= nums2[j] 且 nums2[j-1] <= nums1[i]
 * 4. 處理邊界情況：當 i 或 j 為 0 或最大長度時，使用 -∞ 或 +∞ 代替。
 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. 確保 nums1 是較短的陣列，減少二分搜尋的次數
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int halfLen = (m + n + 1) / 2;

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = halfLen - i;

            // 取得切分點兩側的四個數值，注意邊界檢查
            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int R1 = (i == m) ? INT_MAX : nums1[i];
            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n) ? INT_MAX : nums2[j];

            // 判斷是否達成中位數條件
            if (L1 <= R2 && L2 <= R1) {
                // 找到正確切分點
                if ((m + n) % 2 == 1) {
                    // 總數為奇數，中位數是左側最大的那一個
                    return max(L1, L2);
                } else {
                    // 總數為偶數，中位數是左側最大與右側最小的平均
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                }
            } else if (L1 > R2) {
                // nums1 切分點太靠右，需要往左移
                right = i - 1;
            } else {
                // nums1 切分點太靠左，需要往右移
                left = i + 1;
            }
        }

        return 0.0;
    }
};
