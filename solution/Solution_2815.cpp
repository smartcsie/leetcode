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
private:
    int maxDigit(int n) {
        int n = nums.size();
        vector<int> mx(10, -1);
        vector<int> sum(10, -1);
        int ans = -1;
        for(const int& x : nums) {
            int y = x;
            int maxDigit = -1;
            while(y > 0) {
                int d = y % 10;
                maxDigit = max(maxDigit, d);
                y /= 10;
            }
            if(mx[maxDigit] == -1) {
                mx[maxDigit] = x;
            } else {
                sum[maxDigit] = max(sum[maxDigit], mx[maxDigit] + x);
                mx[maxDigit] = max(mx[maxDigit], x);
                ans = max(ans, sum[maxDigit]);
            }
        }
        return ans;
    }
};
