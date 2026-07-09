/**
 * 題目：1094. Car Pooling
 * 難度：中等 (Medium)
 * 描述：判斷車輛在行駛過程中，乘客人數是否曾超過容量限制。
 * * 優化重點：
 * 1. 差分陣列：將 O(N * Range) 的複雜度降至 O(N + Range)。
 * 2. 邊界處理：利用位置 0-1000 的固定範圍，避免了動態分配空間的開銷。
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for(const vector<int>& trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }
        int curPeople = 0;
        for(int i = 0; i <= 1000; i++) {
            curPeople += diff[i];
            if(curPeople > capacity) return false;
        }
        return true;
    }
};
