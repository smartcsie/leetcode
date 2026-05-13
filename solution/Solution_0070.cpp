/**
 * 解題思路：動態規劃 (Dynamic Programming)
 * 1. 思考最後一步：要到達第 n 階，只有兩種可能：
 *    - 從第 n-1 階爬 1 步上來。
 *    - 從第 n-2 階爬 2 步上來。
 * 2. 狀態轉移方程：dp[i] = dp[i-1] + dp[i-2]
 *    - 這與費氏數列 (Fibonacci) 的規律完全一致。
 * 3. 邊界條件：
 *    - dp[1] = 1 (只有 1 種方法)
 *    - dp[2] = 2 (1+1 或 2，共 2 種方法)
 * 4. 空間優化：我們只需要紀錄前兩個狀態，不需完整陣列。
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int first = 1;
        int second = 2;
        for(int i= 3 ; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
