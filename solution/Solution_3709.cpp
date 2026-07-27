/**
 * 題目：3079. Find the Sum of Encrypted Integers
 * 難度：待補充
 * 描述：給你一個由正整數組成的陣列 nums。定義加密函數 enc(x)，將 x 中的每一個數位替換為 x 中的最大數位。
 * 請返回陣列中所有元素加密後的總和。
 *
 * 時間複雜度：O(N) - 單次遍歷，計算相鄰元素差的絕對值總和。
 * 空間複雜度：O(1) - 僅使用常數空間。
 *
 * 解法思路：
 * （數學模擬法）：
 * 1. 逐一處理每個數字：
 * - 對於陣列中的每一個數字 `num`，利用 `while` 迴圈提取每一位數。
 * - 在提取的過程中，記錄下整數中最大的數位（`maxDigit`），並統計總位數（`digit`）。
 * 2. 邊界條件處理：
 * - 如果數字小於 10（即個位數），其加密結果就是它自己，直接加到總和中。
 * 3. 構造加密後的數字：
 * - 根據統計出的位數 `digit` 與最大數位 `maxDigit`，利用迴圈組合出全部由該最大數位組成的全新數字（例如：若最大數位為 5，位數為 3，則組合成 555）。
 * - 最後將加密後的數字累加至總和 `ans` 中。
 */

class Solution {
public:
    int sumOfEncryptedInt(std::vector<int>& nums) {
        int ans = 0;
        for (const int& num : nums) {
            int temp = num;
            int maxDigit = 0;
            int digit = 0;
            
            // 若小於 10，直接加總（其加密結果為自身）
            if (num < 10) { 
                ans += num;
            } else {
                // 找出最大數位與總位數
                while (temp > 0) {
                    maxDigit = std::max(maxDigit, temp % 10);
                    temp /= 10;
                    digit++;
                }
                
                // 根據位數組合出全新加密數字
                int newNum = 0;
                while (digit--) {
                    newNum = newNum * 10 + maxDigit;
                }
                ans += newNum;
            }
        }
        return ans;
    }
};
