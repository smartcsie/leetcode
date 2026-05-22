/**
 * 題目：201. Bitwise AND of Numbers Range (數字範圍按位與)
 * 難度：中等 (Medium)
 * 描述：給你兩個整數 left 和 right，返回 [left, right] 範圍內所有數字的按位與 (AND)。
 * 
 * 時間複雜度：O(log n) - 取決於數字的位數（最高 32 次）。
 * 空間複雜度：O(1)
 * 
 * 解法思路 (位元移位法)：
 * 1. 我們要找的是 left 和 right 的「公共前綴」。
 * 2. 如果 left != right，說明範圍內至少有兩個數，最後一位必定會因為 AND 運算而變為 0。
 * 3. 我們不斷將 left 和 right 向右移位 (>>= 1)，直到它們相等。
 * 4. 相等後的數就是公共前綴，最後再左移回原本的位數即可。
 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // 找到兩個數字的公共前綴
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        // 將公共前綴左移回原來的位置
        return left << shift;
    }
};
