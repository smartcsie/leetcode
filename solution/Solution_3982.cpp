/**
 * 題目：3982. Sum of Integers with Maximum Digit Range
 * 難度：簡單 (Easy)
 * 描述：計算陣列中擁有「最大數位極差」的所有整數之和。
 * * 優化重點：
 * 1. 數位拆解：使用 while 迴圈配合取模運算。
 * 2. 邊界條件：使用 INT_MAX 與 INT_MIN 初始化比較基準。
 */

class Solution {
private:
    int digitRange(int n) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        // 若 n 為 0，則極差為 0
        if (n == 0) return 0;
        
        while (n > 0) {
            int digit = n % 10;
            min_val = std::min(min_val, digit);
            max_val = std::max(max_val, digit);
            n /= 10;
        }
        return max_val - min_val;
    }

public:
    int maxDigitRange(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ranges(n);
        int max_range = INT_MIN;
        
        // 第一遍：計算所有數位極差並找出最大值
        for (int i = 0; i < n; i++) {
            ranges[i] = digitRange(nums[i]);
            max_range = std::max(max_range, ranges[i]);
        }
        
        // 第二遍：累加所有極差等於 max_range 的數字
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (ranges[i] == max_range) {
                sum += nums[i];
            }
        }
        return sum;
    }
};
