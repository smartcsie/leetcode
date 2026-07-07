/**
 * 題目：3232. Find if Digit Game Can Be Won
 * 難度：簡單 (Easy)
 * 描述：判斷 Alice 是否能通過拿走所有個位數或所有雙位數來獲勝。
 * * 優化重點：
 * 1. 分類加總：將數字分為 < 10 (個位) 與 >= 10 (雙位) 兩組。
 * 2. 條件判斷：只要兩組總和不相等，Alice 就能選擇總和較大的一組獲勝。
 */

class Solution {
public:
    bool canAliceWin(std::vector<int>& nums) {
        int sum_single = 0; // 個位數總和
        int sum_double = 0; // 雙位數總和
        
        for (const int& num : nums) {
            if (num < 10) {
                sum_single += num;
            } else {
                sum_double += num;
            }
        }
        
        // 若兩組總和不等，Alice 即可選擇總和較大的一組獲勝
        return sum_single != sum_double;
    }
};
