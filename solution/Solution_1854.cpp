/**
 * 題目：1854. Maximum Population Year
 * 難度：簡單 (Easy)
 * 描述：在給定的出生與死亡區間中，找出人口數量最多的一年。
 * 優化重點：
 * 1. 差分法：避免了對每個區間內的年份進行暴力枚舉，大幅提升效率。
 * 2. 空間固定：空間複雜度僅取決於題目規定的年份範圍，為 O(1) 級別。
 *
 * 時間複雜度：O(N+Y)
 * 空間複雜度：O(Y)
 */

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        array<int, 2051> population = {};
        for(const vector<int>& log : logs) {
            population[log[0]]++;
            population[log[1]]--;
        }
        int mx = 0;
        int mxYear = 0;
        int cur = 0;
        for(int i = 1950; i <= 2050; i++) {
            cur += population[i];
            if(cur > mx) {
                mx = cur;
                mxYear = i;
            }
        }
        return mxYear;
    }
};
