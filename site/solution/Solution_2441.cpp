/**
 * 題目：2441. Largest Positive Integer That Exists With Its Negative (與對應負數同時存在的最大正整數)
 * 難度：簡單 (Easy)
 * 描述：給你一個不包含 0 的整數陣列 nums，請你找出滿足下述條件的最大正整數 k：
 *      在陣列中同時存在 k 和 -k。如果不存在這樣的整數，回傳 -1。
 * 
 * 時間複雜度：O(n) - 遍歷一次陣列。
 * 空間複雜度：O(n) - 使用 unordered_set 儲存看過的數字。
 * 
 * 解法思路：
 * 1. 使用一個哈希表 (unordered_set) 來記錄我們掃描過的數字。
 * 2. 遍歷陣列中的每個數字 x：
 *    - 檢查 -x 是否已經存在於集合中。
 *    - 如果存在，代表 {x, -x} 這對組合出現了，此時取絕對值 |x| 並嘗試更新最大值 ans。
 *    - 將當前數字 x 放入集合中。
 * 3. 遍歷結束後，ans 即為所求。
 */

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int res = -1;
        for(int num : nums) {
            if(num > 0 && set.contains(num*(-1))) {
                res = max(res, num);
            }
        }
        return res;
    }
};
