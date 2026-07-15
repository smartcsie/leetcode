/**
 * 題目：1588. Sum of All Odd Length Subarrays
 * 難度：簡單 (Easy)
 * 描述：計算陣列中所有奇數長度子陣列之和。
 * 
 * 解法思路 (貢獻法)：
 * 1. 與其枚舉所有子陣列，不如計算每個元素 arr[i] 出現在多少個「奇數長度」子陣列中。
 * 2. 對於索引 i，其左側有 i 個元素，右側有 n - 1 - i 個元素。
 * 3. 元素 arr[i] 出現的次數為：((左側個數 + 1) * (右側個數 + 1) + 1) / 2。
 * 4. 將每個元素乘以其出現次數並累加，即可得到總和。
 */

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            // 左側元素個數: i, 右側元素個數: n - 1 - i
            int left = i;
            int right = n - 1 - i;
            
            // 左側/右側取偶數或奇數的方法數
            // 數學公式簡化版:
            // 包含 arr[i] 的奇數長度子陣列總數 = ((i+1) * (n-i) + 1) / 2
            int totalOccurrences = ( (left + 1) * (right + 1) + 1 ) / 2;
            
            totalSum += arr[i] * totalOccurrences;
        }
        
        return totalSum;
    }
};
