/**
 * 解題思路：Kadane's Algorithm (貪婪法/動態規劃)
 * 1. 核心想法：如果目前的子陣列和 (currentSum) 已經變成負數，它對未來的總和只會有負貢獻。
 * 2. 策略：
 *    - 遍歷陣列，逐一累加元素到 currentSum。
 *    - 每次累加後，更新全域最大值 maxSum = max(maxSum, currentSum)。
 *    - 如果 currentSum < 0，立即將 currentSum 重置為 0（代表捨棄之前的子陣列，從下一個數字重新開始）。
 * 
 * 為什麼這有效？
 * 因為任何「負的和」加上下一個數字，結果一定比「下一個數字自己本身」還要小。
 * 
 * Time Complexity: O(n) - 只需要遍歷陣列一次。
 * Space Complexity: O(1) - 僅使用兩個整數變數。
 */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        for(int num : nums) {
            count += num;
            if(count > res) res = count;
            if(count < 0 )  count = 0;
        }
        return res;
    }
};
