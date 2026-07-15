/**
 * 題目：485. Max Consecutive Ones (最大連續 1 的個數)
 * 難度：簡單 (Easy)
 * 描述：在二進位陣列中，找出最大連續 1 的數量。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 1. 使用 `current_count` 記錄當前連續 1 的長度。
 * 2. 使用 `max_count` 記錄歷史最大長度。
 * 3. 遇到 1 則計數加一，遇到 0 則將 `current_count` 重置為 0。
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int ones = 0;
        for(const int& num : nums) {
            ones = (num & 1) ? ones + 1 : 0;
            max_ones = max(max_ones, ones);
        }
        return max_ones;
    }
};
