/**
 * 題目：2974. Minimum Number Game
 * 難度：簡單 (Easy)
 * 描述：依據 Alice 與 Bob 的取數規則，重新排列陣列。
 * * 優化重點：
 * 1. 排序：利用 std::sort 將複雜的取數邏輯轉化為簡單的順序處理。
 * 2. 兩兩交換：利用迴圈一次處理一對元素，時間效率高。
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> numberGame(std::vector<int>& nums) {
        // 先排序以確保能取出最小值
        std::sort(nums.begin(), nums.end());
        
        // 兩兩交換 Alice 與 Bob 的數值順序
        for (int i = 0; i < (int)nums.size(); i += 2) {
            std::swap(nums[i], nums[i + 1]);
        }
        
        return nums;
    }
};
