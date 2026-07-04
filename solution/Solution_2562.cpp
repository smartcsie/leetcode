/**
 * 題目：2562. Find the Array Concatenation Value
 * 難度：簡單 (Easy)
 * 描述：計算陣列的串接值（頭尾串接後之總和）。
 * * 優化重點：
 * 1. 移除 `log10` 與 `pow`：這些浮點運算昂貴且容易有精度誤差，改用乘法迴圈。
 * 2. 條件優化：處理單數個元素的特殊情況（中間單一元素無需串接）。
 */

class Solution {
private:
    long long getMultiplier(int n) {
        long long multiplier = 1;
        while(n > 0) {
            n /= 10;
            multiplier *= 10;
        }
        return multiplier;
    }
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            long long  multiplier = getMultiplier(nums[right]);
            if(left < right) sum += nums[left] * multiplier;
            sum += nums[right];
            left++;
            right--;
        }
        return sum;
    }
};
