/**
 * 題目：2442. Count Number of Distinct Integers After Reverse Operations
 * 描述：給你一個正整數陣列 nums。對 nums 中的每個整數，將其數字順序反轉後加入陣列中。
 *       請返回陣列 nums 中所有「相異整數」的數目。
 * 
 * 解法思路：
 * 1. 根據題目範圍，數字最大可能達到 10^6（LeetCode 2442 的測資範圍）。
 * 2. 宣告一個容量為 1000001 的 `std::bitset<1000001>` 來記錄所有出現過的數值（bitset 自動具備去重效果）。
 * 3. 走訪 nums 中的每一個數字 num：
 *    - 將原始數字 num 透過 `bits.set(num)` 標記。
 *    - 使用數學迴圈將 num 進行反轉得到 r（例如 123 -> 321）。
 *    - 將反轉後的數字 r 也透過 `bits.set(r)` 標記。
 * 4. 最後直接回傳 `bits.count()`，即可得到總共被點亮的相異數字個數。
 */

class Solution {
public:
    int countDistinctIntegers(std::vector<int>& nums) {
        // 宣告 bitset 涵蓋至題目最大可能數值 (10^6)
        std::bitset<1000001> bits;
        
        for (const int& num : nums) {
            int n = num;
            // 1. 記錄原始數字
            bits.set(n);
            
            // 2. 計算反轉數字 r
            int r = 0;
            while (n > 0) {
                r = r * 10 + (n % 10);
                n /= 10;
            }
            
            // 3. 記錄反轉後的數字
            bits.set(r);
        }
        
        // 4. 返回 bitset 中被設為 1 的總個數（即相異整數數量）
        return bits.count();
    }
};
