/**
 * 題目：1185. Day of the Week
 * 難度：Easy
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 * 分類主題：math-formula
 * 技巧：Sakamoto's algorithm
 *
 * 解法說明：
 * 使用 Sakamoto's algorithm（Zeller's congruence 的簡化版）直接用公式算出星期幾：
 *   星期 = (y + y/4 - y/100 + y/400 + t[m-1] + d) mod 7，結果 0 = 星期日
 *   - y + y/4 - y/100 + y/400：從西元元年累積的天數，除以 7 取餘數
 *     （每年 365 天，365 mod 7 = 1，所以每年星期往後推 1 天，再加上閏年多出的天數）
 *   - t[m-1]：該月 1 日相對於 1 月 1 日的星期偏移（把前面各月的天數 mod 7 預先算好）
 *   - d：當月第幾天
 * 閏日（2/29）在年底計算會比較方便，所以 1、2 月要當成「前一年」的 13、14 月。
 */
class Solution {
    // 索引 0 = 星期日，順序要與公式的取餘結果一致
    static constexpr array<const char*, 7> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // 各月份的星期偏移表（Sakamoto's table）：
    // 前面各月天數累加後 mod 7 的結果，並已配合「1、2 月視為前一年」做過調整
    static constexpr array<int, 12> dayIdx = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1、2 月當成前一年，這樣閏年多出的 2/29 會落在「這一年」的最後，
        // 公式中 year/4 - year/100 + year/400 才能正確算入該年的閏日
        if (month < 3) year -= 1;

        // 公式各項加總後 mod 7，得到星期索引
        int idx = (year + year / 4 - year / 100 + year / 400 + dayIdx[month - 1] + day) % 7;
        return days[idx];
    }
};