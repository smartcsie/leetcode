/**
 * 題目：2574. Left and Right Sum Differences
 * 難度：簡單 (Easy)
 * 描述：計算陣列中每個位置的左右前綴和差的絕對值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int left = prefix[i];
            int right = prefix[n] - prefix[i + 1];
            res[i] = abs(right - left);
        }
        return res;
    }
};
