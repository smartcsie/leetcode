/**
 * 題目：523. Continuous Subarray Sum
 * 難度：中等 (Medium)
 * 描述：判斷是否存在長度至少為 2 的連續子陣列，其元素之和為 k 的倍數。
 * 
 * 解法思路：
 * 1. 同餘定理：若 (sum[j] - sum[i]) % k == 0，則 sum[j] % k == sum[i] % k。
 * 2. 使用 unordered_map 紀錄「前綴和餘數」第一次出現的索引。
 * 3. 若再次遇到相同的餘數，檢查索引距離是否大於 1，即可確保子陣列長度 >= 2。
 * 4. 必須處理餘數為負數的情況 (C++ 的 % 運算對於負數結果為負)。
 */

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        // 初始狀態 {0, -1} 是為了處理從索引 0 開始的子陣列
        std::unordered_map<int, int> reminder{{0, -1}};
        int prefix = 0;
        
        for(int i = 0 ; i < n ; i++) {
            prefix += nums[i];
            // 確保餘數為正數 (0 <= prefix < k)
            prefix = ((prefix % k) + k) % k;
            
            if (reminder.count(prefix)) {
                // 若餘數已存在，檢查長度是否 >= 2
                if ((i - reminder[prefix]) > 1) {
                    return true;
                }
            } else {
                // 僅在第一次出現時記錄，以保證距離最大化
                reminder[prefix] = i;
            }
        }
        return false;
    }
};
