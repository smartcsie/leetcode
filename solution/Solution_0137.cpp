/**
 * 題目：137. Single Number II
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列，每個元素出現三次，只有一個元素出現一次，找出該元素。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 有限狀態機 (Finite State Machine)
 * 1. 使用 one 和 two 兩個變數來記錄位元出現的次數（模 3 餘數）。
 * 2. 每個位元的狀態轉移如下：
 * - 出現 1 次：one = 1, two = 0
 * - 出現 2 次：one = 0, two = 1
 * - 出現 3 次：one = 0, two = 0 (重置)
 * 3. `~two` 的作用是：如果該位元已經在 `two` 裡了（出現兩次），
 * 則當前的 `one` 運算會被強制歸零。
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
