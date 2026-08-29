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
        int ans = -1;
        while(n > 0) {
            int d = n % 10;
            ans = max(ans, d);
            n /= 10;
        }
        return ans;
    }
public:
    int maxSum(vector<int>& nums) {
        vector<pair<int, int>> pairs(10, {-1, -1});
        for(const int& x : nums) {
            int d = maxDigit(x);
            if(x > pairs[d].first) {
                pairs[d].second = pairs[d].first;
                pairs[d].first = x;
            } else if(x > pairs[d].second) {
                pairs[d].second = x;
            }
        }
        int ans = -1;
        for(int i = 9; i>= 0; i--) {
            if(pairs[i].second != -1) ans = max(ans, pairs[i].first  + pairs[i].second );
        }
        return ans;
    }
};
