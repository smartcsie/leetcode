/**
 * 題目：3512. Minimum Operations to Make Array Sum Divisible by K
 * 難度：簡單 (Easy)
 * 描述：透過減少陣列中的元素值，使總和能被 K 整除，求最小操作次數。
 * * 時間複雜度：O(N) - 遍歷陣列計算總和。
 * 空間複雜度：O(1) - 使用常數空間變數。
 * * 優化思路：
 * 令 S 為總和。我們需要將總和變為 (S - x)，使得 (S - x) % k == 0。
 * 這等同於 x = S % k。
 */

#include <vector>
#include <numeric>

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        // 總和對 k 取餘數，即為最少需要減去的次數
        return sum % k;
    }
};
