/**
 * 題目：2006. Count Number of Pairs With Absolute Difference K
 * 難度：簡單 (Easy)
 * 描述：計算陣列中絕對差等於 k 的配對數量。
 *
 * 時間複雜度：O(N^2)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （暴力雙層迴圈）：
 * 枚舉所有 (i, j) 配對，檢查 abs(nums[i] - nums[j]) == k。
 */
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(abs(nums[i] - nums[j]) == k) ans++;
            }
        }
        return ans;
    }
};
