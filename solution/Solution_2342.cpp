/**
 * 題目：2342. Max Sum of a Pair With Equal Sum of Digits
 * 難度：中等 (Medium)
 * 描述：找到數位和相等的兩個數字，並使它們的和最大化。
 * * 優化重點：
 * 1. 一次遍歷：在遍歷過程中即時更新最大和與分組最大值，無需二次排序。
 * 2. 映射表：利用 Hash Map 以 O(1) 平均時間查找該數位和之前的最大值。
 */

class Solution {
private:
    int digitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> max;
        int maximum = -1;
        for(const int& num : nums) {
            int digit_sum = digitSum(num);
            if(max.count(digit_sum)) {
                maximum  = std::max(maximum, max[digit_sum] + num );
                max[digit_sum] = std::max(max[digit_sum], num);
            } else {
                max[digit_sum] = num;
            }
        }
        return maximum;
    }
};
