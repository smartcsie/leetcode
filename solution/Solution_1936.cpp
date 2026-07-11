/**
 * 題目：1936. Add Minimum Number of Rungs
 * 難度：中等 (Medium)
 * 描述：在給定的梯級中插入最少數量，使每兩階之間距離不超過 dist。
 * * 優化重點：
 * 1. 整數運算：避免使用浮點數 ceil，利用 (diff - 1) / dist 實現向上取整。
 * 2. 空間優化：無需額外陣列，直接在原陣列遍歷。
 */

class Solution {
public:
    int addRungs(std::vector<int>& rungs, int dist) {
        int count = 0;
        int current_pos = 0; // 起始點從地面 0 開始
        
        for (int rung : rungs) {
            int diff = rung - current_pos;
            if (diff > dist) {
                // (diff - 1) / dist 為需要的補梯數量
                count += (diff - 1) / dist;
            }
            current_pos = rung;
        }
        
        return count;
    }
};
