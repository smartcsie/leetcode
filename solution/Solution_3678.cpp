/**
 * 題目：3678. Smallest Absent Positive Greater Than Average (大於平均值的最小缺失正整數)
 * 難度：簡單 (Easy)
 * 描述：找到一個大於數列平均值的最小整數，該數字不在原數列中。
 * * 時間複雜度：O(N)，遍歷數組進行求和與集合建立。
 * 空間複雜度：O(N)，儲存所有數值於集合中。
 * * 優化思路：
 * 1. 使用 long long 防止求和溢位。
 * 2. 精確計算平均值（向上取整）。
 */

#include <vector>
#include <numeric>
#include <unordered_set>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int smallestAbsent(std::vector<int>& nums) {
        // 使用 long long 防止求和溢位
        long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        
        // 計算平均值 (double) 並向上取整，再 +1
        // 等同於大於平均值的最小整數
        int avg = static_cast<int>(std::floor(static_cast<double>(sum) / nums.size()));
        int ans = std::max(1, avg + 1);
        
        // 使用 unordered_set 進行快速查找
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        // 線性搜尋第一個不在 set 中的數字
        while (numSet.count(ans)) {
            ans++;
        }
        
        return ans;
    }
};
