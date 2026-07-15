/**
 * 題目：3432. Count Partitions with Even Sum Difference
 * 難度：簡單 (Easy)
 * 描述：計算陣列分割為兩部分 (left, right) 的次數，使得兩部分和的差為偶數。
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
        int n = nums.size();
        // 前綴和陣列
        std::vector<int> prefixes(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefixes[i + 1] = prefixes[i] + nums[i];
        }
        
        int totalSum = prefixes[n];
        int count = 0;
        
        // 分割點 i 範圍為 [0, n-2]，確保左右兩部分皆非空
        for(int i = 0; i < n - 1; i++) {
            int leftSum = prefixes[i + 1];
            int rightSum = totalSum - leftSum;
            
            // 檢查差值是否為偶數：利用位元運算 !(diff & 1) 等同於 diff % 2 == 0
            if (!((std::abs(leftSum - rightSum)) & 1)) {
                count++;
            }
        }
        
        return count;
    }
};
