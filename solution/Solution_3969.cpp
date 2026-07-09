/**
 * 題目：3969. Valid Subarrays With Matching Sum Digits I
 * 難度：簡單 (Easy)
 * 描述：找出所有子陣列的和，若其和滿足條件（最後一位為x 且 最高位為x），則計數。
 * * 優化重點：
 * 1. 累加法：內部迴圈透過 `sum += nums[right]` 保持 O(N^2) 複雜度。
 * 2. 數位拆解：動態檢查和的性質，無需額外空間。
 */

class Solution {
public:
    int countValidSubarrays(std::vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;
        
        // 枚舉所有可能的子陣列起始點
        for (int left = 0; left < n; left++) {
            long long current_sum = 0;
            // 枚舉終點並累加和
            for (int right = left; right < n; right++) {
                current_sum += nums[right];
                
                // 條件 1: 和的最後一位等於 x
                if (current_sum % 10 != x) continue;
                
                // 條件 2: 和的最高位等於 x
                long long temp = current_sum;
                while (temp >= 10) {
                    temp /= 10;
                }
                
                if (temp == x) {
                    count++;
                }
            }
        }
        return count;
    }
};
