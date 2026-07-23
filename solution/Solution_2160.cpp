/**
 * 題目：2160. Minimum Sum of Four Digit Number After Splitting Digits
 * 描述：給你一個正整數 num，它是一個四位數。請你將 num 分割成兩個新的整數 new1 和 new2，
 *       這兩個數字是由 num 的四個位數重新排列組合而成的（可以有多個前導零）。
 *       求出 new1 和 new2 最小可能的和。
 * 
 * 解法思路：
 * 1. 宣告一個大小為 4 的陣列 `digits` 來存放四個位數。
 * 2. 透過 `num % 10` 與 `num /= 10` 依序將個、十、百、千位數取出並存入陣列。
 * 3. 使用 `ranges::sort`（C++20）將這四個數字由小到大排序。假設排序後為 `[a, b, c, d]`，其中 `a <= b <= c <= d`。
 * 4. 根據貪心策略（Greedy），為了讓組合出來的兩個數字和最小，我們應該把最小的兩個數放在「十位數」，較大的兩個數放在「個位數」。
 * 5. 計算並返回 `(a + b) * 10 + (c + d)` 的結果。
 */

class Solution {
public:
    int minimumSum(int num) {
        std::vector<int> digits(4, 0);
        int temp = num;
        
        // 拆解四個位數
        for (int i = 0; i < 4; ++i) {
            digits[i] = temp % 10;
            temp /= 10; 
        } 
        
        // 將位數由小到大排序
        std::ranges::sort(digits);
        
        // 貪心組合：最小的兩個當十位數，其餘當個位數
        return (digits[0] + digits[1]) * 10 + (digits[2] + digits[3]);
    }
};
