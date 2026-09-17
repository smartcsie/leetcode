/**
 * 題目：2733. Neither Minimum nor Maximum
 * 難度：簡單 (Easy)
 * 描述：在陣列中返回任一非最大值且非最小值的數字。
 * 優化重點：
 * 1. 效能優化：使用 minmax_element 僅需 O(N) 即可獲取極值範圍。
 * 2. 空間節省：未申請任何額外容器，空間複雜度為 O(1)。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    int findNonMinOrMax(std::vector<int>& nums) {
        if(nums.size() <= 2) return -1;
        auto it = nums.begin() + 1;
        nth_element(nums.begin(), it, nums.begin() + 3);
        return *it;
    }
};
