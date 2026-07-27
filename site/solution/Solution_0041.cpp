/**
 * 題目：41. First Missing Positive (第一個缺失的正數)
 * 難度：困難 (Hard)
 * 描述：給你一個未排序的整數陣列 nums ，請你找出其中沒有出現的最小的正整數。
 *      必須實現時間複雜度為 O(n) 並且只使用常數級別額外空間的解決方案。
 * 
 * 時間複雜度：O(n) - 雖然有巢狀 while，但每個數字最多只會被交換到正確位置一次。
 * 空間複雜度：O(1) - 直接在原陣列上進行操作。
 * 
 * 解法思路：
 * 1. 核心思想：將陣列視為一個「桶」，嘗試把數字 x 放到索引 x - 1 的位置。
 *    例如：數字 1 放到 nums[0]，數字 2 放到 nums[1]。
 * 2. 遍歷陣列，對於每個數字 nums[i]：
 *    - 如果 nums[i] 是正數 ( > 0 )
 *    - 且 nums[i] 小於等於陣列長度 ( <= n )
 *    - 且 nums[i] 尚未待在正確的位置 ( nums[i] != nums[nums[i] - 1] )
 *    - 則將 nums[i] 與其目標位置的數字交換，直到無法交換為止。
 * 3. 第二次遍歷：
 *    - 第一個滿足 nums[i] != i + 1 的索引 i，其缺失的正數就是 i + 1。
 *    - 若全部符合，則缺失的是 n + 1。
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 1. 原地置換 (Cyclic Sort)
        for (int i = 0; i < n; ++i) {
            // 使用 while 持續交換，直到當前 nums[i] 無法再被歸位
            // 條件：數字在 [1, n] 範圍內，且目標位置上的數字不等於自己
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 2. 檢查第一個位置與數值不符的點
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        // 3. 如果 1 ~ n 都出現了，則缺失的是 n + 1
        return n + 1;
    }
};
