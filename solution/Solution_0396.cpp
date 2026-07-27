/**
 * 題目：396. Rotate Function (旋轉函數)
 * 難度：中等 (Medium)
 * 描述：計算陣列旋轉後的函數值 F(k) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]，求其中的最大值。
 * * 時間複雜度：O(N)，只需一次遍歷。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 利用前後項關係：F(i) - F(i-1) = sum - n * nums[n-i]。
 * 2. 避免重複運算，使用變數累加更新。
 */

#include <vector>
#include <numeric> // for std::accumulate
#include <algorithm> // for std::max

class Solution {
public:
    int maxRotateFunction(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        // 使用 0LL 確保 accumulate 計算過程為 long long，避免溢位
        long long total_sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long current_f = 0;
        
        // 計算 F(0)
        for (int i = 0; i < n; ++i) {
            current_f += (long long)i * nums[i];
        }
        
        long long max_f = current_f;
        
        // 從 F(1) 計算到 F(n-1)
        // 遞迴公式：F(k) = F(k-1) + sum - n * nums[n-k]
        // 這裡 i 代表當前移到隊尾的元素索引 (倒序)
        for (int i = n - 1; i > 0; --i) {
            current_f = current_f + total_sum - (long long)n * nums[i];
            max_f = std::max(max_f, current_f);
        }
        
        return static_cast<int>(max_f);
    }
};
