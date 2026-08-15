/**
 * 題目：2427. Number of Common Factors
 * 難度：待補充
 * 描述：給你兩個正整數 a 和 b，返回 a 和 b 的公因數個數。
 *
 * 時間複雜度：O(min(A,B)) - 枚舉到 GCD(A,B) 的所有因數。
 * 空間複雜度：O(1) - 僅使用常數空間。
 *
 * 解法思路：
 * 1. 最大公因數（GCD）的數學性質：
 * - 兩個數字 a 和 b 的所有公因數，必然同時也是它們最大公因數 $\gcd(a, b)$ 的因數。
 * 2. 實作步驟：
 * - 使用 `<numeric>` 中的 `std::gcd(a, b)` 快速求出 a 與 b 的最大公因數。
 * - 將 `ans` 初始化為 1（因為 1 必定是所有正整數的公因數）。
 * - 從 `2` 開始迴圈到 $\gcd(a, b)$，檢查是否能同時整除 `a` 與 `b`（或直接檢查能否整除 $\gcd$）。
 * - 若符合條件則計數器 `ans++`。
 */

class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        int _gcd = gcd(a, b);
        for(int x = 1; x <= _gcd; x++) {
            if(a % x == 0 && b % x == 0) ans++;
        }
        return ans;
    }
};
