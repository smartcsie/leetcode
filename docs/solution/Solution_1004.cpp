/**
 * 題目：1004. Max Consecutive Ones III (最大連續 1 的個數 III)
 * 難度：中等 (Medium)
 * 描述：在陣列中最多可以翻轉 k 個 0，找出最長的連續 1 序列。
 * * 時間複雜度：O(N) - 每個元素最多被 left 和 right 指針各訪問一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 1. 視窗 [left, right] 內維護翻轉過的 0 的個數。
 * 2. 若視窗內 0 的數量超過 k，則收縮 left 指針直到視窗再次合法。
 * 3. 視窗長度 (right - left + 1) 即為當前合法的連續序列長度。
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, count_zeros = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // 如果遇到 0，消耗一個翻轉配額
            if (nums[right] == 0) count_zeros++;
            
            // 當 0 的數量超過 k，收縮左邊界
            if (count_zeros > k) {
                if (nums[left] == 0) count_zeros--;
                left++;
            }
        }
        
        // 最終窗口大小即為最長長度 (此為簡化寫法，不需要在迴圈內頻繁呼叫 max)
        return nums.size() - left;
    }
};
