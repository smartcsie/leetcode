/**
 * 題目：1109. Corporate Flight Bookings
 * 難度：中等 (Medium)
 * 描述：計算每一架航班在所有預訂請求後的總座位數。
 * * 優化重點：
 * 1. 差分標記：`diff[first - 1] += seats` 與 `diff[last] -= seats`。
 * 2. 前綴和還原：透過累加差分陣列得出最終結果。
 */

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n , 0);
        vector<int> diff(n , 0);
        for(const vector<int>& booking : bookings) {
            int flight1 = booking[0];
            int flight2 = booking[1];
            int seat = booking[2];
            diff[flight1 - 1] += seat;
            if(flight2 < n) diff[flight2] -= seat;
        }
        int cur_seat = 0;
        for(int i = 0; i <n ;i++) {
            cur_seat += diff[i];
            res[i] = cur_seat;
        }
        return res;
        
    }
};
