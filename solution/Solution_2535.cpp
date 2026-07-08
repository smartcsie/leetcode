/**
 * 題目：2535. Difference Between Element Sum and Digit Sum of an Array
 * 難度：簡單 (Easy)
 * 描述：計算陣列中「元素總和」與所有「數位總和」之間的絕對差值。
 * * 優化重點：
 * 1. 單次遍歷：在同一迴圈內同時處理元素值與數位拆解，效率最高。
 * 2. 空間節省：僅使用單一 sum 變數來維護累計差值，不需要額外的儲存空間。
 */

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        for(const int& num : nums) {
            int temp = num;
            sum += temp;
            while(temp > 0) {
                sum -= (temp % 10);
                temp /= 10;
            }
        }
        return sum;
    }
};
