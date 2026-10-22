/**
 * 題目：401. Binary Watch
 * 難度：簡單 (Easy)
 * 描述：根據點亮的 LED 燈數量，找出所有可能的時間。
 * 優化重點：
 * 1. 窮舉法：小時與分鐘範圍極小，直接枚舉優於遞迴或排列組合。
 * 2. 位元運算：popcount 是硬體級加速，能以極高效率計算位元數量。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(format("{}:{:02d}", h, m));
                } 
            }
        }
        return ans;
    }
};