/**
 * 題目：3300. Minimum Element After Replacement With Digit Sum
 * 難度：簡單 (Easy)
 * 描述：將陣列中的每個整數替換為其數位之和，並返回替換後陣列中的最小值。
 * * 優化重點：
 * 1. 數位拆解：利用 `% 10` 和 `/ 10` 依序提取每個數位並加總。
 * 2. 效率：對每個數字進行 O(log M) 的運算（M 為數字大小），整體複雜度為 O(N * log M)。
 */

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minElement(std::vector<int>& nums) {
        int min_val = INT_MAX;
        
        for (int num : nums) {
            int sum = 0;
            int temp = num;
            // 計算數位之和
            while (temp > 0) {
                sum += (temp % 10);
                temp /= 10;
            }
            // 更新最小值
            min_val = std::min(min_val, sum);
        }
        
        return min_val;
    }
};
