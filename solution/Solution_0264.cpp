/**
 * 題目：264. Ugly Number II (醜數 II)
 * 難度：中等 (Medium)
 * 描述：找出第 n 個醜數。醜數是指質因數只包含 2, 3, 5 的正整數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 動態規劃：定義 dp[i] 為第 i+1 個醜數。
 * 2. 三指標法：利用 p2, p3, p5 指標分別指向「下一個與 2, 3, 5 相乘」的醜數位置。
 * 3. 獨立判斷：必須使用三個獨立的 if 來更新指標，以處理多重因子產生的相同值。
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        int idx2 = 0, idx3 = 0, idx5 = 0;
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n ; i++){
            ans[i] = min({ans[idx2] * 2, ans[idx3] * 3, ans[idx5] * 5});
            if(ans[i] == ans[idx2] * 2) idx2++;
            if(ans[i] == ans[idx3] * 3) idx3++;
            if(ans[i] == ans[idx5] * 5) idx5++;
        }
        return ans.back();
    }
};