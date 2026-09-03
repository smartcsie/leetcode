/**
 * 題目：4. Median of Two Sorted Arrays
 * 難度：困難 (Hard)
 * 分類主題：binary-search
 * 描述：給定兩個已排序的陣列 nums1、nums2，求把它們合併後的中位數，
 * 要求時間複雜度是 O(log(m+n))。
 *
 * 時間複雜度：O(log(min(M,N)))
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （二分搜「切割點」，這是這題真正被設計出來考的最佳解，跟雙指標
 * 合併版是完全不同等級的技巧——這題不是在找某個值，也不是找邊界，
 * 而是在找一個「讓兩個陣列都被切成左右兩半、左半邊剛好湊出中位數
 * 所需元素數」的切法）：
 * 1. **保證在較短的陣列上二分搜**：如果 `nums1` 比 `nums2` 長，直接
 *    交換角色遞迴呼叫。這是為了保證複雜度是 `O(log(min(M,N)))`，
 *    而不是 `O(log(max(M,N)))`。
 * 2. **切割點的定義**：在 `nums1` 上選一個切割點 `i`（左邊放 i 個
 *    元素），對應在 `nums2` 上選切割點 `j = halfLen - i`（左邊放
 *    j 個元素），讓「兩邊左半部的元素總數」剛好等於
 *    `(m+n+1)/2`——這樣不管總長度是奇數還偶數，都能用同一套邏輯
 *    算出中位數（奇數時左半邊比右半邊多一個，偶數時左右相等）。
 * 3. **合法切割點的判斷條件**：`maxLeft1 <= minRight2` 且
 *    `maxLeft2 <= minRight1`——白話講就是「nums1 左半邊的最大值不能
 *    超過 nums2 右半邊的最小值，反之亦然」，滿足這個條件，代表整個
 *    切割點是正確的，「左半邊所有元素」都小於等於「右半邊所有元素」。
 * 4. **二分搜的方向**：如果 `maxLeft1 > minRight2`，代表 `nums1`
 *    切太靠右了（左半邊塞了太大的值），要把 `i` 往左移
 *    （`hi = i - 1`）；否則代表切太靠左了，要把 `i` 往右移
 *    （`lo = i + 1`）。
 * 5. **邊界哨兵值**：當切割點在陣列的最左邊（`i==0`）或最右邊
 *    （`i==m`）時，代表那一側沒有對應的元素，用 `INT_MIN`／`INT_MAX`
 *    當作哨兵，讓「不存在的元素」在比較大小時永遠不會被誤判成
 *    真正的最大/最小值。
 * 6. 找到合法切割點後，答案是：
 *    - 總長度是奇數：`max(maxLeft1, maxLeft2)`（左半邊最大值就是
 *      中位數）。
 *    - 總長度是偶數：`(max(maxLeft1,maxLeft2) + min(minRight1,minRight2)) / 2.0`
 *      （左半邊最大值跟右半邊最小值的平均）。
 * 7. 跟雙指標合併版（O(m+n)）的差異：這版才是題目真正要考的最佳解，
 *    邊界處理（哨兵值、切割點範圍）是這題公認最容易出錯的地方，建議
 *    跟雙指標版並列收錄，體會「暴力解法直覺易寫 vs 最佳解法需要精心
 *    設計邊界」的差距。
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int halfLen = (m + n + 1) / 2;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = halfLen - i;
            int maxLeft1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            int maxLeft2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                }
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else if (maxLeft1 > minRight2) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        return -1.0;
    }
};