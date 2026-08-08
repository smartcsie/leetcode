/**
 * 題目：1344. Angle Between Hands of a Clock
 * 難度：中等 (Medium)
 * 描述：計算時鐘上時針與分針之間較小的夾角。
 * 優化重點：
 * 1. 角度轉換：時針每小時轉 30 度，每分鐘轉 0.5 度；分針每分鐘轉 6 度。
 * 2. 邊界處理：確保時針角度在 360 度範圍內 (處理 12 點情況)。
 * 3. 夾角計算：取兩者差值的絕對值，並確保夾角為較小的那個 (min(angle, 360 - angle))。
 *
 * 時間複雜度：O(1) - 數學計算時針分針角度差。
 * 空間複雜度：O(1) - 無額外空間。
 */
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = 30.0 * hour + minutes * 0.5;
        double m = 6.0 * minutes;
        double angle = abs(h - m);
        return min(angle, 360.0 - angle);
    }
};
