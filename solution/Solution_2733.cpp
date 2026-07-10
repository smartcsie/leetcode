/**
 * 題目：2733. Neither Minimum nor Maximum
 * 難度：簡單 (Easy)
 * 描述：在陣列中返回任一非最大值且非最小值的數字。
 * * 優化重點：
 * 1. 效能優化：使用 minmax_element 僅需 O(N) 即可獲取極值範圍。
 * 2. 空間節省：未申請任何額外容器，空間複雜度為 O(1)。
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    int findNonMinOrMax(std::vector<int>& nums) {
        // 若陣列元素不足 3 個，無法存在既非最大也非最小的數字
        if (nums.size() <= 2) return -1;
        
        // 快速獲取最小值與最大值的迭代器
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;
        
        // 尋找符合條件的數字
        for (const int& num : nums) {
            if (num != min_val && num != max_val) {
                return num;
            }
        }
        
        return -1;
    }
};
