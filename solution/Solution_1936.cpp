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
    int addRungs(vector<int>& rungs, int dist) {
        int count = 0;
        count += ceil(rungs[0]/ (double)dist) - 1;
        for(int i = 0; i < rungs.size() - 1; i++) {
            int diff = rungs[i+ 1] - rungs[i];
            if(diff > dist) {
                // 數學上的 ceil(diff / dist)
                // 在整數除法中即為 (diff + dist - 1) / dist
                count += (diff + dist - 1) / dist - 1;
            }
        }
        return count;
    }
};
