/**
 * 題目：1137. N-th Tribonacci Number
 * 難度：簡單 (Easy)
 * 描述：計算第 n 個 Tribonacci 數列的值（前三項之和）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DP 陣列版）：
 * 用 dp 陣列存每個 Tribonacci 數，dp[i] = dp[i-1] + dp[i-2] + dp[i-3]。
 */
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};