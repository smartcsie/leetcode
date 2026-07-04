/**
 * 題目：961. N-Repeated Element in Size 2N Array
 * 難度：簡單 (Easy)
 * 描述：在 2N 長度的陣列中找出出現 N 次的元素。
 * * 優化重點：
 * 1. 空間複雜度 O(1)：移除 unordered_set，不再需要額外記憶體。
 * 2. 機率/數學性質：因為重複元素出現 N 次（佔總長度的一半），它們很有可能在短距離內重複。
 */

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        // 數學性質：重複元素出現 N 次，若隨機抽樣或檢查小距離，
        // 很快就能發現重複。此處檢查距離 1, 2, 3 的位置。
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && nums[i] == nums[i + 1]) return nums[i];
            if (i + 2 < n && nums[i] == nums[i + 2]) return nums[i];
            if (i + 3 < n && nums[i] == nums[i + 3]) return nums[i];
        }
        return -1;
    }
};
