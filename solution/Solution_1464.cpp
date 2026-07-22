/**
 * 題目：1464. Maximum Product of Two Elements in an Array
 * 描述：給你一個整數陣列 nums，請你選擇兩個不同的索引 i 和 j，
 *       使 (nums[i]-1)*(nums[j]-1) 的值最大。請返回最大值。
 * 
 * 解法思路：
 * 1. 要讓乘積最大，我們需要選出陣列中數值最大的兩個數字。
 * 2. 利用 `std::pair<int, int>` 紀錄最大值（first）與第二大值（second）。
 * 3. 走訪整個 nums 陣列：
 *    - 如果當前元素大於最大值，則將原最大值降級為第二大值，並更新最大值。
 *    - 否則，如果當前元素大於第二大值，則更新第二大值。
 * 4. 迴圈結束後，計算 `(maxVal.first - 1) * (maxVal.second - 1)` 並回傳。
 */

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        // 使用 pair 儲存最大值 (first) 與第二大值 (second)，初值設為 0
        std::pair<int, int> maxVal(0, 0);
        
        for (const int& num : nums) {
            if (num > maxVal.first) {
                // 當前數字大於最大值：原本的最大值變成第二大，再更新最大值
                maxVal.second = maxVal.first;
                maxVal.first = num;
            } else if (num > maxVal.second) {
                // 當前數字沒有大於最大值，但大於第二大值：更新第二大值
                maxVal.second = num;
            }
        }
        
        // 依照題目公式計算結果
        return (maxVal.first - 1) * (maxVal.second - 1);
    }
};
