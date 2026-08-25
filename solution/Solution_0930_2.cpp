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