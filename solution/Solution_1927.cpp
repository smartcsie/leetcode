/**
 * 題目：1927. Sum Game
 * 描述：Alice 和 Bob 輪流將字串中的 '?' 替換成 0-9 的數字。
 *       若最後左半邊總和等於右半邊總和，則 Alice 贏；否則 Bob 贏。
 *       判斷 Alice 是否必勝。
 * 
 * 解法思路 (期望值法)：
 * 1. 將 '?' 視為其平均期望值 4.5。
 * 2. 分別計算左右兩半邊的總和（包含數字與期望值）。
 * 3. 根據博弈特性，若兩邊期望總和不相等，Alice 必勝（因為 Bob 無法打破這個差距）。
 */

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.size();
        double alice = 0.0, bob = 0.0;
        for (int i = 0; i < n; i++) {
            // '?' 的數學期望值為 (0 + 1 + ... + 9) / 10 = 4.5
            double digit = (num[i] == '?') ? 4.5 : static_cast<double>(num[i] - '0');
            // 左半邊歸給 alice，右半邊歸給 bob
            if (i < n / 2) {
                alice += digit;
            } else {
                bob += digit;
            }
        }
        // 若期望總和不相等，Alice 就能透過策略贏得遊戲
        return alice != bob;
    }
};
