/**
 * 題目：1854. Maximum Population Year
 * 難度：簡單 (Easy)
 * 描述：在給定的出生與死亡區間中，找出人口數量最多的一年。
 * * 優化重點：
 * 1. 差分法：避免了對每個區間內的年份進行暴力枚舉，大幅提升效率。
 * 2. 空間固定：空間複雜度僅取決於題目規定的年份範圍，為 O(1) 級別。
 */

#include <vector>

class Solution {
public:
    int maximumPopulation(std::vector<std::vector<int>>& logs) {
        // 題目範圍為 1950-2050，預留足夠空間
        std::vector<int> diff(2051, 0);
        
        for (const auto& log : logs) {
            diff[log[0]] += 1;
            diff[log[1]] -= 1;
        }
        
        int cur_population = 0;
        int max_population = 0;
        int earliest_year = 1950;
        
        // 進行掃描線 (Sweep Line) 計算
        for (int year = 1950; year <= 2050; ++year) {
            cur_population += diff[year];
            
            // 找到人口最多的年份，若相等則因題目要求取最早年份，無需更新
            if (cur_population > max_population) {
                max_population = cur_population;
                earliest_year = year;
            }
        }
        
        return earliest_year;
    }
};
