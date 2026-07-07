/**
 * 題目：3895. Count Digit Appearances
 * 難度：簡單 (Easy)
 * 描述：計算陣列 nums 中所有元素的每一位數字，共有多少位等於指定的 digit。
 *
 * 核心概念：
 * - 對每個數字逐位拆解（取餘數 % 10，再整除 10）。
 * - 每拆解出一位就與 digit 比對，相符則計數。
 * - 拆解直到該數字歸零為止。
 */
class Solution {
public:
    int countDigitOccurrences(vector& nums, int digit) {
        int count = 0;
        for(const int& num : nums) {
            int temp = num;
            while(temp > 0) {
                if(temp % 10 == digit) count++;
                temp /= 10;
            }
        }
        return count;
    }
};
