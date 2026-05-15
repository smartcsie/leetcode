/**
 * 題目：268. Missing Number (缺失數字)
 * 難度：簡單 (Easy)
 * 描述：給定一個包含 [0, n] 中 n 個數的陣列 nums，找出在 0 到 n 範圍內缺失的那一個數字。
 * 
 * 時間複雜度：O(n) - 遍歷一次陣列。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * 
 * 解法思路：
 * 1. XOR (互斥或) 法：
 *    - XOR 運算滿足：a ^ a = 0, a ^ 0 = a。
 *    - 我們將 0 到 n 的所有索引與陣列中所有的數字全部進行 XOR。
 *    - 成對出現的數字會抵消為 0，最後剩下的結果就是缺失的數字。
 * 
 * 2. 數學求和法 (Gauss Sum)：
 *    - 計算 0 到 n 的理論總和：sum = n * (n + 1) / 2。
 *    - 減去陣列中所有數字的實際總和，差值即為缺失數字。
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res = res ^ (i+1) ^ nums[i];
        }
        return res;
    }
};


/**
 * 數學解法參考 (Alternative Math Approach):
 * 
 * int missingNumber(vector<int>& nums) {
 *     int n = nums.size();
 *     int expectedSum = n * (n + 1) / 2;
 *     int actualSum = 0;
 *     for (int x : nums) actualSum += x;
 *     return expectedSum - actualSum;
 * }
 */
