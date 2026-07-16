/**
 * 題目：1201. Ugly Number III
 * 難度：中等 (Medium)
 * 描述：找到第 n 個能被 a, b, 或 c 整除的數字。
 * 
 * 解法思路：
 * 1. 二分搜尋答案範圍 [1, 2e9]。
 * 2. 排容原理 (Inclusion-Exclusion Principle)：
 *    一個數 x 以下能被 a, b, 或 c 整除的個數 =
 *    (x/a + x/b + x/c) - (x/lcm(a,b) + x/lcm(b,c) + x/lcm(a,c)) + (x/lcm(a,b,c))
 * 3. 調整範圍：若 cnt < n，說明該數太小，縮小搜尋區間。
 */

class Solution {
private:
    // 使用 long long 防止計算過程中的溢位
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        // 先除後乘，避免溢位
        return (a / gcd(a, b)) * b;
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long left = 1, right = 2e9; 
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(a, bc); // lcm(a, lcm(b, c))
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            
            // 使用排容原理計算 mid 以下醜數個數
            long long cnt = mid / a + mid / b + mid / c 
                          - mid / ab - mid / bc - mid / ac 
                          + mid / abc;
            
            if (cnt < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return (int)right;
    }
};
