/**
 * 題目：1550. Three Consecutive Odds (三個連續奇數)
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否存在連續的三個奇數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

#include <vector>

class Solution {
public:
    bool threeConsecutiveOdds(const std::vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n - 2; i++) {
            if( (arr[i] & 1) && (arr[i + 1] & 1) &&  (arr[i + 2] & 1)) return true;
        }
        return false;
    }
};
