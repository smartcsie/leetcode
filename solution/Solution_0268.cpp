/**
 * 題目：268. Missing Number
 * 難度：簡單 (Easy)
 * 描述：給定一個包含 0 到 n 的陣列，找出缺少的那個數字。
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
