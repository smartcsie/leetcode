/**
 * 題目：2395. Find Subarrays With Equal Sum (找出和相等的子陣列)
 * 難度：簡單 (Easy)
 * 描述：檢查陣列中是否存在兩個長度為 2 的子陣列，其元素和相等。
 * * 時間複雜度：O(N)，僅需一次遍歷。
 * 空間複雜度：O(N)，雜湊表最多存放 N-1 個和。
 * * 優化思路：
 * 1. 記憶體預留：使用 `reserve` 預先配置空間，提升雜湊表運算效率。
 * 2. 減少條件分支：利用 `unordered_set::insert` 的回傳值特性，進一步簡化判斷。
 */

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool findSubarrays(std::vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        std::unordered_set<int> sums;
        // 預留 N-1 個空間
        sums.reserve(nums.size() - 1);
        
        for (size_t i = 1; i < nums.size(); ++i) {
            int current_sum = nums[i] + nums[i - 1];
            
            // insert().second 會回傳一個 bool：
            // true 表示成功插入 (即之前沒出現過)
            // false 表示已存在 (重複)
            if (!sums.insert(current_sum).second) {
                return true;
            }
        }
        
        return false;
    }
};
