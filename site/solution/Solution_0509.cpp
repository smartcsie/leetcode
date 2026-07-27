
/**
 * 解題思路：動態規劃 (空間優化迭代法)
 * 1. 費氏數列定義：F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)。
 * 2. 雖然可以用遞迴求解，但純遞迴會產生大量重複計算，時間複雜度為 O(2^n)。
 * 3. 使用迭代法 (Bottom-up DP)：
 *    - 我們只需要前兩個數字就能推導出下一個數字。
 *    - 因此不需開一個陣列存所有結果，只需兩個變數 prev1, prev2 滾動更新。
 * 
 * Time Complexity: O(n) - 只需要從 2 遍歷到 n。
 * Space Complexity: O(1) - 僅使用常數個整數變數。
 */

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int first = 0;
        int second = 1;
        for(int i = 2; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
