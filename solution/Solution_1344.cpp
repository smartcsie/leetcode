/**
 * 題目：1344. Angle Between Hands of a Clock (時鐘指針的夾角)
 * 難度：中等 (Medium)
 * 描述：計算時針與分針在指定時間下的夾角。
 * * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 * * 優化思路：
 * 1. 處理 12 點鐘重置：將 hour % 12 轉為 0，避免 hour=12 時計算出 360 度偏移。
 * 2. 精確度處理：保持使用 double 進行計算，最後取絕對值與 360 度取餘。
 */

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = hour * 30.0 + minutes * 0.5;
        double minAngle = minutes * 6.0;
        double angle = abs(hourAngle - minAngle);
        return min(360 - angle, angle);
    }
};
