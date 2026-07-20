/**
 * 題目：1818. Minimum Absolute Sum Difference
 * 描述：計算兩個陣列的絕對差值總和。允許替換 nums1 中的一個元素，求替換後的最小絕對差值總和。
 * 
 * 解法思路：
 * 1. 使用 std::set 將 nums1 排序，以便後續進行二分搜尋 (Binary Search)。
 * 2. 遍歷每一個位置，計算原本的絕對差值並累積至 sumDiff。
 * 3. 利用 lower_bound 尋找 nums1 中最接近 nums2[i] 的元素（檢查其左側與右側）。
 * 4. 計算替換後能省下的最大差值 (maxDecrement)。
 * 5. 最終回傳 (sumDiff - maxDecrement) 並對 10^9 + 7 取模。
 */

class Solution {
public:
    int minAbsoluteSumDiff(std::vector<int>& nums1, std::vector<int>& nums2) {
        constexpr int kMod = 1'000'000'007;
        long sumDiff = 0;
        long maxDecrement = 0;
        // 將 nums1 放入 set 中自動排序，供二分搜尋使用
        std::set<int> sorted(nums1.begin(), nums1.end());
        for (int i = 0; i < nums1.size(); ++i) {
            const long currDiff = std::abs(nums1[i] - nums2[i]);
            sumDiff += currDiff;
            // 尋找 nums1 中第一個大於或等於 nums2[i] 的元素
            const auto it = sorted.lower_bound(nums2[i]);
            // 檢查比 nums2[i] 小或等於的最近元素 (*prev(it))
            if (it != sorted.begin()) {
                maxDecrement = std::max(maxDecrement, currDiff - std::abs(*std::prev(it) - nums2[i]));
            }
            // 檢查大於或等於 nums2[i] 的最近元素 (*it)
            if (it != sorted.end()) {
                maxDecrement = std::max(maxDecrement, currDiff - std::abs(*it - nums2[i]));
            }
        }

        return (sumDiff - maxDecrement) % kMod;
    }
};
