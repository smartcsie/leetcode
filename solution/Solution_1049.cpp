/**
 * 題目：1049. Last Stone Weight II (最後一塊石頭的重量 II)
 * 難度：中等 (Medium)
 * 描述：將石頭分成兩堆，碰撞後求最後剩下的最小重量。
 * * 時間複雜度：O(N * S) - N 為石頭數量，S 為總重量的一半。
 * 空間複雜度：O(S) - 使用一維 DP 陣列優化空間。
 * * 優化思路：
 * 1. 模型轉換：將問題轉化為 0/1 背包問題，目標是尋找一個子集，使其總和最接近總和的一半 (target = sum / 2)。
 * 2. 狀態定義：dp[j] 代表在背包容量為 j 的限制下，能裝下的石頭最大重量。
 * 3. 轉移方程：dp[j] = max(dp[j], dp[j - stone] + stone)。
 */

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        
        // 使用一維陣列優化空間複雜度
        // dp[j] 表示容量為 j 的背包所能裝下的最大石頭重量
        vector<int> dp(target + 1, 0);
        
        for (int stone : stones) {
            // 倒序遍歷確保每個物品(石頭)在同一輪中只被加入一次
            // 若順序遍歷則會變成「完全背包」問題，導致重複使用石頭
            for (int j = target; j >= stone; --j) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }
        
        // 最後剩下的重量為：較大那堆 (sum - dp[target]) - 較小那堆 (dp[target])
        return sum - 2 * dp[target];
    }
};
