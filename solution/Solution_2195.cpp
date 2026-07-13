/**
 * 題目：2195. Append K Integers With Minimal Sum
 * 難度：中等 (Medium)
 * 描述：在陣列中加入 K 個獨一無二的正整數，使得這些數的和最小。
 * * 優化重點：
 * 1. 空間預處理：透過排序與去重 (unique)，簡化搜尋範圍。
 * 2. 數學公式：利用 X*(X+1)/2 求和，避免迴圈累加導致超時。
 */

class Solution {
public:
    long long minimalKSum(std::vector<int>& nums, int k) {
        std::ranges::sort(nums);
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        // 二分搜尋：找尋第 K 個「不在 nums 裡」的數 X
        long long lo = 1, hi = 2e9 + 7; // 設定足夠大的上界
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            // 計算 [1, mid] 中有多少個「不存在於 nums 的數」
            long long blocked = std::upper_bound(nums.begin(), nums.end(), mid) - nums.begin();
            if (mid - blocked >= k) hi = mid;
            else lo = mid + 1;
        }

        long long X = lo;
        // 計算總和：[1, X] 總和 - (nums 中 <= X 的元素和)
        long long sum = X * (X + 1) / 2;
        long long blockedSum = 0;
        for (int x : nums) {
            if (x <= X) blockedSum += x;
            else break;
        }

        return sum - blockedSum;
    }
};
