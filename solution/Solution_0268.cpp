/**
 * 註解：待補充
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)

 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return (1 + n) * n / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
