/**
 * 題目：401. Binary Watch
 * 難度：簡單 (Easy)
 * 描述：根據點亮的 LED 燈數量，找出所有可能的時間。
 * * 優化重點：
 * 1. 窮舉法：小時與分鐘範圍極小，直接枚舉優於遞迴或排列組合。
 * 2. 位元運算：popcount 是硬體級加速，能以極高效率計算位元數量。
 */

class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;
        
        // 枚舉所有 12 小時與 60 分鐘的組合
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                // 計算時與分總共點亮的燈數
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    char buffer[6];
                    // 格式化為 H:MM
                    std::snprintf(buffer, sizeof(buffer), "%d:%02d", h, m);
                    res.push_back(std::string(buffer));
                }
            }
        }
        
        return res;
    }
};
