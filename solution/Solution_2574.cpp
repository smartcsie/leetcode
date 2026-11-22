/**
 * 題目：2574. Left and Right Sum Differences
 * 難度：簡單 (Easy)
 * 描述：計算陣列中每個位置的左右前綴和差的絕對值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 1, prefix = nums[0]; i < n ; i++) {
            ans[i] += prefix;
            prefix += nums[i];
        }
        for(int i = n - 2,  suffix = nums[n - 1]; i >= 0 ; i--) {
            ans[i] -= suffix;
            suffix += nums[i];
        }
        for(int& x : ans) x = abs(x);
        return ans;
    }
};