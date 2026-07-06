/**
 * 題目：3894. Traffic Signal Color
 * 難度：簡單 (Easy)
 * 描述：根據輸入的 timer 數值返回對應的交通燈號字串。
 * * 規則：
 * - 0: Green
 * - 30: Orange
 * - 31 ~ 90: Red
 * - 其他: Invalid
 */

#include <string>

class Solution {
public:
    std::string trafficSignal(int timer) {
        if (timer == 0) {
            return "Green";
        } else if (timer == 30) {
            return "Orange";
        } else if (timer > 30 && timer <= 90) {
            return "Red";
        }
        return "Invalid";
    }
};
