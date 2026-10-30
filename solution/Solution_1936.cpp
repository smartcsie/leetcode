/**
 * 題目：1936. Add Minimum Number of Rungs
 * 難度：中等 (Medium)
 * 描述：在給定的梯級中插入最少數量，使每兩階之間距離不超過 dist。
 * 優化重點：
 * 1. 整數運算：避免使用浮點數 ceil，利用 (diff - 1) / dist 實現向上取整。
 * 2. 空間優化：無需額外陣列，直接在原陣列遍歷。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int added = 0;
        int cur = 0;
        for(const int& rung : rungs) {
            int diff = rung - cur;
            if(diff > dist) added += (diff + dist - 1) / dist - 1;
            cur = rung;
        }
        return added;
    }
};
