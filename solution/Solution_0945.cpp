/**
 * 題目：945. Minimum Increment to Make Array Unique
 * 難度：中等 (Medium)
 * 描述：透過增加陣列元素值，使所有元素互不相同。
 * * 優化重點：
 * 1. 貪心策略：排序後，若後一個數字小於等於前一個數字的最小可用值，則補足差額。
 * 2. 空間效率：原地計算，僅需 O(1) 額外空間。
 * 3. 溢位防護：使用 long long 處理累積增量 (ans)，防止極大測資下的溢位。
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        // 先進行排序，讓數字排列有序
        std::sort(nums.begin(), nums.end());
        
        long long ans = 0; // 使用 long long 確保累加結果安全
        int minAvailable = 0; // 紀錄下一個可用的最小數值
        
        for (const int num : nums) {
            // 如果當前數字小於下一個可用數，則需進行增量
            if (num < minAvailable) {
                ans += (minAvailable - num);
                minAvailable++;
            } else {
                // 若數字大於等於可用數，更新可用數
                minAvailable = num + 1;
            }
        }
        
        return static_cast<int>(ans);
    }
};
