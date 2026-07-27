/**
 * 題目：1913. Maximum Product Difference Between Two Pairs (兩個數對之間的最大乘積差)
 * 難度：簡單 (Easy)
 * 描述：在陣列中找出兩對 (a, b) 與 (c, d)，使得 (a * b) - (c * d) 最大化。
 * * 時間複雜度：O(N) - 僅遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用四個額外變數。
 * * 解法思路：
 * 1. 要使 (a * b) - (c * d) 最大，需讓 (a * b) 為陣列中兩數乘積最大值，(c * d) 為乘積最小值。
 * 2. 維護四個變數：max1, max2 (最大與次大)、min1, min2 (最小與次小)。
 * 3. 遍歷一次陣列，根據數值更新這四個變數。
 * 4. 計算並回傳 (max1 * max2) - (min1 * min2)。
 */

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (const int num : nums) {
            // 更新最大值與次大值
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }

            // 更新最小值與次小值
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        
        return (max1 * max2) - (min1 * min2);
    }
};
