/**
 * 題目：628. Maximum Product of Three Numbers (三個數的最大乘積)
 * 難度：簡單 (Easy)
 * 描述：在整數陣列中找出三個數字的最大乘積。
 * * 時間複雜度：O(N) - 只需要掃描一次陣列。
 * 空間複雜度：O(1) - 僅儲存 5 個變數。
 * * 優化思路：
 * 乘積最大值只有兩種可能：
 * 1. 三個最大的正數相乘。
 * 2. 兩個最小的負數（絕對值大）與一個最大的正數相乘。
 * 因此，只需找出陣列中最大的 3 個數與最小的 2 個數即可。
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX ;
        int n = nums.size();
        for(const int& num : nums ) {
            if(num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if(num > max2) {
                max3 = max2;
                max2 = num;
            } else if(num > max3) {
                max3 = num;
            }

            if(num < min1) { 
                min2 = min1;
                min1 = num;
            } else if(num < min2) { 
                min2 = num;
            } 
        }
       
        return max(max1 * max2 * max3, max1 * min2 * min1);
    }
};
