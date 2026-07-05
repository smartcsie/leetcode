/**
 * 題目：1344. Angle Between Hands of a Clock
 * 難度：中等 (Medium)
 * 描述：計算時鐘上時針與分針之間較小的夾角。
 * * 優化重點：
 * 1. 角度轉換：時針每小時轉 30 度，每分鐘轉 0.5 度；分針每分鐘轉 6 度。
 * 2. 邊界處理：確保時針角度在 360 度範圍內 (處理 12 點情況)。
 * 3. 夾角計算：取兩者差值的絕對值，並確保夾角為較小的那個 (min(angle, 360 - angle))。
 */

#include <algorithm>
#include <cmath>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 時針角度：hour * 30 + 分鐘帶來的偏移 (每分鐘 0.5 度)
        // hour % 12 處理 12 點與 0 點的等價性
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        
        // 分針角度：每分鐘 6 度
        double minAngle = minutes * 6.0;
        
        // 計算兩者差值
        double angle = std::abs(hourAngle - minAngle);
        
        // 返回較小的夾角
        return std::min(360.0 - angle, angle);
    }
};
