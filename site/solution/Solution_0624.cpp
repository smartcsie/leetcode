/**
 * 題目：624. Maximum Distance in Arrays (陣列中的最大距離)
 * 難度：中等 (Medium)
 * 描述：有 m 個陣列，每個陣列均已升序排序。從兩個不同陣列中各取出一個元素，求其絕對差的最大值。
 * 
 * 時間複雜度：O(n) - 只需要遍歷陣列列表一次。
 * 空間複雜度：O(1) - 僅維護常數級別的極值變數。
 * 
 * 解法思路 (貪心法 + 維護極值)：
 * 1. 為了取得最大距離，我們需要維持歷史處理過的「最小值 (last_min)」與「最大值 (last_max)」。
 * 2. 遍歷每一個陣列 `arrays[i]`：
 *    - 考慮當前陣列的尾端與歷史最小值的距離：`abs(arrays[i].back() - last_min)`
 *    - 考慮當前陣列的開頭與歷史最大值的距離：`abs(arrays[i][0] - last_max)`
 *    - 用這兩者更新 `max_dist`。
 * 3. 重要的是：在更新 `max_dist` **之後**，才更新 `last_min` 和 `last_max`。
 *    這保證了計算距離的兩個數值一定來自不同的陣列。
 */

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // 初始化：使用第一個陣列的頭尾作為初始極值
        int last_min = arrays[0][0];
        int last_max = arrays[0].back();
        int max_dist = 0;
        
        // 從第二個陣列開始遍歷
        for (int i = 1; i < arrays.size(); i++) {
            // 計算當前陣列端點與先前紀錄極值的距離
            // 因為 last_min/max 來自於 arrays[0...i-1]，這保證了與當前 arrays[i] 不同源
            max_dist = max(max_dist, abs(arrays[i].back() - last_min));
            max_dist = max(max_dist, abs(last_max - arrays[i][0]));
            
            // 更新歷史極值以供後續陣列使用
            last_min = min(last_min, arrays[i][0]);
            last_max = max(last_max, arrays[i].back());
        }
        
        return max_dist;
    }
};
