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
                int sum = accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            int right_sum = sum - left_sum - cur;
            nums[i] = abs(left_sum - right_sum);
            left_sum += cur;
        }
        return nums;
    }
};