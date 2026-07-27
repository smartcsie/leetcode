/**
 * 題目：643. Maximum Average Subarray I (子陣列最大平均數 I)
 * 難度：簡單 (Easy)
 * 描述：找出長度為 k 的連續子陣列，使其平均數最大。
 * * 時間複雜度：O(N) - 僅遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 使用 long long 儲存 windowSum，防止整數溢位。
 * 2. 維護長度為 k 的滑動視窗，每次移動時「減去出去的元素，加上進來的元素」。
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = accumulate(nums.begin(), nums.begin()+k, 0);
        int maxSum = windowSum;
        for(int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }
        return static_cast<double>(maxSum)/ k;
    }
};
