/**
 * 題目：1588. Sum of All Odd Length Subarrays
 * 難度：簡單 (Easy)
 * 描述：計算陣列中所有奇數長度子陣列之和。
 * 
 * 解法思路：
 * 1. 建立前綴和陣列 `prefix`，其中 `prefix[i]` 為前 i 個元素的總和。
 * 2. 任何子陣列 arr[i...j] 的和可表示為 `prefix[j+1] - prefix[i]`。
 * 3. 使用雙重迴圈，外層 `i` 為起點，內層 `j` 為終點，步進值設為 2，確保長度為奇數。
 */

#include <vector>

class Solution {
public:
    int sumOddLengthSubarrays(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> prefix(n + 1, 0);
        
        // 預計算前綴和
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        int sum = 0;
        // 枚舉所有可能的奇數長度區間
        for (int i = 0; i < n; i++) {
            // j 從 i 開始，每次 +2 確保子陣列長度 (j - i + 1) 為奇數
            for (int j = i; j < n; j += 2) {
                sum += (prefix[j + 1] - prefix[i]);
            }
        }
        return sum;
    }
};
