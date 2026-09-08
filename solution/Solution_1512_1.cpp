/**
 * 題目：1512. Number of Good Pairs
 * 難度：簡單 (Easy)
 * 描述：計算陣列中 nums[i] == nums[j] 且 i < j 的配對數量。
 *
 * 時間複雜度：O(N^2)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （暴力雙層迴圈）：
 * 枚舉所有 (i, j) 配對，檢查是否相等，時間 O(N²)，可用 hash map 優化到 O(N)。
 */
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] == nums[j]) ans++;
            }
        }
        return ans;
    }
};