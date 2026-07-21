/**
 * 題目：1486. XOR Operation in an Array
 * 描述：給定整數 n 和 start。定義一個陣列 nums，其中 nums[i] = start + 2 * i（0 <= i < n）。
 *       請返回 nums 中所有元素的按位與 XOR 總和。
 * 
 * 解法思路：
 * 1. 根據題意，陣列的數值為從 start 開始，依序加上 2、4、6... 等等。
 * 2. 我們不需要真正宣告一個陣列來儲存數值，只需要透過迴圈從 i = start 開始，
 *    每次增加 2（即 i += 2），並執行總體 XOR 累加。
 * 3. 迴圈執行的次數為 n 次（終止條件為小於 start + 2 * n）。
 */

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        
        // 迴圈模擬每次的元素值：start, start + 2, start + 4, ..., start + 2*(n-1)
        for (int i = start; i < start + 2 * n; i += 2) {
            ans ^= i;
        }
        
        return ans;
    }
};
