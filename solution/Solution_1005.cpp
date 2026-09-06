/**
 * 題目：1005. Maximize Sum Of Array After K Negations
 * 難度：待補充
 * 描述：在進行 K 次翻轉（將數字變為 -num）後，求陣列元素的最大和。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(1)
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
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size(); i++ , k--) {
            if(k==0 || nums[i] > 0) break;
            nums[i] = -nums[i];
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int mn = *min_element(nums.begin(), nums.end());
        return (k % 2) ? sum - 2 * mn : sum;
    }
};
