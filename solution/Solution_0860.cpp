/**
 * 題目：860. Lemonade Change
 * 描述：販賣檸檬水（每杯 5 元），根據客人給的鈔票（5, 10, 20）判斷是否能找零。
 * 
 * 解法思路 (Greedy)：
 * 1. 遇到 5 元：直接收下，coin5++。
 * 2. 遇到 10 元：找 5 元，coin5--，coin10++。
 * 3. 遇到 20 元：優先用 10+5 找零，若不行則用 5+5+5 找零。
 */

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        int coin5 = 0, coin10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                coin5++;
            } else if (bill == 10) {
                if (coin5 == 0) return false;
                coin5--;
                coin10++;
            } else { // bill == 20
                // 優先使用 10 元找零，這樣 5 元可以留給找 10 元的客人用
                if (coin10 > 0 && coin5 > 0) {
                    coin10--;
                    coin5--;
                } else if (coin5 >= 3) {
                    coin5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
