/**
 * 題目：3940. Limit Occurrences in Sorted Array (限制有序陣列中的出現次數)
 * 難度：簡單 (Easy)
 * 描述：在已排序的陣列中，移除任何出現次數超過 k 次的元素，同時保持陣列相對順序。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(1) - 原地修改陣列，無額外空間使用。
 * * 優化思路：
 * 1. 雙指標：`i` 為寫入指標，遍歷指標由 for 迴圈隱式管理。
 * 2. 歷史窗口檢查：由於陣列已排序，相同元素必然相鄰。若 `nums[i-k]` 等於當前元素，
 * 意味著該元素已出現過 k 次，因此當前元素必須被捨棄。
 */

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        // 如果 k 為 0 或更小，直接清空陣列
        if (k <= 0) {
            nums.clear();
            return nums;
        }

        int i = 0; // i 是下一個合法元素要放置的位置
        for (const int& num : nums) {
            // 如果寫入指標已達 k，且當前元素與 k 個位置前的元素相同
            // 代表此元素已經累積出現 k 次，不可再放入
            if (i >= k && nums[i - k] == num) {
                continue;
            }
            nums[i++] = num;
        }
        
        // 截斷陣列至處理後的長度
        nums.resize(i);
        return nums;
    }
};
