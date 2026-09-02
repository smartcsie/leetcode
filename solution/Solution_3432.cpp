/**
 * 題目：3432. Count Partitions with Even Sum Difference
 * 難度：簡單 (Easy)
 * 描述：計算陣列分割為兩部分 (left, right) 的次數，使得兩部分和的差為偶數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用前綴和 (Prefix Sum) 快速獲取左半部分的總和。
 * 2. 總和 `totalSum` 減去 `leftSum` 即為 `rightSum`。
 * 3. 檢查 `abs(leftSum - rightSum)` 是否為偶數。
 * 4. 注意：題目要求分割成非空兩部分，因此迴圈範圍為 0 到 n-2。
 */

class Solution {
public:
    int countPartitions(std::vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end(), 0);
        return (sum & 1) ? 0 : nums.size() - 1;
    }
};
