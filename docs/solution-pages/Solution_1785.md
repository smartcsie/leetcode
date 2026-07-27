# Solution_1785

```cpp
/**
 * 題目：1785. Minimum Elements to Add to Form a Given Sum
 * 難度：中等 (Medium)
 * 描述：在陣列中加入最少個數的元素（限制絕對值 <= limit），使其總和等於 goal。
 * 優化重點：
 * 1. 累加器：利用 std::accumulate 計算總和。
 * 2. 數學公式：利用整數除法避開浮點數計算，確保效能與精度。
 *
 * 時間複雜度：O(N) - 計算總和與目標差距，除以 limit 取上整。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    int minElements(std::vector<int>& nums, int limit, int goal) {
        // 使用 long long 以防止數值加總時溢位
        long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long diff = std::abs(sum - (long long)goal);
        
        // 數學上的 ceil(diff / limit)
        // 在整數除法中即為 (diff + limit - 1) / limit
        return (diff + limit - 1) / limit;
    }
};

```
