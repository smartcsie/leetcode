/**
 * 題目：2419. Longest Subarray With Maximum Bitwise AND
 * 描述：給定一個整數陣列 nums，找出一個子陣列，其按位與 (Bitwise AND) 結果最大，
 *       並回傳該子陣列的最長長度。
 * 
 * 解法思路：
 * 1. 數學性質：按位與運算 (AND) 的結果不可能大於參與運算的任一數。
 *    因此，整個子陣列的 AND 最大值，必然等於整個陣列中的「全域最大值 (maxVal)」。
 * 2. 為了讓子陣列的 AND 結果維持在最大值，該子陣列內不能包含任何小於 maxVal 的數字（否則 AND 之後值會變小）。
 * 3. 尋找最長連續子陣列：我們只需要找出包含最多連續 `maxVal` 的區間長度即可。
 */

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        // 1. 找出陣列中的最大值
        int maxVal = *std::max_element(nums.begin(), nums.end());
        int maxCount = 0;
        int count = 0;
        
        // 2. 計算連續出現最大值的最長長度
        for (const int& num : nums) {
            if (num == maxVal) {
                count++;
            } else {
                count = 0; // 一旦中斷，重置連續計數
            }
            maxCount = std::max(maxCount, count);
        }
        
        return maxCount;
    }
};
