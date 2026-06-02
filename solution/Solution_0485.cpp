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
        int max_count = 0;
        int current_count = 0;
        
        // 使用範圍迴圈 (Range-based for loop) 提升效能與可讀性
        for (const int num : nums) {
            if (num == 1) {
                current_count++;
            } else {
                // 將最大值更新移至重置前，確保連續 1 在陣列末尾時也能正確計算
                max_count = max(max_count, current_count);
                current_count = 0;
            }
        }
        
        // 最後一次檢查：若陣列以 1 結尾，需要補上最後的比較
        return max(max_count, current_count);
    }
};
