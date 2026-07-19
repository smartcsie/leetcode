/**
 * 題目：697. Degree of an Array
 * 描述：找出陣列的「度」(最高頻率)，並回傳具有該度數的最短連續子陣列長度。
 * 
 * 解法思路：
 * 1. 使用 unordered_map 記錄每個數字的 {出現次數, 第一次出現的索引}。
 * 2. 透過遍歷陣列，同步維護全局的 maxCount (最大度) 與 minDiffIdx (最短長度)。
 * 3. 邏輯判定：
 *    - 若出現次數超過 maxCount：更新度數，並重置最短長度。
 *    - 若出現次數等於 maxCount：比較當前區間長度與舊的最短長度，保留較小者。
 */

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        // Map 儲存結構: Key 為數字，Value 為 {出現次數, 第一次出現的索引}
        std::unordered_map<int, std::pair<int, int>> map;
        int maxCount = 0;
        int minDiffIdx = 50001; // 根據題目限制，陣列長度最大 50000
        
        for (int i = 0; i < nums.size(); i++) {
            int k = nums[i];
            
            // 記錄第一次出現的索引
            if (!map.count(k)) {
                map[k] = {1, i};
            } else {
                map[k].first++;
            }
            
            // 動態維護最大度與最短長度
            if (map[k].first > maxCount) {
                maxCount = map[k].first;
                minDiffIdx = i - map[k].second + 1;
            } else if (map[k].first == maxCount) {
                minDiffIdx = std::min(minDiffIdx, i - map[k].second + 1);
            }
        }
        
        return minDiffIdx;
    }
};
