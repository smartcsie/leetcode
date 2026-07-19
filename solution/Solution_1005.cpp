/**
 * 題目：1005. Maximize Sum Of Array After K Negations
 * 描述：在進行 K 次翻轉（將數字變為 -num）後，求陣列元素的最大和。
 * 
 * 解法思路：
 * 1. 排序：將陣列由小到大排序，確保負數在前。
 * 2. 貪心翻轉負數：遍歷陣列，遇到負數就翻轉，直到 k 為 0 或無負數為止。
 * 3. 處理剩餘 K：若 k 為奇數，需翻轉當前陣列中絕對值最小的數（即當前陣列的 min）。
 * 4. 計算總和：使用 std::accumulate 計算最終總和。
 */

class Solution {
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        // 1. 排序以便從最小的負數開始處理
        std::sort(nums.begin(), nums.end());
        // 2. 優先將負數轉為正數
        for (int& num : nums) {
            if (num > 0 || k == 0) break;
            num *= -1;
            k--;
        }
        // 3. 計算總和，並處理剩餘的 k：
        // 若 k 為奇數，需要翻轉一次當前陣列中的最小值。
        // 因為已經翻轉過，所以減去 2 倍的最小值（num - (num * -1) = 2 * num）。
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int minVal = *std::min_element(nums.begin(), nums.end());
        return sum - (k % 2) * minVal * 2;
    }
};
