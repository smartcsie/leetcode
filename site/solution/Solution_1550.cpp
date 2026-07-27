/**
 * 題目：1550. Three Consecutive Odds (三個連續奇數)
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否存在連續的三個奇數。
 * * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

#include <vector>

class Solution {
public:
    bool threeConsecutiveOdds(const std::vector<int>& arr) {
        int count = 0;
        
        for (int num : arr) {
            // 使用位元運算檢查奇數 (num & 1)
            if (num & 1) {
                count++;
                if (count == 3) return true;
            } else {
                // 遇到偶數，重置計數器
                count = 0;
            }
        }
        
        return false;
    }
};
