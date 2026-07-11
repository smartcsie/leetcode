/**
 * 題目：Minimum Capacity Box
 * 難度：簡單 (Easy)
 * 描述：在 capacity 陣列中找出一個大於等於 itemSize 且容量值最小的盒子的索引。
 * * 優化重點：
 * 1. 線性搜尋：遍歷一次陣列，時間複雜度 O(N)。
 * 2. 狀態維護：僅需記錄當前的最小容量值與其索引。
 */

class Solution {
public:
    int minimumIndex(std::vector<int>& capacity, int itemSize) {
        int min_val = INT_MAX;
        int min_index = -1;
        
        for (int i = 0; i < capacity.size(); i++) {
            // 檢查是否足夠放入物品
            if (capacity[i] >= itemSize) {
                // 更新找到的最小值及其索引
                if (capacity[i] < min_val) {
                    min_val = capacity[i];
                    min_index = i;
                }
            }
        }
        return min_index;
    }
};
