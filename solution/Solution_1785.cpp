/**
 * 題目：1785. Minimum Elements to Add to Form a Given Sum
 * 難度：中等 (Medium)
 * 描述：在陣列中加入最少個數的元素（限制絕對值 <= limit），使其總和等於 goal。
 * 優化重點：
 * 1. 累加器：利用 std::accumulate 計算總和。
 * 2. 數學公式：利用整數除法避開浮點數計算，確保效能與精度。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int minElements(std::vector<int>& nums, int limit, int goal) {
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        return (abs(sum - goal) + limit - 1)/ limit;
    }
};
