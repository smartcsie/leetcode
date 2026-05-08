/**
 * 解題思路：有限狀態機 (Finite State Machine)
 * 1. 使用 one 和 two 兩個變數來記錄位元出現的次數（模 3 餘數）。
 * 2. 每個位元的狀態轉移如下：
 *    - 出現 1 次：one = 1, two = 0
 *    - 出現 2 次：one = 0, two = 1
 *    - 出現 3 次：one = 0, two = 0 (重置)
 * 3. `~two` 的作用是：如果該位元已經在 `two` 裡了（出現兩次），
 *    則當前的 `one` 運算會被強制歸零。
 * 
 * Time Complexity: O(n) - 僅需遍歷陣列一次，且常數極低。
 * Space Complexity: O(1) - 僅使用兩個變數。
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0, two=0;
        for(int n : nums) {
            one = (one^n) & ~two;
            two = (two^n) & ~one;
        }
        return one;
    }
};
