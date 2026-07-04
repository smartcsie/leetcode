/**
 * 題目：2815. Max Pair Sum in an Array
 * 難度：簡單 (Easy)
 * 描述：找出兩數最大數位相同，且兩數之和最大的數對。
 * * 優化重點：
 * 1. 邏輯內嵌：將 `maxDigit` 邏輯簡化或保持現狀，但在迴圈中避免過度呼叫。
 * 2. 空間優化：`best[10]` 固定陣列空間，處理所有數位 0-9。
 */

class Solution {
private:
    int maxDigit(int n) {
        int max = 0;
        while(n > 0) {
            int digit = n % 10;
            max = std::max(max, digit);
            n /=10;
        }
        return max;
    }
public:
    int maxSum(vector<int>& nums) {
        vector<pair<int, int>> best(10,{-1 , -1});
        for(const int& num : nums) {
            int digit = maxDigit(num);
            if(num > best[digit].first) {
                best[digit].second = best[digit].first;
                best[digit].first = num;
            } else if(num > best[digit].second) {
                best[digit].second = num;
            } 
        }
        int res = -1;
        for(int i = 0; i <=9; i++) {
            if(best[i].second != -1) {
                res = max(res, best[i].first + best[i].second);
            }
        }
        return res;
    }
};
