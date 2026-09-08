/**
 * 題目：930. Binary Subarrays With Sum
 * 難度：中等 (Medium)
 * 描述：計算二進位陣列中和等於 goal 的子陣列個數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （滑動視窗差分，atMost 技巧）：
 * 恰好等於 goal = 至多 goal 個 - 至多 goal-1 個，用滑動視窗計算至多 k 個 1 的子陣列數。
 */
class Solution {
private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0, sum = 0, count = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1); // 以 right 為結尾、合乎條件的子陣列數量
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 剛好等於 goal 的數量 = 至多 goal 個 - 至多 (goal - 1) 個
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};