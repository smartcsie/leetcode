/**
 * 題目：2089. Find Target Indices After Sorting Array (排序後目標值的索引)
 * 難度：簡單 (Easy)
 * 描述：排序陣列後，回傳所有目標值 target 的索引。
 * * 時間複雜度：O(N) - 僅需掃描陣列統計數量。
 * 空間複雜度：O(1) - 不考慮輸出陣列。
 * * 優化思路：
 * 1. 既然要找排序後的索引，我們不需要真正執行排序。
 * 2. 只需要統計：
 * - 小於 target 的數量 (作為起始索引)。
 * - 等於 target 的數量 (決定區間長度)。
 */

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int smaller = 0;
        
        // 單次遍歷即可統計所有資訊
        for (int num : nums) {
            if (num < target) smaller++;
            else if (num == target) count++;
        }
        
        // 直接產生連續的索引序列
        vector<int> res;
        for (int i = 0; i < count; ++i) {
            res.push_back(smaller + i);
        }
        
        return res;
    }
};
