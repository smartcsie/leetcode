/**
 * 題目：2469. Convert the Temperature (溫度轉換)
 * 難度：簡單 (Easy)
 * 描述：將攝氏溫度 celsius 轉換為 Kelvin 和 Fahrenheit。
 * * 時間複雜度：O(1) - 恆定運算。
 * 空間複雜度：O(1) - 回傳一個固定大小的陣列。
 * * 優化思路：
 * 1. Kelvin = Celsius + 273.15
 * 2. Fahrenheit = Celsius * 1.80 + 32.00
 * 直接返回計算結果即可滿足題目誤差要求，無需額外的四捨五入邏輯。
 */

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        // 直接計算並返回，編譯器在執行算術運算時已保留足夠的浮點精度
        return {
            celsius + 273.15,
            celsius * 1.80 + 32.00
        };
    }
};
