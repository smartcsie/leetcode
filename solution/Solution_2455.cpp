/**
 * 題目：2455. Average Value of Even Numbers That Are Divisible by Three
 * 難度：簡單 (Easy)
 * 描述：計算陣列中所有「既是偶數又能被 3 整除」的數字之平均值（向下取整）。
 * 
 * 解法思路：
 * 1. 若一個數字同時能被 2 和 3 整除，根據最小公倍數性質，它必定能被 6 整除。
 * 2. 遍歷陣列，累加所有符合條件的數字並統計次數。
 * 3. 處理除以 0 的邊界條件（若沒有符合條件的數，回傳 0）。
 */

class Solution {
public:
    int averageValue(std::vector<int>& nums) {
        int count = 0;
        int sum = 0;
        
        for (int num : nums) {
            // 同時被 2 和 3 整除 <=> 被 6 整除
            if (num % 6 == 0) {
                sum += num;
                count++;
            }
        }
        
        // 若 count 為 0 則避免除以 0 的錯誤
        return (count == 0) ? 0 : (sum / count);
    }
};
