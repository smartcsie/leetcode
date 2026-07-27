/**
 * 題目：264. Ugly Number II (醜數 II)
 * 難度：中等 (Medium)
 * 描述：找出第 n 個醜數。醜數是指質因數只包含 2, 3, 5 的正整數。
 * * 時間複雜度：O(n) - 只需計算到第 n 個醜數。
 * 空間複雜度：O(n) - 需要長度為 n 的陣列儲存醜數序列。
 * * 優化思路：
 * 1. 動態規劃：定義 dp[i] 為第 i+1 個醜數。
 * 2. 三指標法：利用 p2, p3, p5 指標分別指向「下一個與 2, 3, 5 相乘」的醜數位置。
 * 3. 獨立判斷：必須使用三個獨立的 if 來更新指標，以處理多重因子產生的相同值。
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        for(int i = 1; i < n; i++) {
            int next2 = dp[index2] * 2;
            int next3 = dp[index3] * 3;
            int next5 = dp[index5] * 5;
            dp[i] = min({next2, next3, next5});
            if(dp[i] == next2) index2++;
            if(dp[i] == next3) index3++;
            if(dp[i] == next5) index5++;
        }
        return dp[n - 1];
    }
};
