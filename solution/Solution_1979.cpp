/**
 * 題目：1979. Find Greatest Common Divisor of Array
 * 描述：找出陣列中最大數與最小數的最大公因數。
 * 
 * 解法思路：
 * 1. 使用 std::minmax_element 一次掃描找出陣列中的最小值與最大值。
 * 2. 使用 C++17 標準函式 std::gcd 直接計算這兩個數的最大公因數。
 */

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        // 一次遍歷找出最大與最小值
        auto [minIt, maxIt] = std::minmax_element(nums.begin(), nums.end());
        
        // 利用 std::gcd 計算並回傳結果
        return std::gcd(*minIt, *maxIt);
    }
};
