# Solution_1185

```cpp
/**
 * 題目：1185. Day of the Week
 * 難度：待補充
 * 描述：給你一個日期，請你設計一個演算法返回對應的星期幾（英文名稱）。
 * 範圍通常在 1971 年到 2100 年之間。
 *
 * 時間複雜度：O(1) - Zeller 公式，常數時間計算。
 * 空間複雜度：O(1) - 無額外空間。
 *
 * 解法思路：
 * （蔡勒公式 Zeller's Congruence）：
 * 1. 蔡勒公式：
 * - 是一個由數學家克里斯蒂安·蔡勒推導出來的計算公曆（格里曆）任何一天是星期幾的公式。
 * 2. 變數定義與調整：
 * - 若月份為 1 月或 2 月，則被視為上一年的 13 月和 14 月，因此年份 `year` 需減 1，`month` 需加 12。
 * - `year1` 代表世紀數（`year / 100`），`year2` 代表世紀內的年份（`year % 100`）。
 * 3. 公式計算：
 * - $W = (year2 + \lfloor year2 / 4 \rfloor + \lfloor year1 / 4 \rfloor - 2 \cdot year1 + \lfloor 13(month + 1) / 5 \rfloor + day - 1) \pmod 7$
 * - 透過處理餘數可能為負數的情況（`+7`），對應到正確的星期字串陣列。
 */

class Solution {
public:
    std::string dayOfTheWeek(int day, int month, int year) {
        // 定義星期字串陣列（對應標準蔡勒公式的餘數索引）
        std::vector<std::string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        // 蔡勒公式規則：1 月和 2 月要算作上一年的 13 月和 14 月
        if (month <= 2) {
            month += 12;
            year -= 1;
        }
        int year1 = year / 100; // 世紀
        int year2 = year % 100; // 年份後兩位
        // 標準蔡勒公式
        int dayIdx = (year2 + year2 / 4 + year1 / 4 - 2 * year1 + (13 * (month + 1)) / 5 + day - 1) % 7;
        // 處理 C++ 中負數取模可能小於 0 的情況
        if (dayIdx < 0) {
            dayIdx += 7;
        }
        return days[dayIdx];
    }
};

```
