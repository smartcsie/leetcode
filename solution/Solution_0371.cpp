/**
 * 題目：371. Sum of Two Integers (兩整數之和)
 * 難度：中等 (Medium)
 * 描述：不使用 "+" 或 "-" 運算子計算兩個整數 a 和 b 之和。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 加法的本質：
 * - XOR (^): 模擬不考慮進位的加法 (例如 1+1=0, 1+0=1)。
 * - AND (&) << 1: 計算進位 (例如 1+1=10，進位部分為 1 左移一位)。
 * 2. 迭代過程：
 * 將「不進位加法的結果」與「進位結果」重複進行上述操作，直到進位為 0。
 * 注意：在 C++ 中，對負數執行左移運算 (`<<`) 可能會導致未定義行為 (Undefined Behavior)，
 * 但在 LeetCode 的測試環境下，這通常能順利通過。
 */

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = static_cast<unsigned int>((a & b) << 1);
            a ^= b;
            b = carry;
        }
        return a;
    }
};
