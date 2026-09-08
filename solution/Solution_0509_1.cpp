/**
 * 題目：509. Fibonacci Number
 * 難度：簡單 (Easy)
 * 描述：計算第 n 個費氏數列的值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DP 陣列版）：
 * 用 dp 陣列存每個費氏數，dp[i] = dp[i-1] + dp[i-2]，空間可用滾動變數優化到 O(1)。
 */
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};