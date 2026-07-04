/**
 * 題目：2965. Find Missing and Repeated Values
 * 難度：簡單 (Easy)
 * 描述：在 1 到 n^2 的範圍內，找出矩陣中重複出現與遺失的數字。
 * * 優化重點：
 * 1. 空間使用：頻率陣列大小恰好為 n^2 + 1，符合題目範圍。
 * 2. 提前中斷：利用 `repeat != -1 && missing != -1` 提前跳出迴圈，減少運算。
 */

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> counts(n * n + 1, 0);
        for(const auto& row : grid) {
            for(const int num: row) {
                counts[num]++;
            }
        }
        int repeat = -1;  
        int missing = -1;  
        for(int i =1; i<= n * n; i++) {
            if(counts[i] == 0) missing = i;
            else if(counts[i] == 2) repeat = i;
            if(repeat != -1 && missing != -1) break;
        }
        return {repeat, missing};
    }
};
