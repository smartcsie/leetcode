/**
 * 題目：3005. Count Elements With Maximum Frequency (統計最大頻率元素)
 * 難度：簡單 (Easy)
 * 描述：給你一個由正整數組成的陣列 nums。
 *      找出陣列中元素的出現頻率，並回傳所有「出現頻率等於最大頻率」的元素的總個數。
 * 
 * 時間複雜度：O(n) - 需要遍歷一次陣列來統計頻率，再遍歷一次統計結果。
 * 空間複雜度：O(1) - 雖然使用了頻率陣列，但題目給定數字範圍為 1~100，空間為常數級別。
 * 
 * 解法思路：
 * 1. 使用一個陣列或哈希表統計每個數字出現的次數。
 * 2. 在統計過程中，隨時記錄當前出現過的「最大頻率」是多少。
 * 3. 最後加總所有頻率等於該最大頻率的數值。
 */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n =nums.size();
        vector<int> counts(101,0);
        int max = 0;
        int res = 0;
        for(int num : nums) {
            counts[num]++;
            if(counts[num] > max) {
                max = counts[num];
                res = max;
            }
            else if(counts[num] == max) {
                res += max;
            }
        }
        return res;
    }
};
