/**
 * 題目：2815. Max Pair Sum in an Array
 * 難度：簡單 (Easy)
 * 描述：找出兩數最大數位相同，且兩數之和最大的數對。
 * 優化重點：
 * 1. 邏輯內嵌：將 `maxDigit` 邏輯簡化或保持現狀，但在迴圈中避免過度呼叫。
 * 2. 空間優化：`best[10]` 固定陣列空間，處理所有數位 0-9。
 *
 * 時間複雜度：O(N*D)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int maxSum(vector<int>& nums) {
        array<int, 10> mx = {};
        array<int, 10> sum = {};
        int ans = -1;
        for(const int& x : nums) {
            int y = x;
            int d = -1;
            while(y > 0) {
                d = max(d, y % 10);
                y /= 10;
            }
            if(mx[d] != 0) {
                sum[d] = max(sum[d], mx[d] + x);
                ans = max(ans, sum[d]);
            }
            mx[d] = max(mx[d], x);
        }
        return ans;
    }
};